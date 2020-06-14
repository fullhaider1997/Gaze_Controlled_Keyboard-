#include "videoprocessorpipeline.h"
#include "facealogrithms.h"
#include "variables.h"
#include "facialolgrithmsoncrete.h"
#include "eyealogrithms.h"
#include "facealogrithms.h"
#include "faciallandmarkdetector.h"
#include "drawfacialfeature.h"
#include "datadistributor.h"

VideoProcessorPipleLine::VideoProcessorPipleLine()
    :detector(new FacialLandmarkDetector)

   {

    vectorImageProcessingAlogrithms.push_back(new EyeAlogrithms);
    vectorImageProcessingAlogrithms.push_back(new FaceAlogrithms);
    vectorImageProcessingAlogrithms.push_back(new DrawFacial);


   }
VideoProcessorPipleLine::~VideoProcessorPipleLine(){

}


void VideoProcessorPipleLine::displayVideo(){


    qDebug() << "Starting capturing...";

    cv::VideoCapture camera(2);
    cv::Mat faceFrame;
    cv::Mat orig;


    while(camera.isOpened())
    {

        camera >> faceFrame;


        cv::flip(faceFrame,faceFrame,+1);


        faceLandMarksPoints = detector->generateLandMarkFrame(faceFrame);


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

       faceFrame.release();




 emit finished();
}


