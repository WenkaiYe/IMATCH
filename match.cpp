#include "match.h"

void performMatching(const cv::Mat& img1, const cv::Mat& img2,
                     const std::vector<cv::Point2f>& lpts, const std::vector<cv::Point2f>& rpts,
                     std::vector<Correspondence>& matches,
                     int window_radius, int search_radius, double mcc_threshold)
{
    matches.clear();
    assert(window_radius>0);
    assert(search_radius>0);
    assert(lpts.size()==rpts.size());
    for(int i=0;i<lpts.size();++i){
        //ensure all the coordinates of features are integer
        cv::Point2f point1=lpts.at(i);
        point1.x=floor(point1.x);
        point1.y=floor(point1.y);
        cv::Rect roi1(point1.x-window_radius,point1.y-window_radius,
                      window_radius*2,window_radius*2);
        cv::Mat tpl;
        if(isInRange(img1.size(),roi1))
            tpl=img1(roi1);
        else
            continue;

        cv::Point2f point2=rpts.at(i);
        point2.x=floor(point2.x);
        point2.y=floor(point2.y);
        cv::Rect roi2(point2.x-window_radius-search_radius,point2.y-window_radius-search_radius,
                      (window_radius+search_radius)*2,(window_radius+search_radius)*2);
        cv::Mat src;
        if(isInRange(img2.size(),roi2))
            src=img2(roi2);
        else
            continue;
        double mcc;
        int state;
        cv::Point2f p1,p2;
        NCCBasedMatch(tpl,src,p1,p2,mcc,state);
        if(state)
            if(mcc>mcc_threshold){
                Correspondence match;
                match.p1=point1;
                match.p2=point2+p2-cv::Point2f(window_radius+search_radius,window_radius+search_radius);
                match.corr=mcc;
                match.dx=match.p2.x-match.p1.x;
                match.dy=match.p2.y-match.p1.y;
                match.wsize=window_radius*2;
                matches.push_back(match);
            }
    }
}


void writeCorrespondences(const std::vector<Correspondence> &matches, char* path)
{
    FILE* stream;
    if((stream = fopen(path, "wt")) == NULL)
    {
        fprintf(stderr, "Cannot open output file./n");
        exit(-1);
    }else{
        for(int i=0;i<matches.size();++i){
            Correspondence match=matches.at(i);
            if(i==matches.size()-1)
                fprintf(stream,"%f\t%f\t%f\t%f\t%f",
                        match.p1.x,match.p1.y,match.dx,match.dy,match.corr);
            else
                fprintf(stream,"%f\t%f\t%f\t%f\t%f\n",
                        match.p1.x,match.p1.y,match.dx,match.dy,match.corr);
        }
    }
    fclose(stream);
}

void performMatching(const cv::Mat& img1, const cv::Mat& img2,
                     const std::vector<cv::Point2f>& lpts, const std::vector<cv::Point2f>& rpts,
                     const std::vector<Match>& seeds, std::vector<Correspondence>& matches,
                     int window_radius, int search_radius, double mcc_threshold){
    Delaunay tin1(img1);
    std::vector<cv::Point2f> pts1,pts2;
    getPtsFromMatches(seeds,pts1,pts2);
    tin1.generateDelaunay(pts1);
    tin1.drawDelaunay(img1,image_scale);
    int a=1;
}





