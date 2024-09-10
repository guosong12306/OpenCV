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

    // 缩放扩展
    // Mat res1, res2, res3;
    // resize(apple, res1, Size(), 2, 2, INTER_CUBIC);
    // resize(apple, res2, Size(), 2, 2, INTER_LINEAR);
    // resize(apple, res3, Size(), 0.5, 0.5, INTER_AREA);

    // imshow("res1",res1);
    // imshow("res2",res2);
    // imshow("res3",res3);

    //平移变换
    // Mat M = (Mat_<double>(2,3)<<1.0,0.0,100,
    //                             0.0,1.0,0);
    // Mat res;
    // Size dsize(apple.cols,apple.rows);
    // warpAffine(apple, res, M, dsize);
    // imshow("apple",apple);
    // imshow("res",res);

    //旋转变换
    // int rows = apple.rows;
    // int cols = apple.cols;

    // Point2f center(cols/2.0, rows/2.0);
    // double angle = 45.0;
    // double scale = 0.6;
    // Mat M = getRotationMatrix2D(center, angle, scale);
    // Mat dst;
    // warpAffine(apple, dst, M, Size(cols, rows));
    // imshow("apple", apple);
    // imshow("dst", dst);

    //透视变换
    // 获取图像的行、列和通道数
    // int rows = apple.rows;
    // int cols = apple.cols;
    // int ch = apple.channels();

    // // 定义源图像和目标图像中的四个点
    // std::vector<cv::Point2f> pts1 = { cv::Point2f(56, 65), cv::Point2f(368, 52),
    //                                   cv::Point2f(28, 387), cv::Point2f(389, 390) };
    // std::vector<cv::Point2f> pts2 = { cv::Point2f(0, 0), cv::Point2f(512, 0),
    //                                   cv::Point2f(0, 512), cv::Point2f(512, 512) };

    // // 计算透视变换矩阵
    // cv::Mat M = cv::getPerspectiveTransform(pts1, pts2);

    // // 应用透视变换
    // cv::Mat dst;
    // cv::warpPerspective(apple, dst, M, cv::Size(300, 300));

    // // 显示图像
    // cv::imshow("Input", apple);
    // cv::imshow("Output", dst);



    
    waitKey(0);
    return 0;
}

