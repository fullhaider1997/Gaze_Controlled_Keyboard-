#include "videoprocessorpipeline.h"
#include "faciallandmarkdetector.h"
#include "variables.h"
#include "Detector.h"
#include "eyedetector.h"
#include "faciallandmarkdetector.h"
VideoProcessorPipleLine::VideoProcessorPipleLine()
   {

    imageProcessPipline->push_back(new FacialLandMarkDetector);
    imageProcessPipline->push_back(new EyeDetector);


   }
VideoProcessorPipleLine::~VideoProcessorPipleLine(){

}


void VideoProcessorPipleLine::displayVideo(){




    qDebug() << "Starting capturing...";

    cv::VideoCapture camera(0);
    cv::Mat faceFrame;
    cv::Mat eyeFrame;


    while(camera.isOpened())
    {

        camera >> faceFrame;
        if(faceFrame.empty()){
           return;
        }

        for(auto computationBlock:*imageProcessPipline){
              computationBlock->applyOperations(faceFrame);
        }

       // faceLandmarks = faceDetector->ConvertFrameToLandMarkFrame(faceFrame);
        //faceFrame=  eyeDetector->displayEye(faceLandmarks,faceFrame);


        emit display(QPixmap::fromImage(
                 QImage(faceFrame.data,
                        faceFrame.cols,
                        faceFrame.rows,
                        faceFrame.step,
                 QImage::Format_RGB888).rgbSwapped()));
        }






 emit finished();
}


