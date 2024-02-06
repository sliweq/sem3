#include <iostream>
#include "methods123.h"
#include "const1.h"

void v_alloc_table_fill_34(int iSize) {
	if(iSize >= 1){

		int* table;
		table = new int[iSize];

		for (int tmp_inside_for = 0; tmp_inside_for < iSize; tmp_inside_for++) {
			table[tmp_inside_for] = const_for_filling_table;
		}

		for (int tmp_inside_for = 0; tmp_inside_for < iSize; tmp_inside_for++) {
			std::cout << table[tmp_inside_for] << const_new_line;
		}

		delete[] table;

	}
	else{
		std::cout << const_mess;
	}
}
