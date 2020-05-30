#include "facelandmarkdetector.h"
#define POINT_ONE_X 0
#define POINT_ONE_Y 1
#define POINT_TWO_X 2
#define POINT_TWO_Y 3

FaceLandMarkDetector::~FaceLandMarkDetector(){

}
FaceLandMarkDetector::FaceLandMarkDetector()
{
    try {

        detector = dlib::get_frontal_face_detector();
        dlib::deserialize("/home/haider/Downloads/shape_predictor_68_face_landmarks.dat") >> pose_model;
        fourRightEyeCoodinate.reserve(4);
        fourLeftEyeCoordinate.reserve(4);


    } catch (std::exception &e) {
        qDebug()<< e.what();
    }

}
//void FaceLandMarkDetector::DrawText(cv::Mat frame){

//}

void FaceLandMarkDetector::CreateFourMainEyeCoordinate( double (&faceLandMarksPoints)[68][2]){

    qDebug() << "Creating four main eye coordinate..";


        fourRightEyeCoodinate[POINT_ONE_X] = Helper::GenerateMidPoint(faceLandMarksPoints, 38, 37, 0);
        fourRightEyeCoodinate[POINT_ONE_Y] = Helper::GenerateMidPoint(faceLandMarksPoints, 38, 37, 1);
        fourRightEyeCoodinate[POINT_TWO_X] = Helper::GenerateMidPoint(faceLandMarksPoints, 40, 41, 0);
        fourRightEyeCoodinate[POINT_TWO_Y] = Helper::GenerateMidPoint(faceLandMarksPoints, 40, 41, 1);


        fourLeftEyeCoordinate[POINT_ONE_X] = Helper::GenerateMidPoint(faceLandMarksPoints, 43, 44, 0);
        fourLeftEyeCoordinate[POINT_ONE_Y] = Helper::GenerateMidPoint(faceLandMarksPoints, 43, 44, 1);
        fourLeftEyeCoordinate[POINT_TWO_X] = Helper::GenerateMidPoint(faceLandMarksPoints, 47, 46, 0);
        fourLeftEyeCoordinate[POINT_TWO_Y] = Helper::GenerateMidPoint(faceLandMarksPoints, 47, 46, 1);
        qDebug() <<"eye 38 x: "<< faceLandMarksPoints[38][0];
        qDebug() << "eye 39 y: " <<faceLandMarksPoints[38][1];



}

void FaceLandMarkDetector::CreateLandMarkPointsFace(
                                                    dlib::cv_image<dlib::bgr_pixel> cimg,
                                                    double (&faceLandMarksPoints)[68][2])
{


     qDebug() << "faces:" << faces.size();

    if(faces.size()>0){
     qDebug() << "Creating landmarks...";
        for (unsigned long i = 0; i < faces.size(); ++i)
                    shapes.push_back(pose_model(cimg, faces[i]));



          const dlib::full_object_detection& detectedFace = shapes[0];


          for (unsigned long i = 0; i < 68; ++i) //
                {
                   faceLandMarksPoints[i][0] = (double)detectedFace.part(i).x();
                   faceLandMarksPoints[i][1] = (double)detectedFace.part(i).y();

                }
      }else{

          return;
    }




}
void FaceLandMarkDetector::drawRectFace(std::vector<dlib::rectangle> faces, cv::Mat frame){



    if(!faces.empty() == true){

       cv::Rect points = Helper::dlibRectangleToOpenCV(faces[0]);
       cv::rectangle(frame,points,cv::Scalar(255,255,0),2);

        qDebug() <<"x: "<< points.x << "y: "<<points.y;

     }else {

        qDebug() << "No face "<< faces.size();

       return;
    }

}
cv:: Mat FaceLandMarkDetector::DrawEyeCoordinate(cv::Mat frame,std::vector<int> FourEyeCoordinate,double (&faceLandMarksPoints)[68][2],int eye_p1,int eye_p2){


    qDebug() << "coordinate: "<<FourEyeCoordinate.size();
     if(FourEyeCoordinate.size()> 0)
     {

        cv::line(frame,
                cv::Point(FourEyeCoordinate[POINT_ONE_X],FourEyeCoordinate[POINT_ONE_Y]),
                cv::Point(FourEyeCoordinate[POINT_TWO_X],FourEyeCoordinate[POINT_TWO_Y]),
                cv::Scalar(255, 255, 0), 1);

        cv::line(frame,
                cv::Point(faceLandMarksPoints[eye_p1][0],faceLandMarksPoints[eye_p1][1]),
                cv::Point(faceLandMarksPoints[eye_p2][0], faceLandMarksPoints[eye_p2][1]),
                cv::Scalar(255, 255, 0), 1);
    }else if(FourEyeCoordinate.size() < 0 || frame.empty()){
         qDebug() << "Error";
         return frame;
     }
     return frame;




}

cv::Mat FaceLandMarkDetector::ConvertFrameToLandMarkFrame(cv::Mat frame)
{


         cv::flip(frame,frame, +1);
         dlib::cv_image<dlib::bgr_pixel> cimg(frame);
         faces = detector(cimg);
         double faceLandMarksPoints[68][2];
         cv::Mat proccessed;

         CreateLandMarkPointsFace(cimg,faceLandMarksPoints);
         drawRectFace(faces,frame);
         CreateFourMainEyeCoordinate(faceLandMarksPoints);
         proccessed =DrawEyeCoordinate(frame,fourRightEyeCoodinate,faceLandMarksPoints,36,39);
       // DrawEyeCoordinate(frame,fourLeftEyeCoordinate,42,45);



 return proccessed;


}
