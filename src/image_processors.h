#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

class ImageProcessor {
 public:
  virtual ~ImageProcessor() {}
  virtual const std::string GetProcessName() = 0;
  virtual cv::Mat ProcessImage() = 0;
};

class ShiftImage : public ImageProcessor {
 public:
  int offset_x_;
  int offset_y_;
  cv::Mat image_;
  ShiftImage(int offset_x, int offset_y, cv::Mat image)
      : offset_x_(offset_x), offset_y_(offset_y), image_(image) {}
  const std::string GetProcessName() override { return "shift image"; }
  cv::Mat ProcessImage() override {
    cv::Mat trans_mat =
        (cv::Mat_<double>(2, 3) << 1, 0, offset_x_, 0, 1, offset_y_);
    cv::warpAffine(image_, image_, trans_mat, image_.size());
    return image_;
  }
};

class GrayScaleImage : public ImageProcessor {
 public:
  cv::Mat image_;
  GrayScaleImage(cv::Mat image): image_(image) {}
  const std::string GetProcessName() override { return "gray scale image"; }
  cv::Mat ProcessImage() override {
    cv::Mat image_gray;
    cv::cvtColor(image_, image_gray, cv::COLOR_RGB2GRAY);
    return image_gray;
  }
};

class CreateImageProcessor {
 public:
  virtual ~CreateImageProcessor() {}
  virtual ImageProcessor* GetImageProcessor() = 0;
  cv::Mat process() {
    ImageProcessor* pImageProcessor = this->GetImageProcessor();
    std::cout << pImageProcessor->GetProcessName() << std::endl;
    cv::Mat result_image = pImageProcessor->ProcessImage();
    delete pImageProcessor;
    return result_image;
  }
};
