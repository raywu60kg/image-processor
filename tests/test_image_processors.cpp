#include <gtest/gtest.h>

#include <opencv2/opencv.hpp>

#include "../src/image_processors.h"
// Reference:
// https://stackoverflow.com/questions/9905093/how-to-check-whether-two-matrices-are-identical-in-opencv
TEST(ShiftImageTest, BasicAssertions) {
  cv::Mat a = (cv::Mat_<double>(2, 2) << 1, 1, 1, 1);
  cv::Mat b = (cv::Mat_<double>(2, 2) << 0, 0, 0, 1);
  // Get a matrix with non-zero values at points where the
  // two matrices have different valuesß

  ShiftImage shift_image(1, 1);
  cv::Mat c = shift_image.ProcessImage(a);
  cv::Mat diff = c != b;
  // Equal if no elements disagree
  bool eq = cv::countNonZero(diff) == 0;
  EXPECT_EQ(eq, true);
}

TEST(GrayScaleImageTest, BasicAssertions) {
  cv::Mat a(2, 2, CV_8UC3, cv::Scalar(255, 255, 255));
  GrayScaleImage gray_scale_image;
  cv::Mat b = gray_scale_image.ProcessImage(a);
  EXPECT_EQ(b.channels(), 1);
}
