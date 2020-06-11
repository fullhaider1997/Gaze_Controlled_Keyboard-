#include "videoprocessorpipeline.h"
#include "facealogrithms.h"
#include "variables.h"
#include "facialolgrithmsoncrete.h"
#include "eyealogrithms.h"
#include "facealogrithms.h"
#include "faciallandmarkdetector.h"
#include "drawfacialfeature.h"
VideoProcessorPipleLine::VideoProcessorPipleLine():
    detector(new FacialLandmarkDetector)
   {

    vectorImageProcessingAlogrithms.push_back(new EyeAlogrithms);
    vectorImageProcessingAlogrithms.push_back(new FaceAlogrithms);



   }
VideoProcessorPipleLine::~VideoProcessorPipleLine(){

}


void VideoProcessorPipleLine::displayVideo(){


    qDebug() << "Starting capturing...";

    cv::VideoCapture camera(2);







    while(camera.isOpened())
    {

        camera >> faceFrame;

        cv::flip(faceFrame,faceFrame,+1);
       // cv::LUT(faceFrame, lookUpTable, faceFrame);


        faceLandMarksPoints = detector->generateLandMarkFrame(faceFrame);
       // DrawFacialFeature::Draw(faceLandMarksPoints,faceFrame);

     //   if(faceLandMarksPoints.size() >0)
        //    qDebug() << "x: "<<faceLandMarksPoints[0].x;

        for(auto alogrithm :vectorImageProcessingAlogrithms)
          {

              alogrithm->update(faceLandMarksPoints);
              alogrithm->applyOperations(faceFrame);

          }





        emit display(QPixmap::fromImage(
                 QImage(faceFrame.data,
                        faceFrame.cols,
                        faceFrame.rows,
                        faceFrame.step,
                 QImage::Format_RGB888).rgbSwapped()));
         }





 emit finished();
}


