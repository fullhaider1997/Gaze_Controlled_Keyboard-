#ifndef VIDEOPROCESSOR_H
#define VIDEOPROCESSOR_H

#include <QObject>
#include <QDebug>
#include "opencv2/opencv.hpp"
#include "qpixmap.h"
#include "QImage"
#include "Detector.h"
#include "faciallandmarkdetector.h"
#include "eyedetector.h"
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
    Detector *faceDetector;
    Detector * eyeDetector;
    std::vector<Detector*> *imageProcessPipline;


};


#endif // VIDEOPROCESSOR_H
