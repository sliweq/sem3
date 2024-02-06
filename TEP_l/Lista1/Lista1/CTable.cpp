#include "CTable.h"
#include "constCTable.h"
#include<iostream>

CTable::CTable() {
	table_len = default_length;
	table = new int[table_len];
	s_name = default_name;

	std::cout << normal_constructor_mess << apostrophe << s_name << apostrophe << end_of_the_line;
}

CTable::CTable(std::string sName, int iTableLen) {
	table_len = iTableLen;
	table = new int[iTableLen];
	s_name = sName; 

	std::cout << parameter_constructor_mess << apostrophe << s_name << apostrophe << end_of_the_line;
}

CTable::CTable(CTable& pcOther) {
	s_name = pcOther.s_name + only_copy;
	table_len = pcOther.table_len;
	table = new int[table_len];
	

	std::cout << copy_constructor_mess << apostrophe << s_name << apostrophe << end_of_the_line;
}

CTable::CTable(bool TMP) {
	s_name = default_name;
	table_len = default_length;
	table = new int[table_len];
	for (int tmp_inside_loop = 0; tmp_inside_loop < table_len; tmp_inside_loop++) {
		table[tmp_inside_loop] = (tmp_inside_loop + 1);
	}
}


CTable::~CTable() {
	std::cout << destructor_mess << apostrophe << s_name << apostrophe << end_of_the_line;
	delete[] table;
}

void CTable::vSetName(std::string sName) {
	s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
	
	if(iTableLen <= 0){
		return false;
	}
	if (iTableLen > table_len) {
		int* tmp_table;
		tmp_table = new int[iTableLen];

		for (int tmp_inside_for = 0; tmp_inside_for < table_len; tmp_inside_for++) {
			tmp_table[tmp_inside_for] = table[tmp_inside_for];
		}
		delete[] table;
		table = tmp_table;
		table_len = iTableLen;
		return true;
	}
	else if(iTableLen < table_len) {
		int* tmp_table;
		tmp_table = new int[iTableLen];

		for (int tmp_inside_for = 0; tmp_inside_for < iTableLen; tmp_inside_for++) {
			tmp_table[tmp_inside_for] = table[tmp_inside_for];
		}

		delete[] table;
		table = tmp_table;
		table_len = iTableLen;
		return true;
	}
	return true;
}

CTable* CTable::pcClone() {
	return new CTable(*this);
}

void CTable::printData() {
	std::cout << s_name << end_of_the_line;
	std::cout << table_len << end_of_the_line;
	for (int tmp_inside_loop = 0; tmp_inside_loop < table_len; tmp_inside_loop++) {
		std::cout << table[tmp_inside_loop] << ", ";
	}
	std::cout << end_of_the_line;
}

void v_mod_tab(CTable* pcTab, int iNewSize) {
	pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize) {
	cTab.bSetNewSize(iNewSize);
}




void CTable::vDoubleSize(CTable **other) {
	*other = new CTable(default_name, table_len*2);
	
	for (int tmp_double_for = 0; tmp_double_for < 2; tmp_double_for++) {

		for (int tmp_inside_for = 0; tmp_inside_for < table_len; tmp_inside_for++) {
			(* other)->table[(table_len*tmp_double_for)+tmp_inside_for] = table[tmp_inside_for];
		}
	}
}
