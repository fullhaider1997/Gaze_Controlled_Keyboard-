#include "datadistributor.h"

DataDistributor::DataDistributor()
{

}

void DataDistributor::notify(std::vector<cv::Point> landmarks){


       draw->updateDrawRightEye(landmarks);

}

void DataDistributor::setEye(EyeAlogrithms *eye){

    this->eye = eye;
}
void DataDistributor::setDraw(DrawFacial *draw){

    this->draw = draw;
}
