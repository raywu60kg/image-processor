
#include <iostream>
#include <opencv2/opencv.hpp>

#include "./image_processors.h"
#include "./argparser.h"

int main(int argc, char* argv[]) {
  if (cmdOptionExists(argv, argv + argc, "-h")) {
    std::cout << "Hello, world!\n";
  }
  char* filename = getCmdOption(argv, argv + argc, "-f");

  if (filename) {
    std::cout << filename << std::endl;
  }
  cv::Mat image;
  image = cv::imread(filename);
  cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
  cv::imshow("Display Image", image);
  cv::waitKey(0);
  return 0;
}
