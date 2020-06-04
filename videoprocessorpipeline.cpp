#include "videoprocessorpipeline.h"
#include "faciallandmarkdetector.h"
#include "variables.h"
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
    std::vector<cv::Point> faceLandmarks;
    cv::Mat faceFrame;
    cv::Mat eyeFrame;
    listFrame frame;

    while(camera.isOpened())
    {

        camera >> faceFrame;
        if(faceFrame.empty()){
           return;
        }

        faceLandmarks = faceDetector->ConvertFrameToLandMarkFrame(faceFrame);
         frame =  eyeDetector->displayEye(faceLandmarks,faceFrame);

        emit display(QPixmap::fromImage(
                 QImage(frame.face.data,
                        frame.face.cols,
                        frame.face.rows,
                        frame.face.step,
                 QImage::Format_RGB888).rgbSwapped()));
        }

        emit display(QPixmap::fromImage(
                     QImage(frame.eye.data,
                            frame.eye.cols,
                            frame.eye.rows,
                            frame.eye.step,
                     QImage::Format_RGB888).rgbSwapped()));




 emit finished();
}


