
#include "HaffmanEncoder.h"


HaffmanEncoder::HaffmanEncoder()
{
	this->AC_Y = new ACTable("./HaffmanTable/Y_ACTable.txt");
	this->DC_Y = new DCTable("./HaffmanTable/Y_DCTable.txt");
	this->AC_C = new ACTable("./HaffmanTable/C_ACTable.txt");
	this->DC_C = new DCTable("./HaffmanTable/C_DCTable.txt");

}


HaffmanEncoder::~HaffmanEncoder()
{
}

string HaffmanEncoder::Yencoding(int *src) {
	vector<Vec2w> rleCode = RLEencoding(src);
	vector<Vec3w> bitCode = BITencoding(rleCode);
	string rst = "";

	rst += DC_Y->getCode(bitCode[0][1]);
	rst += getSecondNumCode(bitCode[0][2]);
	for (int i = 1; i < bitCode.size; i++) {
		int x = bitCode[i][0];
		int y = bitCode[i][1];
		int z = bitCode[i][2];
		rst += AC_Y->getCode(x, y);
		rst += getSecondNumCode(z);
	}

	return rst;
}

string HaffmanEncoder::Cencoding(int *src) {
	vector<Vec2w> rleCode = RLEencoding(src);
	vector<Vec3w> bitCode = BITencoding(rleCode);
	string rst = "";

	rst += DC_C->getCode(bitCode[0][1]);
	rst += getSecondNumCode(bitCode[0][2]);
	for (int i = 1; i < bitCode.size; i++) {
		int x = bitCode[i][0];
		int y = bitCode[i][1];
		int z = bitCode[i][2];
		rst += AC_C->getCode(x, y);
		rst += getSecondNumCode(z);
	}

	return rst;
}

vector<Vec2w> HaffmanEncoder::RLEencoding(int *src) {
	vector<Vec2w> rst;
	int zeroCount = 0, t;
	Vec2w tmp;

	tmp[0] = 0;
	tmp[1] = src[0];
	rst.push_back(tmp);
	for (int i = 1; i < 64; i++) {
		zeroCount = 0;
		t = i;
		while (i < 64 && src[i] == 0 && zeroCount<16) {
			zeroCount++;
			i++;
		}
		if (i >= 64) {
			tmp[0] = 0;
			tmp[1] = 0;
		}
		else if (src[i] != 0) {
			tmp[0] = zeroCount;
			tmp[1] = src[i];
		}
		else {
			tmp[0] = 15;
			tmp[1] = src[i];
		}
		rst.push_back(tmp);
	}
	return rst;
}

vector<Vec3w> HaffmanEncoder::BITencoding(vector<Vec2w> src) {
	vector<Vec3w> rst;
	Vec3w tmp;
	//tmp[0] = getSecondNumCode(src[0][0]);
	//tmp[1] = src[0][0];
	//rst.push_back(tmp);
	for (int i = 0; i < src.size; i++) {
		if (src[i][0] == 0 && src[i][1] == 0) {
			break;
		}
		tmp[2] = src[i][1];
		tmp[0] = src[i][0];
		tmp[1] = getSecondNum(src[i][1]);
		rst.push_back(tmp);
	}
	return rst;
}

//	count for src bit number
int HaffmanEncoder::getSecondNum(int src) {
	if (src == 0) return 0;
	if (src < 0) src *= -1;
	
	double numLen = log(src) / log(2);
	for (int i = (int)(numLen - 5); i <= numLen + 5; i++) {
		if (pow(2, i - 1) <= src && src <= pow(2, i) - 1) {
			return i;
		}
	}
	return 0;
}

template<typename T> string toString(const T& t) {
	ostringstream st;
	st << t;
	return st.str();
}

//	src > 0
string HaffmanEncoder::num2binaryString(int src) {
	int secondNum = getSecondNum(src);
	int mm;
	string rst = "";
	while (src != 0) {
		mm = src % 2;
		src /= 2;
		rst += toString(mm);
	}
	rst.reserve();
	return rst;
}

string HaffmanEncoder::getSecondNumCode(int src) {
	if (src == 0) return "";
	int secondNum = getSecondNum(src);
	string rst = "";
	if (src < 0) {
		rst = num2binaryString((-src) ^ (int)(pow(2, secondNum) - 1));
	}
	else {
		rst = num2binaryString(src);
	}
	return rst;
}

int HaffmanEncoder::secondNumCode2num(string secondNumCode) {
	int rst;

	return rst;
}