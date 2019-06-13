#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include<vector>

using namespace std;
using namespace cv;

#define RIGHT 1
#define LEFT_DOWN 2
#define DOWN 3
#define RIGHT_UP 4

class PreEncoder
{
private:
	Vec3f PARAM_RGB_Y, PARAM_RGB_Cb, PARAM_RGB_Cr;
	vector<int> readMat(Mat src, int &x, int &y, int dir);
public:
	PreEncoder();
	~PreEncoder();
	Mat RGB2YCbCr(Mat src);
	vector<int> twoD2oneD(Mat src);
};

