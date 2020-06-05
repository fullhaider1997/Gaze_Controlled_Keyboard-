#ifndef ABSTRACTDETECTOR_H
#define ABSTRACTDETECTOR_H

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "qobject.h"
class AbstractDetector: public QObject{

    //Q_DISABLE_COPY(AbstractDetector);
 public:
    void virtual applyOperations(cv::Mat ) = 0;




};


#endif // ABSTRACTDETECTOR_H




