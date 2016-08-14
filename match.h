#ifndef MATCH
#define MATCH

#include "utils.h"
#include "ncc.h"
#include "feature.h"
#include "delaunay.h"

extern double image_scale;

void performMatching(const cv::Mat& img1, const cv::Mat& img2,
                     const std::vector<cv::Point2f>& lpts, const std::vector<cv::Point2f>& rpts,
                     std::vector<Correspondence>& matches,
                     int window_radius=8, int search_radius=10, double mcc_threshold=0.8);

void performMatching(const cv::Mat& img1, const cv::Mat& img2,
                     const std::vector<cv::Point2f>& lpts, const std::vector<cv::Point2f>& rpts,
                     const std::vector<Match>& seeds, std::vector<Correspondence>& matches,
                     int window_radius=8, int search_radius=10, double mcc_threshold=0.8);

void writeCorrespondences(const std::vector<Correspondence>& matches,char* path);

#endif // MATCH

