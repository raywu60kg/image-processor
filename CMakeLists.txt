cmake_minimum_required (VERSION 3.0.0)
project (image-preprocessor)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
file (GLOB source_files "./src/*.cpp")
add_executable(image-preprocessor ${source_files})

target_link_libraries(image-preprocessor ${OpenCV_LIBS} )