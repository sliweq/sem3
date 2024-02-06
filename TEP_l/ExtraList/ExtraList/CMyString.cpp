#include "CMyString.h"
#include <iostream>
#include "CMyStringConsts.h"

CMyString::CMyString(){
	myStringSize = new int;
	*myStringSize = cMyStringConstuctorWord.length();
	tableIndex = new int;
	*tableIndex = *myStringSize;

	myStringTable = new char[*myStringSize];

	for (int i = 0; i < *myStringSize; i++) {
		myStringTable[i] = cMyStringConstuctorWord[i];
	}
};

CMyString::CMyString(const CMyString& originalCMyString) {
	myStringSize = new int;
	*myStringSize = *(originalCMyString.myStringSize);

	tableIndex = new int;
	*tableIndex = *(originalCMyString.tableIndex);

	myStringTable = new char[*myStringSize];

	for (int i = 0; i < *tableIndex; i++) {
		myStringTable[i] = originalCMyString.myStringTable[i];
	}
};

CMyString::CMyString(const string& originalCMyString) {
	myStringSize = new int;
	*myStringSize = originalCMyString.size();

	tableIndex = new int;
	*tableIndex = originalCMyString.size();

	myStringTable = new char[*myStringSize];

	for (int i = 0; i < *tableIndex; i++) {
		myStringTable[i] = originalCMyString[i];
	}
};

CMyString::~CMyString() {
	delete[] myStringTable;
	delete myStringSize;
	delete tableIndex;
};

CMyString CMyString::operator-(const string& originalCMyString) {
	if (originalCMyString.size() > *tableIndex || emptyString == originalCMyString) {
		CMyString newCMyString(*this);
		return newCMyString;
	}	
	string thisString = sToStandard();
	string subSolution = emptyString;

	for (int i = 0; i < thisString.size(); i++) {
		int whileIterator = 0;

		while ((i + whileIterator) < (*tableIndex) && whileIterator < originalCMyString.size() &&
			thisString[i + whileIterator] == originalCMyString[whileIterator]) {
			whileIterator += 1;
		}
		if (whileIterator != originalCMyString.size()) {
			subSolution += thisString[i];
		}
		else {
			i += whileIterator - 1;
		}
	}

	CMyString newCMyString(subSolution);
	return newCMyString;
}

CMyString CMyString::operator+ (const string& addCMyString) {
	CMyString newCMyString;

	newCMyString.myStringSize = new int;
	*newCMyString.myStringSize = *tableIndex + addCMyString.length();

	newCMyString.tableIndex = new int;
	*newCMyString.tableIndex = *tableIndex + addCMyString.length();

	newCMyString.myStringTable = new char[*newCMyString.myStringSize];

	for (int i = 0; i < *tableIndex; i++) {
		newCMyString.myStringTable[i] = myStringTable[i];
		
	}
	for (int i = 0; i < addCMyString.length(); i++) {
		newCMyString.myStringTable[i + (*tableIndex)] = addCMyString[i];
	}

	return newCMyString;

};

void CMyString::operator=(const CMyString& originalCMyString) {
	delete tableIndex;
	delete myStringSize;
	delete[] myStringTable;

	myStringSize = new int;
	*myStringSize = *(originalCMyString.myStringSize);

	tableIndex = new int;
	*tableIndex = *(originalCMyString.tableIndex);

	myStringTable = new char[*myStringSize];

	for (int i = 0; i < *tableIndex; i++) {
		myStringTable[i] = originalCMyString.myStringTable[i];
	}
};

void CMyString::operator=(const string& originalCMyString) {
	if (*myStringSize >= originalCMyString.size()) {
		for (int i = 0; i < *myStringSize; i++) {
			myStringTable[i] = NULL;
		}
		*tableIndex = originalCMyString.length();
		for (int i = 0; i < *tableIndex; i++) {
			myStringTable[i] = originalCMyString[i];
		}

	}
	else {
		delete tableIndex;
		delete myStringSize;
		delete[] myStringTable;

		myStringSize = new int;
		*myStringSize = originalCMyString.length();

		tableIndex = new int;
		*tableIndex = originalCMyString.length();

		myStringTable = new char[*myStringSize];

		for (int i = 0; i < *tableIndex; i++) {
			myStringTable[i] = originalCMyString[i];
		}
	}
};

void CMyString::operator+=(const string& addCMyString) {
	if (*tableIndex + addCMyString.length() > *myStringSize) {
		char* myNewStringTable = new char[*tableIndex + addCMyString.length()];
		int* myNewStringSize = new int;
		*myNewStringSize = *tableIndex + addCMyString.length();

		for (int i = 0; i < *tableIndex; i++){
			myNewStringTable[i] = myStringTable[i];
		}
		for (int i = *tableIndex; i < *myNewStringSize; i++) {
			myNewStringTable[i] = addCMyString[i - *tableIndex];
		}

		delete[] myStringTable;
		myStringTable = myNewStringTable;
		myNewStringTable = NULL;
		*myStringSize = *myNewStringSize;
		delete myNewStringSize;
		*tableIndex = *myStringSize;
		delete[] myNewStringTable;
	}
	else {

		for (int i = *tableIndex; i < *myStringSize; i++) {
			myStringTable[i] = addCMyString[i - *tableIndex];
		}
		*tableIndex = *tableIndex + addCMyString.length();
	}
};

string CMyString::sToStandard() {
	string standardString;
	for (int i = 0; i < *tableIndex; i++) {
		standardString += myStringTable[i];
	}
	return standardString;
};

void CMyString::nullString() {
	for(int i = 0; i < *myStringSize; i++){
		myStringTable[i] = NULL;
	}
	*tableIndex = 0;
};

CMyString::operator bool() const {
	if (*tableIndex == 0) {
		return false;
	}
	else {
		return true;
	}
};

