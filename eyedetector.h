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
    void drawEyeBoundary(std::vector<cv::Point> eyeBoundary);
    std::vector<cv::Point> getEnclosedLeftEyeBoundary(std::vector<std::vector<double>>faceLandMarksPoints );
    std::vector<cv::Point> getEnclosedRightEyeBoundary(std::vector<std::vector<double>>faceLandMarksPoints );
    cv::Mat displayEye(std::vector<std::vector<double>>  faceLandMarksPoints, cv::Mat faceFrame);
    int getAverageHorizontalLengthEye(int eyeLocation);

private:
    int rightEyeVerticalLength;
    int leftEyeVerticalLength;
    std::vector<std::vector<double>>faceLandMarksPointsCopy;
    std::vector<cv::Point>  leftEyeBoundary;
    std::vector<cv::Point>  rightEyeBoundary;
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
