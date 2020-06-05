#ifndef FACELANDMARKDETECTOR_H
#define FACELANDMARKDETECTOR_H

#include <QObject>
#include <iostream>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <thread>
#include <math.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include <iostream>
#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include "helper.h"
#include "QDebug"
#include "qtimer.h"
#include "Detector.h"

#define FIRST_FACE 0


class FacialLandMarkDetector: public Detector
{
     Q_OBJECT
public:
    FacialLandMarkDetector();
    ~ FacialLandMarkDetector();
     std::vector<cv::Point> ConvertFrameToLandMarkFrame(cv::Mat originalFrame);
     void DrawText(cv::Mat frame,std::string word,cv::Point point);
     void DrawLandMarks(cv::Mat frame);
     std::vector<cv::Point>  CreateLandMarkPointsFace(cv::Mat frame);
     void drawRectFace(std::vector<dlib::rectangle> faces, cv::Mat frame);
     void applyOperations(cv::Mat frame) override;

private:
     cv::Rect points;
     cv::Mat copy;
     std::vector<dlib::rectangle> faces;
     std::vector<dlib::full_object_detection> shapes;
     dlib::frontal_face_detector detector;
     dlib::shape_predictor pose_model;
     dlib::cv_image<dlib::bgr_pixel> cimg;
     std::vector<cv::Point> faceLandMarksPoints;





};


#endif // FACELANDMARKDETECTOR_H
