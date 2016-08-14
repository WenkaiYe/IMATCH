#ifndef MATCH
#define MATCH

#include "common.h"
#include "ncc.h"

void performMatching(const cv::Mat& img1, const cv::Mat& img2,
                     const std::vector<cv::Point2f>& lpts, const std::vector<cv::Point2f>& rpts,
                     std::vector<Correspondence>& matches,
                     int window_radius=8, int search_radius=10, double mcc_threshold=0.8);

void performMatchingOMP(const cv::Mat& img1, const cv::Mat& img2,
                        const std::vector<cv::Point2f>& lpts, const std::vector<cv::Point2f>& rpts,
                        std::vector<Correspondence>& matches,
                        int window_radius=8, int search_radius=10, double mcc_threshold=0.8);

void gridPointGeneration(const cv::Size size1, const cv::Size size2,
                         int step, int x_shift, int y_shift,
                         std::vector<cv::Point2f>& pts1, std::vector<cv::Point2f>& pts2);

void gridPointGeneration(const cv::Size size1, const cv::Size size2,
                         int step, const cv::Mat& xshift_map, const cv::Mat& yshift_map,
                         std::vector<cv::Point2f>& pts1, std::vector<cv::Point2f>& pts2);

void writeCorrespondences(const std::vector<Correspondence>& matches,char* path);

#endif // MATCH

