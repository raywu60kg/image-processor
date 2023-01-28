#pragma once
#include <algorithm>
#include <iostream>
#include <string>

#include "./config.h"

bool cmdOptionExists(char** begin, char** end, const std::string& option) {
  return std::find(begin, end, option) != end;
}
void displayHelp() { std::cout << "hello" << std::endl; }

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
