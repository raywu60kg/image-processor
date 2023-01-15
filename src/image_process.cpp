#include "image_process.h"

#include <opencv2/opencv.hpp>
#include <string>
// class ImageProcess{
//  public:
//     virtual std::string GetProcessName() = 0;
//     virtual cv::Mat ProcessImage() = 0;
// };

// shift image
// Example:
// Reference:
// https://stackoverflow.com/questions/19068085/shift-image-content-with-opencv
// class ShiftImage:public ImageProcess{
//  public:
//     int offset_x;
//     int offset_y;
//     ShiftImage(int offset_x_, int offset_y_) {
//         offset_x = offset_x_;
//         offset_x = offset_y_;
//     }
//     std::string GetProcessName() override {
//         return "shift image";
//     }
//     cv::Mat ProcessImage(cv::Mat image){
//         cv::Mat trans_mat = (cv::Mat_<double>(2, 3) << 1, 0, offset_x, 0, 1,
//         offset_y); cv::warpAffine(image, image, trans_mat, image.size());
//         return image;
//     }
// };
ShiftImage::ShiftImage(int offset_x_, int offset_y_)
    : offset_x(offset_x_), offset_y(offset_y_) {}
const std::string ShiftImage::GetProcessName() { return "shift image"; }
cv::Mat ShiftImage::ProcessImage(cv::Mat image) {
  cv::Mat trans_mat =
      (cv::Mat_<double>(2, 3) << 1, 0, offset_x, 0, 1, offset_y);
  cv::warpAffine(image, image, trans_mat, image.size());
  return image;
}
