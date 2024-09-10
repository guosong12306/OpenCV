#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <string>
#include <vector>

using namespace cv;

int main(int argc, char const *argv[])
{
    const std::string apple_path = "../img/apple.jpg";
    
    //读取图像
    Mat apple = imread(apple_path);
    if(apple.empty())
    {
        std::cerr << "ERROR: unable to open the file" << std::endl;
        return -1;
    }

    // // 应用均值模糊
    // cv::Mat blur;
    // cv::blur(apple, blur, cv::Size(5, 5));
     
    // // 应用高斯模糊
    // cv::Mat blur;
    // cv::GaussianBlur(apple, blur, cv::Size(5, 5), 0);

    // 应用中值模糊
    
    // 应用双边滤波

    // 显示图像
    // cv::imshow("Original", apple);
    // cv::imshow("Averaging", blur);


    
    waitKey(0);
    return 0;
}

