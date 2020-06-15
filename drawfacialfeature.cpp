#include "drawfacialfeature.h"


void DrawFacial::drawRightEye(cv::Mat face,std::vector<cv::Point> rightEyeBoundary){

      cv::polylines(face,rightEyeBoundary,0,cv::Scalar(0,0,255),1);
      cv::imshow("copy",face);

}

void DrawFacial::updateDrawRightEye(std::vector<cv::Point> landmarkspoints){

        rightEyeBoundary = landmarkspoints;
}


cv::Mat DrawFacial::DrawEyeCoordinateOnFace(cv::Mat frame){
    //Right eye//

// vertical x line
  //cv::line(frame,  cv::Point(eye.rightEyeLines.p1_x, eye.rightEyeLines.p1_y),
    //             cv::Point(eye.rightEyeLines.p2_x, eye.rightEyeLines. p2_y),
      //           cv::Scalar(255, 255, 0), 1);

// horizontal y line
//cv::line(frame, cv::Point(faceLandMarksPoints[36].x,faceLandMarksPoints[36].y),
  //              cv::Point(faceLandMarksPoints[39].x,faceLandMarksPoints[39].y),
    //            cv::Scalar(255, 255, 0), 1);

    // Left eye //

 // vertical x line
 // cv::line(frame, cv::Point(faceLandMarksPoints[42].x,faceLandMarksPoints[42].y),
    //            cv::Point(faceLandMarksPoints[45].x,faceLandMarksPoints[45].y),
      //          cv::Scalar(255, 255, 0), 1);
// horizontal y line
 //cv::line(frame, cv::Point(eye.leftEyeLines.p1_x, eye.leftEyeLines.p1_y),
   //             cv::Point(eye.leftEyeLines.p2_x, eye.leftEyeLines.p2_y),
     //           cv::Scalar(255, 255, 0), 1);


}


cv::Mat DrawFacial::applyOperations(cv::Mat face){

    extern std::vector<cv::Point> rightEyeboundaryGlobal;
    extern std::vector<cv::Point> leftEyeboundaryGlobal;
    extern cv::Rect fourRightEyeCornerGlobal;
    extern cv::Rect fourLeftEyeCornerGlobal;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::Mat rightEye;
    cv::Mat leftEye;
    cv::Mat rightEyeT;
    cv::Mat leftEyeT;
    cv::Mat segment;
    cv::Mat copy;
    face.copyTo(copy);
    cv::cvtColor(copy,copy,cv::COLOR_RGB2GRAY);
    rightEye = copy(fourLeftEyeCornerGlobal);
    leftEye = copy(fourRightEyeCornerGlobal);
    cv::Mat redMask(480, 640, CV_8UC3, cv::Scalar(0,0,255));
    cv::Mat greenMask(480, 640, CV_8UC3, cv::Scalar(255,0,0));




    cv::threshold(rightEye,rightEyeT,70,255,cv::THRESH_BINARY);
    cv::threshold(leftEye,leftEyeT,70,255,cv::THRESH_BINARY);

    cv::Mat halfRight = leftEyeT(cv::Rect(leftEyeT.cols/2, 0, leftEyeT.cols/2, leftEyeT.rows));
    cv::Mat halfLeft = leftEyeT(cv::Rect(0, 0, leftEyeT.cols/2, leftEyeT.rows));
    int leftEyeRightHalf = cv::countNonZero(halfRight)+1;
    int leftEyeLeftHalf = cv::countNonZero(halfLeft)+1;

    double ratio = leftEyeLeftHalf / leftEyeRightHalf;
    cv::putText(face, std::to_string(ratio), cv::Point(100,100),
        cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(200,200,250), 1, CV_AA);
    if(ratio < 3){
        cv::imshow("red",redMask);
        cv::destroyWindow("green");
    }else if(ratio > 10){
        cv::imshow("green",greenMask);
        cv::destroyWindow("red");

    }

    if(rightEyeboundaryGlobal.size() > 0){
        qDebug()<< "I recieved the eyeboundary and size is " << rightEyeboundaryGlobal.size();
        for( auto a: rightEyeboundaryGlobal){
             qDebug() << a.x << " ," << a.y;
        }





     cv::Mat mask =  cv::Mat::zeros(copy.size(), CV_8UC1);
     cv::fillConvexPoly(mask,rightEyeboundaryGlobal,cv::Scalar(255,255,255));

     cv::bitwise_and(copy,copy,segment,mask);

    // cv::imshow("segement",segment);
    // cv::imshow("right",rightEye);
   //  cv::imshow("left",leftEye);
     //cv::imshow("half right",halfRight);
   //  cv::imshow("left half",halfLeft);







    }else{
        std::cout << "I didn't recieved the eyeboundary !";
    }
   return face;
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
