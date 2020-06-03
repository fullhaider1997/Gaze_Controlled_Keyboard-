#include "videoprocessorpipeline.h"
#include "faciallandmarkdetector.h"
VideoProcessorPipleLine::VideoProcessorPipleLine()
    :
  faceDetector( new FacialLandMarkDetector),
  eyeDetector( new EyeDetector)
   {

   }
VideoProcessorPipleLine::~VideoProcessorPipleLine(){

}


void VideoProcessorPipleLine::displayVideo(){
    qDebug() << "Starting capturing...";

    cv::VideoCapture camera(0);
    std::vector<std::vector<double>> faceLandmarks;
    cv::Mat faceFrame;
    cv::Mat eyeFrame;

    while(camera.isOpened())
    {

        camera >> faceFrame;
        if(faceFrame.empty()){
           return;
        }

        faceLandmarks = faceDetector->ConvertFrameToLandMarkFrame(faceFrame);
        eyeFrame =  eyeDetector->displayEye(faceLandmarks,faceFrame);

        emit display(QPixmap::fromImage(
                 QImage(faceFrame.data,faceFrame.cols,faceFrame.rows,faceFrame.step,
                 QImage::Format_RGB888).rgbSwapped()));
        }

        emit display(QPixmap::fromImage(
                     QImage(eyeFrame.data,eyeFrame.cols,eyeFrame.rows,eyeFrame.step,
                     QImage::Format_RGB888).rgbSwapped()));




 emit finished();
}


