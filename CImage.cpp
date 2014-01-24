#include "CImage.h"
#include "dialog.h"
#include "QProgressDialog"


#include <iostream>
#include <string>



#include <omp.h> 		// omp library implementation multithreading
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace std;
using namespace cv;

//  default constructor

CImage::CImage() {}


// constructor with parameters

CImage::CImage(const string& pImg,const int& blur)
{
    setImg(pImg,blur);
}

// set image & blur kernel

void CImage::setImg(const string& pImg,const int& blur)
{

    m_img =  imread(pImg,CV_LOAD_IMAGE_UNCHANGED);
    if(m_img.empty())
      {  //Message box error
        check.messageBox("Image no load");
        exit(1);
      }
    blur_range = blur;
}

// set blur kernel

void CImage::setBlur(const int& blur)
{
    blur_range = blur;
}

// set image

void CImage::setPath(const string& pImg)
{
    m_img =  imread(pImg,CV_LOAD_IMAGE_UNCHANGED); 		// Mat m_img read imread parameters first file name, second specifies the format
    if(m_img.empty())
        //Message box error
        check.messageBox("Image no load");
        exit(1);
}

// return a Mat m_img

Mat CImage::getImg() const
{
    return m_img;
}

//  method for image show 

int CImage::ImgShow()
{


    if (m_img.empty())
      {
        //Message box error
        check.messageBox("Image empty");
            exit(1);
      }

        namedWindow("Original image", CV_WINDOW_AUTOSIZE);  // Creates a window first parameter window name, second flags of the window
        imshow("Original image",m_img);
        waitKey(0);
        return 0;
   
    destroyWindow("Original image");
}
void CImage::bluringImg(Dialog *w)
{

    Dialog *th = w;


	// progress bar 
    int numTasks = 100;
       QProgressDialog progress("Task in progress...", "Cancel", 0, numTasks, th);
       progress.setWindowModality(Qt::WindowModal);

   
    for(int i = 1;i < blur_range; i += 2)
    {

		// Calculating the percentage for the current step
		
        int persent;
        float ratio = (i)/(float)blur_range;
        persent = ratio*100;

         //action on the application of image blur filter
        // ##pragma omp parallel directive explicitly instructs the compiler to parallelize the chosen block of code
        #pragma omp parallel
            {blur(m_img,m_img,Size(i,i));}		// Bluring  an image first parameter a source, second output image, Size kernel size 


        progress.setValue(persent);
        if (progress.wasCanceled())
        {exit(1);}


    }
    progress.setValue(numTasks);

}

