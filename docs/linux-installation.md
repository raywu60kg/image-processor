# linux installation
Installation guide for linux

## 1. Install opencv
[check here](https://www.geeksforgeeks.org/how-to-install-opencv-in-c-on-linux/)

## option 1. Clone this repo and build by your self
```
git clone https://github.com/raywu60kg/image-processor.git && cd "$_"
```

### option 1.2 Configure CMake cmake
```
cmake -B ./build -DCMAKE_BUILD_TYPE=Release
```
### option 1.2 Build project by cmake
```
cmake --build ./build --config Release
```

### option 1.3 Finish
Now, you can find the binary file `image-processor` in build folder. You can test it by 
```bash
./build/image-processor --help
```

## option 2. Use the release version on github
Download `image-processor` on the [release page](https://github.com/raywu60kg/image-processor/releases). Then, you can directly use them.
