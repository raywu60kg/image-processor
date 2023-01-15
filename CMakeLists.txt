cmake_minimum_required (VERSION 3.0.0)
project (image-preprocessor)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
file (GLOB source_files "./src/*.cpp" "./src/*.h")
add_executable(${PROJECT_NAME} ${source_files})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} GTest::gtest_main)


# testing
enable_testing()
add_executable(
  unitTests
  tests/hello_test.cpp
  tests/test_image_process.cpp
  src/image_process.h
  src/image_process.cpp
  # ${source_files}
  # ${test_files}
)

# include_directories( ${source_files} )
target_link_libraries(
  unitTests
  GTest::gtest_main
  ${OpenCV_LIBS}
)

include(GoogleTest)
gtest_discover_tests(unitTests)
