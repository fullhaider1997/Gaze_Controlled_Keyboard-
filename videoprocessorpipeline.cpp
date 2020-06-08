#include "videoprocessorpipeline.h"
#include "facealogrithms.h"
#include "variables.h"
#include "facialolgrithmsoncrete.h"
#include "eyealogrithms.h"
#include "facealogrithms.h"
#include "faciallandmarkdetector.h"
VideoProcessorPipleLine::VideoProcessorPipleLine()
    :faceLandMarkDetector(new FacialLandmarkDetector)
   {

    vectorImageProcessingAlogrithms.push_back(new EyeAlogrithms(*faceLandMarkDetector));
    vectorImageProcessingAlogrithms.push_back(new FaceAlogrithms(*faceLandMarkDetector));



   }
VideoProcessorPipleLine::~VideoProcessorPipleLine(){

}


void VideoProcessorPipleLine::displayVideo(){




    qDebug() << "Starting capturing...";

    cv::VideoCapture camera(0);
    cv::Mat faceFrame;
    FacialLandmarkDetector detector;


    while(camera.isOpened())
    {

        camera >> faceFrame;


        detector.generateLandMarkFrame(faceFrame);

        for(auto alogrithm :vectorImageProcessingAlogrithms){
            alogrithm->update();
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


