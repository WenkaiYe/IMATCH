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

/*????????????????????????? need further development ???????????????????????????*/
bool extractFeatures(const cv::Mat& img, std::vector<cv::KeyPoint>& kpts){
    cv::Ptr<cv::FeatureDetector> detector;
//    vector<KeyPoint> keypoints;
//    string ImageID="left",outPath=directory+"keypoints.txt";
//    bool display=false;
//    bool saveKpts=false;
//    //read common key variables
//    readConfigFile(filename,"ImageID",ImageID);
//    readConfigFile(filename,"DisplayKeypoints",display);
//    readConfigFile(filename,"SaveKeypoints",saveKpts);
//    readConfigFile(filename,"SaveKeypointsPath",outPath);
//    lowerString(ImageID);
//    //set detector
//    switch(type[0])
//    {
//        case GoodFeature:
//        {//Good feature to track
//            cout<<"Feature Extraction:\tGood feature to track..."<<endl<<endl;
//            /*GoodFeaturesToTrackDetector( int maxCorners, double qualityLevel,
//            double minDistance, int blockSize=3,bool useHarrisDetector=false, double k=0.04 );*/
//            //initialize the parameters
            int maxCorners=1e8,blockSize=10;
            double qualityLevel=0.01,minDistance=15,k=0.04;
            bool useHarrisDEtector=false;
//            //set parameters
//            readConfigFile(filename,"maxCorners",maxCorners);
//            readConfigFile(filename,"blockSize",blockSize);
//            readConfigFile(filename,"qualityLevel",qualityLevel);
//            readConfigFile(filename,"minDistance",minDistance);
//            readConfigFile(filename,"k",k);
//            readConfigFile(filename,"useHarrisDetector",useHarrisDEtector);
//            //initialize feature detector
            detector=new cv::GoodFeaturesToTrackDetector(maxCorners,qualityLevel,minDistance,blockSize,useHarrisDEtector,k);
//            //detect
//            if(ImageID=="left")
                detector->detect(img,kpts);
//            else if(ImageID=="right")
//                detector->detect(img2,keypoints);
//            else{
//                detector->detect(img1,keypoints);
//                cerr<<"Unknown option for the image_id, the left image was detected instead!"<<endl;
//            }
//            break;
//        }
//        case SiftFeature:
//        {//Fast feature to track
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
//            break;
//        }
//        case GridFeature:
//        {//Grid feature to track
//            cout<<"Feature Extraction:\tGrid feature to track..."<<endl<<endl;
//            /*DenseFeatureDetector(float initFeatureScale=1.f,int featureScaleLevels=1,float featureScaleMul=0.1f,
//                   int initXyStep=6,int initImgBound=0,bool varyXyStepWithScale=true,bool varyImgBoundWithScale=false)*/
//            float initFeatureScale=1.f,featureScaleMul=0.1f;
//            int featureScaleLevels=1,initXyStep=6,initImgBound=0;
//            bool varyXyStepWithScale=true,varyImgBoundWithScale=false;
//            //set parameters
//            readConfigFile(filename,"initFeatureScale",initFeatureScale);
//            readConfigFile(filename,"featureScaleMul",featureScaleMul);
//            readConfigFile(filename,"featureScaleLevels",featureScaleLevels);
//            readConfigFile(filename,"initXyStep",initXyStep);
//            readConfigFile(filename,"initImgBound",initImgBound);
//            readConfigFile(filename,"varyXyStepWithScale",varyXyStepWithScale);
//            readConfigFile(filename,"varyImgBoundWithScale",varyImgBoundWithScale);
//            //initialize feature detector
//            detector=new DenseFeatureDetector(initFeatureScale,featureScaleLevels,featureScaleMul,
//                                              initXyStep,initImgBound,varyXyStepWithScale,varyImgBoundWithScale);
//            //detect
//            if(ImageID=="left")
//                detector->detect(img1,keypoints);
//            else if(ImageID=="right")
//                detector->detect(img2,keypoints);
//            else{
//                detector->detect(img1,keypoints);
//                cerr<<"Unknown option for the image_id, the left image was detected instead!"<<endl;
//            }
//            break;
//        }
//        default:
//            exitwithErrors("unknown type for feature extraction!");
//    }

//    if(display)
//        if(ImageID=="right")
//            showKeypoints(img2,keypoints,imagescale);
//        else
//            showKeypoints(img1,keypoints,imagescale);

//    if(saveKpts){
//        printKeypoints(outPath,keypoints);
//    }
}
