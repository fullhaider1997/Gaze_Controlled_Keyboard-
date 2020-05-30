#include "helper.h"


double Helper::GenerateMidPoint(double lmPoints[68][2], int index_1, int index_2, int cols)
{
        return ((lmPoints[index_1][cols] + lmPoints[index_2][cols]) / 2);
}

cv::Rect Helper::dlibRectangleToOpenCV(dlib::rectangle r)
{
        return  cv::Rect(cv::Point2i(r.left(), r.top()), cv::Point2i(r.right() + 1, r.bottom() + 1));
}

double Helper::GetDistance(int x1, int x2, int y1, int y2)
{

    return std::sqrt(pow((x2 - x1), 2)) + pow((y2 - y1), 2);
}

