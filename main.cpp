#include <iostream>
#include <vector>
#include <iterator>
#include "CImage.h"
#include "CIplAdd.h"
#include <string>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/cstdint.hpp>
#include <boost/thread.hpp>


using namespace  std;

const int cFilt = 64;





int main()
{


    //дефиниране на указател за динамичен  масив нужен ни за циклите/при различен брой процесори
    boost::thread *t;

    // определяне на броя на процесори на системата
    int cpuNum = boost::thread::hardware_concurrency();

    t = new boost::thread[cpuNum];

    // дефинираме вектор от вектор от обекти от тип CImage

    vector <CImage> mImg;

    // определяме каква стойност на филтъра  се пада върху един процесор (при стойност на филтъра 64)
    int calc = cFilt / cpuNum;



    // разпределяне на задачта върху всички процесори
    for (int i = 0; i <  cpuNum; i++)
    {
        CImage buff("img.jpg",calc);

         t[i] = boost::thread(buff);

        //запълваме вектора от обекти
        mImg.push_back(buff);

    }

    vector <CImage>::iterator iter = mImg.begin();
    Mat chImg,add_img;
    IplAdd oAdd;



    // "събиране" на получените резултати
    for(int i = 0; i < cpuNum; i++)
    {
        t[i].join();
        chImg = iter[i].getImg();
        if(i == 0)
        {
            //initial
            add_img = iter[i].getImg();
        }

        add_img = oAdd.showTwoImages(chImg,add_img);


    }

    //освобождаваме заетата памет
    delete[] t;
    cout << "Complete\n";
    namedWindow("Return image",CV_WINDOW_AUTOSIZE);
    imshow("Return image",add_img);
    waitKey(0);

    destroyWindow("Return image");


    return 0;
}
