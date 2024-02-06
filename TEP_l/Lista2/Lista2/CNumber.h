#pragma once
#include <string>


class CNumber {
public:
	CNumber();
	CNumber(const CNumber& pcOther);
	~CNumber();
	
	void operator =(const int iValue);
	void operator=(const CNumber& pcOther);
	CNumber operator+(const CNumber& pcNewVal);
	CNumber operator-(const CNumber& pcNewVal);
	CNumber  operator*(const CNumber& pcNewVal);
	CNumber operator/( CNumber& pcNewVal);

	CNumber c_Div(CNumber& pcNewVal, CNumber** cRest);

	void v_add_two_tables(int* this_pi_table, int* this_i_length, int* table_add, int** result_table, int* length_table_add, int* length_result_table);
	void v_reapir_neagitve_number(int* result_table, int* length_result_table, bool* result_is_positive);
	void v_remove_zeroes(CNumber* result_table);
	void v_remove_zeroes1(int** zero_pi_table, int* zero_i_length);
	void v_mul_two_tables(int* this_pi_table, int* this_i_lenght, int* table_mul, int** result_table, int* length_table_mul, int* length_result_table);

	int i_which_is_bigger(int* this_pi_table, int* this_i_length, int* input_pi_table, int* input_i_length); // 0 -this 1 - pcNewVal 2- equal
	void v_div_two_tables(int* this_pi_table, int* this_i_lenght, int* table_div, int** result_table, int* length_table_div, int* length_result_table);
	void v_creater_table_of_dividers(int** dividers_table, int div_table_length, int* divider, int* divider_length, int* dividers_table_table);

	void add_at_0_to_table(int** table, int* length, int new_element);
	void v_copy_dividend(int*copied_table, int* length);
	int find_result_of_division(int** dividers_table, int* dividers_table_length, int**divided_table, int* divided_length);

	void v_print_table();
	std::string sToStr();
private:
	int* pi_table;
	int *i_length;
	bool* is_positive;

};
