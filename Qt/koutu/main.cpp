#include <iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    //显示图片
    Mat image=imread("D:/work/shuai.jpg");
    imshow("image",image);

    //转hsv格式,h(色调）s(饱和度),v(亮度)
    Mat hsv;
    cvtColor(image,hsv,COLOR_BGR2HSV);
    imshow("hsv",hsv);

    //inRange,因为背景图颜色单一，因此好对此操作，inrange将其变成白色
    //H判断是否是蓝色，S,V判断是否是亮的。
    Mat mask;
    inRange(hsv,Scalar(100,43,46),Scalar(124,255,255),mask);//输入，hsv最小值(h,s,v三个min)，hsv最大值，输出
    //Scalar只是放数字的，既可以是bgr，也可以是hsv，bgr的三个数字在hsv转换的时候就已经变了。
    imshow("mask",mask);

    //取反，由于copyTo是把后一个参数的白色拷到前一个图上，因此将前图黑的人变成白的
    bitwise_not(mask,mask);
    imshow("4",mask);

    //生成红色背景图 大小类型参考原始图片
    //#include<opencv2/opencv.hpp>调用opencv.hpp文件，文件里面有调用其他文件指令
    //然后opencv.hpp调用结束后，此文件调用了一大堆文件
    //其他文件被调用后，有某个文件里有cv，cv里有Mat，还有很多类，类里还有自己的指令
    //例如Mat.size size指令，但是Mat有个特殊的东西叫zeros
    Mat redback=Mat::zeros(image.size(),image.type());
    redback=Scalar(40,40,200);//参数为Blue,Green,Red
    imshow("5",redback);

    //拷贝
    image.copyTo(redback,mask);//copyTo是指把后一个参数，白的拷贝到前一个参数上。
    imshow("5",redback);
    waitKey(0);
    return 0;
}
//Mat,imread,imshow,waitKey,Scalar,
//cvtColor(convert color转化颜色)--输入，输出，指令
//inRange()--输入,min,max,输出
//bitwise_not()输入，输出
//Mat::zeros(创建画布)--横向尺寸，纵向尺寸
//COLOR_BGR2HSV
