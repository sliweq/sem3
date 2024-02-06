#pragma once
#include <iostream>

int letters_amount = 52;
int numbers_amount = 9;
int operators_amount = 4;

std::string table_of_trygonometric_operators[] = { "sin", "cos" };
int sin_size = 3;
std::string super_sum_operator = "supersum";

std::string table_of_numbers[] = { "1","2","3","4","5","6","7","8","9" };
std::string table_of_letters[] = {
		"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
		"N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
		"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
		"n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
};
std::string table_of_operators[] = { "+","-","/","*" };

std::string node_space_char = " ";

std::string zero_var_string = "0";

std::string error_syntax = "Syntax error\n";

int type_not_added = 0;
int type_sin_cos = 1;
int type_operators_cons = 2;
int type_numbers_0_child = 3;
int type_variables = 4;
int error_type = 5;
int type_supersum = 6;

int super_sum_kids = 4;

int double_index_inc = 2;


int get_type_of_char_illegal_arg = 0; 
int get_type_of_char_int = 1;
int get_type_of_char_operator = 2;
int get_type_of_char_letter = 3; 
int get_type_of_char_space = 4;