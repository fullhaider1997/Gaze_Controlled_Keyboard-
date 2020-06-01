#include "videoprocessor.h"
#include "faciallandmarkdetector.h"
VideoProcessor::VideoProcessor()
    :
 faceDetector( new FacialLandMarkDetector),
 eyeDetector(new EyeDetector)
{

}
VideoProcessor::~VideoProcessor(){

}


void VideoProcessor::displayVideo(){
    qDebug() << "Starting capturing...";

    cv::VideoCapture camera(0);
    cv::Mat faceFrame;
    cv::Mat ProcessedFrame;
    cv::Mat eyeFrame;

    while(camera.isOpened())
    {

        camera >> faceFrame;
        if(faceFrame.empty()){
           return;
        }

        faceFrame = faceDetector->ConvertFrameToLandMarkFrame(faceFrame);
        eyeFrame =  eyeDetector->displayEye(faceFrame);

        emit display(QPixmap::fromImage(
                 QImage(eyeFrame.data,eyeFrame.cols,eyeFrame.rows,eyeFrame.step,
                 QImage::Format_RGB888).rgbSwapped()));
        }

        emit display(QPixmap::fromImage(
                     QImage(faceFrame.data,faceFrame.cols,faceFrame.rows,faceFrame.step,
                     QImage::Format_RGB888).rgbSwapped()));




    emit finished();
}


