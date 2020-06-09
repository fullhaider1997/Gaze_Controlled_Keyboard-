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
class VideoProcessorPipleLine : public QObject
{
    Q_OBJECT
public:
    VideoProcessorPipleLine();
    ~VideoProcessorPipleLine();
public slots:
    void displayVideo();
signals:
    void display(QPixmap pixmap);
    void finished();
    void error(QString);
private:
    std::vector<FacialAlgorithms*> vectorImageProcessingAlogrithms;
    FacialLandmarkDetector *detector;
};


#endif // VIDEOPROCESSOR_H
