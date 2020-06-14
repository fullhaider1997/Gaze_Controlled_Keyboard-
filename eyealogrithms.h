#ifndef EYEDETECTOR_H
#define EYEDETECTOR_H

#include <QObject>
#include <QDebug>
#include "opencv2/opencv.hpp"
#include "qpixmap.h"
#include "QImage"
#include "facealogrithms.h"
#include "variables.h"
#include "facialolgrithmsoncrete.h"
#include "faciallandmarkdetector.h"
#include "drawfacialfeature.h"
class FacialLandmarkDetector;
class DrawFacial;

class EyeAlogrithms :  public  FacialAlgorithms
{
    Q_OBJECT
public:
     EyeAlogrithms();
     ~EyeAlogrithms ();
    void CreateFourMainEyeCoordinate();
    cv::Mat  DrawEyeCoordinateOnFace(cv::Mat frame);
    void drawEyeBoundary(cv::Mat mask);
    std::vector<cv::Point> GenerateRectEye(std::vector<cv::Point> eyeBoundaryPoints);
    std::vector<cv::Point> getEnclosedLeftEyeBoundary();
    std::vector<cv::Point> getEnclosedRightEyeBoundary();
    int getAverageHorizontalLengthEye(int eyeLocation);
    void blinkDetection(cv::Mat frame);


public:
    void applyOperations(cv::Mat frame) override;
    void update(std::vector<cv::Point> landmarkspoints) override;




private:
    cv::Mat copy;
    cv::Mat copy2;
    std::vector<cv::Point> faceLandMarksPoints;
    FacialLandmarkDetector * detector;
    int rightEyeVerticalLength;
    int leftEyeVerticalLength;
    cv::Mat mask;
    std::vector<cv::Point> faceLandMarksPointsCopy;
    std::vector<cv::Point>  leftEyeBoundary;
    std::vector<cv::Point>  rightEyeBoundary;
    std::vector<cv::Point> leftEyeBoundaryPoint ;
    std::vector<cv::Point> rightEyeBoundaryPoint ;
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
