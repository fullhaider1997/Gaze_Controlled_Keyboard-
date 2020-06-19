#ifndef VIDEOPROCESSOR_H
#define VIDEOPROCESSOR_H

#include <QObject>
#include <QDebug>
#include "opencv2/opencv.hpp"
#include "qpixmap.h"
#include "QImage"
#include "facialolgrithmsoncrete.h"
#include "facealogrithms.h"
#include "eyealogrithms.h"
#include "faciallandmarkdetector.h"
#include "drawfacialfeature.h"
#include "qabstractbutton.h"
#include "keyboardprocessor.h"

class VideoProcessorPipleLine : public QObject
{
    Q_OBJECT
public:
    VideoProcessorPipleLine();
    ~VideoProcessorPipleLine();
public slots:
    void displayVideo();
    void loopButtons();
    void receivedBlink(bool answer);

signals:
    void videoProcessorBlinked(bool answer);
    void display(QPixmap pixmap);
    void finished();
    void error(QString);
private:

    std::vector<FacialAlgorithms*> vectorImageProcessingAlogrithms;
    FacialLandmarkDetector *detector;
     std::vector<QAbstractButton*> *KeyBoardButtons;
    std::vector<cv::Point> faceLandMarksPoints;
    cv::Mat faceFrame;



};


#endif // VIDEOPROCESSOR_H
