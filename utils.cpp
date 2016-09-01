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
        float x1,y1,x2,y2;
        x1=pts1[i].x;
        y1=pts1[i].y;
        x2=pts2[i].x;
        y2=pts2[i].y;
//        printf("%f\t%f\t%f\t%f\n",x1,y1,x2,y2);
        //A matrix
        cv::Mat row1=A.row(2*i);
        cv::Mat row=(cv::Mat_<double>(1,6)<<1,x1,y1,0,0,0);
        row.copyTo(row1);
        cv::Mat row2=A.row(2*i+1);
        row=(cv::Mat_<double>(1,6)<<0,0,0,1,x1,y1);
        row.copyTo(row2);
        //L matrix
        L.at<double>(0,2*i)=x2;
        L.at<double>(0,2*i+1)=y2;
    }
    cv::solve(A,L,x);

    for(int i=0; i<6; ++i){
        double t=x.at<double>(i,0);
        paras.push_back(t);
    }

//    std::cout<<x<<std::endl;
//    int a=1;
}

//inline void affineTransform(const cv::Point2f& src, const std::vector<double>& paras, cv::Point2f& dst)

void showCandidates(const cv::Mat& img1, const cv::Mat& img2,
                    const cv::Point2f& src, /*const cv::Point2f& dst,*/
                    const cv::Rect& contour, const std::vector<cv::Point2f>& pts, const int maxid){
    cv::Mat left_img=img1.clone();
    if(left_img.type()==CV_8UC1){
        cv::cvtColor(left_img,left_img,CV_GRAY2RGB);
    }
    cv::Mat right_img=img2.clone();
    if(right_img.type()==CV_8UC1){
        cv::cvtColor(right_img,right_img,CV_GRAY2RGB);
    }
    cv::circle(left_img,src,5,cv::Scalar(0,0,255),3);
//    cv::imshow("Left Scene",left_img);
    //draw rectangle
    cv::Point2f ul,ur,ll,lr;
    ul=cv::Point2f(contour.x, contour.y);
    ur=cv::Point2f(contour.x+contour.width, contour.y);
    ll=cv::Point2f(contour.x, contour.y+contour.height);
    lr=cv::Point2f(contour.x+contour.width, contour.y+contour.height);
    cv::line(right_img,ul,ur,cv::Scalar(255,0,0),2);
    cv::line(right_img,ur,lr,cv::Scalar(255,0,0),2);
    cv::line(right_img,lr,ll,cv::Scalar(255,0,0),2);
    cv::line(right_img,ll,ul,cv::Scalar(255,0,0),2);
    //draw candidates
    for(int i=0; i<pts.size(); ++i){
        if(i==maxid)
            cv::circle(right_img, pts[i], 2, cv::Scalar(0, 0, 255), 3);
        else
            cv::circle(right_img, pts[i], 2, cv::Scalar(0, 255, 0), 2);
    }
    showImagepair(left_img,right_img);
}

void showCorrespondences(const cv::Mat &img1, const cv::Mat &img2, const std::vector<cv::Point2f> &pts1, const std::vector<cv::Point2f> &pts2, const std::vector<Correspondence> &matches)
{
    std::vector<cv::KeyPoint> kpts1, kpts2;
    Point2f2KeyPoint(pts1, kpts1);
    Point2f2KeyPoint(pts2, kpts2);
    std::vector<std::vector<cv::DMatch> > dmatches;
    Crpd2VDMatch(matches, dmatches);
    cv::Mat dst;
    cv::drawMatches(img1, kpts1, img2, kpts2, dmatches, dst);
    showImage(dst, "test", image_scale);
}

void Crpd2VDMatch(const std::vector<Correspondence> &crpd, std::vector<std::vector<cv::DMatch> > &dmatch)
{
    dmatch.clear();
    for(int i=0; i<crpd.size(); ++i){
        std::vector<cv::DMatch> matches;
        cv::DMatch match;
        match.queryIdx=crpd[i].p1_id;
        match.trainIdx=crpd[i].p2_id;
        matches.push_back(match);
        dmatch.push_back(matches);
    }
}
