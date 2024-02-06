#pragma once
#include <iostream>

std::string menu_string = "Menu:"
"\n\tenter <formula> -enter formula in prefix notation"
"\n\tvars - print all variable in last enterd tree"
"\n\tprint - print tree in prefix notation"
"\n\tcomp <var0><var1><var2>...<varN> - calculate value of entered formula"
"\n\tjoin <formula> - create a new tree and extend the existing tree with a new one"
"\n\tq - quit program\n";

std::string enter_formula = "Enter formula:\n";

std::string to_much_variables = "Too much variables, tree has been created but last variables are missing\n";
std::string too_much_variables_comp = "Too much variables\n";
std::string unknown_command = "Command not found\n";
std::string communique_tree_created = "Tree created successfully\n";

std::string error_tree_noe_exists = "Tree hasnt been created\n";
std::string error_need_variables = "Formula needs more variables\n";
std::string error_unknown_sign = "Unknown sign in formula\n";
std::string error_tree_aborted = "Tree creation was interrupted\n";
std::string only_digits = "Remember only positive digits allowed in formula!\n";

std::string quiting_mess = "quiting...\n";

std::string result_mess = "Tree result: ";
std::string enter_formula_mess = "Enter formula:\n";


std::string command_enter = "enter";
std::string command_vars = "vars";
std::string command_print = "print";
std::string command_comp = "comp";
std::string command_join = "join";
std::string command_quit = "q";

int type_check_comp_number_ok = 0;
int type_check_comp_number_err = 1;
int type_check_comp_number_not = 2;

int interface_command_enter = 1;
int interface_command_vars = 2;
int interface_command_print = 3;
int interface_command_comp = 4;
int interface_command_join = 5;
int interface_command_quit = 6;
int interface_command_error = 7;

int command_vars_n = 2;
int command_print_n = 3;
int command_comp_n = 4;
int command_join_n = 5;
int command_quit_n = 6;
int command_erorr = 7;

std::string table_of_numbers1[] = { "1","2","3","4","5","6","7","8","9" };
int numbers_amount1 = 9;

std::string space_char = " ";