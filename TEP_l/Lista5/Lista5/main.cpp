#include <iostream>
#include "Interface.h"
#include "CTree.h"
#include "CMySmartPointer.h"	
int main() {
	//licznik referencji przechowuje adresy intelignetcnych wska�nik�w do kt�rych jest przypi�ty
	//Interface obj_interface;
	//obj_interface.run_get_type_simulation();
	
	int* tmp = new int[10];
	CMySmartPointer <int> xd(tmp);



	return 0;
};
 