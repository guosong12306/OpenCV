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

    Mat apple = imread(apple_path);
    Mat orange = imread(orange_path);
    if (apple.empty() || orange.empty()) 
    {
        std::cerr << "Error loading images!" << std::endl;
        return -1;
    }
    
    int rows = apple.rows/2;
    int cols = apple.cols/2;

    Mat roi = orange(Rect(0,0,cols,rows));
    Mat logo = apple(Rect(0,0,cols,rows));
    Mat logo_gray;
    cvtColor(logo, logo_gray, COLOR_BGR2GRAY);
    Mat mask, mask_inv;
    threshold(logo_gray, mask, 105, 255, THRESH_BINARY);
    bitwise_not(mask, mask_inv);
    
    Mat orange_bg;
    bitwise_and(roi, roi, orange_bg, mask);
    Mat apple_fg;
    bitwise_and(logo, logo, apple_fg, mask_inv);

    Mat dst;
    add(orange_bg, apple_fg, dst);

    dst.copyTo(orange);
    imshow("orange",orange);
    // imshow("logo_gray", logo_gray); 
    // imshow("mask_inv", mask_inv);

    waitKey(0);
    return 0;
}

