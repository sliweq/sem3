#pragma once
#include <string>
#include <iostream>
using namespace std;

class CMyString
{
private:
	char* myStringTable;
	int* myStringSize;

	//tableIndex is useless until we start implementing subtract operator
	int* tableIndex; //index of future char in table 
public:
	
	CMyString(); 
	CMyString(const CMyString& originalCMyString); 
	CMyString(const string& originalCMyString);
	~CMyString();

	CMyString operator+(const string& addCMyString);
	void operator=(const CMyString& originalCMyString);
	void operator=(const string& originalCMyString); 
	void operator+=(const string& originalCMyString); 
	CMyString operator-(const string& originalCMyString);

	string sToStandard();
	void nullString();
	operator bool() const;

};

