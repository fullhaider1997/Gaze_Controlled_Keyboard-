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
#include "facialolgrithmsoncrete.h"
#include "eyealogrithms.h"
#include "faciallandmarkdetector.h"

class FacialLandmarkDetector;

class FaceAlogrithms: public FacialAlgorithms
{
     Q_OBJECT
public:
     FaceAlogrithms(FacialLandmarkDetector& detector);
    ~ FaceAlogrithms();
     void applyOperations(cv::Mat frame) override;
     void update() override;

private:
     FacialLandmarkDetector* detector;
     std::vector<cv::Point> faceLandMarksPoints;





};


#endif // FACELANDMARKDETECTOR_H
