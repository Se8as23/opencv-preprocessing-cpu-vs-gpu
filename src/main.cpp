#include <opencv2/opencv.hpp>
#include <opencv2/cudaarithm.hpp>
#include <opencv2/cudafilters.hpp>
#include <opencv2/cudafeatures2d.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "cpu_pipeline.hpp"
#include "gpu_pipeline.hpp"
#include "utils.hpp"
#include <filesystem>

namespace fs = std::filesystem;

void processImage(const std::string& imagePath) {
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cerr << "Error: Unable to load image: " << imagePath << std::endl;
        return;
    }

    // CPU Processing
    cv::Mat cpuResult;
    auto cpuStart = std::chrono::high_resolution_clock::now();
    cpuResult = processImageCPU(image);
    auto cpuEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> cpuDuration = cpuEnd - cpuStart;

    // GPU Processing
    cv::cuda::GpuMat gpuImage, gpuResult;
    gpuImage.upload(image);
    auto gpuStart = std::chrono::high_resolution_clock::now();
    gpuResult = processImageGPU(gpuImage);
    auto gpuEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> gpuDuration = gpuEnd - gpuStart;

    // Download GPU result
    cv::Mat gpuResultMat;
    gpuResult.download(gpuResultMat);

    // Display results
    cv::imshow("Original Image", image);
    cv::imshow("CPU Result", cpuResult);
    cv::imshow("GPU Result", gpuResultMat);
    std::cout << "CPU Processing Time: " << cpuDuration.count() << " seconds" << std::endl;
    std::cout << "GPU Processing Time: " << gpuDuration.count() << " seconds" << std::endl;

    cv::waitKey(0);
}

void processImagesInFolder(const std::string& folderPath) {
    std::vector<std::string> imagePaths;
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            std::string ext = entry.path().extension().string();
            if (ext == ".jpg" || ext == ".png" || ext == ".jpeg" || ext == ".bmp" || ext == ".tiff") {
                imagePaths.push_back(entry.path().string());
            }
        }
    }

    for (const auto& imagePath : imagePaths) {
        std::cout << "Processing: " << imagePath << std::endl;
        processImage(imagePath);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <image_folder>" << std::endl;
        return -1;
    }

    std::string folderPath = argv[1];
    processImagesInFolder(folderPath);

    return 0;
}