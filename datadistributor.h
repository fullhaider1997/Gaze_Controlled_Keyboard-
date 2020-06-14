#ifndef DATADISTRIBUTOR_H
#define DATADISTRIBUTOR_H

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "eyealogrithms.h"
#include "facealogrithms.h"
#include "drawfacialfeature.h"
#include <thread>

class DataDistributor
{
    FaceAlogrithms * face;
    EyeAlogrithms * eye;
    DrawFacial * draw;
private:
    std::vector<cv::Point> rightEyeBoundaryPoints;



public:
    void notify(std::vector<cv::Point> landmarks);
    DataDistributor();
    void setEye(EyeAlogrithms*);
    void setDraw(DrawFacial *);
};

#endif // DATADISTRIBUTOR_H
