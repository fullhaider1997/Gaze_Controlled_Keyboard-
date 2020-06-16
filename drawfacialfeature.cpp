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

    struct eye leftEye,rightEye;
    extern std::vector<cv::Point> rightEyeboundaryGlobal;
    extern std::vector<cv::Point> leftEyeboundaryGlobal;
    extern cv::Rect fourRightEyeCornerGlobal;
    extern cv::Rect fourLeftEyeCornerGlobal;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::Mat rightEyeC;
    cv::Mat leftEyeC;
    cv::Mat rightEyeT;
    cv::Mat leftEyeT;
    cv::Mat segment;
    cv::Mat copy;
    face.copyTo(copy);
    cv::cvtColor(copy,copy,cv::COLOR_RGB2GRAY);
    rightEyeC = copy(fourLeftEyeCornerGlobal);
    leftEyeC = copy(fourRightEyeCornerGlobal);
    cv::Mat rightMask(480, 640, CV_8UC3, cv::Scalar(0,0,0));
    cv::Mat leftMask(480, 640, CV_8UC3, cv::Scalar(255,255,255));
    cv::Mat centerMask(480, 640, CV_8UC3, cv::Scalar(255,0,0));





    cv::threshold(rightEyeC,rightEyeT,70,255,cv::THRESH_BINARY);
    cv::threshold(leftEyeC,leftEyeT,70,255,cv::THRESH_BINARY);



    leftEye.rightHalf = leftEyeT(cv::Rect(leftEyeT.cols/2, 0, leftEyeT.cols/2, leftEyeT.rows));
    leftEye.leftHalf = leftEyeT(cv::Rect(0, 0, leftEyeT.cols/2, leftEyeT.rows));

    rightEye.rightHalf = leftEyeT(cv::Rect(leftEyeT.cols/2, 0, leftEyeT.cols/2, leftEyeT.rows));
    rightEye.leftHalf = leftEyeT(cv::Rect(0, 0, leftEyeT.cols/2, leftEyeT.rows));



    double leftEyeRightHalf = cv::countNonZero(leftEye.rightHalf);
    double leftEyeLeftHalf = cv::countNonZero(leftEye.leftHalf);

    double rightEyeRightHalf = cv::countNonZero(rightEye.rightHalf);
    double rightEyeLeftHalf = cv::countNonZero(rightEye.leftHalf);

    if(leftEyeRightHalf == 0)
        leftEyeRightHalf = -1;
    if(rightEyeRightHalf == 0)
        rightEyeRightHalf = 1;



    double ratioLeftEye = leftEyeLeftHalf / leftEyeRightHalf;
    double ratioRightEye = rightEyeLeftHalf / rightEyeRightHalf;
    double  avgRatio = (ratioLeftEye + ratioRightEye) / 2;


    cv::putText(face,
                std::to_string(avgRatio),
                cv::Point(100,100),
                cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0,0,250), 1, CV_AA);

    qDebug() <<"Ratio is " << avgRatio;



     if(avgRatio > 0.4  && 0.5 < avgRatio)
       {
          cv::imshow("center",centerMask);
          cv::destroyWindow("right");
       } else if (avgRatio > 1){
        cv::imshow("right",rightMask);
        cv::destroyWindow("center");

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
