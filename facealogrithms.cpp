#include "facealogrithms.h"
#include "helper.h"
#include "faciallandmarkdetector.h"


FaceAlogrithms::~FaceAlogrithms(){

}
FaceAlogrithms::FaceAlogrithms(FacialLandmarkDetector &detector)

{

    this->detector = &detector;

}

void FaceAlogrithms::update(){

    faceLandMarksPoints = detector->getFacialLandMarks();

}
void FaceAlogrithms::applyOperations(cv::Mat){




}





