#ifndef HELPER_H
#define HELPER_H

#include <QObject>
#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>

class Helper
{
public:
        static double GenerateMidPoint(std::vector<std::vector<double>> faceLandMarksPoints, int index_1, int index_2, int cols);
        static cv::Rect dlibRectangleToOpenCV(dlib::rectangle r);
        static double GetDistance(int x1, int x2, int y1, int y2);
};

#endif // HELPER_H
