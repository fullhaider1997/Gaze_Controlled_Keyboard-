#include "facealogrithms.h"
#include "helper.h"
#include "faciallandmarkdetector.h"


FaceAlogrithms::~FaceAlogrithms(){

}
FaceAlogrithms::FaceAlogrithms()
{



}



void FaceAlogrithms::update(std::vector<cv::Point> landmarkspoints){

    faceLandMarksPoints = landmarkspoints;
    if(faceLandMarksPoints.size() <= 0 ){
        qDebug() << "faceAlogrithms fail update(): fandlandmarks size is " << faceLandMarksPoints.size();
        faceLandMarksPoints = std::vector<cv::Point>(68);
        return;
    }else{
        qDebug() << "faceAlogrithms successful update(): fandlandmarks size is " << faceLandMarksPoints.size();

    }

}
cv::Mat FaceAlogrithms::applyOperations(cv::Mat frame){



 return frame;
}





