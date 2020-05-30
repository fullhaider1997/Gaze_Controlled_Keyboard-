#include "videoprocessor.h"
#include "facelandmarkdetector.h"
VideoProcessor::VideoProcessor()
    :
 detector( new FaceLandMarkDetector)
{

}
VideoProcessor::~VideoProcessor(){

}


void VideoProcessor::displayVideo(){
    qDebug() << "Starting capturing...";

    cv::VideoCapture camera(0);
    cv::Mat Originalframe;
    cv::Mat ProcessedFrame;

    while(camera.isOpened())
    {

        camera >> Originalframe;
        if(Originalframe.empty()){
           return;
        }

       ProcessedFrame = detector->ConvertFrameToLandMarkFrame(Originalframe);




        emit display(QPixmap::fromImage(
                     QImage(Originalframe.data,Originalframe.cols,Originalframe.rows,Originalframe.step,
                     QImage::Format_RGB888).rgbSwapped()));
            }






    emit finished();
}

