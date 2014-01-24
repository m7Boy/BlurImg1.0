#ifndef CIMAGE_H
#define CIMAGE_H

#include "dialog.h"
#include <QDialog>


#include <string>


#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;


class CImage{
    Mat m_img;
    int blur_range;
    Dialog check;

public:
    CImage();
    CImage(const string&,const int&);
    void setImg(const string&,const int&);
    void setBlur(const int&);
    void setPath(const string&);
    Mat getImg() const;
    int ImgShow();
    void bluringImg(Dialog*);


};




#endif // CIMAGE_H
