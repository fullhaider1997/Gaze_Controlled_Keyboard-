#include "faciallandmarkdetector.h"



FacialLandmarkDetector::~FacialLandmarkDetector(){


}

 FacialLandmarkDetector::FacialLandmarkDetector():
     FIRST_FACE(0),
    faceLandMarksPoints(68, cv::Point(2, 0))

{

     detector = dlib::get_frontal_face_detector();
     dlib::deserialize("/home/haider/Downloads/shape_predictor_68_face_landmarks.dat") >> pose_model;

}

 std::vector<cv::Point>  FacialLandmarkDetector::getFacialLandMarks() const{
    return faceLandMarksPoints;
 }

void FacialLandmarkDetector::generateLandMarkFrame(cv::Mat faceframe){


    dlib::cv_image<dlib::bgr_pixel> cimg(faceframe);

    faces = detector(cimg);


   if(faces.size() > 0) {

    for (auto single_face: faces){
        shapes.push_back(pose_model(cimg, single_face));
    }

    const dlib::full_object_detection& detectedFace = shapes[FIRST_FACE];



    for (unsigned int landmark = 0; landmark < detectedFace.num_parts(); ++landmark)
    {
        faceLandMarksPoints[landmark] = cv::Point((double)detectedFace.part(landmark).x(),
                                                  (double)detectedFace.part(landmark).y());

     }
   }





}

