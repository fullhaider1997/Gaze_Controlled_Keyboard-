#include "faciallandmarkdetector.h"


 FacialLandmarkDetector::FacialLandmarkDetector():
    faceLandMarksPoints(68, cv::Point(2, 0))
{

     detector = dlib::get_frontal_face_detector();
     dlib::deserialize("/home/haider/Downloads/shape_predictor_68_face_landmarks.dat") >> pose_model;

}

 std::vector<cv::Point> FacialLandMarkDetector::getFacialLandMarks() const{




 }

void FacialLandmarkDetector::generateLandMarkFrame(cv::Mat faceframe){



    dlib::cv_image<dlib::bgr_pixel> cimg(faceframe);

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





}

