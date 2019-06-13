#include "PreEncoder.h"



PreEncoder::PreEncoder()
{
	//B G R
	this->PARAM_RGB_Y[0] = 0.1140;
	this->PARAM_RGB_Y[1] = 0.5870;
	this->PARAM_RGB_Y[2] = 0.2990;

	this->PARAM_RGB_Cb[0] = 0.500;
	this->PARAM_RGB_Cb[1] = -0.3313;
	this->PARAM_RGB_Cb[2] = -0.1687;

	this->PARAM_RGB_Cr[0] = -0.0813;
	this->PARAM_RGB_Cr[1] = -0.4187;
	this->PARAM_RGB_Cr[2] = 0.5000;

}


PreEncoder::~PreEncoder()
{
}

Mat PreEncoder::RGB2YCbCr(Mat src) {
	int i, j, k;
	Mat dst(src.rows, src.cols, CV_8UC3);
	Vec3b pixRGB;
	for (i = 0; i < src.rows; i++) {
		for (j = 0; j < src.cols; j++) {
			pixRGB[0] = PARAM_RGB_Y[0] * src.at<Vec3b>(i, j)[0]
				+ PARAM_RGB_Y[1] * src.at<Vec3b>(i, j)[1]
				+ PARAM_RGB_Y[2] * src.at<Vec3b>(i, j)[2];
			pixRGB[1] = PARAM_RGB_Cb[0] * src.at<Vec3b>(i, j)[0]
				+ PARAM_RGB_Cb[1] * src.at<Vec3b>(i, j)[1]
				+ PARAM_RGB_Cb[2] * src.at<Vec3b>(i, j)[2];
			pixRGB[2] = PARAM_RGB_Cr[0] * src.at<Vec3b>(i, j)[0]
				+ PARAM_RGB_Cr[1] * src.at<Vec3b>(i, j)[1]
				+ PARAM_RGB_Cr[2] * src.at<Vec3b>(i, j)[2];
			dst.at<Vec3f>(i, j) = pixRGB;//B G R -> Y CB CR
		}
	}
	return dst;
}

vector<int> PreEncoder::readMat(Mat src, int &x, int &y, int dir) {
	vector<int> rst;
	int i,j;
	switch (dir) {
	case RIGHT:	//right
		if (y < src.cols) {
			rst.push_back(src.at<int>(x, y + 1));
		}
		y++;
		break;
	case LEFT_DOWN:	//left-down
		i = x;
		j = y;
		while (i < src.rows - 1 && j > 0) {
			rst.push_back(src.at<int>(i + 1, j - 1));
		}
		x = i;
		y = j;
		break;
	case DOWN:	//down
		if (x < src.rows) {
			rst.push_back(src.at<int>(x + 1, y));
		}
		x++;
		break;
	case RIGHT_UP:	//right up
		i = x;
		j = y;
		while (j < src.cols - 1 && i > 0) {
			rst.push_back(src.at<int>(i - 1, j + 1));
		}
		x = i;
		y = j;
		break;
	default:
		cout << "ERROR: wrong direction" << endl;
	}
	return rst;
}

vector<int> PreEncoder::twoD2oneD(Mat src) {
	int x, y, state;
	vector<int> rst,tmp;
	rst.push_back(src.at<int>(0, 0));
	x = 0;
	y = 0;
	state = RIGHT;
	while (x != src.rows - 1 || y != src.cols - 1) {
		switch (state) {
		case RIGHT:
			tmp = readMat(src, x, y, RIGHT);
			rst.insert(rst.end(), tmp.begin(), tmp.end());
			if (x == src.rows - 1 && y == src.cols - 1) {
				break;
			}
			state = (x == 0) ? LEFT_DOWN : RIGHT_UP;
			break;
		case LEFT_DOWN:
			tmp = readMat(src, x, y, LEFT_DOWN);
			rst.insert(rst.end(), tmp.begin(), tmp.end());
			state = (x == src.rows - 1) ? RIGHT : DOWN;
			break;
		case DOWN:
			tmp = readMat(src, x, y, DOWN);
			rst.insert(rst.end(), tmp.begin(), tmp.end());
			state = (y == 0) ? RIGHT_UP : LEFT_DOWN;
			break;
		case RIGHT_UP:
			tmp = readMat(src, x, y, RIGHT_UP);
			rst.insert(rst.end(), tmp.begin(), tmp.end());
			state = (y == src.cols - 1) ? DOWN : RIGHT;
			break;
		default:
			cout << "ERROR: wrong state" << endl;
		}
	}
	return rst;
}