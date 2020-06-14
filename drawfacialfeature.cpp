#include "drawfacialfeature.h"


void DrawFacial::drawRightEye(cv::Mat face,std::vector<cv::Point> rightEyeBoundary){


      cv::polylines(face,rightEyeBoundary,0,cv::Scalar(0,0,255),1);
      cv::imshow("copy",face);



}

void DrawFacial::updateDrawRightEye(std::vector<cv::Point> landmarkspoints){

        rightEyeBoundary = landmarkspoints;
}

void DrawFacial::applyOperations(cv::Mat face){

    extern std::vector<cv::Point> rightEyeboundaryGlobal;
    extern cv::Rect fourRightEyeCornerGlobal;
    extern cv::Rect fourLeftEyeCornerGlobal;
    cv::Mat rightEye;
    cv::Mat leftEye;
    cv::Mat segment;

    cv::cvtColor(face,face,cv::COLOR_RGB2GRAY);
    rightEye = face(fourLeftEyeCornerGlobal);
    leftEye = face(fourRightEyeCornerGlobal);


    cv::threshold(rightEye,rightEye,70,255,cv::THRESH_BINARY);
    cv::threshold(leftEye,leftEye,70,255,cv::THRESH_BINARY);




    if(rightEyeboundaryGlobal.size() > 0){
        qDebug()<< "I recieved the eyeboundary and size is " << rightEyeboundaryGlobal.size();
        for( auto a: rightEyeboundaryGlobal){
             qDebug() << a.x << " ," << a.y;
        }

      cv::polylines(face,rightEyeboundaryGlobal,0,cv::Scalar(0,0,255),1);

     cv::Mat mask =  cv::Mat::zeros(face.size(), CV_8UC1);
     cv::fillConvexPoly(mask,rightEyeboundaryGlobal,cv::Scalar(255,255,255));

     cv::bitwise_and(face,face,segment,mask);

     cv::imshow("mask",face);
     cv::imshow("segement",segment);
     cv::imshow("right",rightEye);
     cv::imshow("left",leftEye);


    }else{
        std::cout << "I didn't recieved the eyeboundary !";
    }

}





void DrawFacial::update(std::vector<cv::Point> landmarkspoints){


    faceLandMarksPoints = landmarkspoints;

    if(faceLandMarksPoints.size() <= 0){
        qDebug() << "draw Algorithm fail update(): fandlandmarks size is " << faceLandMarksPoints.size();
        faceLandMarksPoints = std::vector<cv::Point>(68);
        return;
    }else{
        qDebug() << "draw Alogrithm successful update(): fandlandmarks size is " << faceLandMarksPoints.size();

    }
}
