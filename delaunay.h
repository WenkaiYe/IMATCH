#ifndef DELAUNAY_H
#define DELAUNAY_H

#include "utils.h"

class Delaunay:cv::Subdiv2D{

    typedef struct {
        int vtxID;
        cv::Point2f pt;
        double attr;
    } vertex;

    typedef struct {
        int triID;//triangle index
//        Point2f vertices[3];
//        double attribute[3];
        int vtx_idx[3];
        double area;
    } triangle;

public:
    Delaunay(cv::Rect rect):cv::Subdiv2D(rect),coverage(rect){}
    Delaunay(const cv::Mat& img):cv::Subdiv2D(cv::Rect(0,0,img.cols,img.rows)),
                                coverage(cv::Rect(0,0,img.cols,img.rows)){}
    ~Delaunay(){}
    //generate the triangulation
    void generateDelaunay(const std::vector<cv::Point2f>& pts,
                          const std::vector<double>& attribute=cv::vector<double>());
    void generateDelaunay(const std::vector<cv::KeyPoint>& kpts,
                          const std::vector<double>& attribute=cv::vector<double>());
    void generateDelaunay(const std::vector<Match>& matches, int mode=0);
    //get the triangulation
    void getTriangulation(const std::vector<double>& attribute=std::vector<double>());
    //draw the triangulation
    void drawDelaunay(const cv::Mat& src,double scale=1.0,cv::Scalar delaunayColor=cv::Scalar(0,0,255));
    //get the number of triangles contained in the triangulation
    int getNumberOfTri() const {return triangulation.size();}
    //check if the point is inside the certain triangle
    bool iswithinTri(const cv::Point2f& pt,int tri_id) const;
    //find the corresponding triangle
    int findTri(const cv::Point2f& pt);
    //
    void getTrilist(std::vector<cv::Point3i>& list);
//    //interpolate the attribute
//    double interpolateAttr (const cv::Point2f& pt,int tri_id) const;
//    //interpolate to get the parallax map
//    void interpolateSurface(double *&pData,int flag=0);

    //根据三角网预测位置
private:
    std::vector<triangle> triangulation;
    //calculate the area of the triangle
    double calTriArea(const cv::Point2f pt1,const cv::Point2f pt2,const cv::Point2f pt3);
    //overloaded
    double calTriArea(const int vtx_idx[]);
    //compare the areas of triangles
    static bool compTri(const triangle& a, const triangle& b){return a.area>b.area;}
    //get the contour of the triangle
    void convert2Contour(const triangle& tri,std::vector<cv::Point2f>& contour) const;
    //covering area of the delaunay
    cv::Rect coverage;
    //points for building up the triangulation
    std::vector<vertex> vertexes;
};

#endif // DELAUNAY_H

