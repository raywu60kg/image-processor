#pragma once
#include <string>
#include <unordered_set>
enum ImageProcessMethod { EDefault, EShiftImage, EGrayScaleImage };

static std::unordered_map<std::string, ImageProcessMethod>
    IMAGE_PROCESS_MAPPING_TABLE = {{"shift_image", EShiftImage},
                                   {"gray_scale_image", EGrayScaleImage}};
static std::unordered_set<std::string> VALID_ARGUMENT{
    "--offset_x", "--offset_y", "--method", "--input_image_dir",
    "--output_image_dir"};
class Config {
 public:
  bool valid = true;
  int offset_x = 0;
  int offset_y = 0;
  ImageProcessMethod method = EDefault;
  std::string input_image_dir = "./image.png";
  std::string output_image_dir = "./result_image.png";
};
