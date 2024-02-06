#include <iostream>
#include "methods123.h"

bool b_dealloc_table_2_dim(int** piTable, int iSizeX, int iSizeY) {
	if (iSizeX <= 0) {
		return false;

	}
	if (iSizeY <= 0) {
		return false;

	}
	if (*piTable == NULL) {
		return true;
	}
	
	for (int tmp_inside_for = 0; tmp_inside_for < iSizeX; tmp_inside_for++) {
		delete[] piTable[tmp_inside_for];
	}

	delete[] piTable;

	return true;
}