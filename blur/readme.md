# 图像平滑
### 作用
去除噪音，其实就是去除图像中的高频成分（比如：噪音，边界）。
### 原理
用卷积核与原图像像素矩阵做卷积
### 常见的几种模糊方式
- 均值模糊
    - 用卷积框覆盖区域所有像素的平均值来代替中心元素
    ``` c
    // 应用均值模糊,第三个参数为核大小
    cv::Mat blur;
    cv::blur(apple, blur, cv::Size(5, 5));
    ```
- 高斯模糊
    - 现在把卷积核换成高斯核（简单来说，方框不变，将原来每个方框的值是
相等的，现在里面的值是符合高斯分布的，方框中心的值最大，其余方框根据
距离中心元素的距离递减，构成一个高斯小山包
    ``` c
    // 应用高斯模糊,第四个参数为标准差
    cv::Mat blur;
    cv::GaussianBlur(apple, blur, cv::Size(5, 5), 0);
    // 高斯模糊源函数
    cv::GaussianBlur(
    src,               // 输入图像
    dst,               // 输出图像
    cv::Size(5, 5),    // 高斯核大小，必须为奇数
    1.0,               // sigmaX
    1.0,               // sigmaY (为0时自动设置为sigmaX)
    cv::BORDER_DEFAULT // 边界处理方式
    );
    ```
- 中值模糊
    - 用与卷积框对应像素的中值来替代中心像素的值
    ``` c
    // 应用中值滤波
    cv::Mat median;
    cv::medianBlur(img, median, 5);  // 5是滤波器的内核大小，必须是奇数
    // 中值滤波源函数
    cv::medianBlur(
    cv::InputArray src,       // 输入图像
    cv::OutputArray dst,      // 输出图像
    int ksize                 // 内核大小，必须是奇数
    );
    ```
- 双边滤波
    - 双边滤波在同时使用空间高斯权重和灰度值相似性高斯权重。空间高斯函
数确保只有邻近区域的像素对中心点有影响，灰度值相似性高斯函数确保只有
与中心像素灰度值相近的才会被用来做模糊运算。所以这种方法会确保边界不
会被模糊掉，因为边界处的灰度值变化比较大。
    ```c
    // 双边滤波源函数
    void cv::bilateralFilter(
    cv::InputArray src,       // 输入图像
    cv::OutputArray dst,      // 输出图像
    int d,                    // 邻域直径
    double sigmaColor,        // 颜色空间的标准差
    double sigmaSpace         // 坐标空间的标准差
    );
    // 应用双边滤波
    cv::Mat blur;
    int d = 9;               // 邻域直径
    double sigmaColor = 75; // 颜色空间的标准差
    double sigmaSpace = 75; // 坐标空间的标准差
    cv::bilateralFilter(img, blur, d, sigmaColor, sigmaSpace);
    ```

