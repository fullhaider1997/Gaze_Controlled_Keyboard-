#include "eyedetector.h"
#include "helper.h"
#include "variables.h"
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



    eye.rightEyeLines.p1_x = Helper::GenerateMidPoint(faceLandMarksPointsCopy[38].x,faceLandMarksPointsCopy[37].x);
    eye.rightEyeLines.p1_y = Helper::GenerateMidPoint(faceLandMarksPointsCopy[38].y,faceLandMarksPointsCopy[37].y);
    eye.rightEyeLines.p2_x = Helper::GenerateMidPoint(faceLandMarksPointsCopy[40].x,faceLandMarksPointsCopy[41].x);
    eye.rightEyeLines.p2_y = Helper::GenerateMidPoint(faceLandMarksPointsCopy[40].y,faceLandMarksPointsCopy[41].y);


     eye.leftEyeLines.p1_x = Helper::GenerateMidPoint(faceLandMarksPointsCopy[43].x,faceLandMarksPointsCopy[44].x);
     eye.leftEyeLines.p1_y = Helper::GenerateMidPoint(faceLandMarksPointsCopy[43].y,faceLandMarksPointsCopy[44].y);
     eye.leftEyeLines.p2_x = Helper::GenerateMidPoint(faceLandMarksPointsCopy[47].x,faceLandMarksPointsCopy[46].x);
     eye.leftEyeLines.p2_y = Helper::GenerateMidPoint(faceLandMarksPointsCopy[47].y,faceLandMarksPointsCopy[46].y);



}

cv:: Mat EyeDetector::DrawEyeCoordinateOnFace(cv::Mat frame){

        //Right eye//

    // vertical x line
    cv::line(frame,  cv::Point(eye.rightEyeLines.p1_x,  eye.rightEyeLines.p1_y),
                     cv::Point(eye.rightEyeLines.p2_x, eye.rightEyeLines. p2_y),
                     cv::Scalar(255, 255, 0), 1);

   // horizontal y line
    cv::line(frame, cv::Point(faceLandMarksPointsCopy[36].x,
                              faceLandMarksPointsCopy[36].y),
                    cv::Point(faceLandMarksPointsCopy[39].x,
                              faceLandMarksPointsCopy[39].y),
                    cv::Scalar(255, 255, 0), 1);

        // Left eye //

     // vertical x line
    cv::line(frame, cv::Point(faceLandMarksPointsCopy[42].x,
                              faceLandMarksPointsCopy[42].y),
                    cv::Point(faceLandMarksPointsCopy[45].x,
                              faceLandMarksPointsCopy[45].y),
                    cv::Scalar(255, 255, 0), 1);
    // horizontal y line
    cv::line(frame, cv::Point(eye.leftEyeLines.p1_x, eye.leftEyeLines.p1_y),
                    cv::Point(eye.leftEyeLines.p2_x, eye.leftEyeLines.p2_y),
                    cv::Scalar(255, 255, 0), 1);


return frame;
}

std::vector<cv::Point> EyeDetector::getEnclosedLeftEyeBoundary
           (std::vector<cv::Point> faceLandMarksPointsCopy)
 {
                std::vector<int> list = {36,37,38,39,40,41};
                for(size_t i=0; i<list.size(); i++){
                  leftEyeBoundary.push_back(cv::Point(faceLandMarksPointsCopy[list[i]].x,faceLandMarksPointsCopy[list[i]].y));
                 }


 return leftEyeBoundary;
}

std::vector<cv::Point> EyeDetector::getEnclosedRightEyeBoundary
           (std::vector<cv::Point> faceLandMarksPointsCopy)
 {
              std::vector<int> list={42,43,44,45,46,47};

              for(size_t i=0; i<list.size(); i++){
                  rightEyeBoundary.push_back(cv::Point(faceLandMarksPointsCopy[list[i]].x,faceLandMarksPointsCopy[list[i]].y));
              }



 return rightEyeBoundary;
}


void EyeDetector::drawEyeBoundary(std::vector<cv::Point> eyeBoundary){



}




listFrame EyeDetector::displayEye(std::vector<cv::Point>  faceLandMarksPoints, cv::Mat faceFrame){

        cv::Mat face;

        listFrame frame;
        std::vector<cv::Point> leftEyeBoundaryPoint ;
        std::vector<cv::Point> rightEyeBoundaryPoint ;
        std::vector<cv::Point> leftEyeOuterPoint;


        faceLandMarksPointsCopy =  faceLandMarksPoints;

        CreateFourMainEyeCoordinate();
        faceFrame = DrawEyeCoordinateOnFace(faceFrame);


        leftEyeBoundaryPoint = getEnclosedLeftEyeBoundary(faceLandMarksPointsCopy);
        rightEyeBoundaryPoint = getEnclosedRightEyeBoundary(faceLandMarksPointsCopy);
        frame.face = faceFrame;

        //leftEyeOuterPoint   = getRectEye();
         cv::Mat eye    =  faceFrame(cv::Rect(faceLandMarksPointsCopy[35].x,
                                              faceLandMarksPointsCopy[36].y,
                                              faceLandMarksPointsCopy[38].x,
                                              faceLandMarksPointsCopy[39].y));
         frame.eye=eye;

        for(size_t i=0; i<leftEyeOuterPoint.size(); i++){
            qDebug() << leftEyeOuterPoint[i].x << " , "<<leftEyeOuterPoint[i].y;
        }

        //drawEyeBoundary(lefteye);
//
        cv::polylines(faceFrame,leftEyeOuterPoint,true, cv::Scalar(0,255,0),2);
        cv::polylines(faceFrame,rightEyeBoundaryPoint,true, cv::Scalar(0,255,0),2);


       // cv::polylines(faceFrame,righteye,true,cv::Scalar(255,255,0),10);


      // if(getAverageHorizontalLengthEye(RIGHT_EYE) < 55)
       //  {
        //   DrawText(faceFrame,"Blink",cv::Point(100,100));
        // }


    qDebug() << "right: " << rightEyeVerticalLength;
    qDebug() << "left: " <<  leftEyeVerticalLength;

       leftEyeBoundaryPoint.clear();
       rightEyeBoundaryPoint.clear();
       leftEyeBoundary.clear();
       rightEyeBoundary.clear();
       faceLandMarksPointsCopy.clear();



  return frame;
}
