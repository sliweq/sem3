#pragma once
#include<iostream>
#include <vector>
#include "CTree.h"
#include "interface_consts.h"

#include <string>


//TODO repair comps for bool

class Interface
{
public:
	Interface();
	void run_get_type_simulation();
	~Interface();

private:

	template <typename T> void start_program(CTree<T>* our_ctree);

	CTree<int>* our_ctree_int;
	CTree<double>* our_ctree_double;
	CTree<std::string>* our_ctree_string;
	CTree<bool>* our_ctree_bool;

	int command_type(std::string text, int* index);
	int get_type_of_char1(char value);

	template <typename T> int check_comp_numbers(CTree<T>* our_ctree, std::vector <std::string>* vactor_of_variables, std::string text, int* index);
};


Interface::Interface() {
	our_ctree_int = new CTree<int>;
	our_ctree_double = new CTree<double>;
	our_ctree_string = new CTree<std::string>;
	our_ctree_bool = new CTree<bool>;
}

Interface::~Interface() {
	delete our_ctree_int;
	delete our_ctree_double;
	delete our_ctree_string;
	delete our_ctree_bool;
}

void Interface::run_get_type_simulation() {
	std::string command_string = "";
	std::cout << mess_type_of_ctree;

	int command_as_number = 0;
	int* index;
	index = new int;
	*index = 0;

	int tree_type = ctree_quiting;

	while (command_as_number != interface_command_quit) {

		std::getline(std::cin, command_string);

		command_as_number = command_type(command_string, index);

		if (command_as_number == intreface_command_string) {
			tree_type = ctree_type_string;
			command_as_number = interface_command_quit;
		}
		else if (command_as_number == interface_command_int) {
			tree_type = ctree_type_int;
			command_as_number = interface_command_quit;
		}
		else if (command_as_number == interface_command_double) {
			tree_type = ctree_type_double;
			command_as_number = interface_command_quit;
		}
		else if (command_as_number == interface_command_quit) {
			std::cout << quiting_mess;
			tree_type = ctree_quiting;
		}
		else if (command_as_number == interface_command_bool) {
			tree_type = ctree_type_bool;
			command_as_number = interface_command_quit;
		}
		else {
			std::cout << unknown_command;
		}
	}

	if (tree_type == ctree_type_string) {
		start_program(our_ctree_string);
	}
	else if (tree_type == ctree_type_int) {
		start_program(our_ctree_int);
	}
	else if (tree_type == ctree_type_double) {
		start_program(our_ctree_double);
	}
	else if (tree_type == ctree_type_bool) {
		start_program(our_ctree_bool);
	}


	delete index;
}

template <typename T>
inline void Interface::start_program(CTree<T>* our_ctree) {

	std::string command_string = "";

	int command_as_number = 0;

	int* index;
	index = new int;
	*index = 0;

	std::cout << menu_string;

	bool has_been_created = false;

	*index = 0;


	while (command_as_number != interface_command_quit) {
		std::cout << enter_formula_mess;

		std::getline(std::cin, command_string);

		command_as_number = command_type(command_string, index);

		if (command_as_number == interface_command_enter) {

			//int* index = 0;
			//std::cout << *index;
			if (has_been_created) {
				our_ctree->clean_tree();
				has_been_created = false;
			}

			if (!(our_ctree->create_tree(command_string, index))) {

				our_ctree->clean_tree();
				std::cout << error_tree_aborted;
			}
			else {
				has_been_created = true;
				std::cout << communique_tree_created;
			}

		}
		else if (command_as_number == interface_command_vars) {
			if (has_been_created) {
				our_ctree->vars_ctree();
				std::cout << std::endl;
			}
			else {
				std::cout << error_tree_noe_exists;
			}

		}
		else if (command_as_number == interface_command_print) {
			if (has_been_created) {
				our_ctree->print_tree();
			}
			else {
				std::cout << error_tree_noe_exists;
			}
		}
		else if (command_as_number == interface_command_comp) {
			//std::cout << has_been_created;
			if (!has_been_created) {
				std::cout << error_tree_noe_exists;
			}
			else {
				std::vector <std::string>* vector_of_numbers;
				vector_of_numbers = new std::vector<std::string>;

				int comp_check = check_comp_numbers(our_ctree, vector_of_numbers, command_string, index);

				//std::cout << our_ctree->variables_amount() <<"|" << (*vector_of_numbers).size();

				if (comp_check == type_check_comp_number_ok) {

					if ((*vector_of_numbers).size() > our_ctree->variables_amount()) {
						std::cout << too_much_variables_comp;
						std::cout << result_mess;
						std::cout << our_ctree->tree_solve_the_problem(vector_of_numbers) << std::endl;

						// za du?o zmiennych ale git
					}
					else if ((*vector_of_numbers).size() < our_ctree->variables_amount()) {
						std::cout << error_need_variables;
					}
					else {
						//std::cout << too_much_variables_comp;
						std::cout << result_mess;
						std::cout << our_ctree->tree_solve_the_problem(vector_of_numbers) << std::endl;
						//jest idealnie
					}
				}
				else if (comp_check == type_check_comp_number_err) {

					std::cout << error_need_variables;
				}
				else {
					std::cout << only_letters;
				}
				delete vector_of_numbers;

			}
		}
		else if (command_as_number == interface_command_join) {
			if (!has_been_created) {
				std::cout << error_tree_noe_exists;
			}
			else {
				CTree<T> new_tree;

				if (!new_tree.create_tree(command_string, index)) {

					new_tree.clean_tree();
					std::cout << error_tree_aborted;
				}
				else {
					has_been_created = true;
					std::cout << communique_tree_created;
					(*our_ctree) = (*our_ctree) + new_tree;
				}
			}

			//std::cout << "joining...\n";
		}
		else if (command_as_number == interface_command_quit) {
			std::cout << quiting_mess;
		}
		else if (command_as_number == interface_command_error) {
			std::cout << error_need_variables;
		}
		else {
			std::cout << unknown_command;
		}

		*index = 0;
	}

	delete index;
};

int Interface::command_type(std::string text, int* index) {

	*index = 0;
	while (*index < text.length() && text[*index] == space_char[0]) {
		*index += 1;
	}
	if (*index >= text.length()) {
		return interface_command_default_value;
	}
	if (text[*index] == command_enter[0]) {
		int command_index = 1;
		*index += 1;
		while (*index < text.length() && text[*index] == command_enter[command_index]) {
			if (command_enter.length() == command_index + 1) {
				if (*index + 1 >= text.length()) {
					return interface_command_error;
				}
				if (text[(*index) + 1] != space_char[0]) {
					return interface_command_default_value;
				}
				return interface_command_enter;
			}
			*index += 1;
			command_index += 1;
		}
		return interface_command_default_value;
	}
	else if (text[*index] == command_vars[0]) {
		//command_vars
		int command_index = 1;
		*index += 1;
		while (*index < text.length() && text[*index] == command_vars[command_index]) {
			if (command_vars.length() == command_index + 1) {
				return interface_command_vars;
			}
			*index += 1;
			command_index += 1;
		}
		return interface_command_default_value;
	}
	else if (text[*index] == command_print[0]) {
		//command_print
		int command_index = 1;
		*index += 1;
		while (*index < text.length() && text[*index] == command_print[command_index]) {
			if (command_print.length() == command_index + 1) {
				if (*index + 1 >= text.length()) {
					return interface_command_print;
				}
				if (text[*index + 1] != space_char[0]) {
					return interface_command_default_value;
				}
				return interface_command_print;
			}
			*index += 1;
			command_index += 1;
		}
		return interface_command_default_value;
	}
	else if (text[*index] == command_comp[0]) {
		int command_index = 1;
		*index += 1;
		while (*index < text.length() && text[*index] == command_comp[command_index]) {
			if (command_comp.length() == command_index + 1) {
				if (*index + 1 >= text.length()) {
					return interface_command_comp;
				}
				if (text[*index + 1] != space_char[0]) {
					return interface_command_default_value;
				}
				return interface_command_comp;
			}
			*index += 1;
			command_index += 1;
		}

		return interface_command_default_value;
	}
	else if (text[*index] == command_join[0]) {
		int command_index = 1;
		*index += 1;
		while (*index < text.length() && text[*index] == command_join[command_index]) {
			if (command_join.length() == command_index + 1) {
				if (*index + 1 >= text.length()) {
					return interface_command_error;
				}
				if (text[*index + 1] != space_char[0]) {
					return interface_command_default_value;
				}
				return interface_command_join;
			}
			*index += 1;
			command_index += 1;
		}
		return interface_command_default_value;
	}
	else if (text[*index] == command_quit[0]) {
		if (*index + 1 >= text.length()) {
			return interface_command_quit;
		}
		while (text[*index] <= text.length()) {
			if (text[*index] != space_char[0]) {
				return interface_command_error;
			}
			*index += 1;
		}
		return interface_command_quit;

	}

	else if (text[*index] == command_string[0]) {
		int command_index = 1;
		*index += 1;
		while (*index < text.length() && text[*index] == command_string[command_index]) {
			if (command_string.length() == command_index + 1) {
				*index += 1;
				while (*index < text.length()) {
					if (text[*index] != space_char[0]) {
						return interface_command_error;
					}
					*index += 1;

				}
				if (*index >= text.length()) {
					return intreface_command_string;
				}
				return intreface_command_string;
			}
			*index += 1;
			command_index += 1;
		}
		return interface_command_default_value;
	}

	else if (text[*index] == command_int[0]) {
		int command_index = 1;
		*index += 1;
		while (*index < text.length() && text[*index] == command_int[command_index]) {
			if (command_int.length() == command_index + 1) {
				*index += 1;
				while (*index < text.length()) {
					if (text[*index] != space_char[0]) {
						return interface_command_error;
					}
					*index += 1;

				}
				if (*index >= text.length()) {
					return interface_command_int;
				}
				return interface_command_int;
			}
			*index += 1;
			command_index += 1;
		}
		return interface_command_default_value;
	}

	else if (text[*index] == command_double[0]) {

		int command_index = 1;
		*index += 1;
		while (*index < text.length() && text[*index] == command_double[command_index]) {
			if (command_double.length() == command_index + 1) {
				*index += 1;
				while (*index < text.length()) {
					if (text[*index] != space_char[0]) {
						return interface_command_error;
					}
					*index += 1;

				}
				if (*index >= text.length()) {
					return interface_command_double;
				}
				return interface_command_double;
			}
			*index += 1;
			command_index += 1;
		}
		return interface_command_default_value;
	}

	else if (text[*index] == command_bool[0]) {

		int command_index = 1;
		*index += 1;
		while (*index < text.length() && text[*index] == command_bool[command_index]) {
			if (command_bool.length() == command_index + 1) {
				*index += 1;
				while (*index < text.length()) {
					if (text[*index] != space_char[0]) {
						return interface_command_error;
					}
					*index += 1;

				}
				if (*index >= text.length()) {
					return interface_command_bool;
				}
				return interface_command_bool;
			}
			*index += 1;
			command_index += 1;
		}
		return interface_command_default_value;
	}


	return interface_command_default_value;
}

template <>
inline int Interface::check_comp_numbers(CTree<std::string>* our_ctree, std::vector <std::string>* vactor_of_variables, std::string text, int* index) {
	//return 0 wszystko git
	//return 1 syntax error
	//return 2 tylko liczby mo?na

	std::string tmp_text = "";
	*index += 1;
	while (*index < text.length() && text[*index] == node_space_char[0]) {
		*index += 1;
	}
	if (*index >= text.size()) {
		return type_check_comp_number_ok;
	}

	while (*index < text.length()) {

		tmp_text = "";
		if (get_type_of_char1(text[*index]) != get_type_of_char_mark1) {
			return type_check_comp_number_not;
		}
		*index += 1;
		while (*index < text.length() &&
			(get_type_of_char_letter1 == get_type_of_char1(text[*index]) || get_type_of_char1(text[*index]) == get_type_of_char_mark1)) {
			if (get_type_of_char1(text[*index]) == get_type_of_char_mark1) {
				(*vactor_of_variables).push_back(tmp_text);
				tmp_text = "";
				*index += 1;
			}
			else {
				tmp_text += text[*index];
				*index += 1;
			}
		}
		if (*index >= text.length()) {
			if (tmp_text.length() > 0) {
				(*vactor_of_variables).push_back(tmp_text);
			}
			return type_check_comp_number_ok;
		}
		if (get_type_of_char1(text[*index]) == get_type_of_char_space1) {
			if (tmp_text.length() > 0) {
				(*vactor_of_variables).push_back(tmp_text);
			}

			tmp_text = "";
		}

		else {
			return type_check_comp_number_not;
		}
		*index += 1;
	}
	std::cout << tmp_text;
	if (tmp_text.size() != 0) {
		(*vactor_of_variables).push_back(tmp_text);
	}
	return type_check_comp_number_ok;

}

template <>
inline int Interface::check_comp_numbers(CTree<int>* our_ctree, std::vector <std::string>* vactor_of_variables, std::string text, int* index) {
	//return 0 wszystko git
	//return 1 syntax error
	//return 2 tylko liczby mo?na

	std::string tmp_text = "";
	*index += 1;

	while (*index < text.length() && text[*index] == node_space_char[0]) {
		*index += 1;
	}
	if (*index >= text.size()) {
		return type_check_comp_number_ok;
	}

	while (*index < text.length()) {

		tmp_text = "";
		while (*index < text.length() &&
			(get_type_of_char_int1 == get_type_of_char1(text[*index]) || get_type_of_char_zero == get_type_of_char1(text[*index]))) {

			tmp_text += text[*index];
			*index += 1;
		}
		if (*index >= text.length()) {
			if (std::stoi(tmp_text) == 0) {
				return type_check_comp_number_not;
			}
			(*vactor_of_variables).push_back(tmp_text);
			return type_check_comp_number_ok;
		}
		if (get_type_of_char1(text[*index]) == get_type_of_char_space1) {
			if (std::stoi(tmp_text) == 0) {
				return type_check_comp_number_not;
			}
			(*vactor_of_variables).push_back(tmp_text);
			tmp_text = "";
		}
		else {
			return type_check_comp_number_not;
		}

		*index += 1;
	}
	//std::cout << tmp_text;
	if (tmp_text.size() != 0) {
		if (std::stoi(tmp_text) == 0) {
			return type_check_comp_number_not;
		}
		(*vactor_of_variables).push_back(tmp_text);
	}
	return type_check_comp_number_ok;
}

template <>
inline int Interface::check_comp_numbers(CTree<double>* our_ctree, std::vector <std::string>* vactor_of_variables, std::string text, int* index) {

	//return 0 wszystko git
	//return 1 syntax error
	//return 2 tylko liczby mo?na

	std::string tmp_text = "";
	*index += 1;

	while (*index < text.length() && text[*index] == node_space_char[0]) {
		*index += 1;
	}
	if (*index >= text.size()) {
		return type_check_comp_number_ok;
	}

	while (*index < text.length()) {

		tmp_text = "";
		bool contains_dot = false;
		while (*index < text.length() &&
			(get_type_of_char_int1 == get_type_of_char1(text[*index]) || get_type_of_char_zero == get_type_of_char1(text[*index]))
			|| get_type_of_char_dot1 == get_type_of_char1(text[*index])) {
			if (get_type_of_char_dot1 == get_type_of_char1(text[*index])) {
				if (contains_dot || tmp_text.size() == 0) {
					return type_check_comp_number_not;
				}
				contains_dot = true;

			}
			tmp_text += text[*index];
			*index += 1;
		}

		if (*index >= text.length()) {
			if (std::stod(tmp_text) == 0) {
				return type_check_comp_number_not;
			}
			(*vactor_of_variables).push_back(tmp_text);
			return type_check_comp_number_ok;
		}
		if (get_type_of_char1(text[*index]) == get_type_of_char_space1) {
			if (std::stod(tmp_text) == 0) {
				return type_check_comp_number_not;
			}
			(*vactor_of_variables).push_back(tmp_text);
			tmp_text = "";
		}
		else {
			return type_check_comp_number_not;
		}

		*index += 1;
	}
	//std::cout << tmp_text;
	if (tmp_text.size() != 0) {
		if (std::stod(tmp_text) == 0) {
			return type_check_comp_number_not;
		}
		(*vactor_of_variables).push_back(tmp_text);
	}
	return type_check_comp_number_ok;
}

template <typename T>
inline int Interface::check_comp_numbers(CTree<T>* our_ctree, std::vector <std::string>* vactor_of_variables, std::string text, int* index) {

	//return 0 wszystko git
	//return 1 syntax error
	//return 2 tylko liczby mo?na

	std::string tmp_text = "";
	*index += 1;

	while (*index < text.length() && text[*index] == node_space_char[0]) {
		*index += 1;
	}
	if (*index >= text.size()) {
		return type_check_comp_number_ok;
	}

	while (*index < text.length()) {

		tmp_text = "";
		if (text[*index] == zero_var_string1[0] || text[*index] == table_of_numbers1[0][0]) {
			tmp_text += text[*index];
			(*vactor_of_variables).push_back(tmp_text);
			tmp_text = "";
			*index += 1;
		}
		//std::cout << "|" << text[*index] << "|";
		if (*index >= text.length()) {
			(*vactor_of_variables).push_back(tmp_text);
			return type_check_comp_number_ok;
		}
		if (get_type_of_char1(text[*index]) == get_type_of_char_space1) {
			(*vactor_of_variables).push_back(tmp_text);
			tmp_text = "";
		}
		else {
			return type_check_comp_number_not;
		}
		*index += 1;
	}
	//std::cout << tmp_text;
	if (tmp_text.size() != 0) {
		(*vactor_of_variables).push_back(tmp_text);
	}
	return type_check_comp_number_ok;
}

int Interface::get_type_of_char1(char value) {
	if (value == zero_var_string1[0]) {
		return get_type_of_char_zero;
	}

	for (int i = 0; i < numbers_amount1; i++) {
		if (value == table_of_numbers1[i][0]) {
			return get_type_of_char_int1;
		}
	}
	for (int i = 0; i < letters_amount1; i++) {
		if (value == table_of_letters1[i][0]) {
			return get_type_of_char_letter1;
		}
	}
	if (value == space_char[0]) {
		return get_type_of_char_space1;
	}
	if (value == dot_char_for_double1[0]) {
		return get_type_of_char_dot1;
	}
	if (value == quote_mark_char1) {
		return get_type_of_char_mark1;
	}
	return get_type_of_char_illegal_arg;
}