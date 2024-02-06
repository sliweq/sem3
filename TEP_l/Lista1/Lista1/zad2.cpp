#include <iostream>
#include "methods123.h"


bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY) {

	if (iSizeX <= 0) {
		return false;

	}
	else if (iSizeY <= 0) {
		return false;

	}
	else {
		*piTable = new int* [iSizeX];

		for (int tmp_inside_for = 0; tmp_inside_for < iSizeX; tmp_inside_for++) {
			(*piTable)[tmp_inside_for] = new int[iSizeY];

		}
		return true;
	}

}