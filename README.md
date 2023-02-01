# image-processor
[![GitHub Actions status](https://github.com/raywu60kg/image-processor/workflows/test/badge.svg)](https://github.com/raywu60kg/image-processor/actions)
[![GitHub Actions status](https://github.com/raywu60kg/image-processor/workflows/release/badge.svg)](https://github.com/raywu60kg/image-processor/actions)
[![GitHub](https://img.shields.io/github/license/xresloader/upload-to-github-release)](LICENSE)
![image](images/image-processor.png)

C++ command line tool for processing image. 
## Usages
### help
Display the description of this command line tools
```bash
./image-processor --help
```
### Shift image
Shift image based on the arguments `offset_x` and `offset_y`.
![image](images/image-processor-shift.png)
```bash
./image-processor --method shift_image --input_image_dir <image directory> --offset_x <offset x axis>  --offset_x <offset y axis>
```
### gray scale image
![image](images/image-processor-grayscale.png)
```bash
./image-processor --method gray_scale_image --input_image_dir <image directory> --offset_x <offset x axis>  --offset_x <offset y axis>
```
## Installation guild
### For linux
[check here](https://github.com/raywu60kg/image-processor/blob/main/docs/linux-installation.md)

### For Mac ARM
[check here](https://github.com/raywu60kg/image-processor/blob/main/docs/macOS-installation.md)