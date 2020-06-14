#ifndef DETECTOR_H
#define DETECTOR_H
#include "facialalgorithmabsract.h"

class FacialAlgorithms: public FacialAlgorithmsAbstract{

 public:
    void virtual applyOperations(cv::Mat face)  override= 0;
    void virtual update(std::vector<cv::Point> landmarkspoints) override= 0;


private:

};








#endif // DETECTOR_H
