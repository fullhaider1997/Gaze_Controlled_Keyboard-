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
    cv::Mat frame;
    cv::Mat ProcessedFrame;

    while(camera.isOpened())
    {

        camera >> frame;
        if(frame.empty()){
           return;
        }

        frame = detector->ConvertFrameToLandMarkFrame(frame);




        emit display(QPixmap::fromImage(
                     QImage(frame.data,frame.cols,frame.rows,frame.step,
                     QImage::Format_RGB888).rgbSwapped()));
            }






    emit finished();
}

