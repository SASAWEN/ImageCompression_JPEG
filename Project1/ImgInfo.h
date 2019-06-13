#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include<vector>
#include "PreEncoder.h"
using namespace std;
using namespace cv;

//typedef  Vec<uchar, 3>  Vec3b;

class ImgInfo
{
private:
	string fileName;
	Mat RGBvalue;
	Mat YCbCrValue;
	PreEncoder preProcess;
public:
	ImgInfo();
	ImgInfo(string fileName);
	~ImgInfo();
	Mat getRGB();
	Mat getYCbCr();
};

