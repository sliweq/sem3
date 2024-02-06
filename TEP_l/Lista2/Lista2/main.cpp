#include <iostream>
#include "CNumber.h"
#include "MainConst.h"

int main() {
	CNumber c_num_0, c_num_1, c_num_2, c_num_3,c_num_4;
	CNumber* c_num_5;
	c_num_0 = first_number_for_operation;
	c_num_1 = second_number_for_operation;

	//c_num_3 = 10;
	//c_num_4 = 3;

	//zadanie 2
	//z destruktorem chcemy usuwaæ miejsce w pamiêci które ju¿ usunêlimy poniewa¿ mam dwie klasy z tymi samymi elementami
	// gdy usuniemy destruktory kompilator radzi sobie bez problemu 


	c_num_0.v_print_table();
	c_num_1.v_print_table();

	std::cout << table_to_string << std::endl;

	std::cout << c_num_0.sToStr() << std::endl;
	std::cout << c_num_1.sToStr() << std::endl;

	std::cout << answer_of_operation;

	c_num_2 = c_num_0 / c_num_1;

	c_num_2.v_print_table();

	c_num_2 = c_num_3.c_Div(c_num_4, &c_num_5);
	c_num_2.v_print_table();
	
	//c_num_5->v_print_table();
	//std::cout << (*c_num_5)
	
}