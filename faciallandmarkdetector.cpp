#include "faciallandmarkdetector.h"
#include "helper.h"
#define POINT_ONE_X 0
#define POINT_ONE_Y 1
#define POINT_TWO_X 2
#define POINT_TWO_Y 3

FacialLandMarkDetector::~FacialLandMarkDetector(){

}
FacialLandMarkDetector::FacialLandMarkDetector()
    :faceLandMarksPoints(68, cv::Point(2, 0))

{

    try {
        //std::vector<std::vector<int>> faceLandMarksPoints(68, std::vector<int>(2, 0));
        detector = dlib::get_frontal_face_detector();
        dlib::deserialize("/home/haider/Downloads/shape_predictor_68_face_landmarks.dat") >> pose_model;



    } catch (std::exception &e) {
        qDebug()<< e.what();
    }

}
void FacialLandMarkDetector::DrawText(cv::Mat frame,std::string word, cv::Point point){

    cv::putText(frame,
                         word, point,
                         cv::FONT_HERSHEY_COMPLEX_SMALL,
                         0.8, cvScalar(200, 0, 0), 1);

 }


std::vector<cv::Point>  FacialLandMarkDetector::CreateLandMarkPointsFace(cv::Mat frame)
{
    dlib::cv_image<dlib::bgr_pixel> cimg(frame);


    faces = detector(cimg);


   if(faces.size() >0) {
    std::vector<dlib::full_object_detection> shapes;
    for (unsigned long i = 0; i < faces.size(); ++i)
        shapes.push_back(pose_model(cimg, faces[i]));

    std::cout << "Size: " << faces.size() << std::endl;

    const dlib::full_object_detection& d = shapes[0]; // Hold the detected face i

    for (unsigned long i = 0; i < 68; ++i) // Hold all the 68 face landmark coordinates(x, y)
    {
        faceLandMarksPoints[i] = cv::Point(d.part(i).x(), (double)d.part(i).y());

     }
   }


 return faceLandMarksPoints;
}
void FacialLandMarkDetector::DrawLandMarks(cv::Mat frame){

    for (unsigned long i = 0; i < 68; ++i) //
          {
            cv::circle(frame,faceLandMarksPoints[i],2,cv::Scalar(255,255,0),2);
            qDebug() <<"x: "<<faceLandMarksPoints[i].x<<" y: "<<faceLandMarksPoints[i].y ;

          }



}
void FacialLandMarkDetector::drawRectFace(std::vector<dlib::rectangle> faces, cv::Mat frame){


    if(!faces.empty() == true){

       cv::Rect points = Helper::dlibRectangleToOpenCV(faces[0]);
       cv::rectangle(frame,points,cv::Scalar(255,255,0),2);

        qDebug() <<"x: "<< points.x << "y: "<<points.y;

        return;

     }else {

        qDebug() << "No face "<< faces.size();

       return;
    }

}

void FacialLandMarkDetector::applyOperations(cv::Mat frame){

    cv::flip(frame,frame, +1);
   // faceLandMarksPoints = CreateLandMarkPointsFace(frame);


}

std::vector<cv::Point> FacialLandMarkDetector::ConvertFrameToLandMarkFrame(cv::Mat frame)
{

   cv::cvtColor(frame,frame,cv::COLOR_BGR2GRAY);



 return faceLandMarksPoints;


}
