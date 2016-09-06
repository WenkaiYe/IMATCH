#include "feature.h"

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

bool extractFeatures(const cv::Mat& img, std::vector<cv::KeyPoint>& kpts, FeatureType ftype){
    cv::Ptr<cv::FeatureDetector> detector;
    kpts.clear();
    //set detector
    switch(ftype)
    {
    case GoodFeature:
    {//Good feature to track
        //initialize the default parameters
        int maxCorners=1e8,blockSize=5;
        double qualityLevel=0.001,minDistance=5,k=0.04;
        bool useHarrisDEtector=false;
        //set parameters
        readConfigFile(FEATURE_CONFIG,"maxCorners",maxCorners);
        readConfigFile(FEATURE_CONFIG,"blockSize",blockSize);
        readConfigFile(FEATURE_CONFIG,"qualityLevel",qualityLevel);
        readConfigFile(FEATURE_CONFIG,"minDistance",minDistance);
        readConfigFile(FEATURE_CONFIG,"k",k);
        readConfigFile(FEATURE_CONFIG,"useHarrisDetector",useHarrisDEtector);
        //initialize feature detector
        detector=new cv::GoodFeaturesToTrackDetector(maxCorners,qualityLevel,minDistance,blockSize,useHarrisDEtector,k);
        //detect
        detector->detect(img,kpts);
        break;
    }
    case FastFeature:
    {//Fast feature detector
        int threshold=10;
        bool nonmaxSuppression=true;
        //set parameters
        readConfigFile(FEATURE_CONFIG,"threshold", threshold);
        readConfigFile(FEATURE_CONFIG,"nonmaxSuppression", nonmaxSuppression);
        //initialize feature detector
        detector=new cv::FastFeatureDetector(threshold, nonmaxSuppression);
        //detect
        detector->detect(img,kpts);
        break;
    }
    case SIFT:
    {//Sift feature
        //            cout<<"Feature Extraction:\tFast feature to track..."<<endl<<endl;
        //            /*  FastFeatureDetector(int threshold=10,bool nonmaxSuppression=true)*/
        //            //initialize the parameters
        //            int threshold=1;
        //            bool nonmaxSuppression=true;
        //            //set parameters
        //            readConfigFile(filename,"threshold",threshold);
        //            readConfigFile(filename,"nonmaxSuppression",nonmaxSuppression);
        //            //initialize feature detector
        //            detector=new FastFeatureDetector(threshold, nonmaxSuppression);
        //            //detect
        //            if(ImageID=="left")
        //                detector->detect(img1,keypoints);
        //            else if(ImageID=="right")
        //                detector->detect(img2,keypoints);
        //            else{
        //                detector->detect(img1,keypoints);
        //                cerr<<"Unknown option for the image_id, the left image was detected instead!"<<endl;
        //            }
        break;
    }
    case ORB:
    {
        int nfeatures=1e8, nlevels=8, edgeThreshold=31;
        int firstLevel=0, WTA_K=2, /*scoreType=ORB::HARRIS_SCORE, */patchSize=31;
        float scaleFactor=1.2f;
        //set parameters
        readConfigFile(FEATURE_CONFIG,"nfeatures", nfeatures);
        readConfigFile(FEATURE_CONFIG,"nlevels", nlevels);
        readConfigFile(FEATURE_CONFIG,"edgeThreshold", edgeThreshold);
        readConfigFile(FEATURE_CONFIG,"firstLevel", firstLevel);
        readConfigFile(FEATURE_CONFIG,"WTA_K", WTA_K);
        readConfigFile(FEATURE_CONFIG,"patchSize", patchSize);
        readConfigFile(FEATURE_CONFIG,"scaleFactor", scaleFactor);
        //initialize feature detector
        cv::ORB orb(nfeatures, scaleFactor, nlevels,
                    edgeThreshold, firstLevel, WTA_K, cv::ORB::HARRIS_SCORE, patchSize);
        //detect
        orb.detect(img,kpts);
        break;
    }
    case BRISK:
    {
        int thresh=30, octaves=3;
        float patternScale=1.0f;
        //set parameters
        readConfigFile(FEATURE_CONFIG,"thresh", thresh);
        readConfigFile(FEATURE_CONFIG,"octaves", octaves);
        readConfigFile(FEATURE_CONFIG,"patternScale", patternScale);
        //initialize feature detector
        cv::BRISK bsk(thresh, octaves, patternScale);
        //detect
        bsk.detect(img,kpts);
        break;
    }
    case MSER:
    {
        int _delta=5, _min_area=60, _max_area=14400, _max_evolution=200, _edge_blur_size=5;
        double _max_variation=0.25, _min_diversity=.2, _area_threshold=1.01, _min_margin=0.003;
        //set parameters
        readConfigFile(FEATURE_CONFIG,"_delta", _delta);
        readConfigFile(FEATURE_CONFIG,"_min_area", _min_area);
        readConfigFile(FEATURE_CONFIG,"_max_area", _max_area);
        readConfigFile(FEATURE_CONFIG,"_max_evolution", _max_evolution);
        readConfigFile(FEATURE_CONFIG,"_edge_blur_size", _edge_blur_size);
        readConfigFile(FEATURE_CONFIG,"_max_variation", _max_variation);
        readConfigFile(FEATURE_CONFIG,"_min_diversity", _min_diversity);
        readConfigFile(FEATURE_CONFIG,"_area_threshold", _area_threshold);
        readConfigFile(FEATURE_CONFIG,"_min_margin", _min_margin);
        //initialize feature detector
        cv::MSER ms(_delta, _min_area, _max_area, _max_variation, _min_diversity,
                    _max_evolution, _area_threshold, _min_margin, _edge_blur_size);

        //detect
        ms.detect(img,kpts);
        break;
    }
    default:
        exitwithErrors("unknown type for feature extraction!");
    }
}
