#ifndef MATCH
#define MATCH

#include "utils.h"
#include "ncc.h"
#include "feature.h"
#include "delaunay.h"

extern double image_scale;
//typedef std::pair<int, int> ipair;

void performMatching(const cv::Mat& img1, const cv::Mat& img2,
                     const std::vector<cv::Point2f>& lpts, const std::vector<cv::Point2f>& rpts,
                     std::vector<Match>& matches,
                     int window_radius=8, int search_radius=10, double mcc_threshold=0.8);

void performMatching(const cv::Mat& img1, const cv::Mat& img2,
                     const std::vector<cv::Point2f>& lpts, const std::vector<cv::Point2f>& rpts,
                     const std::vector<Match>& seeds, std::vector<Match>& matches,
                     int window_radius=8, int search_radius=10, double mcc_threshold=0.8);

void ftfMatchImpl(const cv::Mat &img1, const cv::Mat &img2, const std::vector<cv::Point2f> &lpts, const std::vector<cv::Point2f> &rpts,
                  std::vector<cv::Point2f> pts1, std::vector<cv::Point2f> pts2, std::vector<std::vector<int> > t2f, std::vector<std::vector<int> > list,
                  std::vector<Match> &matches, int window_radius=8, int search_radius=10);

void writeCorrespondences(const std::vector<Match>& matches,char* path);

void genFeature2TriangleTable(const std::vector<cv::Point2f>& features,
                              const Delaunay& tris,
                              std::vector<int>& f2t, std::vector<std::vector<int> >& t2f);

void showFeatureInsideTriangles(const cv::Mat& img, const std::vector<cv::Point2f>& features,
                                const Delaunay& tris, const std::vector<std::vector<int> >& t2f);

void constructContour(const cv::Point2f& center, const int searchRadius, std::vector<cv::Point2f>& contour);

void constructContour(const cv::Point2f& center, const int searchRadius, cv::Rect& contour);
#endif // MATCH

