#include "videoprocessor.h"

VideoProcessor::VideoProcessor()
{

}
 VideoProcessor::~VideoProcessor(){

}

void VideoProcessor::displayVideo(){
    qDebug() << "Starting capturing...";

    cv::VideoCapture camera(0);
    cv::Mat frame;

    while(camera.isOpened())
    {

        camera >> frame;


        cv::flip(frame,frame, +1);

        if(frame.empty()){
           return;
        }

        emit display(QPixmap::fromImage(
                     QImage(frame.data,frame.cols,frame.rows,frame.step,
                     QImage::Format_BGR888).rgbSwapped()));
         }






    emit finished();
}

