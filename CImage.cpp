#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "CImage.h"
#include <iostream>
#include <string>
using namespace std;
using namespace cv;



CImage::CImage()
{}
CImage::CImage(string pImg,int blur)
{
    m_img =  imread(pImg,CV_LOAD_IMAGE_UNCHANGED);
    blur_range = blur;
}
void CImage::setImg(string pImg,int blur)
{
    m_img =  imread(pImg,CV_LOAD_IMAGE_UNCHANGED);
    blur_range = blur;
}
Mat CImage::getImg()
{
    return m_img;
}

void CImage::ImgShow()
{
    namedWindow("Original image",CV_WINDOW_AUTOSIZE);
    imshow("Original image",m_img);

    if (m_img.empty())
      {
            cout << "Error no loaded a image\n";
            exit(1);
      }
    waitKey(0);

    destroyWindow("Original image");
}
void CImage::operator ()()
{
    //действия върху изображението прилагане на blur филтър

    for(int i = 0;i < blur_range; i += 2)
    {
        blur(m_img,m_img,Size(blur_range,blur_range));

    }
}

