#include "utils.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;

Mat loadImage(const string& imagePath) {
    Mat image = imread(imagePath, IMREAD_COLOR);
    if (image.empty()) {
        cerr << "Error: Could not load image at " << imagePath << endl;
    }
    return image;
}

void displayImage(const string& windowName, const Mat& image) {
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow(windowName, image);
    waitKey(0);
    destroyWindow(windowName);
}

double measureTime(function<void()> func) {
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count();
}