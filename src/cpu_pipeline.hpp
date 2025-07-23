#ifndef CPU_PIPELINE_HPP
#define CPU_PIPELINE_HPP

#include <opencv2/opencv.hpp>

class CPUPipeline {
public:
    static cv::Mat gaussianSmoothing(const cv::Mat& input, int kernelSize, double sigma);
    static cv::Mat morphologicalErosion(const cv::Mat& input, int kernelSize);
    static cv::Mat morphologicalDilation(const cv::Mat& input, int kernelSize);
    static cv::Mat cannyEdgeDetection(const cv::Mat& input, double threshold1, double threshold2);
    static cv::Mat histogramEqualization(const cv::Mat& input);
};

cv::Mat processImageCPU(const cv::Mat& image);

#endif // CPU_PIPELINE_HPP