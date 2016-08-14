#include "common.h"
#include "match.h"
//global variables and functions
char* const short_options = "o:hvfdp";
char out_path[MAX_LENGTH_OF_FILEPATH];       /*output directory*/
char cur_dir[MAX_LENGTH_OF_FILEPATH];        /*current directory*/
std::string img1_path;                       /*file paths of the stereo image pair*/
std::string img2_path;
bool display=false;                          /*display matching arguments*/
bool parallel=false;                         /*perform matching parallelly*/
int mode_flag=0;                             /*0:grid; other:feature*/
int window_radius=8;                         /*window size*/
int search_radius=10;                        /*search size*/
int step=50;                                 /*grid interval*/
int shift_x=0;                               /*x shift of the first grid point*/
int shift_y=0;                               /*y shift of the first grid point*/
std::string xshift_path="";
std::string yshift_path="";
double cor_coe=0.8;                          /*correlation coefficient threshold*/
float version_id=1.1;                        /*version information*/
std::string version_Date="2016-08-04";

struct option long_options[] = {
{ "out", 1, NULL, 'o' },
{ "version", 0, NULL, 'v' },
{ "display", 0, NULL, 'd' },
{ "help", 0, NULL, 'h' },
{ "parallel", 0, NULL, 'p' },
{ 0, 0, 0, 0},
};

void print_usage(){
    printf("============================================================\n");
    printf("Usage: tj [-v/--version] [-h/--help] [-d/--display] [-p/--parallel]\n"
           "[img1 img2 window_radius search_radius step x_shift/x_shift_map y_shift/y_shift_map cc]\n");
    printf(" -h --help\t\t显示帮助信息;\n"
           " -o --out filepath\t结果输出路径;\n"
           " -p --parallel\t\t并行匹配;\n"
           " -d --display\t\t显示匹配参数;\n"
           " -v --version\t\t打印版本信息.\n");
    printf("============================================================\n");
}

void parse_args(int argc, char *argv[])
{
    int opt;
    while((opt = getopt_long (argc, argv, short_options, long_options, NULL)) != -1)
    {
        switch (opt)
        {
        case 'o':
            strcpy(out_path,optarg);
            break;
        case 'h':
            print_usage();
            break;
        case 'd':
            display=true;
            break;
        case 'p':
            parallel=true;
            break;
        case 'v':
            printf("TJ package for matching. %s Version: %.1f\n",version_Date.c_str(),version_id);
            break;
        default:
            break;
        }
    }

    int num_args=argc-optind;
    if(num_args>1){
        img1_path=std::string(cur_dir)+std::string(argv[optind++]);
        img2_path=std::string(cur_dir)+std::string(argv[optind++]);
        if(num_args>2){
            window_radius=atoi(argv[optind++]);
            if(num_args>3){
                search_radius=atoi(argv[optind++]);
                if(num_args>4){
                    step=atoi(argv[optind++]);
                    if(num_args>5){
                        xshift_path=std::string(argv[optind++]);
                        if(num_args>6){
                            yshift_path=std::string(argv[optind++]);
                            if(num_args>7){
                                cor_coe=atof(argv[optind]);
                                if(num_args>8){
                                    printf("Error:Too many arguments for matching!\n");
                                    exit(-1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }else{
        if(num_args==1){
            printf("Error:Too few arguments for matching!\n");
            exit(-1);
        }
    }

    if(display){
        //print matching arguments
        printf("************ Matching Arguments **************\n");
        printf("Stereo image pair:\n--Image1:%s\n--Image2:%s\n",img1_path.c_str(),img2_path.c_str());
        printf("Window Radius:%d;\tSearch Radius:%d;\tStep:%d;\n",window_radius,search_radius,step);
        printf("Shift X:%d;\tShift Y:%d;\nCorrelation Coefficient Threshold:%f;\n",shift_x,shift_y,cor_coe);
        printf("**********************************************\n");
    }
}

void init_dir(){
    getcwd(cur_dir,MAX_LENGTH_OF_FILEPATH);
    strcat(cur_dir,"/");
    strcpy(out_path,cur_dir);
    strcat(out_path,"out.txt");
}

int is_digit(const std::string str){
    const char* tmp_str=str.c_str();
    size_t len=strlen(tmp_str);
    while(len>0){
        if(*tmp_str<'0' || *tmp_str>'9')
            return -1;
        tmp_str++;
        len--;
    }
    return 1;
}

int main(int argc, char *argv[]){
    //initialize parameters
    init_dir();
    //parse commandline arguments
    parse_args(argc,argv);
    //not perform matching
    if(img1_path=="")
        return 0;
    //read stereo image pair
    cv::Mat img1=cv::imread(img1_path);
    if(!img1.data){
        fprintf(stderr,"cannot open the first image!\n");
        exit(-1);
    }
    cv::Mat img2=cv::imread(img2_path);
    if(!img2.data){
        fprintf(stderr,"cannot open the second image!\n");
        exit(-1);
    }

    std::vector<cv::Point2f> pts1,pts2;
    std::vector<Correspondence> matches;

    //grid point generation according to the shift-type
    if(is_digit(xshift_path)==1 && is_digit(yshift_path)==1){

        shift_x=atoi(xshift_path.c_str());
        shift_y=atoi(yshift_path.c_str());

        gridPointGeneration(img1.size(),img2.size(),step,shift_x,shift_y,pts1,pts2);

    }else if(is_digit(xshift_path)==-1 && is_digit(yshift_path)==-1){
        cv::Mat xshift_map=cv::imread(std::string(cur_dir)+xshift_path,CV_64F);

        if(!xshift_map.data){
            fprintf(stderr,"cannot open the x-shift map!\n");
            exit(-1);
        }
        cv::Mat yshift_map=cv::imread(std::string(cur_dir)+yshift_path, CV_64F);
        if(!yshift_map.data){
            fprintf(stderr,"cannot open the y-shift map!\n");
            exit(-1);
        }
        gridPointGeneration(img1.size(),img2.size(),step,xshift_map,yshift_map,pts1,pts2);

    }else{
        fprintf(stderr,"unsupported shift input parameters!\n");
        exit(-1);
    }

    //perform matching
//    ///NOT IMPLEMENTED YET...
//    if(parallel)
//        performMatchingOMP(img1,img2,pts1,pts2,matches,window_radius,search_radius,cor_coe);
//    else
        performMatching(img1,img2,pts1,pts2,matches,window_radius,search_radius,cor_coe);

    //output
    writeCorrespondences(matches,out_path);
    return 0;
}


