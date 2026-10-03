#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    //调用摄像头,得到持续输入的图片
    //循环抠图
    Mat background=imread("/home/cjx/code/Qt/background4.jpg");
    Mat hide,hsv,mask,umask,bkmask,bkumask,plus,mask1;
    VideoCapture capture(0);//参数为0时，调用摄像头
    while(capture.read(hide)==1)
    {
          cvtColor(hide,hsv,COLOR_BGR2HSV);
          inRange(hsv,Scalar(46,43,46),Scalar(77,255,255),mask);//mask=布区域
          bitwise_not(mask,umask);//umask=非布区域
          bkmask=0;
          bkumask=0;
          bitwise_and(background,background,bkmask,mask);//布区域给到背景
          bitwise_and(hide,hide,bkumask,umask);//非布区域给到此刻
          add(bkumask,bkmask,plus);//
          imshow("plus",plus);
          if (waitKey(5) == 'q')   // 按 q 退出
                  break;
          waitKey(30);
    }
    waitKey(0);
    return 0;
}
