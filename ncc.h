#ifndef NCC_
#define NCC_
#include "utils.h"

//void NCCBasedMatch(const cv::Mat& tpl, const cv::Mat& src,cv::Point2f& pt1,cv::Point2f& pt2,
//                   int window_radius, int search_radius, double& mcc);

void NCCBasedMatch(const cv::Mat &tpl, const cv::Mat &src, cv::Point2f &pt1, cv::Point2f &pt2,
              double &max_cc, int& state,bool interpolation=true);

void interpolate(const cv::Mat patch, double& x, double& y);

bool isInRange(const cv::Size size,const cv::Rect roi);

double fit2ndPolynomial(const std::vector<cv::Point2d> pts);

void getMaxElements33(const cv::Mat& src,double dst[],int flag=0);

#endif
