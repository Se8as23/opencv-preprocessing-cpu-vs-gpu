#ifndef OPENCV_PREPROCESSING_CPU_VS_GPU_UTILS_HPP
#define OPENCV_PREPROCESSING_CPU_VS_GPU_UTILS_HPP

#include <opencv2/opencv.hpp>
#include <string>

void loadImage(const std::string& imagePath, cv::Mat& image);
void displayImage(const std::string& windowName, const cv::Mat& image);
double measureTime(std::function<void()> func);

#endif // OPENCV_PREPROCESSING_CPU_VS_GPU_UTILS_HPP