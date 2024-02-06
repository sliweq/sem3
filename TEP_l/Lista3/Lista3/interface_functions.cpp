#include "interface_functions.h"
#include "interface_consts.h"
#include "CTree.h"
#include <iostream>
#include <string>


void start_program() {

	std::string command_string = "";
	std::cout << menu_string;

	CTree our_ctree;

	bool has_been_created = false;
	
	int command_as_number = 0;
	int* index;
	index = new int; 
	*index = 0; 

	while(command_as_number != command_quit_n){

			/*
		std::string command_enter = "enter"; 1
		std::string command_vars = "vars"; 2
		std::string command_print = "print"; 3
		std::string command_comp = "comp"; 4
		std::string command_join = "join"; 5
		std::string command_quit = "q"; 6
		std::string not enought arguments 7
		*/

		std::cout << enter_formula_mess;

		std::getline(std::cin, command_string);

		//std::cout << command_string << "\n";
		command_as_number = command_type(command_string,index);

		if (command_as_number == command_enter_n) {

			//int* index = 0;
			//std::cout << *index;
			if (has_been_created) {
				our_ctree.clean_tree();
				has_been_created = false;
			}
			
			if (!our_ctree.create_tree(command_string, index)) {
				
				our_ctree.clean_tree();
				std::cout << error_tree_aborted;
			}
			else {
				has_been_created = true;
				std::cout << communique_tree_created;
			}
			
		}
		else if (command_as_number == command_vars_n) {
			if (has_been_created) {
				our_ctree.vars_ctree();
				std::cout << std::endl;
			}
			else {
				std::cout << error_tree_noe_exists;
			}

		}
		else if (command_as_number == command_print_n) {
			if (has_been_created) {
				our_ctree.print_tree();
			}
			else {
				std::cout << error_tree_noe_exists;
			}
		}
		else if (command_as_number == command_comp_n) {
			//std::cout << has_been_created;
			if (!has_been_created) {
				std::cout << error_tree_noe_exists;
			}
			else {
				std::vector <std::string>* vector_of_numbers;
				vector_of_numbers = new std::vector<std::string>;

				int comp_check = check_comp_numbers(vector_of_numbers, command_string, index);
				if (comp_check == type_check_comp_number_ok) {
					if ((*vector_of_numbers).size() > our_ctree.variables_amount()) {
						std::cout << too_much_variables_comp;
						std::cout << result_mess;
						std::cout << our_ctree.tree_solve_the_problem(vector_of_numbers) << std::endl;
						
						// za du¿o zmiennych ale git
					}
					else if ((*vector_of_numbers).size() < our_ctree.variables_amount()) {
						std::cout << error_need_variables;
					}
					else {
						//std::cout << too_much_variables_comp;
						std::cout << result_mess;
						std::cout << our_ctree.tree_solve_the_problem(vector_of_numbers) << std::endl;
						//jest idealnie
					}
				}
				else if (comp_check == type_check_comp_number_err) {
					
					std::cout << error_need_variables;
				}
				else {
					std::cout << only_digits;
				}
				delete vector_of_numbers;

			}
		}
		else if (command_as_number == command_join_n) {
			if (!has_been_created) {
				std::cout << error_tree_noe_exists;
			}
			else {
				CTree new_tree;
				if (!new_tree.create_tree(command_string, index)) {

					new_tree.clean_tree();
					std::cout << error_tree_aborted;
				}
				else {
					has_been_created = true;
					std::cout << communique_tree_created;
				}
				our_ctree = our_ctree + new_tree;
			}
			
			//std::cout << "joining...\n";
		}
		else if (command_as_number == command_quit_n) {
			std::cout << quiting_mess;
		}
		else if( command_as_number == command_erorr){
			std::cout << error_need_variables;
		}
		else {
			std::cout << unknown_command; 
		}

		*index = 0;
	}

	delete index;
};

int command_type(std::string text, int* index) {
	/*
	std::string command_enter = "enter"; 1
	std::string command_vars = "vars"; 2 
	std::string command_print = "print"; 3 
	std::string command_comp = "comp"; 4 
	std::string command_join = "join"; 5 
	std::string command_quit = "q"; 6 
	std::string not enought arguments 7 
	*/

	*index = 0;
	while (*index < text.length() && text[*index] == space_char[0]) {
		*index += 1;
	}
	if (text[*index] == command_enter[0]) {
		int command_index = 1;
		*index += 1;
		while (*index < text.length() && text[*index] == command_enter[command_index]) {
			if (command_enter.length() == command_index + 1) {
				if (*index + 1 >= text.length()) {
					return command_erorr;
				}
				if (text[(*index)+1] != space_char[0]) {
					return 0;
				}
				return command_enter_n;
			}
			*index += 1;
			command_index += 1;
		}
		return 0;
	}
	else if (text[*index] == command_vars[0]) {
		//command_vars
		int command_index = 1;
		*index += 1;
		while (*index < text.length() && text[*index] == command_vars[command_index]) {
			if (command_vars.length() == command_index + 1) {
				return command_vars_n;
			}
			*index += 1;
			command_index += 1;
		}
		return 0;
	}
	else if (text[*index] == command_print[0]) {
		//command_print
		int command_index = 1;
		*index += 1;
		while (*index < text.length() && text[*index] == command_print[command_index]) {
			if (command_print.length() == command_index + 1) {
				if (*index + 1 >= text.length()) {
					return command_print_n;
				}
				if (text[*index + 1] != space_char[0]) {
					return 0;
				}
				return command_print_n;
			}
			*index += 1;
			command_index += 1;
		}
		return 0;
	}
	else if (text[*index] == command_comp[0]) {
		int command_index = 1;
		*index += 1;
		while (*index < text.length() && text[*index] == command_comp[command_index]) {
			if (command_comp.length() == command_index + 1) {
				if (*index + 1 >= text.length()) {
					return command_comp_n;
				}
				if (text[*index + 1] != space_char[0]) {
					return 0;
				}
				return command_comp_n;
			}
			*index += 1;
			command_index += 1;
		}
	
		return 0;
	}
	else if (text[*index] == command_join[0]) {
		int command_index = 1;
		*index += 1;
		while (*index < text.length() && text[*index] == command_join[command_index]) {
			if (command_join.length() == command_index + 1) {
				if (*index + 1 >= text.length()) {
					return command_erorr;
				}
				if (text[*index + 1] != space_char[0]) {
					return 0;
				}
				return command_join_n;
			}
			*index += 1;
			command_index += 1;
		}
		return 0;
	}
	else if (text[*index] == command_quit[0]) {

		if (*index + 1 >= text.length()) {
			return command_quit_n;
		}
		if (text[*index + 1] == space_char[0]) {
			return command_quit_n;
		}
	}
	//std::cout << "asdasd";
	return 0;
}

int check_comp_numbers(std::vector <std::string>* vactor_of_variables, std::string text, int* index) {
	//return 0 wszystko git
	//return 2 tylko liczby mo¿na

	*index += 1;
	
	if (*index >= text.length()) {
		return 0;
	}
	int last_sign = 0; 
	//0 space
	//1 number

	while (*index < text.length()) {
		int sign = 0;
		if (text[*index] == space_char[0]) {
			last_sign = 0;
			//std::cout << "s" << *index << "s";
			*index += 1;
			//std::cout << "s" << *index << "s";
			sign = 1;
		}
		else {
			for (int i = 0; numbers_amount1 > i; i++) {
				if (table_of_numbers1[i][0] == text[*index]) {
					if (last_sign == 0) {
						//dodawanie
						(*vactor_of_variables).push_back(table_of_numbers1[i]);
						//std::cout << "l" << *index << "l";
						*index += 1;
						//std::cout << "l" << *index << "l";
						sign = 1;
						last_sign = 1;
					}
					else {
						return type_check_comp_number_not;
					}

				}
			}
		}
		//std::cout << "a" << *index << "a";
		//std::cout << "|"<< sign<< "|";
		if (sign == 0) {
			//std::cout << *index;
			return type_check_comp_number_not;
		}
	}
	return 0;
}
