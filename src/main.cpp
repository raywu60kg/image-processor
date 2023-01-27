#include <iostream>
#include <opencv2/opencv.hpp>

#include "./argparser.h"
#include "./image_processors.h"

int main(int argc, char* argv[]) {
  Config config = getConfig(argc, argv);
  std::cout << config.offset_x << std::endl;
  //   cv::Mat image;
  //   image = cv::imread(filename);
  //   cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
  //   cv::imshow("Display Image", image);
  //   cv::waitKey(0);
  //   cv::imwrite("test.jpg", image);
}
