#pragma once
#include <opencv2/core/core.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include "ACTable.h"
#include "DCTable.h"

using namespace std;
using namespace cv;

class HaffmanEncoder
{
private:
	ACTable *AC_Y, *AC_C;
	DCTable *DC_Y, *DC_C;
	template<typename T> toString(const T& t);
	string num2binaryString(int src);
	int getSecondNum(int secondNum);
	string getSecondNumCode(int src);
	int secondNumCode2num(string secondNumCode);
public:
	HaffmanEncoder();
	~HaffmanEncoder();
	string Yencoding(int *src);
	string Cencoding(int *src);
	vector<Vec2w> RLEencoding(int *src);
	vector<Vec3w> BITencoding(vector<Vec2w>);
};

