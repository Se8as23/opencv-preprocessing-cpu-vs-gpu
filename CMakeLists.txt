cmake_minimum_required(VERSION 3.10)
project(OpenCV_Preprocessing_CPU_vs_GPU)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
find_package(CUDA REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} include)

set(SOURCES
    src/main.cpp
    src/cpu_pipeline.cpp
    src/gpu_pipeline.cpp
    src/utils.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} ${CUDA_LIBRARIES} stdc++fs)