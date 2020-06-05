#ifndef DETECTOR_H
#define DETECTOR_H
#include "AbstractDetector.h"


class Detector: public AbstractDetector{

 public:
    void virtual applyOperations(cv::Mat) = 0;


private:

};








#endif // DETECTOR_H
