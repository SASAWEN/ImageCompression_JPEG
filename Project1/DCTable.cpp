#include "DCTable.h"



DCTable::DCTable(string filePath)
{
	this->filePath = filePath;
}


DCTable::~DCTable()
{
}


vector<string> DCTable::split(const string& str, const string& delim) {
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

int DCTable::string2num(const char& str) {
	if (str >= '0' && str <= '9') {
		return str - '0';
	}
	else if (str >= 'A' && str <= 'F') {
		return str - 'A' + 10;
	}
}

int DCTable::string2num(const string& str) {
	char ch = str[0];
	return string2num(ch);
}

void DCTable::init() {
	ifstream file;
	string temp;
	vector<string> ss, numsString;
	int num;
	file.open(filePath, ios::in);
	if (!file.is_open()) {
		cout << "ERROR: fail to open file" << endl;
	}

	while (getline(file, temp)) {
		ss = split(temp, "\\s\\s");
		num = string2num(ss[0]);
		this->value2code.insert(pair<int, string>(num, ss[1]));
	}

}

string DCTable::getCode(int x) {
	if (this->value2code.count(x) == 1)
		return this->value2code[x];
	return "";
}
