#include "eyedetector.h"
#include "helper.h"
EyeDetector::EyeDetector()
{
    rightEyeBoundary.reserve(6);
    leftEyeBoundary.reserve(6);
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

    eye.rightEyeLines.p1_x = Helper::GenerateMidPoint(faceLandMarksPointsCopy, 38, 37, 0);
    eye.rightEyeLines.p1_y = Helper::GenerateMidPoint(faceLandMarksPointsCopy, 38, 37, 1);
    eye.rightEyeLines.p2_x = Helper::GenerateMidPoint(faceLandMarksPointsCopy, 40, 41, 0);
    eye.rightEyeLines.p2_y = Helper::GenerateMidPoint(faceLandMarksPointsCopy, 40, 41, 1);


    eye.leftEyeLines.p1_x = Helper::GenerateMidPoint(faceLandMarksPointsCopy, 43, 44, 0);
    eye.leftEyeLines.p1_y = Helper::GenerateMidPoint(faceLandMarksPointsCopy, 43, 44, 1);
    eye.leftEyeLines.p2_x = Helper::GenerateMidPoint(faceLandMarksPointsCopy, 47, 46, 0);
    eye.leftEyeLines.p2_y = Helper::GenerateMidPoint(faceLandMarksPointsCopy, 47, 46, 1);

}

cv:: Mat EyeDetector::DrawEyeCoordinateOnFace(cv::Mat frame){

        //Right eye//

    // vertical x line
    cv::line(frame,  cv::Point(eye.rightEyeLines.p1_x,  eye.rightEyeLines.p1_y),
                     cv::Point(eye.rightEyeLines. p2_x, eye.rightEyeLines. p2_y),
                     cv::Scalar(255, 255, 0), 1);

   // horizontal y line
    cv::line(frame, cv::Point(faceLandMarksPointsCopy[36][0],
                              faceLandMarksPointsCopy[36][1]),
                    cv::Point(faceLandMarksPointsCopy[39][0],
                              faceLandMarksPointsCopy[39][1]),
                    cv::Scalar(255, 255, 0), 1);

        // Left eye //

     // vertical x line
    cv::line(frame, cv::Point(faceLandMarksPointsCopy[42][0],
                              faceLandMarksPointsCopy[42][1]),
                    cv::Point(faceLandMarksPointsCopy[45][0],
                              faceLandMarksPointsCopy[45][1]),
                    cv::Scalar(255, 255, 0), 1);
    // horizontal y line
    cv::line(frame, cv::Point(eye.leftEyeLines.p1_x, eye.leftEyeLines.p1_y),
                    cv::Point(eye.leftEyeLines.p2_x, eye.leftEyeLines.p2_y),
                    cv::Scalar(255, 255, 0), 1);


return frame;
}

std::vector<cv::Point> EyeDetector::getEnclosedLeftEyeBoundary
           (std::vector<std::vector<double>> faceLandMarksPointsCopy)
 {

                leftEyeBoundary[0]=cv::Point(faceLandMarksPointsCopy[36][0],faceLandMarksPointsCopy[36][1]);
                leftEyeBoundary[1]=cv::Point(faceLandMarksPointsCopy[37][0],faceLandMarksPointsCopy[37][1]);
                leftEyeBoundary[2]=cv::Point(faceLandMarksPointsCopy[38][0],faceLandMarksPointsCopy[38][1]);
                leftEyeBoundary[3]=cv::Point(faceLandMarksPointsCopy[39][0],faceLandMarksPointsCopy[39][1]);
                leftEyeBoundary[4]=cv::Point(faceLandMarksPointsCopy[40][0],faceLandMarksPointsCopy[40][1]);
                leftEyeBoundary[5]=cv::Point(faceLandMarksPointsCopy[41][0],faceLandMarksPointsCopy[41][1]);



 return leftEyeBoundary;
}

std::vector<cv::Point> EyeDetector::getEnclosedRightEyeBoundary
           (std::vector<std::vector<double>> faceLandMarksPointsCopy)
 {


                 rightEyeBoundary[0]=cv::Point(faceLandMarksPointsCopy[42][0],faceLandMarksPointsCopy[42][1]);
                 rightEyeBoundary[1]=cv::Point(faceLandMarksPointsCopy[43][0],faceLandMarksPointsCopy[43][1]);
                 rightEyeBoundary[2]=cv::Point(faceLandMarksPointsCopy[44][0],faceLandMarksPointsCopy[44][1]);
                 rightEyeBoundary[3]=cv::Point(faceLandMarksPointsCopy[45][0],faceLandMarksPointsCopy[45][1]);
                 rightEyeBoundary[4]=cv::Point(faceLandMarksPointsCopy[46][0],faceLandMarksPointsCopy[46][1]);
                 rightEyeBoundary[5]=cv::Point(faceLandMarksPointsCopy[47][0],faceLandMarksPointsCopy[47][1]);



 return rightEyeBoundary;
}


void EyeDetector::drawEyeBoundary(std::vector<cv::Point> eyeBoundary){



}

cv::Mat EyeDetector::displayEye(std::vector<std::vector<double>>  faceLandMarksPoints, cv::Mat faceFrame){

        cv::Mat face;
        std::vector<cv::Point> lefteye;
        std::vector<cv::Point> righteye;


        faceLandMarksPointsCopy =  faceLandMarksPoints;

        CreateFourMainEyeCoordinate();
        faceFrame = DrawEyeCoordinateOnFace(faceFrame);

        lefteye = getEnclosedLeftEyeBoundary(faceLandMarksPointsCopy);
        righteye = getEnclosedRightEyeBoundary(faceLandMarksPointsCopy);

        drawEyeBoundary(lefteye);

        cv::polylines(faceFrame,lefteye,true, cv::Scalar(255,255,0),10);


        for(int i=0; i<lefteye.size(); i++){

            cv::circle(faceFrame,lefteye[i],5,cv::Scalar(0,255,0),5);
            qDebug() << lefteye[i].x <<","<< lefteye[i].y;
        }
       // cv::polylines(faceFrame,righteye,true,cv::Scalar(255,255,0),10);


      // if(getAverageHorizontalLengthEye(RIGHT_EYE) < 55)
       //  {
        //   DrawText(faceFrame,"Blink",cv::Point(100,100));
        // }


    qDebug() << "right: " << rightEyeVerticalLength;
    qDebug() << "left: " <<  leftEyeVerticalLength;
    qDebug() << "size of eyes: " << lefteye.size();





  return faceFrame;
}
