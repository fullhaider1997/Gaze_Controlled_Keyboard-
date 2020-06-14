#include "faciallandmarkdetector.h"



FacialLandmarkDetector::~FacialLandmarkDetector(){


}

 FacialLandmarkDetector::FacialLandmarkDetector():
     FIRST_FACE(0)

{

     detector = dlib::get_frontal_face_detector();
     dlib::deserialize("/home/haider/Downloads/shape_predictor_68_face_landmarks.dat") >> pose_model;
    // faceLandMarksPoints.reserve(68);

}


  std::vector<cv::Point>  FacialLandmarkDetector::generateLandMarkFrame(cv::Mat faceFrame){

      if(faceFrame.empty() == true){
          qDebug() << "frame is empty !";
      }


      qDebug() << "detecting face...";
      dlib::cv_image<dlib::bgr_pixel> cimg(faceFrame);
      std::vector<cv::Point> faceLandMarksPoints;
      // Detect faces
      if(cimg.size() <= 0)
          qDebug() << "cmg is empty";

      std::vector<dlib::rectangle> faces = detector(cimg);
      // Find the pose of each face.
      std::vector<dlib::full_object_detection> shapes;
      for (unsigned long i = 0; i < faces.size(); ++i)
          shapes.push_back(pose_model(cimg, faces[i]));

      const dlib::full_object_detection& detectedFace = shapes[0];

   if(faces.size()>0){

      for (unsigned int landmark = 0; landmark < 68; ++landmark)
      {
          faceLandMarksPoints.push_back(cv::Point((double)detectedFace.part(landmark).x(),
                                                  (double)detectedFace.part(landmark).y()));
          qDebug() << "x:"<<(double)detectedFace.part(0).y() <<",x: "<<(double)detectedFace.part(0).x() ;
       }
      return faceLandMarksPoints;

   }


return faceLandMarksPoints;


}

