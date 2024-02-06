#include <iostream>
#include "methods123.h"
#include "CTable.h"
#include "mainConst.h"


int main() {

	//zadanie 1
	v_alloc_table_fill_34(table_size_for_allocate);
	v_alloc_table_fill_34(negative_table_size);

	//zadanie 2
	int** table;
	b_alloc_table_2_dim(&table, table_2_dim_size, table_2_dim_size);

	//zadanie 3
	b_dealloc_table_2_dim(table, table_2_dim_size, table_2_dim_size);
	//zadanie 4

	CTable *ctable1, *ctable2, *ctable3, *ctable4;
	ctable1 = new CTable();
	ctable2 = new CTable();
	ctable3 = new CTable(forced_name_class, table_size_paremeter);
	ctable4 = ctable3->pcClone();
	
	ctable1->printData();
	ctable2->printData();

	v_mod_tab(*ctable1, table_size_for_mod_method); //tworzy kopiê, wartosc sie nie zmienia
	v_mod_tab(ctable2, table_size_for_mod_method); //dlugosc listy sie zmienia
	
	ctable1->printData();
	ctable2->printData(); 

	CTable static_table;
	static_table.vSetName(static_name_class);
	static_table.printData();

	delete ctable1;
	delete ctable2;
	delete ctable3;
	delete ctable4;


	CTable* table_of_ctable;
	table_of_ctable = new CTable[table_of_ctable_size];
	delete[] table_of_ctable;

	
	CTable ctab(true);
	CTable* pc_dub;

	ctab.vDoubleSize(&pc_dub);
	ctab.printData();
	pc_dub->printData();

	delete pc_dub; 
}