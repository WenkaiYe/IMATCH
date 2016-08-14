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

void showImage(cv::Mat &img,std::string title,double scale){
    cv::Mat tmp=img;
    cv::resize(tmp,tmp,cv::Size(tmp.cols*scale,tmp.rows*scale));
    cv::imshow(title,tmp);
    cv::waitKey(0);
}

void showImagepair(const cv::Mat& img1,const cv::Mat& img2,std::string title,double scale)  {

    cv::Mat dst;
    int width,height;
    width=img1.cols+img2.cols;
    height=img1.rows+img2.rows;
    dst.create(cv::Size(width,height), CV_8UC1);
    cv::resize(dst, dst, cv::Size((int)dst.rows*scale,(int)dst.cols*scale));
    cv::imshow(title, dst);
    cv::waitKey(0);
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
