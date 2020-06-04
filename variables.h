#ifndef VARIABLES_H
#define VARIABLES_H




#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

typedef struct {
     cv::Mat face;
     cv::Mat eye;

 } listFrame;


#endif // VARIABLES_H
