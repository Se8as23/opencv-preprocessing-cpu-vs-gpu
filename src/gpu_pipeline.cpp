#include "gpu_pipeline.hpp"
#include <opencv2/cudaarithm.hpp>
#include <opencv2/cudafilters.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/cudawarping.hpp>
#include <opencv4/opencv2/highgui.hpp>

using namespace cv;
using namespace cv::cuda;

void gaussianSmoothing(const GpuMat& input, GpuMat& output, int kernelSize, double sigma) {
    Ptr<cuda::Filter> gaussianFilter = cuda::createGaussianFilter(input.type(), input.type(), Size(kernelSize, kernelSize), sigma);
    gaussianFilter->apply(input, output);
}

void morphologicalOperations(const GpuMat& input, GpuMat& output, int operation, int kernelSize) {
    Mat kernel = getStructuringElement(MORPH_RECT, Size(kernelSize, kernelSize));
    Ptr<cuda::Filter> morphFilter = cuda::createMorphologyFilter(operation, input.type(), kernel);
    morphFilter->apply(input, output);
}

void cannyEdgeDetection(const GpuMat& input, GpuMat& output, double threshold1, double threshold2) {
    Ptr<cuda::CannyEdgeDetector> canny = cuda::createCannyEdgeDetector(threshold1, threshold2);
    canny->detect(input, output);
}

void histogramEqualization(const GpuMat& input, GpuMat& output) {
    cuda::equalizeHist(input, output);
}

cv::cuda::GpuMat processImageGPU(const cv::cuda::GpuMat& image) {
    cv::cuda::GpuMat gray, blurred, morph, edges, histEq;

    // Convertir a escala de grises
    cv::cuda::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::Mat grayMat;
    gray.download(grayMat);
    cv::imshow("GPU - Gray", grayMat);

    // Suavizado Gaussiano
    gaussianSmoothing(gray, blurred, 5, 1.5);
    cv::Mat blurredMat;
    blurred.download(blurredMat);
    cv::imshow("GPU - Gaussian Blur", blurredMat);

    // Operación morfológica (ejemplo: erosión)
    morphologicalOperations(blurred, morph, 0, 3); // 0: erode, 1: dilate
    cv::Mat morphMat;
    morph.download(morphMat);
    cv::imshow("GPU - Morphology", morphMat);

    // Detección de bordes (Canny)
    cannyEdgeDetection(morph, edges, 50, 150);
    cv::Mat edgesMat;
    edges.download(edgesMat);
    cv::imshow("GPU - Canny Edges", edgesMat);

    // Ecualización del histograma
    histogramEqualization(edges, histEq);
    cv::Mat histEqMat;
    histEq.download(histEqMat);
    cv::imshow("GPU - Histogram Equalization", histEqMat);

    return histEq;
}

// Solo funciones GPU aquí