#ifndef CIPLADD_H
#define CIPLADD_H
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"

class IplAdd{
    Mat totalImage;
  public:
    IplAdd(){}
    Mat showTwoImages(Mat imageOne, Mat imageTwo)
    {

        add(imageOne,imageTwo,totalImage);

       return totalImage;

    }
};

#endif // CIPLADD_H
