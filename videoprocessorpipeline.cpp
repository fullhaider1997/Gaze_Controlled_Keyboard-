#include "videoprocessorpipeline.h"
#include "facealogrithms.h"
#include "variables.h"
#include "facialolgrithmsoncrete.h"
#include "eyealogrithms.h"
#include "facealogrithms.h"
#include "faciallandmarkdetector.h"
#include "drawfacialfeature.h"
#include "datadistributor.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

VideoProcessorPipleLine::VideoProcessorPipleLine()
    :
      detector(new FacialLandmarkDetector)

   {


    vectorImageProcessingAlogrithms.push_back(new EyeAlogrithms);
    vectorImageProcessingAlogrithms.push_back(new FaceAlogrithms);
    vectorImageProcessingAlogrithms.push_back(new DrawFacial);
    connect(vectorImageProcessingAlogrithms[0],SIGNAL(UserBlinked(bool)),this,SLOT(receivedBlink(bool)));

   }
VideoProcessorPipleLine::~VideoProcessorPipleLine(){

}

void VideoProcessorPipleLine::receivedBlink(bool answer){

    qDebug() << "Video processor recieved the blinking signals...:"  << answer;
    emit  videoProcessorBlinked(answer);
}

void VideoProcessorPipleLine::loopButtons(){

    qDebug() << "Hello world";

}

void VideoProcessorPipleLine::displayVideo(){


    qDebug() << "Starting capturing...";

    cv::VideoCapture camera(2);
    cv::Mat faceFrame;
    cv::Mat orig;
    cv::Mat processsed;


    while(camera.isOpened())
    {

        camera >> faceFrame;


        cv::flip(faceFrame,faceFrame,+1);


        faceLandMarksPoints = detector->generateLandMarkFrame(faceFrame);


         for(auto alogrithm :vectorImageProcessingAlogrithms)
            {
                alogrithm->update(faceLandMarksPoints);
                processsed = alogrithm->applyOperations(faceFrame);
            }




        emit display(QPixmap::fromImage(
                 QImage(processsed.data,
                        processsed.cols,
                        processsed.rows,
                        processsed.step,
                 QImage::Format_RGB888).rgbSwapped()));
         }

       faceFrame.release();




 emit finished();
}


