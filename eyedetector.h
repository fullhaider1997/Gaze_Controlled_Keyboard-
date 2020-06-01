#ifndef EYEDETECTOR_H
#define EYEDETECTOR_H

#include <QObject>
#include <QDebug>
#include "opencv2/opencv.hpp"
#include "qpixmap.h"
#include "QImage"
#include "faciallandmarkdetector.h"

class EyeDetector:public FacialLandMarkDetector
{
    Q_OBJECT
public:
     EyeDetector();
     ~EyeDetector();
    void CreateFourMainEyeCoordinate();
    cv::Mat  DrawEyeCoordinateOnFace(cv::Mat frame);
    cv::Mat displayEye(cv::Mat frame);
    int getAverageHorizontalLengthEye(int eyeLocation);

private:
    int rightEyeVerticalLength;
    int leftEyeVerticalLength;
    const int RIGHT_EYE = 1;
    const int LEFT_EYE = 2;
    struct Eyelines {
       struct rightEyeLines{
           int p1_x;
           int p1_y;
           int p2_x;
           int p2_y;

     } rightEyeLines;
    struct leftEyeLines{
           int p1_x;
           int p1_y;
           int p2_x;
           int p2_y;
    } leftEyeLines;
    } eye;

};

#endif // EYEDETECTOR_H
