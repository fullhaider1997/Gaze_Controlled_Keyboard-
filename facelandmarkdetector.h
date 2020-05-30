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


class FaceLandMarkDetector: public QObject
{
     Q_OBJECT
public:
    FaceLandMarkDetector();
    ~FaceLandMarkDetector();
     cv:: Mat ConvertFrameToLandMarkFrame(cv::Mat originalFrame);
     //void DrawText(cv::Mat frame);
     void CreateLandMarkPointsFace(dlib::cv_image<dlib::bgr_pixel> cimg, double (&faceLandMarksPoints)[68][2]);
     void CreateFourMainEyeCoordinate(double (&faceLandMarksPoints)[68][2]);
     cv::Mat  DrawEyeCoordinate(cv::Mat frame,std::vector<int> FourEyeCoordinate,double (&faceLandMarksPoints)[68][2],int eye_p1,int eyep_2);
     void BlinkDetection();
     void drawRectFace(std::vector<dlib::rectangle> faces, cv::Mat frame);
signals:

public slots:



private:
     dlib::shape_predictor pose_model;
     dlib::cv_image<dlib::bgr_pixel> cimg;
     std::vector<dlib::rectangle> faces;
     std::vector<dlib::full_object_detection> shapes;
     dlib::frontal_face_detector detector;
     cv::Rect points;
     double faceLandMarksPoints[68][2];
     bool check_once;
     int blinkCounter;
     int open;
     int close;
     std::vector<int> fourRightEyeCoodinate;
     std::vector<int> fourLeftEyeCoordinate;





};


#endif // FACELANDMARKDETECTOR_H
