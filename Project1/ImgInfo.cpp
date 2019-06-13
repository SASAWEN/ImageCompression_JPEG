#include "ImgInfo.h"


ImgInfo::ImgInfo(string fileName)
{
	this->fileName = fileName;
	Mat src = imread(fileName, CV_LOAD_IMAGE_COLOR);
	this->RGBvalue = imread(fileName, CV_LOAD_IMAGE_COLOR);

	PreEncoder* preProcess = new PreEncoder();
	this->YCbCrValue = preProcess->RGB2YCbCr(src);
}

ImgInfo::ImgInfo()
{
}

ImgInfo::~ImgInfo()
{
}

Mat ImgInfo::getRGB() {
	return this->RGBvalue;
}

Mat ImgInfo::getYCbCr() {
	return this->YCbCrValue;
}
