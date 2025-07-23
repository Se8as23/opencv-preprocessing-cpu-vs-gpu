#ifndef UTILS_HPP
#define UTILS_HPP

#include <opencv2/opencv.hpp>
#include <string>
#include <chrono>

cv::Mat loadImage(const std::string& imagePath);
void displayImage(const std::string& windowName, const cv::Mat& image);
double measureTime(std::function<void()> func);

#endif // UTILS_HPP