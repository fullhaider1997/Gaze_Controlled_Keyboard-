#include "drawfacialfeature.h"



void DrawFacialFeature::Draw(std::vector<cv::Point> Points,cv::Mat face){

    for(auto i: Points){
       cv::circle(face,i,1,cv::Scalar(0,0,255),2,150);
    }




}
