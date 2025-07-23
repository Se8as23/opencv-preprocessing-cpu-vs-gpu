#ifndef GPU_PIPELINE_HPP
#define GPU_PIPELINE_HPP

#include <opencv2/opencv.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/cudaarithm.hpp>
#include <opencv2/cudafeatures2d.hpp>

class GPUPipeline {
public:
    static cv::cuda::GpuMat gaussianSmoothing(const cv::cuda::GpuMat& input, int kernelSize, double sigmaX);
    static cv::cuda::GpuMat morphologicalErosion(const cv::cuda::GpuMat& input, int kernelSize);
    static cv::cuda::GpuMat morphologicalDilation(const cv::cuda::GpuMat& input, int kernelSize);
    static cv::cuda::GpuMat cannyEdgeDetection(const cv::cuda::GpuMat& input, double threshold1, double threshold2);
    static cv::cuda::GpuMat histogramEqualization(const cv::cuda::GpuMat& input);
};

#endif // GPU_PIPELINE_HPP