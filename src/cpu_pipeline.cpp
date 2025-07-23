#include "cpu_pipeline.hpp"
#include <opencv2/opencv.hpp>

using namespace cv;

void gaussianSmoothing(const Mat& input, Mat& output, int kernelSize, double sigma) {
    GaussianBlur(input, output, Size(kernelSize, kernelSize), sigma);
}

void morphologicalOperations(const Mat& input, Mat& output, int operation, int kernelSize) {
    Mat element = getStructuringElement(MORPH_RECT, Size(kernelSize, kernelSize));
    if (operation == 0) {
        erode(input, output, element);
    } else if (operation == 1) {
        dilate(input, output, element);
    }
}

void cannyEdgeDetection(const Mat& input, Mat& output, double threshold1, double threshold2) {
    Canny(input, output, threshold1, threshold2);
}

void histogramEqualization(const Mat& input, Mat& output) {
    if (input.channels() == 1) {
        equalizeHist(input, output);
    } else {
        std::vector<Mat> channels;
        split(input, channels);
        for (size_t i = 0; i < channels.size(); i++) {
            equalizeHist(channels[i], channels[i]);
        }
        merge(channels, output);
    }
}

cv::Mat processImageCPU(const cv::Mat& image) {
    cv::Mat gray, blurred, morph, edges, histEq;

    // Convertir a escala de grises
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::imshow("CPU - Gray", gray);

    // Suavizado Gaussiano
    gaussianSmoothing(gray, blurred, 5, 1.5);
    cv::imshow("CPU - Gaussian Blur", blurred);

    // Operación morfológica (ejemplo: erosión)
    morphologicalOperations(blurred, morph, 0, 3); // 0: erode, 1: dilate
    cv::imshow("CPU - Morphology", morph);

    // Detección de bordes (Canny)
    cannyEdgeDetection(morph, edges, 50, 150);
    cv::imshow("CPU - Canny Edges", edges);

    // Ecualización del histograma
    histogramEqualization(edges, histEq);
    cv::imshow("CPU - Histogram Equalization", histEq);

    return histEq;
}

// Solo funciones CPU aquí