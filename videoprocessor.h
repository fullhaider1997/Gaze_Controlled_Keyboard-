#ifndef VIDEOPROCESSOR_H
#define VIDEOPROCESSOR_H

#include <QObject>
#include <QDebug>
#include "opencv2/opencv.hpp"
#include "qpixmap.h"
#include "QImage"
class VideoProcessor : public QObject
{
    Q_OBJECT
public:
    VideoProcessor();
    ~VideoProcessor();
public slots:
    void displayVideo();

signals:
    void display(QPixmap pixmap);
    void finished();
    void error(QString);
private:


};

#endif // VIDEOPROCESSOR_H
