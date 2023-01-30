#include <iostream>
#include <opencv2/opencv.hpp>

#include "./argparser.hpp"
#include "./config.hpp"
#include "./image_processors.hpp"
int main(int argc, char* argv[]) {
  Config config = getConfig(argc, argv);
  if (!config.valid) {
    return 0;
  }
  cv::Mat image = cv::imread(config.input_image_dir);
  CreateImageProcessor* create_image_processor;
  if (config.method == EShiftImage) {
    create_image_processor = new CreateShiftImageProcessor(config);
  } else if (config.method == EGrayScaleImage) {
    create_image_processor = new CreateGrayScaleImageProcessor(config);
  }
  cv::Mat result_image = ImageProcessorClient(*create_image_processor, image);
  cv::imwrite(config.output_image_dir, result_image);
}
