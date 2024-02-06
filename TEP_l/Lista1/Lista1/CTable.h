#pragma once
#include <iostream>


class CTable
{
private:
	int table_len;
	std::string s_name;
	int* table;
public:
	CTable();
	CTable(std::string, int iTableLen);
	CTable(CTable& pcOther);
	CTable(bool TMP);
	~CTable();

	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();

	void printData();
	void vDoubleSize(CTable **other);

	
};


void v_mod_tab(CTable* pcTab, int iNewSize);
void v_mod_tab(CTable cTab, int iNewSize);
