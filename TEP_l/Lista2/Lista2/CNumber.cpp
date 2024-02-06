#include "CNumber.h"
#include "CNumberConst.h"
#include <iostream>
#include <cmath>
#include <string>

CNumber::CNumber() { 
	i_length = new int;
	*i_length = 1;

	is_positive = new bool;
	*is_positive = true;

	pi_table = new int[*i_length];
	pi_table[0] = 0;
};

CNumber::CNumber(const CNumber& pcOther) {
	delete i_length;
	delete is_positive;

	i_length = new int;
	*i_length = *pcOther.i_length;

	is_positive = new bool;
	*is_positive = *pcOther.is_positive;

	//std::cout << "\nKonstruktor kopiuj¹cy\n";

	pi_table = new int[*i_length];
	
	for (int i = 0; i < *i_length; i++) {
		pi_table[i] = pcOther.pi_table[i];
	}
}

void CNumber::operator = (const int iValue) {

	delete pi_table;

	if (iValue >= 0) {
		while ((iValue) / (int)(pow(divider_for_table, (*i_length))) > 0) {
			(*i_length)++;
		}

		pi_table = new int[*i_length];


		*is_positive = true;
		for (int i = 0; i < *i_length; i++) {
			//std::cout << i << "\n";
			//std::cout << (iValue / (int)(pow(10, (*i_length) - i))) % 10 << "\n";
			pi_table[( * i_length) - i-1] = (iValue / (int)(pow(divider_for_table, (*i_length) - (i + 1)))) % number_system;
		}
	}
	else {
		while (((-1) * iValue) / (int)(pow(divider_for_table, (*i_length))) > 0) {
			(*i_length)++;
		}

		pi_table = new int[*i_length];

		*is_positive = false;
		for (int i = 0; i < *i_length; i++) {
			//std::cout << i << "\n";
			//std::cout << (iValue / (int)(pow(10, (*i_length) - i))) % 10 << "\n";
			pi_table[(*i_length) - i - 1] = (- 1) *(iValue / (int)(pow(divider_for_table, (*i_length) - (i + 1)))) % number_system;
			
		}
	}
};

CNumber::~CNumber() {
	//std::cout << "usuwam\n";
	//this->v_print_table();
	delete pi_table;
	delete i_length;
}

void CNumber::v_print_table() {
	
	if (!*is_positive) {
		std::cout << "-";
	}
	
	for (int i = 0; i < *i_length; i++) {
		std::cout << pi_table[( * i_length) - i-1];
	}
	std::cout << std::endl;
}

CNumber CNumber::operator-(const CNumber& pcNewVal) {
	CNumber c_result;
	c_result.i_length = new int;
	c_result.is_positive = new bool;
	//xor

	if ((!(*is_positive)&&(*pcNewVal.is_positive))||((*is_positive) && !(*pcNewVal.is_positive)))
	{
		if (*is_positive) {
			*c_result.is_positive = *is_positive;

			v_add_two_tables(pi_table,i_length,pcNewVal.pi_table, &c_result.pi_table, pcNewVal.i_length, c_result.i_length);

			//tmp.v_print_table();
			return c_result;
		}
		else {
			
			*c_result.is_positive = *is_positive;

			v_add_two_tables(pi_table, i_length, pcNewVal.pi_table, &c_result.pi_table, pcNewVal.i_length, c_result.i_length);

			//tmp.v_print_table();
			return c_result;
		}
	}
	else 
	{
		if (*is_positive) {
			//+ - + 
			for (int i = 0; i < *pcNewVal.i_length; i++) {
				pcNewVal.pi_table[i] *= (-1);
			}

			v_add_two_tables(pi_table, i_length, pcNewVal.pi_table, &c_result.pi_table, pcNewVal.i_length, c_result.i_length);
			for (int i = 0; i < *pcNewVal.i_length; i++) {
				pcNewVal.pi_table[i] *= (-1);
			}

			v_remove_zeroes(&c_result);
			v_reapir_neagitve_number(c_result.pi_table, c_result.i_length, c_result.is_positive);
			v_remove_zeroes(&c_result);
			//tmp.v_print_table();
			return c_result;

		}
		else {
			//- - -
			for (int i = 0; i < *pcNewVal.i_length; i++) {
				pcNewVal.pi_table[i] *= (-1);
			}

			v_add_two_tables(pi_table, i_length, pcNewVal.pi_table, &c_result.pi_table, pcNewVal.i_length, c_result.i_length);
			for (int i = 0; i < *pcNewVal.i_length; i++) {
				pcNewVal.pi_table[i] *= (-1);
			}

			v_remove_zeroes(&c_result);
			v_reapir_neagitve_number(c_result.pi_table, c_result.i_length, c_result.is_positive);
			v_remove_zeroes(&c_result);
			//tmp.v_print_table();
			return c_result;
		}
	}
}

CNumber CNumber::operator+(const CNumber& pcNewVal) {

	CNumber c_result;
	c_result.i_length = new int;
	c_result.is_positive = new bool;

	//XNOR
	if (((*is_positive) && (*pcNewVal.is_positive)) || (!(*is_positive) && !(*pcNewVal.is_positive))) 
	{ 
		
		*c_result.is_positive = *is_positive;
		
		v_add_two_tables(pi_table,i_length,pcNewVal.pi_table,&c_result.pi_table,pcNewVal.i_length, c_result.i_length);

		//tmp.v_print_table();
		return (c_result);
		
	}
	else{
		//jesli liczba jest ujemna mnoze wszsytkie elementy razy -1 i dodaje wssytko normalnie
		//i znak ostatniego elementu dyktuje znak 
		if (*is_positive) 
		{
			// jesli druga tabela jest ujemna
			for (int i = 0; i < *pcNewVal.i_length; i++) {
				pcNewVal.pi_table[i] *= (-1);
			}

			v_add_two_tables(pi_table, i_length, pcNewVal.pi_table, &c_result.pi_table, pcNewVal.i_length, c_result.i_length);
			for (int i = 0; i < *pcNewVal.i_length; i++) {
				pcNewVal.pi_table[i] *= (-1);
			}

			v_remove_zeroes(&c_result);
			v_reapir_neagitve_number(c_result.pi_table, c_result.i_length, c_result.is_positive);
			v_remove_zeroes(&c_result);
			//tmp.v_print_table();
			return (c_result);

		}
		else {
			// jesli ta liczba jest ujemna
			for (int i = 0; i < *i_length; i++) {
				pi_table[i] *= (-1);
			}

			v_add_two_tables(pi_table, i_length, pcNewVal.pi_table, &c_result.pi_table, pcNewVal.i_length, c_result.i_length);
			for (int i = 0; i < *i_length; i++) {
				pi_table[i] *= (-1);
			}
			
			v_remove_zeroes(&c_result);
			v_reapir_neagitve_number(c_result.pi_table, c_result.i_length, c_result.is_positive);
			v_remove_zeroes(&c_result);
			//tmp.v_print_table();
			return (c_result);
		}
	}
}

void CNumber::v_reapir_neagitve_number(int* result_table, int* length_result_table, bool* result_is_positive){
	// mozliwosc waracania
	if (result_table[*length_result_table-1] >=0 ) {
		//liczba bedzie dodatnia
		*result_is_positive = true;

		for (int i = 0; i < *length_result_table; i++) {
			// sprawdzam nexta
			if (result_table[i] < 0) {
				result_table[i] += number_system; // 10 na system w jakim robie 
				result_table[i + 1] -= 1; 
			}
		}

	}
	else {
		*result_is_positive = false;
		for (int i = 0; i < *length_result_table; i++) {
			// sprawdzam nexta
			if (result_table[i] > 0)
			{
				result_table[i] -= number_system; // 10 na system w jakim robie 
				result_table[i + 1] += 1;
			}
		}
	}
	// to jest git yulkko trzeba naprawic to
	for (int i = 0; i < *length_result_table; i++) {
		if (result_table[i] < 0) 
		{
			result_table[i] = (-1)* result_table[i];
		}
	}
	
}

void CNumber::v_remove_zeroes(CNumber* result_table) {
	int* new_table;
	int* index_counter = new int;
	*index_counter = *(result_table->i_length);

	while ((result_table->pi_table[*index_counter - 1]) == 0 && *index_counter > 1) 
	{
		*index_counter -= 1;
	}

	new_table = new int[*index_counter];

	for (int i = 0; i < *index_counter; i++) {
		new_table[i] = (result_table->pi_table[i]);
 	}

	delete[] (result_table->pi_table);
	delete result_table->i_length;

	(result_table->pi_table) = new_table;
	(result_table->i_length) = index_counter;
}

void CNumber::v_remove_zeroes1(int** zero_pi_table,int* zero_i_length) {
	int* new_table;
	int* index_counter = new int;
	*index_counter = *zero_i_length;

	while (( * zero_pi_table)[*index_counter - 1] == 0 && *index_counter > 1) {
		*index_counter -= 1;
	}

	new_table = new int[*index_counter];

	for (int i = 0; i < *index_counter; i++) {
		new_table[i] = ( * zero_pi_table)[i];
	}

	delete[] * zero_pi_table;

	*zero_i_length = *index_counter;
	*zero_pi_table = new int[*zero_i_length];

	for (int i = 0; i < *zero_i_length; i++) {
		(*zero_pi_table)[i] = new_table[i];
	}
	delete new_table;
	delete index_counter;
}

void CNumber::v_add_two_tables(int* this_pi_table, int* this_i_length,int* table_add, int** result_table, int* length_table_add, int* length_result_table){
	int* tmp_table = new int[1 + std::max(*this_i_length, *length_table_add)];

	int* transfer = new int;
	*transfer = 0;

	int* counter = new int;
	*counter = 0;

	for (int i = 0; i < std::max(*this_i_length, *length_table_add) + 1; i++) {
		*counter += *transfer;
		*transfer = 0;

		if (i < *length_table_add) {
			*counter += table_add[i];
		}
		if (i < *this_i_length) {
			*counter += this_pi_table[i];
		}
		if (*counter >= number_system) {
			*transfer += 1;
			*counter -= number_system;
		}

		tmp_table[i] = *counter;

		*counter = 0;
	}
	delete counter;
	delete transfer;

	if (tmp_table[std::max(*this_i_length, *length_table_add)] != 0) {
		*length_result_table = std::max(*this_i_length, *length_table_add) + 1;
		*result_table = new int[*length_result_table];
	}
	else {
		*length_result_table = std::max(*this_i_length, *length_table_add);
		*result_table  = new int[*length_result_table];
	}
	for (int i = 0; i < *length_result_table; i++) {
		(* result_table)[i] = tmp_table[i];
	}

	delete[] tmp_table;
}

void CNumber::operator=(const CNumber &pcOther) {

	*is_positive = *pcOther.is_positive;
	delete pi_table;
	*i_length = *pcOther.i_length;

	pi_table = new int[*i_length];
	

	for (int i = 0; i < *i_length; i++) {
		pi_table[i] = pcOther.pi_table[i];
	}
}

std::string CNumber::sToStr() {
	std::string our_string = "";
	for (int i = 0; i < *i_length; i++) {
		our_string = std::to_string(pi_table[i]) + our_string;
		
	}
	if (!*is_positive) {
		our_string = "-" + our_string;
	}
	return our_string;
}

CNumber CNumber::operator*(const CNumber& pcNewVal) {
	CNumber c_result;
	c_result.i_length = new int;
	c_result.is_positive = new bool;
	//xnor
	if (((*is_positive) && (*pcNewVal.is_positive)) || (!(*is_positive) && !(*pcNewVal.is_positive))) {
		// wynik dodatni
		*c_result.is_positive = true;

		v_mul_two_tables(pi_table, i_length, pcNewVal.pi_table, &c_result.pi_table, pcNewVal.i_length, c_result.i_length);
		v_remove_zeroes(&c_result);
		//tmp.v_print_table();
		return (c_result);

	}
	else{
		*c_result.is_positive = false;

		v_mul_two_tables(pi_table, i_length, pcNewVal.pi_table, &c_result.pi_table, pcNewVal.i_length, c_result.i_length);
		v_remove_zeroes(&c_result);
		//tmp.v_print_table();
		return (c_result);
	}
}

void CNumber::v_mul_two_tables(int* this_pi_table, int* this_i_lenght,int* table_mul, int** result_table, int* length_table_mul, int* length_result_table) {
	int* tmp_table = new int[(*this_i_lenght)+(*length_table_mul)];
	for (int i = 0; (*this_i_lenght) + (*length_table_mul) > i; i++) {
		tmp_table[i] = 0;
	}

	int* transfer = new int;
	*transfer = 0;

	int* counter = new int;
	*counter = 0;

	for (int i = 0; i < *length_table_mul; i++) {
		for (int j = 0; j < *this_i_lenght; j++) {
			
			*counter = (table_mul[i] * this_pi_table[j]) + *transfer;
			*transfer = 0;

			if (*counter >= number_system) { //zamiana 10 na system
				*transfer = ( * counter / number_system);

				*counter = (*counter - (number_system * ( * transfer)));
			}

			tmp_table[i+j] += *counter;

			*counter = 0;
			if (j + 1 == *this_i_lenght) {
				tmp_table[i + j + 1] += *transfer;
				*transfer = 0;
			}
		}
	}

	delete counter;
	*transfer = 0;
	for (int i = 0; i < (*this_i_lenght) + (*length_table_mul)-1; i++) {
		if (tmp_table[i] >= number_system) {
			*transfer = tmp_table[i] / number_system;
			tmp_table[i] = tmp_table[i] - (number_system * (*transfer));
			tmp_table[i + 1] += *transfer;
		}
	}
	delete transfer;

	*length_result_table = (*this_i_lenght) + (*length_table_mul);
	*result_table = new int[*length_result_table];
	for (int i = 0; i < (*this_i_lenght) + (*length_table_mul); i++) {
		(*result_table)[i] = tmp_table[i];
	}
	delete[] tmp_table;
}

int CNumber::i_which_is_bigger(int* this_pi_table, int* this_i_length,int* input_pi_table, int* input_i_length) {
	// 0 -this 1 - pcNewVal 2- equal
	if (*this_i_length > *input_i_length) {
		return 0;
	}
	if (*this_i_length < *input_i_length) {
		return 1;
	}
	for (int i = (*this_i_length) - 1; i >= 0; i--) {
		if (input_pi_table[i] > this_pi_table[i]) {
			return 1;
		}
		if (input_pi_table[i] < this_pi_table[i]) {
			return 0;
		}
	}
	return 2;
}

CNumber CNumber::operator/(CNumber & pcNewVal) {
	//sprawdzam czy s¹ zerami

	CNumber c_result;
	//tmp.i_length = new int;
	//tmp.is_positive = new bool;

	if ((*i_length == 1 && pi_table[0] == 0) || (*pcNewVal.i_length == 1 && pcNewVal.pi_table[0] == 0) ||
		i_which_is_bigger(pi_table,i_length,pcNewVal.pi_table,pcNewVal.i_length) == 1) {

		*c_result.i_length = 1;
		*c_result.is_positive = true;
		c_result.pi_table = new int[*c_result.i_length];
		c_result.pi_table[0] = 0;
		return(c_result);
	}else if (i_which_is_bigger(pi_table, i_length, pcNewVal.pi_table, pcNewVal.i_length) == 2) {
		*c_result.i_length = 1;
		*c_result.is_positive = true;
		c_result.pi_table = new int[*c_result.i_length];
		c_result.pi_table[0] = 1;
		
		return(c_result);
	}
	
	if (((*is_positive) && (*pcNewVal.is_positive)) || (!(*is_positive) && !(*pcNewVal.is_positive))) {

		*c_result.is_positive = true;
	}
	else {
		*c_result.is_positive = false;
	}
	v_div_two_tables(pi_table, i_length, pcNewVal.pi_table, &c_result.pi_table, pcNewVal.i_length, c_result.i_length);
	v_remove_zeroes(&c_result);

	c_result.v_print_table();
	return(c_result);
}

void CNumber::add_at_0_to_table(int** table, int* length, int new_element) {
	//std::cout << "add:";
	int* tmp_table = new int[*length+1];
	tmp_table[0] = new_element;
	for (int i = 0; i < *length; i++) {
		tmp_table[i+1] = ( * table)[i];
	}

	*length = *length + 1;
	delete[](* table);
	*table = new int[*length];

	for (int i = 0; i < *length; i++) {
		(* table)[i] = tmp_table[i];
		//std::cout << (*table)[i];
		
	}

	delete tmp_table;
}

void CNumber::v_div_two_tables(int* this_pi_table, int* this_i_lenght, int* table_div, int** result_table, int* length_table_div, int* length_result_table) {
	//this w nazwie  bardziej chodzi o dzieln¹ (dividend)
	//stworzenie tabicy dzielnikówdzelnika 0-9 int[][]; 
	int** divider_table = new int* [number_system]; //system 10 
	int* dividers_table_table = new int[number_system];
	v_creater_table_of_dividers(divider_table, number_system, table_div, length_table_div, dividers_table_table);

	//tablica wyniku
	//rename this result table to early result or something 
	*result_table = new int[1];
	(* result_table)[0] = 0;
	
	int* part_of_dividend_length = new int;
	*part_of_dividend_length = *length_table_div;

	int* part_of_dividend = new int[*part_of_dividend_length];
	int* counter_of_indexes = new int;

	*counter_of_indexes = ( * i_length - *part_of_dividend_length);
	v_copy_dividend(part_of_dividend, part_of_dividend_length);


	if (i_which_is_bigger(part_of_dividend, part_of_dividend_length, table_div, length_table_div) == 1) {
		*counter_of_indexes -= 1;
		// add at 0 to table
		int* tmp_table = new int[*part_of_dividend_length + 1];
		//2137
		//7312
		tmp_table[0] = pi_table[*counter_of_indexes];
		for (int i = 0; i < *part_of_dividend_length; i++) {
			tmp_table[i+1] = part_of_dividend[i];
		}

		delete part_of_dividend;
		*part_of_dividend_length += 1;
		part_of_dividend = new int[*part_of_dividend_length];

		for (int i = 0; i < *part_of_dividend_length; i++) {
			part_of_dividend[i] = tmp_table[i];
		}
		delete tmp_table;	
	}

	while (*counter_of_indexes > 0) {

		int x = find_result_of_division(divider_table, dividers_table_table, &part_of_dividend, part_of_dividend_length);
		
		add_at_0_to_table(result_table, length_result_table, x);

		*counter_of_indexes -= 1;

		add_at_0_to_table(&part_of_dividend, part_of_dividend_length, pi_table[*counter_of_indexes]);
		v_remove_zeroes1(&part_of_dividend, part_of_dividend_length);

	}

	int x = find_result_of_division(divider_table, dividers_table_table, &part_of_dividend, part_of_dividend_length);
	add_at_0_to_table(result_table, length_result_table, x);
}

void CNumber::v_copy_dividend(int* copied_table, int* length) {
	for (int i = 0; i < *length; i++) {
		copied_table[i] = pi_table[*i_length - *length + i];
	}
}

void CNumber::v_creater_table_of_dividers(int** dividers_table, int div_table_length, int*divider, int* divider_length, int* dividers_table_table) {
	for (int i = 0; i < div_table_length; i++) {
		int* tmp_table = new int[1];
		tmp_table[0] = i;

		int* result_table;
		int* result_table_length = new int;
		int* tmp_1_lenth = new int; 

		*tmp_1_lenth = 1;
		v_mul_two_tables(divider, divider_length, tmp_table, &result_table, tmp_1_lenth, result_table_length);


		delete tmp_1_lenth;
		delete tmp_table;

		//remove zero
		int* index_counter = new int;
		*index_counter = *result_table_length;

		while (result_table[*index_counter - 1] == 0 && *index_counter > 1) {
			*index_counter -= 1;
		}

		dividers_table[i] = new int[*index_counter];
		dividers_table_table[i] = *index_counter;
		//std::cout << "number: ";
		for (int j = 0; j < *index_counter; j++) {
			dividers_table[i][j] = result_table[j];
			//std::cout << dividers_table[i][j]; 
		}
		//std::cout << "\n";

	}
}

int CNumber::find_result_of_division(int** dividers_table, int* dividers_table_length, int**divided_table, int* divided_length) {
	for (int i = 0; i < number_system; i++) { //system
		// jesli bedzie rzucac wyjatkami tu to nizej zmienic &dividers_table_length na bez & a nizej stworzyc jakis wskaznik i zmianna o tej samej wartosci
		
		if (i_which_is_bigger(dividers_table[i], &dividers_table_length[i], *divided_table, divided_length) ==0) {
			for (int j = 0; j < ( dividers_table_length[i - 1]); j++) {
				dividers_table[i - 1][j] *= (-1);
			}
			//todo result table 
			int* result_of_sub;
			int*result_length = new int;

			v_add_two_tables(*divided_table, divided_length, dividers_table[i-1], &result_of_sub, 
				&dividers_table_length[i-1], result_length);
			
			for (int j = 0; j < ( dividers_table_length[i - 1]); j++) {
				dividers_table[i-1][j] *= (-1);
			}

			v_remove_zeroes1(&result_of_sub, result_length);

			bool* tmp_bool_true = new bool;
			*tmp_bool_true = true;
			v_reapir_neagitve_number(result_of_sub, result_length, tmp_bool_true);

			v_remove_zeroes1(&result_of_sub, result_length);
			
			delete tmp_bool_true;
			delete[] (* divided_table);
			
			// przypisanie do nowych
			
			*divided_length = *result_length;
			
			*divided_table = new int[*divided_length];
			for (int i = 0; i < *divided_length; i++) {
				(*divided_table)[i] = result_of_sub[i];
			}
			delete[] result_of_sub;
			delete result_length;

			return i - 1;
		}
		if (i_which_is_bigger(dividers_table[i], &dividers_table_length[i], *divided_table, divided_length) == 2) {
			for (int j = 0; j < (dividers_table_length[i]); j++) {
				dividers_table[i][j] *= (-1);
			}
			//todo result table 
			int* result_of_sub;
			int* result_length = new int;

			v_add_two_tables(*divided_table, divided_length, dividers_table[i], &result_of_sub,
				&dividers_table_length[i], result_length);

			for (int j = 0; j < (dividers_table_length[i]); j++) {
				dividers_table[i][j] *= (-1);
			}

			v_remove_zeroes1(&result_of_sub, result_length);

			bool* tmp_bool_true = new bool;
			*tmp_bool_true = true;
			v_reapir_neagitve_number(result_of_sub, result_length, tmp_bool_true);

			v_remove_zeroes1(&result_of_sub, result_length);

			delete tmp_bool_true;
			delete[](*divided_table);

			// przypisanie do nowych

			*divided_length = *result_length;

			*divided_table = new int[*divided_length];
			for (int i = 0; i < *divided_length; i++) {
				(*divided_table)[i] = result_of_sub[i];
			}
			delete[] result_of_sub;
			delete result_length;

			return i ;
		}
	}


	for (int j = 0; j < (dividers_table_length[number_system - 1]); j++) {
		dividers_table[number_system - 1][j] *= (-1);
	}
	//todo result table 
	int* result_of_sub;
	int* result_length = new int;

	v_add_two_tables(*divided_table, divided_length, dividers_table[number_system - 1], &result_of_sub,
		&dividers_table_length[number_system - 1], result_length);

	for (int j = 0; j < (dividers_table_length[number_system - 1]); j++) {
		dividers_table[number_system - 1][j] *= (-1);
	}

	v_remove_zeroes1(&result_of_sub, result_length);

	bool* tmp_bool_true = new bool;
	*tmp_bool_true = true;
	v_reapir_neagitve_number(result_of_sub, result_length, tmp_bool_true);
	v_remove_zeroes1(&result_of_sub, result_length);

	delete tmp_bool_true;
	delete[](*divided_table);

	*divided_length = *result_length;

	*divided_table = new int[*divided_length];
	for (int i = 0; i < *divided_length; i++) {
		(*divided_table)[i] = result_of_sub[i];
	}
	delete[] result_of_sub;
	delete result_length;

	return number_system - 1;
}

CNumber CNumber::c_Div(CNumber& pcNewVal, CNumber**cRest) {

	CNumber c_num_division;

	if ((*i_length == 1 && pi_table[0] == 0) || (*pcNewVal.i_length == 1 && pcNewVal.pi_table[0] == 0) ||
		i_which_is_bigger(pi_table, i_length, pcNewVal.pi_table, pcNewVal.i_length) == 1) {

		*c_num_division.i_length = 1;
		*c_num_division.is_positive = true;
		c_num_division.pi_table = new int[*c_num_division.i_length];
		c_num_division.pi_table[0] = 0;
		return(c_num_division);
	}
	else if (i_which_is_bigger(pi_table, i_length, pcNewVal.pi_table, pcNewVal.i_length) == 2) {
		*c_num_division.i_length = 1;
		*c_num_division.is_positive = true;
		c_num_division.pi_table = new int[*c_num_division.i_length];
		c_num_division.pi_table[0] = 1;

		return(c_num_division);
	}

	if (((*is_positive) && (*pcNewVal.is_positive)) || (!(*is_positive) && !(*pcNewVal.is_positive))) {
		*c_num_division.is_positive = true;
	}
	else {
		*c_num_division.is_positive = false;
	}

	v_div_two_tables(pi_table, i_length, pcNewVal.pi_table, &c_num_division.pi_table, pcNewVal.i_length, c_num_division.i_length);
	v_remove_zeroes(&c_num_division);

	int* sub_result_table;
	int* sub_result_table_lenght = new int;

	
	for (int i = 0; i < *c_num_division.i_length; i++) {
		c_num_division.pi_table[i] *= (-1);
	}

	v_add_two_tables(pi_table, i_length, c_num_division.pi_table, &sub_result_table, c_num_division.i_length, sub_result_table_lenght);
	
	for (int i = 0; i < *c_num_division.i_length; i++) {
		c_num_division.pi_table[i] *= (-1);
	}
	
	if (*sub_result_table_lenght == 1) {
		if (sub_result_table[0] == 0) {
			cRest = NULL;
		}
		else {
			* cRest = new CNumber;
			
			*(*cRest)->is_positive = true;
			*(*cRest)->i_length = *sub_result_table_lenght;
			delete (*cRest)->pi_table;
			(*cRest)->pi_table = new int[*sub_result_table_lenght];

			for (int i = 0; i < *(*cRest)->i_length; i++) {
				((*cRest)->pi_table)[i] = sub_result_table[i];
			}

			
		}
	}
	else {
		*cRest = new CNumber;

		*(*cRest)->is_positive = true;
		*(*cRest)->i_length = *sub_result_table_lenght;
		delete (*cRest)->pi_table;
		(*cRest)->pi_table = new int[*sub_result_table_lenght];

		for (int i = 0; i < *(*cRest)->i_length; i++) {
			((*cRest)->pi_table)[i] = sub_result_table[i];
		}
	}

	
	delete[] sub_result_table;
	delete sub_result_table_lenght; 


	return c_num_division; 

}