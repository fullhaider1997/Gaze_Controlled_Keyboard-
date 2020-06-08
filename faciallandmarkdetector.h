#ifndef FACIALLANDMARKDETECTOR_H
#define FACIALLANDMARKDETECTOR_H

#include <QDebug>
#include "opencv2/opencv.hpp"
#include "qpixmap.h"
#include "QImage"
#include "facealogrithms.h"

class FacialLandmarkDetector
{
public:
    FacialLandmarkDetector();
    ~FacialLandmarkDetector();
    void generateLandMarkFrame(cv::Mat originalFrame);
    std::vector<cv::Point> getFacialLandMarks() const;
    void notify();

private:

    cv::Rect points;
    cv::Mat copy;
    const int FIRST_FACE;
    std::vector<dlib::rectangle> faces;
    std::vector<dlib::full_object_detection> shapes;
    dlib::frontal_face_detector detector;
    dlib::shape_predictor pose_model;
    dlib::cv_image<dlib::bgr_pixel> cimg;
    std::vector<cv::Point> faceLandMarksPoints;

};

#endif // FACIALLANDMARKDETECTOR_H
