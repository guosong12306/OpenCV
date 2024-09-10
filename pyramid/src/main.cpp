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
    const std::string orange_path = "../img/orange.png";
    
    //读取图像
    Mat apple = imread(apple_path);
    Mat orange = imread(orange_path);
    if(apple.empty())
    {
        std::cerr << "ERROR: unable to open the file" << std::endl;
        return -1;
    }
    
    if(orange.empty())
    {
        std::cerr << "ERROR: unable to open the file" << std::endl;
        return -1;
    }

    std::vector<Mat> gauss_apple = {apple};
    std::vector<Mat> gauss_orange = {orange};
    std::vector<Mat> laplace_apple(4);
    std::vector<Mat> laplace_orange(4);
    std::vector<Mat> laplace(4);
    
    
    //处理图像
    //制作高斯金字塔
    for(int i=1; i<4; i++)
    {
        Mat temp;
        pyrDown(gauss_apple[i-1], temp);
        gauss_apple.push_back(temp);
    }
    for(int i = 1; i<4; i++)
    {
        Mat temp;
        pyrDown(gauss_orange[i-1], temp);
        gauss_orange.push_back(temp);
    }
    //制作laplace金字塔
    for(int i=0; i<3; i++)
    {
        Mat result;
        pyrUp(gauss_apple[i+1], result);

        subtract(gauss_apple[i], result, laplace_apple[i]);
        // imshow("test", result);
        // imshow("1", gauss_apple[i]);
        // imshow("2", laplace_apple[i]);
        // waitKey(0);
        // waitKey(0);
    }
    laplace_apple[3] = gauss_apple[3];

    for(int i=0; i<3; i++)
    {
        Mat result;
        pyrUp(gauss_orange[i+1], result);
        subtract(gauss_orange[i], result, laplace_orange[i]);
    }
    laplace_orange[3] = gauss_orange[3];

    //laplace金字塔组合
    
    for(int i=0; i<4; i++)
    {
        int cols = laplace_apple[i].cols;
        int midcols = cols/2;
        Mat left = laplace_apple[i].colRange(0,midcols);
        Mat right = laplace_orange[i].colRange(midcols,cols);
        hconcat(left, right, laplace[i]);
    }
    
    //还原
    Mat last = laplace[3];
    for(int i=2; i>=0; i--)
    {
        pyrUp(last, last);
        add(last, laplace[i], last);
    }
    // Mat real;
    // int cols = apple.cols;
    // int midcols = cols/2;
    // Mat left = apple.colRange(0,midcols);
    // Mat right = orange.colRange(midcols,cols);
    // hconcat(left, right, real);
    // imshow("apple", apple);
    // imshow("orange", orange);
    // imshow("real", real);
    // imshow("last", last);
    
    //test


    Mat test = gauss_apple[2];
    Mat test1;
    Mat test2;
    pyrDown(test, test1);
    pyrUp(test1, test2);
    Mat result;
    subtract(test, test2, result);
    Mat result1,result2;
    // add(result,test2,result2);
    // pyrUp(test, test);
    // pyrUp(result2, result2);
    // pyrUp(test1, test1);
    // pyrUp(test1, test1);
    // pyrUp(result, result);
    // pyrUp(test2, test2);

        // 获取图像的尺寸
    int rows = test2.rows;
    int cols = test2.cols;

    // 遍历图像的每个像素并打印其颜色值
    for (int y = 0; y < rows; ++y)
    {
        for (int x = 0; x < cols; ++x)
        {
            // 获取像素值 (BGR格式)
            cv::Vec3b color = test2.at<cv::Vec3b>(y, x);

            // 打印颜色值
            std::cout << "Pixel at (" << x << ", " << y << "): "
                      << "B: " << static_cast<int>(color[0]) << ", "
                      << "G: " << static_cast<int>(color[1]) << ", "
                      << "R: " << static_cast<int>(color[2]) << std::endl;
        }
    }
    // imshow("g2", test);
    // imshow("result2", result2);
    // imshow("test1", test1);
    // imshow("test2", test2);
    // imshow("result", result);
    // waitKey(0);
    return 0;
}

