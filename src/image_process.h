#pragma once
#include <opencv2/opencv.hpp>
#include <string>
class ImageProcess {
 public:
  virtual const std::string GetProcessName() = 0;
  virtual cv::Mat ProcessImage(cv::Mat image) = 0;
};

class ShiftImage : public ImageProcess {
 public:
  int offset_x;
  int offset_y;
  ShiftImage(int offset_x_, int offset_y_);
  const std::string GetProcessName() override;
  cv::Mat ProcessImage(cv::Mat image) override;
};