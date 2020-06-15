#ifndef DRAWFACIALFEATURE_H
#define DRAWFACIALFEATURE_H

#include "absractdraw.h"
#include "facealogrithms.h"
#include "facialolgrithmsoncrete.h"
class FacialAlgorithms;

class DrawFacial :public FacialAlgorithms
{
public:
     cv::Mat applyOperations(cv::Mat face) override;
     void update(std::vector<cv::Point> landMarksPoints) override ;

public:
     void updateDrawRightEye(std::vector<cv::Point> landMarksPoints) ;
     void drawRightEye(cv::Mat face,std::vector<cv::Point> rightFaceLandmarks);
     cv::Mat  DrawEyeCoordinateOnFace(cv::Mat frame);

private:
     std::vector<cv::Point> faceLandMarksPoints;
     std::vector<cv::Point> rightEyeBoundary;


};

#endif // DRAWFACIALFEATURE_H
