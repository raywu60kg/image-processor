#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

#include "./config.h"

class ImageProcessor {
 public:
  virtual ~ImageProcessor() {}
  virtual const std::string GetProcessName() = 0;
  virtual cv::Mat ProcessImage(cv::Mat image) = 0;
};

class ShiftImage : public ImageProcessor {
 public:
  int offset_x_;
  int offset_y_;
  ShiftImage(int offset_x, int offset_y)
      : offset_x_(offset_x), offset_y_(offset_y) {}
  const std::string GetProcessName() override { return "shift image"; }
  cv::Mat ProcessImage(cv::Mat image) override {
    cv::Mat trans_mat =
        (cv::Mat_<double>(2, 3) << 1, 0, offset_x_, 0, 1, offset_y_);
    cv::warpAffine(image, image, trans_mat, image.size());
    return image;
  }
};

class GrayScaleImage : public ImageProcessor {
 public:
  const std::string GetProcessName() override { return "gray scale image"; }
  cv::Mat ProcessImage(cv::Mat image) override {
    cv::Mat image_gray;
    cv::cvtColor(image, image_gray, cv::COLOR_RGB2GRAY);
    return image_gray;
  }
};

class CreateImageProcessor {
 public:
  virtual ImageProcessor* GetImageProcessor() = 0;
  cv::Mat process(cv::Mat image) {
    ImageProcessor* pImageProcessor = this->GetImageProcessor();
    std::cout << pImageProcessor->GetProcessName() << std::endl;
    cv::Mat result_image = pImageProcessor->ProcessImage(image);
    delete pImageProcessor;
    return result_image;
  }
};

class CreateShiftImageProcessor : public CreateImageProcessor {
 private:
  int offset_x;
  int offset_y;

 public:
  CreateShiftImageProcessor(const Config& config) {
    offset_x = config.offset_x;
    offset_y = config.offset_y;
  }
  ImageProcessor* GetImageProcessor() override {
    return new ShiftImage(offset_x, offset_y);
  }
};

class CreateGrayScaleImageProcessor : public CreateImageProcessor {
 public:
  CreateGrayScaleImageProcessor(const Config& config) {}
  ImageProcessor* GetImageProcessor() override { return new GrayScaleImage(); }
};

cv::Mat ImageProcessorClient(CreateImageProcessor& image_processor,
                             cv::Mat image) {
  return image_processor.process(image);
}
