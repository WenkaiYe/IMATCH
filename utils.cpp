#include "utils.h"

//bool readConfigFile(const char *cfgfilepath, const std::string &key, std::string &value){
//    /*
//     * parameter:
//                 cfgfilepath - configuration file path
//                         key - variable name in the configuration file
//                       value - value that corresponds to the key
//    */
//    std::fstream cfgFile;
//    cfgFile.open(cfgfilepath);
//    if(!cfgFile.is_open()){
//        std::cerr<<"Error happened while loading the configuration file!"<<std::endl<<std::endl;
//        return 0;
//    }
//    std::string line;
//    while(!cfgFile.eof()){
//        std::getline(cfgFile,line,'\n');
//        trimString(line);
//        if(line[0]=='#' || line.length()==0)
//            //
//            continue;
//        else{
//            size_t pos=line.find('=');
//            if(pos==std::string::npos){
//                std::cerr<<"Error happened while reading the configuration file!"<<std::endl;
//                cfgFile.close();
//                return 0;
//            }
//            std::string tmpKey=line.substr(0,pos);
//            if(key==tmpKey){
//                value=line.substr(pos+1);
//                cfgFile.close();
//                return 1;
//            }
//        }
//    }
//    cfgFile.close();
//    return 0;
//}
//bool readConfigFile(const char *cfgfilepath, const std::string &key, int &value){
//    std::string strtmp;
//    bool b=readConfigFile(cfgfilepath,key,strtmp);
//    if(b) value=atoi(strtmp.c_str());
//    return b;
//}
//bool readConfigFile(const char *cfgfilepath, const std::string &key, double &value){
//    std::string strtmp;
//    bool b=readConfigFile(cfgfilepath,key,strtmp);
//    if(b) value=atof(strtmp.c_str());
//    return b;
//}
//bool readConfigFile(const char *cfgfilepath, const std::string &key, float &value){
//    double tmp=value;
//    bool b=readConfigFile(cfgfilepath,key,tmp);
//    if(b) value=(float)tmp;
//    return b;
//}
//bool readConfigFile(const char *cfgfilepath, const std::string &key, bool &value){
//    std::string strtmp;
//    bool b=readConfigFile(cfgfilepath,key,strtmp);
//    if(b) value=str2bool(strtmp);
//    return b;
//}

void trimString(std::string &str){
    int s=str.find_first_not_of(" ");
    int e=str.find_last_not_of(" ");
    if(e>s)
        str=str.substr(s,e-s+1);
    else
        str="";
}

bool str2bool(std::string s){
    trimString(s);
    lowerString(s);
    if(s=="true")
        return true;
    else
        return false;
}

void lowerString(std::string &str){
    transform(str.begin(),str.end(),str.begin(),::tolower);
}

void showImage(const cv::Mat &img,std::string title,double scale){
    cv::Mat tmp=img;
    cv::resize(tmp,tmp,cv::Size(tmp.cols*scale,tmp.rows*scale));
    cv::imshow(title,tmp);
    cv::waitKey(0);
    cv::destroyWindow(title);
}

void showImagepair(const cv::Mat& img1,const cv::Mat& img2,std::string title,double scale)  {
    std::vector<cv::Mat> srcImgs(2);
    cv::resize(img1,srcImgs[0],cv::Size((int)img1.cols*scale,(int)img1.rows*scale));
    cv::resize(img2,srcImgs[1],cv::Size((int)img2.cols*scale,(int)img2.rows*scale));
    showMulImages(srcImgs,cv::Size(2,1),cv::Size(600,1200),title);
}

void showMulImages(const std::vector<cv::Mat>& srcImgs, cv::Size SubPlot, cv::Size ImgMax_Size,const std::string title)
{
    //Reference : http://blog.csdn.net/yangyangyang20092010/article/details/21740373
    //title of the window
    cv::Mat dst;
    //Max Height & Width of source image
    int width=0,height=0;
    for(int i=0;i<srcImgs.size();++i){
        width=srcImgs[i].cols>width?srcImgs[i].cols:width;
        height=srcImgs[i].rows>height?srcImgs[i].rows:height;
    }
    cv::Size Img_OrigSize = cv::Size(width, height);
    //******************** Set the width for displayed image ********************//
    //Width vs height ratio of source image
    float WH_Ratio_Orig = Img_OrigSize.width/(float)Img_OrigSize.height;
    cv::Size ImgDisp_Size = cv::Size(100, 100);
    if(Img_OrigSize.width > ImgMax_Size.width)
        ImgDisp_Size = cv::Size(ImgMax_Size.width, (int)ImgMax_Size.width/WH_Ratio_Orig);
    else if(Img_OrigSize.height > ImgMax_Size.height)
        ImgDisp_Size = cv::Size((int)ImgMax_Size.height*WH_Ratio_Orig, ImgMax_Size.height);
    else
        ImgDisp_Size = cv::Size(Img_OrigSize.width, Img_OrigSize.height);
    //******************** Check Image numbers with Subplot layout ********************//
    int Img_Num = (int)srcImgs.size();
    if(Img_Num > SubPlot.width * SubPlot.height)
        exitwithErrors("Inconsistency detected between number of images and the subplot settings!...\n");

    //******************** Blank setting ********************//
    cv::Size DispBlank_Edge = cv::Size(80, 60);
    cv::Size DispBlank_Gap  = cv::Size(15, 15);
    //******************** Size for Window ********************//
    dst.create(cv::Size(ImgDisp_Size.width*SubPlot.width + DispBlank_Edge.width + (SubPlot.width - 1)*DispBlank_Gap.width,
        ImgDisp_Size.height*SubPlot.height + DispBlank_Edge.height + (SubPlot.height - 1)*DispBlank_Gap.height), srcImgs[0].type());
    dst.setTo(0);//Background
    //Left top position for each image
    int EdgeBlank_X = (dst.cols - (ImgDisp_Size.width*SubPlot.width + (SubPlot.width - 1)*DispBlank_Gap.width))/2;
    int EdgeBlank_Y = (dst.rows - (ImgDisp_Size.height*SubPlot.height + (SubPlot.height - 1)*DispBlank_Gap.height))/2;
    CvPoint LT_BasePos = cv::Point(EdgeBlank_X, EdgeBlank_Y);
    CvPoint LT_Pos = LT_BasePos;
    //Display all images
    for (int i=0; i < Img_Num; i++)
    {
        //Obtain the left top position
        if ((i%SubPlot.width == 0) && (LT_Pos.x != LT_BasePos.x))
        {
            LT_Pos.x = LT_BasePos.x;
            LT_Pos.y += (DispBlank_Gap.height + ImgDisp_Size.height);
        }
        //Writting each to Window's Image
        cv::Mat imgROI,tmp;
        cv::resize(srcImgs[i], tmp, cv::Size(ImgDisp_Size.width, ImgDisp_Size.height));
        imgROI=dst(cv::Rect(LT_Pos.x, LT_Pos.y, ImgDisp_Size.width, ImgDisp_Size.height));
        tmp.copyTo(imgROI);
        LT_Pos.x += (DispBlank_Gap.width + ImgDisp_Size.width);
    }
    //Get the screen size of computer
    Display* disp=XOpenDisplay(NULL);
    Screen* screen=DefaultScreenOfDisplay(disp);
    int Screen_W = screen->width;
    int Screen_H = screen->height;
//    printf("screen size:\nwidth: %d, height: %d\n",Screen_W,Screen_H);
    cv::namedWindow(title.c_str(), CV_WINDOW_AUTOSIZE);
    cv::moveWindow(title.c_str(),(Screen_W - dst.cols)/2 ,(Screen_H - dst.rows)/2);//Centralize the window
    cv::imshow(title.c_str(),dst);
//    cv::imshow(title.c_str(), &(IplImage(dst)));
    cv::waitKey(0);
    cv::destroyWindow(title.c_str());
}

void KeyPoint2Point2f(const std::vector<cv::KeyPoint>& src, std::vector<cv::Point2f>& dst){
    dst.clear();
    for (size_t i=0; i<src.size(); ++i)
        dst.push_back(src[i].pt);
}

void Point2f2KeyPoint(const std::vector<cv::Point2f>& src, std::vector<cv::KeyPoint>& dst){
    dst.clear();
    for (size_t i=0; i<src.size();++i)
        dst.push_back(cv::KeyPoint(src[i],1.0f));
}

void printKeypoints(std::string filename,const std::vector<cv::KeyPoint>& kpts, bool display){
    std::ofstream out;
    out.open(filename.c_str());
    int c=0;
    if(out.is_open()){
        std::vector<cv::KeyPoint>::const_iterator iter;
        for(iter=kpts.begin();iter<kpts.end();++iter){
            out<<(*iter).pt.x<<"\t"<<(*iter).pt.y;
            if(++c!=kpts.size())
                out<<std::endl;
        }
        out.close();
    }else{
        exitwithErrors("Unable to open the output file!");
    }
    if(display)
        std::cout<<kpts.size()<<" Keypoints were written into the file "<<filename<<std::endl;
}

void printKeypoints(std::string filename,const std::vector<cv::Point2f>& pts, bool display){
    std::vector<cv::KeyPoint> kpts;
    Point2f2KeyPoint(pts,kpts);
    printKeypoints(filename,kpts,display);
}

bool exitwithErrors(const char *msg){
    std::cerr<<msg<<std::endl<<std::endl;
    return -1;
}

void getPtsFromMatches(const std::vector<Match> &matches, std::vector<cv::Point2f> &lpts, std::vector<cv::Point2f> &rpts)
{
    assert(matches.size()>0);
    lpts.clear();
    rpts.clear();
    for(std::vector<Match>::const_iterator citer=matches.begin();citer<matches.end();++citer){
        cv::Point2f lpt,rpt;
        lpt=(*citer).p1;
        lpts.push_back(lpt);
        rpt=(*citer).p2;
        rpts.push_back(rpt);
    }
}

void readMatches(const std::string filename, std::vector<Match> &matches,
                 bool withTitle,bool withCC, bool withWindowSize,bool withArcgisCoor,bool withParaXY)
{
    matches.clear();
    std::ifstream in;
    in.open(filename.c_str());
    if(!in.is_open())
        exitwithErrors("Unable to read the file!");
    else{
        while(!in.eof()){
            cv::Point2f pt1,pt2;
            Match match;

            if(withTitle){
                std::string tmp;
                std::getline(in,tmp);
            }

            in>>pt1.x>>pt1.y>>pt2.x>>pt2.y;
            match.p1=pt1;
            match.p2=pt2;

            if(withCC){
                double cc;
                in>>cc;
                match.corr=cc;
            }

            if(withWindowSize){
                int ww;
                in>>ww;
                match.windowSize=ww;
            }
            if(withArcgisCoor){
                double tmpd;
                in>>tmpd>>tmpd>>tmpd>>tmpd;
            }
            if(withParaXY){
                double paraX,paraY;
                in>>paraX>>paraY;
            }
            matches.push_back(match);
        }
    }
    in.close();
}


void calAffineParas(const std::vector<cv::Point2f> &pts1, const std::vector<cv::Point2f> &pts2, std::vector<double> &paras)
{
//    C++: bool solve(InputArray src1, InputArray src2, OutputArray dst, int flags=DECOMP_LU)
    cv::Mat A(6, 6, CV_64FC1);
    A.setTo(0);
    cv::Mat L(6, 1, CV_64FC1);
    L.setTo(0);
    cv::Mat x(6, 1, CV_64FC1);
    x.setTo(0);
    for(int i=0; i<3; ++i){
        cv::Mat row=;
    }

}
