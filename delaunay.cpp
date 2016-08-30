#include "delaunay.h"

void Delaunay::drawDelaunay(const cv::Mat& src, cv::Mat& dst, int tri_idx, cv::Scalar delaunayColor) const{
    bool draw;
    dst=src.clone();
    if(dst.type()==CV_8UC1){
        cv::cvtColor(dst,dst,CV_GRAY2RGB);
    }
    int ntris=triangulation.size();
    for(size_t i = 0; i < ntris; ++i)
    {
        triangle tri = triangulation[i];

        draw=true;
        cv::Point2f pts[3];
        pts[0]=vertexes[tri.vtx_idx[0]].pt;
        pts[1]=vertexes[tri.vtx_idx[1]].pt;
        pts[2]=vertexes[tri.vtx_idx[2]].pt;

        for(int i=0;i<3;i++){
            if((pts[i].x>src.cols-1)||(pts[i].y>src.rows-1)||(pts[i].x<0)||(pts[i].y<0))
                draw=false;
        }

        if (draw){
            if(tri_idx==i){
                cv::line(dst, pts[0], pts[1], cv::Scalar(0, 0, 255), 2);
                cv::line(dst, pts[1], pts[2], cv::Scalar(0, 0, 255), 2);
                cv::line(dst, pts[2], pts[0], cv::Scalar(0, 0, 255), 2);

            }else{
                cv::line(dst, pts[0], pts[1], delaunayColor, 1);
                cv::line(dst, pts[1], pts[2], delaunayColor, 1);
                cv::line(dst, pts[2], pts[0], delaunayColor, 1);
            }
        }
    }
//    showImage(dst,title,scale);
}


bool Delaunay::iswithinTri (const cv::Point2f &pt, int tri_id) const
{
    triangle tri=triangulation[tri_id];
    std::vector<cv::Point2f> contour;
    convert2Contour(tri,contour);
    return cv::pointPolygonTest(contour,pt,false)>0;
}

int Delaunay::findTri(const cv::Point2f &pt)
{
    for(size_t i=0;i<triangulation.size();++i){
        if(iswithinTri(pt,i))
            return i;
    }
    return -1;
}

void Delaunay::getTrilist(std::vector<std::vector<int> > &list)
{
    list.clear();
    if(triangulation.size()==0){
        //not generate the triangulation yet
        exitwithErrors("Please generate the triangulation before retrieve the triangulation list!\n");
    }else{
        int ntris=this->getNumberOfTri();
        for(int i=0;i<ntris;++i){
            std::vector<int> l;
            l.push_back(triangulation[i].vtx_idx[0]);
            l.push_back(triangulation[i].vtx_idx[1]);
            l.push_back(triangulation[i].vtx_idx[2]);
            list.push_back(l);
        }
    }
}

////double Delaunay::interpolateAttr (const cv::Point2f &pt, int tri_id) const{
////    MatrixXd A(3,3);
////    Vector3d yv_mapped(-1,-1,-1);
////    VectorXd coeff;
////    triangle tri=triangulation[tri_id];

////    //create matrix
////    for (size_t i=0;i<3;++i){
////        A(i,0)=tri.vtx[i].pt.x;
////        A(i,1)=tri.vtx[i].pt.y;
////        A(i,2)=tri.vtx[i].attr;
////    }

////    //solve for linear least squares fit
////    ColPivHouseholderQR<MatrixXd> qr_decomp(A);
////    auto rank_A=qr_decomp.rank();
////    MatrixXd B(A.rows(),yv_mapped.cols()+A.cols());
////    B<<A,yv_mapped;
////    qr_decomp.compute(B);
////    auto rank_B=qr_decomp.rank();
////    double result;
////    if(rank_A==rank_B && rank_A==A.cols()){
////            coeff=A.householderQr().solve(yv_mapped);
////            result=(-1.0-coeff[0]*pt.x-coeff[1]*pt.y)/coeff[2];
////    }
////    else if(A(0,2)==A(1,2) && A(1,2)==A(2,2))
////        result=A(0,2);
////    else
////        exitwithErrors("Error occured while predicting the disparity!");

////    return result;
////}

////void Delaunay::interpolateSurface(double *&pData,int flag)
////{
////    //initialize the Mat with no_data
////    GUInt32 nPoints=vertexes.size();
////    double pixResolution=1.0;
////    GUInt32 nXSize=(double)this->range.width/pixResolution;
////    GUInt32 nYSize=(double)this->range.height/pixResolution;

////    GDALAllRegister();

////    //moving average interpolation
////    GDALGridMovingAverageOptions *poOptions=new GDALGridMovingAverageOptions();

////    poOptions->dfNoDataValue=-999.0;
////    poOptions->dfRadius1=50;
////    poOptions->dfRadius2=50;
////    poOptions->nMinPoints=6;

////    pData=new double[nXSize*nYSize];

////    double *padfX=new double[nPoints];
////    double *padfY=new double[nPoints];
////    double *padfZ=new double[nPoints];

////    for(int i=0;i!=nPoints;++i){
////        padfX[i]=(double)vertexes[i].pt.x;
////        padfY[i]=(double)vertexes[i].pt.y;
////        padfZ[i]=(double)vertexes[i].attr;
////    }

////    //data is organized in row major order
////    GDALGridCreate(GGA_MovingAverage,poOptions,nPoints,padfX,padfY,padfZ,
////                   range.x,range.x+range.width-1,range.y,range.y+range.height-1,
////                   nXSize,nYSize,GDT_Float64,pData,NULL,NULL);

////    //write interpolated result
////    GDALDriver *pDriver=NULL;
////    pDriver=GetGDALDriverManager()->GetDriverByName("Gtiff");
////    std::string fullfilename=directory+"temp.tif";
////    GDALDataset *poDataset=pDriver->Create(fullfilename.c_str(),nXSize,nYSize,1,GDT_Float64,NULL);

////    //set six parameters
////    double adfGeoTransform[6]={range.x,pixResolution,0,range.y,0,-pixResolution};
////    poDataset->SetGeoTransform(adfGeoTransform);

////    //output to the tiff file
////    poDataset->RasterIO(GF_Write,0,0,nXSize,nYSize,pData,nXSize,nYSize,GDT_Float64,1,0,0,0,0);

////    if(flag){
////        for(int i=0;i!=nPoints;++i){
////            int pos=NULL;
////            sub2ind(img1.size(),(int)padfX[i],(int)padfY[i],pos);
////            pData[pos]=-999.0;
////        }
////    }

////    //release resource taken up
////    delete poOptions;
////    delete []padfX;
////    delete []padfY;
////    delete []padfZ;
////    GDALClose(poDataset);
////    poDataset=NULL;
////}


double Delaunay::calTriArea(const cv::Point2f pt1, const cv::Point2f pt2, const cv::Point2f pt3)
{
//    vector< vector<Point2f>> contour;
    std::vector<cv::Point2f> contour;
    contour.push_back(pt1);
    contour.push_back(pt2);
    contour.push_back(pt3);
//    contour.push_back(tri);
    return contourArea(contour);
}


double Delaunay::calTriArea(const int vtx_idx[])
{
    cv::Point2f p1,p2,p3;
    p1=vertexes[vtx_idx[0]].pt;
    p2=vertexes[vtx_idx[1]].pt;
    p3=vertexes[vtx_idx[2]].pt;
    return calTriArea(p1,p2,p3);
}


void Delaunay::convert2Contour(const Delaunay::triangle &tri, std::vector<cv::Point2f> &contour) const
{
    contour.clear();
    contour.push_back(vertexes[tri.vtx_idx[0]].pt);
    contour.push_back(vertexes[tri.vtx_idx[1]].pt);
    contour.push_back(vertexes[tri.vtx_idx[2]].pt);
}


void Delaunay::generateDelaunay(const std::vector<cv::Point2f> &pts,const std::vector<double>& attribute){
    if(attribute.size()!=0)
        assert(pts.size()==attribute.size());
    //store vertexes
    vertexes.clear();
    for(int i=0;i!=pts.size();++i){
        vertex vt;
        vt.vtxID=i;
        if(attribute.size()!=0)
            vt.attr=attribute[i];
        vt.pt=pts[i];
        vertexes.push_back(vt);
    }
    //generate delaunay triangulation
    this->insert(pts);

    getTriangulation(attribute);
    std::sort(triangulation.begin(),triangulation.end(),compTri);//descend
}


void Delaunay::generateDelaunay(const std::vector<cv::KeyPoint> &kpts,const std::vector<double>& attribute){
    std::vector<cv::Point2f> pts;
    KeyPoint2Point2f(kpts,pts);
    generateDelaunay(pts,attribute);
}


void Delaunay::generateDelaunay(const std::vector<Match> &matches, int mode){
    std::vector<double> attribute;
    if(mode!=0)
        for(int i=0;i<matches.size();++i){
            double attri;
            if(mode==1)
                attri=matches[i].p1.x-matches[i].p2.x;
            else if(mode==2)
                attri=matches[i].p1.y-matches[i].p2.y;
            else
                exitwithErrors("Unknown delaunay generation type!");
            attribute.push_back(attri);
        }
    std::vector<cv::Point2f> l,r;
    getPtsFromMatches(matches,l,r);
    generateDelaunay(l,attribute);
}

void Delaunay::getTriangulation(const std::vector<double> &attribute){
    std::vector<double> attri_backup=attribute;

    if(attribute.size()!=0)
        assert(attribute.size()==(this->vtx.size()-4));
//        assert(attribute.size()==(this->vertexes.size()));
    else
        attri_backup=std::vector<double>(this->vtx.size()-4,0);

            triangulation.clear();
            int total = (int)(this->qedges.size()*4);
            std::vector<bool> edgemask(total, false);
//            int idx=0;

            for(int i = 4; i < total; i += 2 ){
                if( edgemask[i] )
                    continue;
                cv::Point2f pt[3];
                int pt_id[3];

                int edge = i;

                pt_id[0]=edgeOrg(edge, &pt[0]);
                if (pt_id[0]<4) continue;
                edgeOrg(edge, &pt[0]);
                edgemask[edge] = true;
                edge = getEdge(edge, NEXT_AROUND_LEFT);

                pt_id[1]=edgeOrg(edge, &pt[1]);
                if(pt_id[1]<4) continue;
                edgeOrg(edge, &pt[1]);
                edgemask[edge] = true;
                edge = getEdge(edge, NEXT_AROUND_LEFT);

                pt_id[2]=edgeOrg(edge, &pt[2]);
                if(pt_id[2]<4) continue;
                edgeOrg(edge, &pt[2]);
                edgemask[edge] = true;

                triangle tri;
//                tri.id=idx++;
                for(int k=0;k<3;++k){
//                    vertex v;
//                    v.vtxID=pt_id[k]-4;/*???*/
//                    v.pt=pt[k];
//                    v.attr=attri_backup[pt_id[k]-4];
                    tri.vtx_idx[k]=pt_id[k]-4;/*???*/
                }
                tri.area=calTriArea(tri.vtx_idx);/*???*/

                triangulation.push_back(tri);
            }
}

void Delaunay::resetTriPoints(const std::vector<cv::Point2f>& pts){
    assert(vertexes.size()==pts.size());
//    std::vector<vertex>::iterator iter=vertexes.begin();
    for(int i=0; i<pts.size(); ++i)
        vertexes[i].pt=pts[i];
}


void locateCandidate(const std::vector<cv::Point2f>& tri1, const cv::Point2f pt1,
                     const std::vector<cv::Point2f>& tri2, cv::Point2f& pt2)
{

}


void Delaunay::getTriVtxes(const std::vector<cv::Point2f>& pts,
                           const std::vector<int>& vtx_ids , std::vector<cv::Point2f>& vtxes)
{
    size_t npts=pts.size();
    assert(npts>0);
    vtxes.clear();
    for(int i=0; i<3; ++i)
        if(vtx_ids[i]>=0 && vtx_ids[i]<npts)
            vtxes.push_back(pts[vtx_ids[i]]);
        else
            exitwithErrors("index of vertex is beyond the size of pts!\n");
}























