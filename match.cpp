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

void gridPointGeneration(const cv::Size size1, const cv::Size size2,
                         int step, int x_shift, int y_shift,
                         std::vector<cv::Point2f>& pts1,std::vector<cv::Point2f>& pts2)
{
    if(step==0) step=1e8;
    pts1.clear();
    pts2.clear();
    int width1=size1.width;
    int height1=size1.height;
    int width2=size2.width;
    int height2=size2.height;
    for(int x=29; x<width1; x+=step)
        for(int y=29; y<height1; y+=step){
            if(x+x_shift<width2 && y+y_shift<height2){
                cv::Point2f pt;
                pt.x=(double)x;
                pt.y=(double)y;
                pts1.push_back(pt);

                pt.x=(double)(x+x_shift);
                pt.y=(double)(y+y_shift);
                pts2.push_back(pt);
            }else
                continue;
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


void performMatchingOMP(const cv::Mat& img1, const cv::Mat& img2,
                        const std::vector<cv::Point2f>& lpts, const std::vector<cv::Point2f>& rpts,
                        std::vector<Correspondence>& matches,
                        int window_radius, int search_radius, double mcc_threshold)
{
//    matches.clear();
//    assert(window_radius>0);
//    assert(search_radius>0);

//    int max_threads;

//    #ifdef _OPENMP
//        max_threads=omp_get_max_threads();
//    #else
//        max_threads=1;
//    #endif

//    std::vector<std::vector<Correspondence> > temp_matches(max_threads);

//#pragma omp parallel for schedule(static,1) num_threads(max_threads)
//    for(int i=0;i<lpts.size();++i){
//        //get the id of the current thread
//        int thread_id;
//        #ifdef _OPENMP
//                thread_id=omp_get_thread_num();
//        #else
//                thread_id=0;
//        #endif
//        //ensure all the coordinates of features are integer
//        cv::Point2f point1=lpts.at(i);
//        point1.x=floor(point1.x);
//        point1.y=floor(point1.y);
//        cv::Rect roi1(point1.x-window_radius,point1.y-window_radius,
//                      window_radius*2,window_radius*2);
//        cv::Mat tpl;
//        if(isInRange(img1.size(),roi1))
//            tpl=img1(roi1);
//        else
//            continue;

//        cv::Point2f point2=rpts.at(i);
//        point2.x=floor(point2.x);
//        point2.y=floor(point2.y);
//        cv::Rect roi2(point2.x-window_radius-search_radius,point2.y-window_radius-search_radius,
//                      (window_radius+search_radius)*2,(window_radius+search_radius)*2);
//        cv::Mat src;
//        if(isInRange(img2.size(),roi2))
//            src=img2(roi2);
//        else
//            continue;
//        double mcc;
//        int state;
//        cv::Point2f p1,p2;
//        NCCBasedMatch(tpl,src,p1,p2,mcc,state);
//        if(state)
//            if(mcc>mcc_threshold){
//                Correspondence match;
//                match.p1=point1;
//                match.p2=point2+p2-cv::Point2f(window_radius+search_radius,window_radius+search_radius);
//                match.corr=mcc;
//                match.dx=match.p2.x-match.p1.x;
//                match.dy=match.p2.y-match.p1.y;
//                match.wsize=window_radius*2;
//                temp_matches[thread_id].push_back(match);
//            }
//    }

//    //merge
//    for(int i=0;i<max_threads;++i)
//        matches.insert(matches.end(),temp_matches[i].begin(),temp_matches[i].end());
    printf("Not implemented yet...\n");
}


void gridPointGeneration(const cv::Size size1, const cv::Size size2, int step,
                         const cv::Mat &xshift_map, const cv::Mat &yshift_map,
                         std::vector<cv::Point2f> &pts1, std::vector<cv::Point2f> &pts2)
{
    assert(xshift_map.size()==size1);
    assert(yshift_map.size()==xshift_map.size());
//    assert(xshift_map.depth()==CV_64F);
//    assert(yshift_map.depth()==CV_64F);

    if(step==0) step=1e8;
    pts1.clear();
    pts2.clear();
    int width1=size1.width;
    int height1=size1.height;
    int width2=size2.width;
    int height2=size2.height;
    for(int x=29; x<width1; x+=step)
        for(int y=29; y<height1; y+=step){
            //NOTE:depth of the shift mat must be 32 bits
            int x_shift=xshift_map.at<float>(y,x);
            int y_shift=yshift_map.at<float>(y,x);

            if(x+x_shift<width2 && y+y_shift<height2){
                cv::Point2f pt;
                pt.x=(double)x;
                pt.y=(double)y;
                pts1.push_back(pt);

                pt.x=(double)(x+x_shift);
                pt.y=(double)(y+y_shift);
                pts2.push_back(pt);
            }else
                continue;
        }
}
