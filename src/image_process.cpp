#include <string>
#include <opencv2/opencv.hpp>
class ImageProcess
{
public:
    virtual std::string GetProcessName()=0;
    virtual void ProcessImage()=0;
};

class ShiftImage:public ImageProcess
{
public:
    cv::Mat image;
    std::string GetProcessName() override {
        return "shift image";
    }
    void ProcessImage(cv::Mat& image){
        
    }
};