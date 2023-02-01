# masOS installation
Installation guide for MacOS(x64 or arm)

## 1. Install cmake
[check here](https://cmake.org/install/)

## 2. Install opencv
```bash
git clone https://github.com/opencv/opencv.git


mkdir build && cd build

cmake ../opencv/ .


## remove arch -arm64 for x64 MacOS on the following commands

arch -arm64 cmake ../opencv/ -DWITH_QT=OFF -DWITH_OPENGL=OFF -DFORCE_VTK=OFF -DWITH_TBB=OFF -DWITH_GDAL=OFF -DWITH_XINE=OFF -DBUILD_EXAMPLES=OFF -DBUILD_ZLIB=OFF -DBUILD_TESTS=OFF .

arch -arm64 sudo make -j 4

arch -arm64 sudo make install
```

Reference: https://gist.github.com/nucliweb/b2a234c673221af5ec24508da7d8b854



## 3. Install clang
[check here](https://www.ics.uci.edu/~pattis/common/handouts/macclion/clang.html)

## 4. Clone this repo
```
git clone https://github.com/raywu60kg/image-processor.git && cd "$_"
```

## 5. Build project by cmake
```
mkdir -p build
cmake -B ./build -DCMAKE_BUILD_TYPE=Release
cd build
make
```

## 6. Finish
Now, you can find the binary file `image-processor` in build folder. You can test it by 
```bash
./build/image-processor --help
```
