#include "ACTable.h"



ACTable::ACTable(string filePath)
{
	this->filePath = filePath;
}


ACTable::~ACTable()
{
}

vector<string> ACTable::split(const string& str, const string& delim) {
	vector<string> res;
	if ("" == str) return res;
	//先将要切割的字符串从string类型转换为char*类型  
	char * strs = new char[str.length() + 1]; //不要忘了  
	strcpy(strs, str.c_str());

	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char *p = strtok(strs, d);
	while (p) {
		string s = p; //分割得到的字符串转换为string类型  
		res.push_back(s); //存入结果数组  
		p = strtok(NULL, d);
	}

	return res;
}

int ACTable::string2num(const char& str) {
	if (str >= '0' && str <= '9') {
		return str - '0';
	}
	else if (str >= 'A' && str <= 'F') {
		return str - 'A' + 10;
	}
}

int ACTable::string2num(const string& str) {
	char ch = str[0];
	return string2num(ch);
}

void ACTable::init() {
	ifstream file;
	string temp;
	vector<string> ss, numsString;
	vector<int> nums;
	file.open(filePath, ios::in);
	if (!file.is_open()) {
		cout << "ERROR: fail to open file" << endl;
	}

	while (getline(file, temp)) {
		ss = split(temp, "\\s\\s");
		numsString = split(ss[0], "/");
		nums[0] = string2num(numsString[0]);
		nums[1] = string2num(numsString[1]);
		this->value2code.insert(pair<vector<int>, string>(nums, ss[1]));
	}

}

string ACTable::getCode(int x, int y) {
	vector<int> key;
	key[0] = x;
	key[1] = y;
	if (this->value2code.count(key) == 1)
		return this->value2code[key];
	return "";
}
