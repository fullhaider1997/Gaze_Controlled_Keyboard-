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

#define FIRST_FACE 0

class FaceLandMarkDetector: public QObject
{
     Q_OBJECT
public:
    FaceLandMarkDetector();
    ~FaceLandMarkDetector();
     cv:: Mat ConvertFrameToLandMarkFrame(cv::Mat originalFrame);
     void DrawText(cv::Mat frame);
     void DrawLandMarks(cv::Mat frame);
     void CreateLandMarkPointsFace(cv::Mat frame);
     void CreateFourMainEyeCoordinate();
     cv::Mat  DrawEyeCoordinateOnFace(cv::Mat frame);
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
     dlib::image_window window;
     double faceLandMarksPoints[68][2];
    int rightEyeVerticalLength;
    int leftEyeVerticalLength;
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


#endif // FACELANDMARKDETECTOR_H
