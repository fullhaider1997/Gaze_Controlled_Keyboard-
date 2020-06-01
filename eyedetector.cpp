#include "eyedetector.h"
#include "helper.h"
EyeDetector::EyeDetector()
{

}
EyeDetector::~EyeDetector(){

}
int EyeDetector::getAverageHorizontalLengthEye(int eyeLocation){




   if(eyeLocation==1){
      return  rightEyeVerticalLength =
              Helper::GetDistance( eye.rightEyeLines.p2_x, eye.rightEyeLines.p1_x,
                                   eye.rightEyeLines.p2_y, eye.rightEyeLines.p1_y);
    }

   if(eyeLocation==2){
      return leftEyeVerticalLength =
              Helper::GetDistance( eye.leftEyeLines.p2_x, eye.leftEyeLines.p1_x,
                                   eye.leftEyeLines.p2_y, eye.leftEyeLines.p1_y);
    }


return 0;
}
void EyeDetector::CreateFourMainEyeCoordinate(){

    eye.rightEyeLines.p1_x = Helper::GenerateMidPoint(faceLandMarksPoints, 38, 37, 0);
    eye.rightEyeLines. p1_y = Helper::GenerateMidPoint(faceLandMarksPoints, 38, 37, 1);
    eye.rightEyeLines. p2_x = Helper::GenerateMidPoint(faceLandMarksPoints, 40, 41, 0);
    eye.rightEyeLines. p2_y = Helper::GenerateMidPoint(faceLandMarksPoints, 40, 41, 1);


    eye.leftEyeLines.p1_x = Helper::GenerateMidPoint(faceLandMarksPoints, 43, 44, 0);
    eye.leftEyeLines.p1_y = Helper::GenerateMidPoint(faceLandMarksPoints, 43, 44, 1);
    eye.leftEyeLines.p2_x = Helper::GenerateMidPoint(faceLandMarksPoints, 47, 46, 0);
    eye.leftEyeLines.p2_y = Helper::GenerateMidPoint(faceLandMarksPoints, 47, 46, 1);

}

cv:: Mat EyeDetector::DrawEyeCoordinateOnFace(cv::Mat frame){

        //Right eye//

    // vertical x line
    cv::line(frame,  cv::Point(eye.rightEyeLines.p1_x,  eye.rightEyeLines.p1_y),
                     cv::Point(eye.rightEyeLines. p2_x, eye.rightEyeLines. p2_y),
                     cv::Scalar(255, 255, 0), 1);

   // horizontal y line
    cv::line(frame, cv::Point(FacialLandMarkDetector::faceLandMarksPoints[36][0],
                              FacialLandMarkDetector::faceLandMarksPoints[36][1]),
                    cv::Point(FacialLandMarkDetector::faceLandMarksPoints[39][0],
                              FacialLandMarkDetector::faceLandMarksPoints[39][1]),
                    cv::Scalar(255, 255, 0), 1);

        // Left eye //

     // vertical x line
    cv::line(frame, cv::Point(FacialLandMarkDetector::faceLandMarksPoints[42][0],
                              FacialLandMarkDetector::faceLandMarksPoints[42][1]),
                    cv::Point(FacialLandMarkDetector::faceLandMarksPoints[45][0],
                              FacialLandMarkDetector::faceLandMarksPoints[45][1]),
                    cv::Scalar(255, 255, 0), 1);
    // horizontal y line
    cv::line(frame, cv::Point(eye.leftEyeLines.p1_x, eye.leftEyeLines.p1_y),
                    cv::Point(eye.leftEyeLines.p2_x, eye.leftEyeLines.p2_y),
                    cv::Scalar(255, 255, 0), 1);


return frame;
}
cv::Mat EyeDetector::displayEye(cv::Mat faceFrame){

        cv::Mat face;
        FacialLandMarkDetector::CreateLandMarkPointsFace(faceFrame);

        for (unsigned long i = 0; i < 68; ++i) //
              {

                qDebug() <<"x: "<<faceLandMarksPoints[i][0]<<" y: "<<faceLandMarksPoints[i][1] ;

              }

       CreateFourMainEyeCoordinate();
       faceFrame = DrawEyeCoordinateOnFace(faceFrame);

    if(getAverageHorizontalLengthEye(RIGHT_EYE) < 55)
       {
          DrawText(faceFrame,"Blink",cv::Point(100,100));
       }


    qDebug() << "right: " << rightEyeVerticalLength;
    qDebug() << "left: " <<  leftEyeVerticalLength;





  return faceFrame;
}
