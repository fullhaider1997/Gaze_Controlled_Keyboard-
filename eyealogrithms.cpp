#include "eyealogrithms.h"
#include "helper.h"
#include "variables.h"
#include "facialolgrithmsoncrete.h"


EyeAlogrithms::EyeAlogrithms()
{
    rightEyeBoundary.reserve(6);
    leftEyeBoundary.reserve(6);


}
EyeAlogrithms::~EyeAlogrithms(){


}

int EyeAlogrithms::getAverageHorizontalLengthEye(int eyeLocation){


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
void EyeAlogrithms::CreateFourMainEyeCoordinate(){


    eye.rightEyeLines.p1_x = Helper::GenerateMidPoint(faceLandMarksPointsCopy[38].x,faceLandMarksPointsCopy[37].x);
    eye.rightEyeLines.p1_y = Helper::GenerateMidPoint(faceLandMarksPointsCopy[38].y,faceLandMarksPointsCopy[37].y);
    eye.rightEyeLines.p2_x = Helper::GenerateMidPoint(faceLandMarksPointsCopy[40].x,faceLandMarksPointsCopy[41].x);
    eye.rightEyeLines.p2_y = Helper::GenerateMidPoint(faceLandMarksPointsCopy[40].y,faceLandMarksPointsCopy[41].y);


     eye.leftEyeLines.p1_x = Helper::GenerateMidPoint(faceLandMarksPointsCopy[43].x,faceLandMarksPointsCopy[44].x);
     eye.leftEyeLines.p1_y = Helper::GenerateMidPoint(faceLandMarksPointsCopy[43].y,faceLandMarksPointsCopy[44].y);
     eye.leftEyeLines.p2_x = Helper::GenerateMidPoint(faceLandMarksPointsCopy[47].x,faceLandMarksPointsCopy[46].x);
     eye.leftEyeLines.p2_y = Helper::GenerateMidPoint(faceLandMarksPointsCopy[47].y,faceLandMarksPointsCopy[46].y);



}

cv:: Mat EyeAlogrithms::DrawEyeCoordinateOnFace(cv::Mat frame){

        //Right eye//

    // vertical x line
    cv::line(frame,  cv::Point(eye.rightEyeLines.p1_x, eye.rightEyeLines.p1_y),
                     cv::Point(eye.rightEyeLines.p2_x, eye.rightEyeLines. p2_y),
                     cv::Scalar(255, 255, 0), 1);

   // horizontal y line
    cv::line(frame, cv::Point(faceLandMarksPointsCopy[36].x,faceLandMarksPointsCopy[36].y),
                    cv::Point(faceLandMarksPointsCopy[39].x,faceLandMarksPointsCopy[39].y),
                    cv::Scalar(255, 255, 0), 1);

        // Left eye //

     // vertical x line
    cv::line(frame, cv::Point(faceLandMarksPointsCopy[42].x,faceLandMarksPointsCopy[42].y),
                    cv::Point(faceLandMarksPointsCopy[45].x,faceLandMarksPointsCopy[45].y),
                    cv::Scalar(255, 255, 0), 1);
    // horizontal y line
    cv::line(frame, cv::Point(eye.leftEyeLines.p1_x, eye.leftEyeLines.p1_y),
                    cv::Point(eye.leftEyeLines.p2_x, eye.leftEyeLines.p2_y),
                    cv::Scalar(255, 255, 0), 1);


return frame;
}

std::vector<cv::Point> EyeAlogrithms::getEnclosedLeftEyeBoundary()
 {
      std::vector<int> list = {36,37,38,39,40,41};
      for(size_t i=0; i<list.size(); i++){
            leftEyeBoundary.push_back(cv::Point(faceLandMarksPointsCopy[list[i]].x,faceLandMarksPointsCopy[list[i]].y));
         }//


 return leftEyeBoundary;
}

std::vector<cv::Point> EyeAlogrithms::getEnclosedRightEyeBoundary()
 {
         std::vector<int> list={42,43,44,45,46,47};
         for(size_t i=0; i<list.size(); i++){
              rightEyeBoundary.push_back(cv::Point(faceLandMarksPointsCopy[list[i]].x,faceLandMarksPointsCopy[list[i]].y));
            }




 return rightEyeBoundary;
}


void EyeAlogrithms::drawEyeBoundary(std::vector<cv::Point> eyeBoundary){



}

void EyeAlogrithms::clearFilledUpVector(){

    faceLandMarksPoints.clear();
}

void EyeAlogrithms::update(std::vector<cv::Point> landmarkspoints){

        faceLandMarksPointsCopy = landmarkspoints;

        if(faceLandMarksPointsCopy.size() <= 0){
            qDebug() << "eye Algorithm fail update(): fandlandmarks size is " << faceLandMarksPointsCopy.size();
        }else{
            qDebug() << "eye Alogrithm successful update(): fandlandmarks size is " << faceLandMarksPointsCopy.size();

        }

}




void EyeAlogrithms::applyOperations(cv::Mat faceFrame){

    cv::Mat dst;





     if(faceLandMarksPointsCopy.size() > 0)
          {
           CreateFourMainEyeCoordinate();
           //DrawEyeCoordinateOnFace(faceFrame);




          leftEyeBoundaryPoint    =  getEnclosedLeftEyeBoundary();
          rightEyeBoundaryPoint   =  getEnclosedRightEyeBoundary();


        cv::Mat lefteye = faceFrame(cv::Rect(
                                 cv::Point(faceLandMarksPointsCopy[42].x,faceLandMarksPointsCopy[43].y),
                                 cv::Point(faceLandMarksPointsCopy[45].x,faceLandMarksPointsCopy[46].y)));

      if(lefteye.size().width >0 && lefteye.size().height> 0)
         {

           cv::resize(lefteye,lefteye,cv::Size(200,200),0,0,cv::INTER_CUBIC);
           cv::cvtColor(lefteye,dst,cv::COLOR_BGR2GRAY);
        \
           // cv::threshold(dst,dst,70,255,cv::THRESH_BINARY);
           // cv::resize(dst,dst,cv::Size(100,100),0,0,cv::INTER_CUBIC);
           cv::imshow("original",lefteye);
           cv::imshow("processed image",dst);
          // cv::imshow(" threshold image",dst);
        }



      if(getAverageHorizontalLengthEye(RIGHT_EYE) < 50)
          {
            cv::putText(faceFrame,"Blink",cv::Point(200,250),1,2,cv::Scalar(255,255,0));
         }

     }

}

cv::Mat EyeAlogrithms::displayEye(std::vector<cv::Point>  faceLandMarksPoints, cv::Mat faceFrame){

        cv::Mat face;
        cv::Mat dst;

        faceLandMarksPointsCopy =  faceLandMarksPoints;
                                   CreateFourMainEyeCoordinate();
        //leftEyeBoundaryPoint    =  getEnclosedLeftEyeBoundary(faceLandMarksPointsCopy);
        //rightEyeBoundaryPoint   =  getEnclosedRightEyeBoundary(faceLandMarksPointsCopy);


        cv::Mat lefteye = faceFrame(cv::Rect(
                                    cv::Point(faceLandMarksPointsCopy[42].x,faceLandMarksPointsCopy[43].y),
                                    cv::Point(faceLandMarksPointsCopy[45].x,faceLandMarksPointsCopy[46].y)));

        if(lefteye.size().width >0 && lefteye.size().height> 0)
           {
              cv::resize(lefteye,lefteye,cv::Size(100,100),0,0,cv::INTER_CUBIC);
              cv::cvtColor(lefteye,dst,cv::COLOR_BGR2GRAY);
              cv::threshold(dst,dst,90,255,cv::THRESH_BINARY);
              cv::resize(dst,dst,cv::Size(100,100),0,0,cv::INTER_CUBIC);
              cv::imshow("eye",lefteye);
              cv::imshow(" threshold image",dst);
           }



       if(getAverageHorizontalLengthEye(RIGHT_EYE) < 55)
           {
             cv::putText(faceFrame,"Blink",cv::Point(100,100),1,1,cv::Scalar(255,255,0));
           }

      clearFilledUpVector();


  return faceFrame;
}
