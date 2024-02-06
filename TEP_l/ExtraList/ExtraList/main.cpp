#include <iostream>
#include "CMyString.h"

using namespace std;
int main()
{
	std::string alaTestWord = "ala ";
	std::string hasTestWord = "ma ";
	std::string catTestWord = "kota ";
	std::string anddogTestWord = "i psa";

	std::string subTestWord = "ala ala ala ala";
	std::string subTestWord1 = "al";

	CMyString strTest1(subTestWord);
	
	CMyString strTest2(strTest1);
	CMyString strTest3;
	strTest3 = hasTestWord;
	strTest3 += catTestWord;
	strTest3 = strTest3 + anddogTestWord;

	strTest1 = strTest1 - subTestWord1;

	cout << strTest1.sToStandard() << endl;

	cout << strTest2.sToStandard() << endl;
	cout << strTest3.sToStandard() << endl;

	cout << (bool)strTest2 << endl;
	strTest2.nullString();
	cout << (bool)strTest2 << endl;
	

	return 0;
}

