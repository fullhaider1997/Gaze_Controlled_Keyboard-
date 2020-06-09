#ifndef ABSTRACTDETECTOR_H
#define ABSTRACTDETECTOR_H

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "qobject.h"

class FacialAlgorithmsAbstract : public QObject{

    //Q_DISABLE_COPY(AbstractDetector);
 public:
    void virtual applyOperations(cv::Mat) = 0;
    void virtual update(std::vector<cv::Point> landmarkspoints) = 0;



};


#endif // ABSTRACTDETECTOR_H




