#ifndef COMMON_
#define COMMON_
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <fstream>
#include <string>
#include <stdarg.h>
#include <X11/Xlib.h>
//omp
#ifdef _OPENMP
#include <omp.h>
#endif

//opencv
#include "opencv2/opencv.hpp"
extern int display_int_results;
#define DEFAULT_WINDOW_NAME "test_window"
#define MAX_LENGTH_OF_FILEPATH 100
#define PAUSE printf("Press Enter key to continue..."); fgetc(stdin);

struct Correspondence{
//    cv::Point2f p1;
//    cv::Point2f p2;
    int p1_id;
    int p2_id;
    double corr;
    int wsize;
    double dx;
    double dy;
    bool operator<(const Correspondence &c) const {
       return p2_id<c.p2_id;
    }

};

struct Match{
    Match(){}
    Match(cv::Point2f p1,cv::Point2f p2):p1(p1),p2(p2),windowSize(0),corr(0),angle(0),speed(0){}
    double getParaX() const {return (double)(p1.x-p2.x);}
    double getParaY() const {return (double)(p1.y-p2.y);}
    cv::Point2f p1;
//    int p1_id;
//    int p2_id;
    cv::Point2f p2;
    int windowSize;
    double corr;
    double angle;
    double speed;

    bool operator==(const Match& m) const {
        if(p1.x==m.p1.x && p1.y==m.p1.y)
            return true;
        return false;
    }
    bool operator<(const Match &m) const {
        if(p1.x<m.p1.x){
            return true;
        }
        else if(p1.x==m.p1.x && p1.y<m.p1.y){
            return true;
        }
        return false;
    }
    bool operator>(const Match &m) const {
        if(p1.x>m.p1.x){
            return true;
        }
        else if(p1.x==m.p1.x && p1.y>m.p1.y){
            return true;
        }
        return false;
    }
};

//bool readConfigFile(const char *cfgfilepath, const std::string &key, std::string &value);
//bool readConfigFile(const char *cfgfilepath, const std::string &key, int &value);
//bool readConfigFile(const char *cfgfilepath, const std::string &key, double &value);
//bool readConfigFile(const char *cfgfilepath, const std::string &key, float &value);
//bool readConfigFile(const char *cfgfilepath, const std::string &key, bool &value);
void KeyPoint2Point2f(const std::vector<cv::KeyPoint>& src, std::vector<cv::Point2f>& dst);
void Point2f2KeyPoint(const std::vector<cv::Point2f>& src, std::vector<cv::KeyPoint>& dst);
void trimString(std::string &str);
bool str2bool(std::string s);
void lowerString(std::string &str);

void getPtsFromMatches(const std::vector<Match>& matches,std::vector<cv::Point2f>& lpts,std::vector<cv::Point2f>& rpts);
void readMatches(const std::string filename,std::vector<Match>& matches,bool withTitle=false,bool withCC=false, bool withWindowSize=false,
                 bool withArcgisCoor=false,bool withParaXY=false);
void showImage(const cv::Mat &img,std::string title=DEFAULT_WINDOW_NAME,double scale=1.0);
void showImagepair(const cv::Mat& img1,const cv::Mat& img2,std::string title=DEFAULT_WINDOW_NAME,double scale=1.0);
void showMulImages(const std::vector<cv::Mat>& srcImgs, cv::Size SubPlot, cv::Size ImgMax_Size,const std::string title=DEFAULT_WINDOW_NAME);
void printKeypoints(std::string filename,const std::vector<cv::KeyPoint>& kpts, bool display=false);
void printKeypoints(std::string filename,const std::vector<cv::Point2f>& kpts, bool display=false);
bool exitwithErrors(const char *msg);
void calAffineParas(const std::vector<cv::Point2f>& pts1, const std::vector<cv::Point2f>& pts2, std::vector<double>& paras);
inline void affineTransform(const cv::Point2f& src, const std::vector<double>& paras, cv::Point2f& dst){
    assert(paras.size()==6);
    double a0,a1,a2,b0,b1,b2;
    a0=paras[0];a1=paras[1];a2=paras[2];
    b0=paras[3];b1=paras[4];b2=paras[5];
    dst.x=a0+a1*src.x+a2*src.y;
    dst.y=b0+b1*src.x+b2*src.y;
}
void showCandidates(const cv::Mat& img1, const cv::Mat& img2, const cv::Point2f& src, const cv::Point2f& dst,
                    const cv::Rect& contour, const std::vector<cv::Point2f>& pts, const int maxid);

#endif
