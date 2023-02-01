#pragma once
#include <algorithm>
#include <iostream>
#include <string>

#include "./config.hpp"

bool cmdOptionExists(char** begin, char** end, const std::string& option) {
  return std::find(begin, end, option) != end;
}
// reference: http://docopt.org/
void displayHelp() {
  std::cout << "Image processor." << std::endl;
  std::cout << "\n" << std::endl;
  std::cout << "Usags:" << std::endl;
  std::cout << "  image-processor --help" << std::endl;
  std::cout << "  image-processor --method shift_image --input_image_dir <intput image directory> [--output_image_dir <output image directory>] [--offset_x=<x>] [--offset_y=<y>]"<< std::endl;
  std::cout << "  image-processor --method grayscale_image --input_image_dir <intput image directory> [--output_image_dir <output image directory>]" << std::endl;
  std::cout << "\n" << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "  --help                    Display the description." << std::endl;
  std::cout << "  --method grayscale_image  Convert given image to grayscale image." << std::endl;
  std::cout << "  --method shift_image      Shift given image." << std::endl;
  std::cout << "  --input_image_dir         directory of input image." << std::endl;
  std::cout << "  --output_image_dir        directory of output image [default: ./result_image.png]." << std::endl;
  std::cout << "  --offset_x                Shift given image on x-axis by given number of pixels [default: 0]." << std::endl;
  std::cout << "  --offset_y                Shift given image on y-axis by given number of pixels [default: 0]." << std::endl;
}

Config getConfig(int argc, char* argv[]) {
  Config config;
  if (cmdOptionExists(argv, argv + argc, "--help")) {
    displayHelp();
    config.valid = false;
    return config;
  }
  if (!cmdOptionExists(argv, argv + argc, "--method")) {
    config.valid = false;
    std::cout << "You have to put the method parameter." << std::endl;
    return config;
  }

  int idx = 1;
  while (idx < argc) {
    if (VALID_ARGUMENT.find(argv[idx]) != VALID_ARGUMENT.end()) {
      if (strcmp(argv[idx], "--offset_x") == 0) {
        config.offset_x = std::stoi(argv[idx + 1]);
      }
      if (strcmp(argv[idx], "--offset_y") == 0) {
        config.offset_y = std::stoi(argv[idx + 1]);
      }
      if (strcmp(argv[idx], "--method") == 0) {
        if (IMAGE_PROCESS_MAPPING_TABLE.find(argv[idx + 1]) !=
            IMAGE_PROCESS_MAPPING_TABLE.end()) {
          config.method = IMAGE_PROCESS_MAPPING_TABLE[argv[idx + 1]];
        } else {
          std::cout << "Invalid method: " << argv[idx] << std::endl;
          config.valid = false;
          return config;
        }
      }
      if (strcmp(argv[idx], "--input_image_dir") == 0) {
        config.input_image_dir = argv[idx + 1];
      }
      if (strcmp(argv[idx], "--output_image_dir") == 0) {
        config.input_image_dir = argv[idx + 1];
      }
      idx += 2;
    } else {
      std::cout << "Invalid arg: " << argv[idx] << std::endl;
      config.valid = false;
      return config;
    }
  }
  return config;
}
