#ifndef FEATURE_H
#define FEATURE_H

#include "utils.h"

void gridPointGeneration(const cv::Size size1, const cv::Size size2,
                         int step, int x_shift, int y_shift,
                         std::vector<cv::Point2f>& pts1, std::vector<cv::Point2f>& pts2);

void gridPointGeneration(const cv::Size size1, const cv::Size size2,
                         int step, const cv::Mat& xshift_map, const cv::Mat& yshift_map,
                         std::vector<cv::Point2f>& pts1, std::vector<cv::Point2f>& pts2);

bool extractFeatures(const cv::Mat& img, std::vector<cv::KeyPoint>& kpts);

#endif // FEATURE_H

