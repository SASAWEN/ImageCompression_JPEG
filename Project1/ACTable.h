#pragma once
#include <iostream>
#include <fstream> 
#include <vector> 
#include <string> 
#include <map>


using namespace std;

class ACTable
{
private:
	string filePath;
	map <vector<int>, string> value2code;
	vector<string> split(const string& str, const string& delim);
	int string2num(const char& str);
	int string2num(const string& str);
public:
	ACTable(string filePath);
	~ACTable();
	void init();
	string getCode(int x, int y);

};

