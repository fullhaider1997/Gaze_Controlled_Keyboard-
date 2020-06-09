#ifndef DRAWFACIALFEATURE_H
#define DRAWFACIALFEATURE_H

#include "absractdraw.h"

class DrawFacialFeature: public QObject
{
public:
    static void Draw(std::vector<cv::Point> Points, cv::Mat face);
};

#endif // DRAWFACIALFEATURE_H
