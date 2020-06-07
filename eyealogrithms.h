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
class FacialLandmarkDetector;

class EyeAlogrithms :  public  FacialAlgorithms
{
    Q_OBJECT
public:
     EyeAlogrithms();
     EyeAlogrithms (FacialLandmarkDetector &detector);
     ~EyeAlogrithms ();
    void CreateFourMainEyeCoordinate();
    cv::Mat  DrawEyeCoordinateOnFace(cv::Mat frame);
    void drawEyeBoundary(std::vector<cv::Point> eyeBoundary);
    std::vector<cv::Point> GenerateRectEye(std::vector<cv::Point> eyeBoundaryPoints);
    std::vector<cv::Point> getEnclosedLeftEyeBoundary(std::vector<cv::Point>faceLandMarksPoints );
    std::vector<cv::Point> getEnclosedRightEyeBoundary(std::vector<cv::Point>faceLandMarksPoints );
    cv::Mat  displayEye(std::vector<cv::Point>  faceLandMarksPoints, cv::Mat faceFrame);
    int getAverageHorizontalLengthEye(int eyeLocation);
    void clearFilledUpVector();
    void applyOperations(cv::Mat frame) override;
    void update() override;




private:
    std::vector<cv::Point> faceLandMarksPoints;
    FacialLandmarkDetector * detector;
    int rightEyeVerticalLength;
    int leftEyeVerticalLength;
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
