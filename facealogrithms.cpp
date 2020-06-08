#include "facealogrithms.h"
#include "helper.h"
#include "faciallandmarkdetector.h"


FaceAlogrithms::~FaceAlogrithms(){

}
FaceAlogrithms::FaceAlogrithms(FacialLandmarkDetector &detector)

{

    this->detector = &detector;

}

void FaceAlogrithms::update(){

    faceLandMarksPoints = detector->getFacialLandMarks();
    if(faceLandMarksPoints.size() <= 0 || faceLandMarksPoints[0].x < 0 || faceLandMarksPoints[0].y < 0){
        qDebug() << "faceAlogrithms fail update(): fandlandmarks size is " << faceLandMarksPoints.size();
    }else{
        qDebug() << "faceAlogrithms successful update(): fandlandmarks size is " << faceLandMarksPoints.size();
    }

}
void FaceAlogrithms::applyOperations(cv::Mat frame){

     cv::putText(frame,"face detector",cv::Point(100,150),1,2,cv::Scalar(255,255,0));


}





