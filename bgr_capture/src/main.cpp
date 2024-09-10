#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>


#include <iostream>
#include <string>
#include <vector>

using namespace cv;
using namespace std;

int main(int argc, char const *argv[])
{
    VideoCapture cap(0);
    
    // 检查是否成功打开了摄像头
    if (!cap.isOpened()) {
        cerr << "Error: Could not open video capture device." << endl;
        return -1;
    }

    // 创建窗口
    namedWindow("frame", WINDOW_AUTOSIZE);
    namedWindow("mask", WINDOW_AUTOSIZE);
    namedWindow("res", WINDOW_AUTOSIZE);

    while (true) {
        Mat frame;
        Mat hsv;
        Mat mask;
        Mat res;

        // 捕获每一帧
        cap >> frame;

        // 检查是否成功捕获了帧
        if (frame.empty()) {
            cerr << "Error: Could not grab a frame." << endl;
            break;
        }

        // 转换到 HSV 色彩空间
        cvtColor(frame, hsv, COLOR_BGR2HSV);

        // 设定橙色的阈值
        Scalar lower_blue(11, 43, 46);
        Scalar upper_blue(25, 255, 255);

        // 根据阈值构建掩模
        inRange(hsv, lower_blue, upper_blue, mask);

        // 对原图像和掩模进行位运算
        bitwise_and(frame, frame, res, mask);

        // 显示图像
        imshow("frame", frame);
        imshow("mask", mask);
        imshow("res", res);

        // 等待按键事件（5ms）
        int k = waitKey(5) & 0xFF;
        if (k == 27) {  // 按下 ESC 键退出
            break;
        }
    }

    // 释放摄像头并关闭窗口
    cap.release();
    destroyAllWindows();


    return 0;
}

