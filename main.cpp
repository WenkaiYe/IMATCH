#include "utils.h"
#include "match.h"
//global variables and functions
char* const short_options = "o:hvdfsc:a";/*?????*/
char out_path[MAX_LENGTH_OF_FILEPATH];       /*output directory*/
char control_path[MAX_LENGTH_OF_FILEPATH];   /*control path*/
char cur_dir[MAX_LENGTH_OF_FILEPATH];        /*current directory*/
std::string img1_path;                       /*file paths of the stereo image pair*/
std::string img2_path;
int display_int_results=0;                  /*show feature extraction results ?????*/
double image_scale=1.0;                      /*image scale for display*/
//bool parallel=false;                         /*perform matching parallelly*/
//bool histeq=false;                           /*perform histogram equalization*/
bool feature=false;                          /*extract features instead of grid points*/
bool show_parameters=false;                  /*show matching arguments*/
int mode_flag=0;                             /*0:grid; other:feature*/
int window_radius=8;                         /*window size*/
int search_radius=16;                        /*search size*/
int step=50;                                 /*grid interval*/
int shift_x=0;                               /*x shift of the first grid point*/
int shift_y=0;                               /*y shift of the first grid point*/
std::string xshift_path="0";
std::string yshift_path="0";
double cor_coe=0.8;                          /*correlation coefficient threshold*/
float version_id=2.0;                        /*version information*/
std::string version_Date="2016-08-14";

struct option long_options[] = {
{"control", 1, NULL, 'c'},
{"image-scale", 1, NULL, 'a'},
{"show", 0, NULL, 's'},
{"feature", 0, NULL, 'f'},
//{ "histeq", 0, NULL, 'e' },
{ "out", 1, NULL, 'o' },
{ "version", 0, NULL, 'v' },
{ "display", 0/*?????*/, NULL, 'd' },
{ "help", 0, NULL, 'h' },
//{ "parallel", 0, NULL, 'p' },
{ 0, 0, 0, 0},
};

void print_usage(){
//    printf("============================================================\n");
    printf("Usage: imatch [-v/--version] [-h/--help] [-c/--control=<path>]\n\
           [-d/--display] [-f/--feature [<type>]]\n\
           [-o/--out=<path>] [-s/--show [details]]\n\
           <command> [<args>] img1 img2 window_radius search_radius step x_shift/x_shift_map y_shift/y_shift_map cc]\n\n");
    printf("The most commonly used imatch commands are:\n\
             image1         one of the stereo image pair;\n\
             image2         the other one of the stereo image pair;\n\
             window_radius  radius size for template;\n\
             search_radius  additional search range;\n\
             step           interval to generate grid points;\n\
             x_shift        horizontal shift between the stereo image pair;\n\
             y_shift        vertical shift between the stereo image pair;\n\
             cc             correlation coefficient threshold.\n\n");
    printf("'imatch help -a' and 'imatch help -g' list available subcommands and some "
    "concept guides. See 'imatch help <command>' or 'imatch help <concept>'"
    "to read about a specific subcommand or concept.\n\n");
//    printf("============================================================\n");
}

void getCurrentdir(){
    getcwd(cur_dir,MAX_LENGTH_OF_FILEPATH);
    strcat(cur_dir,"/");
    strcpy(out_path,cur_dir);
    strcat(out_path,"out.txt");
}

void getFilepath(char filepath[]){
    if(strlen(filepath)==0)
        return;
    std::string str=std::string(filepath);
    int cmp=str.compare(0,6,std::string(cur_dir),0,6);
    if(cmp!=0){
        //relative path
        str=std::string(cur_dir)+std::string(filepath);
        strcpy(filepath,str.c_str());
    }
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
            getFilepath(out_path);
            break;
        case 'c':
            strcpy(control_path,optarg);
            getFilepath(control_path);
            break;
        case 'h':
            print_usage();
            break;
        case 'd':
            display_int_results=/*atoi(optarg)*/2;/*?????*/
            break;
        case 'a':
            image_scale=atof(optarg);
            break;
//        case 'e':
//            histeq=true;
//            break;
//        case 'p':
//            parallel=true;
//            break;
        case 'f':
            feature=true;
            break;
        case 's':
            show_parameters=true;
            break;
        case 'v':
            printf("TJ package for matching. %s Version: %.1f\n",version_Date.c_str(),version_id);
            break;
        default:
            break;
        }
    }

    int num_args=argc-optind;
    char* tmp=NULL;
    if(num_args>1){
        tmp=argv[optind++];
        img1_path=std::string(tmp);
        tmp=argv[optind++];
        img2_path=std::string(tmp);
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

    if(show_parameters){
        //print matching arguments
        printf("************ Matching Arguments **************\n");
        printf("Stereo image pair:\n--Image1:%s\n--Image2:%s\n",img1_path.c_str(),img2_path.c_str());
        printf("Window Radius:%d;\tSearch Radius:%d;\tStep:%d;\n",window_radius,search_radius,step);
        printf("Shift X:%s;\tShift Y:%s;\nCorrelation Coefficient Threshold:%f;\n",xshift_path.c_str(),yshift_path.c_str(),cor_coe);
        printf("**********************************************\n");
    }
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
    //get current directory
    getCurrentdir();
    //parse commandline arguments
    parse_args(argc,argv);
    //not perform matching
    if(img1_path=="")
        return 0;
    //read stereo image pair
    cv::Mat img1=cv::imread(img1_path,CV_8UC1);
    if(!img1.data){
        fprintf(stderr,"cannot open the first image!\n");
        exit(-1);
    }
    cv::Mat img2=cv::imread(img2_path,CV_8UC1);
    if(!img2.data){
        fprintf(stderr,"cannot open the second image!\n");
        exit(-1);
    }

//    if(histeq){
//        cv::equalizeHist(img1,img1);
//        cv::equalizeHist(img2,img2);
//    }

    std::vector<cv::Point2f> pts1,pts2;
    std::vector<cv::KeyPoint> kpts1,kpts2;
    std::vector<Match> matches, controls;

    //************************ 1. generate points for matching ************************
    if(feature){
        //feature extraction
        printf("Perform feature extraction...\n");
        extractFeatures(img1,kpts1);
        KeyPoint2Point2f(kpts1,pts1);
        extractFeatures(img2,kpts2);
        KeyPoint2Point2f(kpts2,pts2);
        printf("%d features are extracted from the first image and %d features are extracted from the second image...\n",pts1.size(),pts2.size());
    }else{
        //grid point generation according to the shift-type
        printf("Perform grid point generation...\n");
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

        printf("%d points are extracted from the first image and %d points are extracted from the second image...\n",pts1.size(),pts2.size());
    }

    if(feature && display_int_results>0/*need further modifications*/){
        cv::Mat dst1=img1.clone();
        cv::Mat dst2=img2.clone();
        cv::drawKeypoints(img1,kpts1,dst1);
        cv::drawKeypoints(img1,kpts1,dst2);
        showImagepair(dst1,dst2,"Feature Extraction",image_scale);
        printKeypoints(std::string(cur_dir)+std::string(".leftpoints.dat"),pts1);
        printKeypoints(std::string(cur_dir)+std::string(".rightpoints.dat"),pts2);
    }

    //******************** 2. read control information if available ********************
    if(strlen(control_path)!=0)
        readMatches(control_path,controls);

    //****************************** 3. perform matching ******************************
    printf("Perform matching...\n");  

    if(controls.size()!=0){
        //control for matching provided
        if(feature)
            //control+features
            performMatching(img1,img2,pts1,pts2,controls,matches,window_radius,search_radius,cor_coe);
        else
            //control+grid points
            /*performMatching(img1,img2,pts1,pts2,matches,window_radius,search_radius,cor_coe)*/;
    }else{
        //no control for matching available
        if(feature)
            //no control+features
            /*performMatching(img1,img2,pts1,pts2,controls,matches,window_radius,search_radius,cor_coe)*/;
        else
            //no control+grid points
            performMatching(img1,img2,pts1,pts2,matches,window_radius,search_radius,cor_coe);
    }

    //****************************** 4. output ******************************
    writeCorrespondences(matches,out_path);

    printf("Matching completed sucessfully. %d correspondences are found...\n", matches.size());
    return 0;
}


