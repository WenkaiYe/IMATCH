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
    Delaunay tin(img1);
    std::vector<cv::Point2f> pts1,pts2;
    getPtsFromMatches(seeds,pts1,pts2);
    tin.generateDelaunay(pts1);
    std::vector<int> f2t1,f2t2;
    std::vector<std::vector<int> > t2f1,t2f2;
    genFeature2TriangleTable(lpts,tin,f2t1,t2f1);
    std::vector<std::vector<int> > list;
    tin.getTrilist(list);
    //    tin1.drawDelaunay(img1,image_scale);
    showFeatureInsideTriangles(img1, lpts, tin, t2f1);
    for(int i=0; i<t2f1.size(); ++i){
        //get features inside the triangle
        std::vector<int> pts_idx=t2f1[i];
        //calculate transformation parameters
        std::vector<cv::Point2f> tri1, tri2;
        std::vector<double> paras;
        Delaunay::getTriVtxes(pts1, list[i], tri1);
        Delaunay::getTriVtxes(pts2, list[i], tri2);
        calAffineParas(tri1, tri2, paras);
        for(int j=0; j<pts_idx.size(); ++j){
            cv::Point2f src=lpts[pts_idx[j]];
            cv::Point2f dst;
            //estimate potential location
            affineTransform(src, paras, dst);
            dst.x=floor((double)dst.x);
            dst.y=floor((double)dst.y);
            //construct search contour
//            std::vector<cv::Point2f> contour;
            cv::Rect contour;
            constructContour(dst, search_radius, contour);
            //find right-side features within the contour
            std::vector<cv::Point2f> candidates;
            for(int k=0; k<rpts.size(); ++k){
                cv::Point2f pt=rpts[k];
                if(contour.contains(pt)){
                    //calculate correlation coefficient

                    //store the results
                    candidates.push_back(pt);
                }
            }
            showCandidates(img1,img2,src,dst,contour,candidates);
        }
    }
}

void genFeature2TriangleTable(const std::vector<cv::Point2f> &features, const Delaunay& tris,
                              std::vector<int>& f2t, std::vector<std::vector<int> >& t2f)
{
    std::vector<cv::Point2f> f=features;
    int ntris=tris.getNumberOfTri();
    assert(ntris>0);
    f2t.clear();f2t=std::vector<int>(f.size(),-1);
    t2f.clear();
    std::vector<int> idx_backup;
    for(int i=0;i<f.size();++i)
        idx_backup.push_back(i);
    for(int i=0;i<ntris;++i){
        std::vector<int> pts;
//        std::vector<cv::Point2f>::iterator iter=f.begin();
        std::vector<int>::iterator iter=idx_backup.begin();
        for(;iter!=idx_backup.end();){
            if(tris.iswithinTri(features[*iter],i)){
                //update f2t & t2f
                f2t[*iter]=i;
                pts.push_back(*iter);
                //delete this point from the point set
//                f.erase(iter);
                idx_backup.erase(iter);
            }else{
                ++iter;
//                ++iter2;
            }
        }
        t2f.push_back(pts);
    }
}


void showFeatureInsideTriangles(const cv::Mat& img, const std::vector<cv::Point2f> &features,
                                const Delaunay &tris, const std::vector<std::vector<int> >& t2f)
{
    int nfeatures=features.size();
    int ntris=tris.getNumberOfTri();
    assert(ntris>0);
    assert(nfeatures>0);
    std::vector<cv::KeyPoint> kpts;
    Point2f2KeyPoint(features,kpts);
    for(int i=0;i<ntris;++i){
        //for each triangle
        //highlight the edges of a certain triangle
        cv::Mat disp;
        cv::drawKeypoints(img, kpts, disp);
        tris.drawDelaunay(disp, disp, i);
//        showImage(disp, "Delaunay" ,image_scale);
        std::vector<int> pts=t2f[i];
        //highlight features inside the highlighted triangle
        for(int j=0; j<pts.size(); ++j){
            cv::circle(disp, cv::Point(features[pts[j]].x, features[pts[j]].y), 2, cv::Scalar(255, 0, 0), 2);
        }
        showImage(disp, DEFAULT_WINDOW_NAME, image_scale);
    }
}

void constructContour(const cv::Point2f& center, const int searchRadius, std::vector<cv::Point2f>& contour){
    cv::Point2f ul,ur,ll,lr;
    ul=cv::Point2f(center.x-searchRadius, center.y-searchRadius);
    ur=cv::Point2f(center.x+searchRadius, center.y-searchRadius);
    ll=cv::Point2f(center.x-searchRadius, center.y+searchRadius);
    lr=cv::Point2f(center.x+searchRadius, center.y+searchRadius);
    contour.clear();
    contour.push_back(ul);
    contour.push_back(ur);
    contour.push_back(ll);
    contour.push_back(lr);
}

void constructContour(const cv::Point2f& center, const int searchRadius, cv::Rect& contour){
    cv::Point2f ul,ur,ll,lr;
    ul=cv::Point2f(center.x-searchRadius, center.y-searchRadius);
//    ur=cv::Point2f(center.x+searchRadius, center.y-searchRadius);
//    ll=cv::Point2f(center.x-searchRadius, center.y+searchRadius);
//    lr=cv::Point2f(center.x+searchRadius, center.y+searchRadius);
//    contour.clear();
    contour=cv::Rect(ul.x, ul.y, 2*searchRadius, 2*searchRadius);
}
