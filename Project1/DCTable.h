#pragma once
#include <iostream>
#include <fstream> 
#include <vector> 
#include <string> 
#include <map>

using namespace std;

class DCTable
{
private:
	string filePath;
	map <int, string> value2code;
	vector<string> split(const string& str, const string& delim);
	int string2num(const char& str);
	int string2num(const string& str);
public:
	DCTable(string filePath);
	~DCTable();
	void init();
	string getCode(int x);
};


