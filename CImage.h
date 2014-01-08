#ifndef CIMAGE_H
#define CIMAGE_H

#include <string>
using namespace std;
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
class CImage{
    Mat m_img;
    int blur_range;

public:
    CImage();
    CImage(string,int);
    void setImg(string,int);
    Mat getImg();
    void ImgShow();
    void operator()();


};




#endif // CIMAGE_H
