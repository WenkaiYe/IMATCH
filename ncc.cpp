#include "ncc.h"

void NCCBasedMatch(const cv::Mat &tpl, const cv::Mat &src, cv::Point2f &pt1, cv::Point2f &pt2,
              double &max_cc, int& state,bool interpolation){
    //make sure that both the size of tmp and src are even
    assert(tpl.rows%2==0);
    assert(tpl.cols%2==0);
    assert(src.rows%2==0);
    assert(src.cols%2==0);
    //create the correlation coefficient matrix
    int result_cols=src.cols-tpl.cols+1;
    int result_rows=src.rows-tpl.rows+1;
    cv::Mat ccMat(result_rows,result_cols,CV_64FC1);
    //Do the Matching and Normalize
    matchTemplate(src,tpl,ccMat,cv::TM_CCOEFF_NORMED);
    //Localizing the best match with minMaxLoc
    double minVal;
    cv::Point minLoc,maxLoc;
    pt1.x=tpl.cols/2.0;
    pt1.y=tpl.rows/2.0;
    minMaxLoc(ccMat,&minVal,&max_cc,&minLoc,&maxLoc,cv::Mat());
    //initial location, and it will be covered if interpolation is performed
    pt2.x=(double)maxLoc.x+tpl.cols/2.0;
    pt2.y=(double)maxLoc.y+tpl.rows/2.0;
    //refine the location by using interpolation
    state=false;
    double max_shift=0.5;
    if(interpolation){
        if(isInRange(ccMat.size(),cv::Rect(maxLoc.x-1,maxLoc.y-1,3,3))){
            cv::Mat patch=ccMat(cv::Rect(maxLoc.x-1,maxLoc.y-1,3,3));
            double x,y;
            interpolate(patch,x,y);
            if(fabs(x-1.5)<=max_shift && fabs(y-1.5)<=max_shift){
                state=true;
                pt2.x+=x-1.5;
                pt2.y+=y-1.5;
            }
        }
    }
}

void interpolate(const cv::Mat patch, double& x, double& y){
    std::vector<cv::Point2d> tmp;
    cv::Point2d p1,p2,p3;
    //fit a 2nd polynomial curve along the x direction
    p1.x=0.5;p2.x=1.5;p3.x=2.5;
    //issue:max value yet ???
    double t[3];
    getMaxElements33(patch,t);
    p1.y=t[0];tmp.push_back(p1);
    p2.y=t[1];tmp.push_back(p2);
    p3.y=t[2];tmp.push_back(p3);
    x=fit2ndPolynomial(tmp);

    //fit a 2nd polynomial curve along the y direction
    tmp.clear();
    getMaxElements33(patch,t,1);
    p1.y=t[0];tmp.push_back(p1);
    p2.y=t[1];tmp.push_back(p2);
    p3.y=t[2];tmp.push_back(p3);
    y=fit2ndPolynomial(tmp);
}

double fit2ndPolynomial(const std::vector<cv::Point2d> pts){
    assert(pts.size()==3);
    cv::Point2d p1,p2,p3;
    p1=pts[0];p2=pts[1];p3=pts[2];
    double a,b,l1,l2,l3,l4;
    l1=(p1.x-p2.x)*(p1.x+p2.x)*(p2.y-p3.y);
    l2=(p1.x-p2.x)*(p1.x+p2.x)*(p2.x-p3.x);
    l3=(p2.x-p3.x)*(p2.x+p3.x)*(p1.y-p2.y);
    l4=(p2.x-p3.x)*(p2.x+p3.x)*(p1.x-p2.x);
    b=(l3-l1)/(l4-l2);
    a=((p1.y-p2.y)-b*(p1.x-p2.x))/(pow(p1.x,2.0)-pow(p2.x,2.0));
    return -b/(2.0*a);
}

bool isInRange(const cv::Size size,const cv::Rect roi){
    bool con1=false,con2=false;
    if(roi.x>=0 && roi.y>=0)
        con1=true;
    if((roi.x+roi.width)<=size.width && (roi.y+roi.height)<=size.height)
        con2=true;
    return con1 && con2;
}

void getMaxElements33(const cv::Mat &src, double dst[], int flag)
{
    assert(src.size().width==3 && src.size().height==3);
    for(int i=0;i<3;++i)
        if(flag==0){
            //get max element of each column
            double a=src.at<float>(0,i);
            double b=src.at<float>(1,i);
            double c=src.at<float>(2,i);
            a=a>b?a:b;
            a=a>c?a:c;
            dst[i]=a;
        }else{
            //get max element of each row
            double a=src.at<float>(i,0);
            double b=src.at<float>(i,1);
            double c=src.at<float>(i,2);
            a=a>b?a:b;
            a=a>c?a:c;
            dst[i]=a;
        }
}
