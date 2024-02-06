#include "CNode.h"
#include "CTree.h"
#include <vector>
#include <iostream>
#include "CNode_consts.h"
#include <random>
#include <cmath>
#include <string>
#include <string.h>

//TODO metoda która is corrent build <T> -> dla stringów sprawdza stringa | dla inta sprawdza inta itd
// w przypadku liczb sprawdza czy poprawni zbudowane s¹ liczby

//TODO zmienne ka¿dej d³ugoœci nie tylko 1

//TODO solving the problem 

//Notka 01.12.2023
//TODO add_to_node 
//TODO build_typed_value

template <typename T>
CNode<T>::CNode() {
	node_type = type_not_added;
};

template <typename T>
CNode<T>::~CNode<T>() {
	if (node_type == type_sin_cos || node_type == type_operators_cons) {
		for (CNode* node : kids_of_cnode) {
			delete node;
		}
	}
};

template <typename T>
bool CNode<T>::set_node(std::string value, int type) {
	node_value = value;
	node_type = type;
	return true;
}





template <typename T>
int CNode<T>::add_to_node(std::string text, int* index) { return 0; }

template <typename T>
int CNode<T>::build_typed_value(int* index, std::string) { return 0; }



template <typename T>
int CNode<T>::get_type_of_char(char value) {
	if (value == zero_var_string[0]) {
		return get_type_of_char_illegal_arg;
	}

	for (int i = 0; i < numbers_amount; i++) {
		if (value == table_of_numbers[i][0]) {
			return get_type_of_char_int;
		}
	}
	for (int i = 0; i < operators_amount; i++) {
		if (value == table_of_operators[i][0]) {
			return get_type_of_char_operator;
		}
	}
	for (int i = 0; i < letters_amount; i++) {
		if (value == table_of_letters[i][0]) {
			return get_type_of_char_letter;
		}
	}
	if (value == node_space_char[0]) {
		return get_type_of_char_space;
	}
	if (value == dot_char_for_double[0]) {
		return get_type_of_char_dot;
	}
	if (value == quote_mark_char) {
		return get_type_of_char_mark;
	}

	return get_type_of_char_illegal_arg;
}

template <>
void CNode<std::string>::print_this_node() {
	if (node_type == type_numbers_0_child) {
		std::cout << quote_mark_char;
		std::cout << node_value << node_space_char;
		std::cout << quote_mark_char;
	}
	else {
		std::cout << node_value << node_space_char;
	}
	
	//std::cout << node_type << node_space_char;
	//std::cout << "value:" << node_value << std::endl;
	//std::cout << "type:" << node_type << std::endl;
	//std::cout << kids_of_cnode.size();
	for (int i = 0; i < kids_of_cnode.size(); i++) {
		if ((*kids_of_cnode[i]).node_type != 0) {
			(*kids_of_cnode[i]).print_this_node();
		}
		//TODO co to by³o xd
		//if ((*kids_of_cnode[i]).node_type == 0) {
		//	(*kids_of_cnode[i]).print_this_node();
		//}
	}
}

template <typename T>
void CNode<T>::print_this_node(){
	std::cout << node_value << node_space_char;
	//std::cout << node_type << node_space_char;
	//std::cout << "value:" << node_value << std::endl;
	//std::cout << "type:" << node_type << std::endl;
	//std::cout << kids_of_cnode.size();
	for (int i = 0; i < kids_of_cnode.size(); i++) {
		if ((*kids_of_cnode[i]).node_type != 0) {
			(*kids_of_cnode[i]).print_this_node();
		}
		//TODO co to by³o xd
		//if ((*kids_of_cnode[i]).node_type == 0) {
		//	(*kids_of_cnode[i]).print_this_node();
		//}
	}
}

template <typename T>
void CNode<T>::vars_cnode(std::vector <std::string>* vector_of_variables) {
	if (node_type != type_variables) {
		for (int i = 0; i < kids_of_cnode.size(); i++) {
			(*kids_of_cnode[i]).vars_cnode(vector_of_variables);
		}
	}
	else {
		bool was_printed = false;
		for (int i = 0; i < vector_of_variables->size(); i++) {
			if ((*vector_of_variables)[i] == node_value) {
				was_printed = true;
			}
		}
		if (!was_printed) {
			(*vector_of_variables).push_back(node_value);
		}
	}
}

template <typename T>
void CNode<T>::copy_node_value(CNode<T>* originalNode){

	node_type = (*originalNode).node_type;
	node_value = (*originalNode).node_value;

	for (int i = 0; i < (*originalNode).kids_of_cnode.size(); i++) {
		//std::cout << "|" << node_value << "|";
		CNode* copied_child;

		copied_child = new CNode();
		(*copied_child).copy_node_value((*originalNode).kids_of_cnodev[i]);

		kids_of_cnode.push_back(copied_child);
	}
}

template <typename T>
int CNode<T>::get_node_type() {
	return node_type;
}

template <typename T>
void CNode<T>::find_number_node(CNode<T>* originalNode) {
	if (node_type == type_numbers_0_child || node_type == type_variables) {
		copy_node_value(originalNode);
	}
	else {
		if (node_type == type_sin_cos) {
			(*kids_of_cnode[0]).find_number_node(originalNode);
		}
		else {
			//typ 2 +-/*

			//losowo
			/*
			std::random_device rd;
			std::mt19937 gen(rd());

			std::uniform_int_distribution<> distribution(0, kids_of_cnode.size());
			int random_number = distribution(gen);
			(*kids_of_cnode[random_number]).find_number_node(originalNode);
			*/

			//idziemy na lewo

			(*kids_of_cnode[0]).find_number_node(originalNode);
		}
	}

}

template <typename T>
int CNode<T>::is_properly_built() {
	if (node_type == type_not_added) {
		return type_not_added;
	}
	else if (node_type == error_type) {

		std::cout << error_syntax;
		return error_type;
	}
	else {
		if (node_type == type_variables || node_type == type_numbers_0_child) {
			return node_type;
		}
		else {
			for (int i = 0; i < kids_of_cnode.size(); i++) {
				if ((*kids_of_cnode[i]).is_properly_built() == error_type) {
					return error_type;
				}
				if ((*kids_of_cnode[i]).is_properly_built() == type_not_added) {
					return type_not_added;
				}
			}
			return node_type;
		}
	}
}

template <typename T>
void CNode<T>::repair_node() {
	if (node_type == type_not_added) {

		node_type = type_numbers_0_child;
		node_value = table_of_numbers[0];
	}
	else {
		for (int i = 0; i < kids_of_cnode.size(); i++) {
			(*kids_of_cnode[i]).repair_node();
		}
	}
}

template <>
void CNode<std::string>::repair_node() {
	if (node_type == type_not_added) {

		node_type = type_numbers_0_child;
		node_value = table_of_letters[0];
	}
	else {
		for (int i = 0; i < kids_of_cnode.size(); i++) {
			(*kids_of_cnode[i]).repair_node();
		}
	}
}

template <typename T>
std::string CNode<T>::node_answer_the_problem(std::vector <std::string>* vactor_of_digits, std::vector <std::string>* vactor_of_variables) {
	if (node_type == type_numbers_0_child) {
		return node_value;
	}
	if (node_type == type_variables) {
		for (int i = 0; i < (*vactor_of_variables).size(); i++) {
			if (node_value == (*vactor_of_variables)[i]) {
				return (*vactor_of_digits)[i];
			}
		}
	}
	if (node_type == type_sin_cos) {
		if (table_of_trygonometric_operators[0] == node_value) {
			return std::to_string(sin(std::stod((*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables))));
		}
		else {
			return std::to_string(cos(std::stod((*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables))));;
		}
	}
	if (node_type == type_operators_cons) {
		if (node_value == table_of_operators[0]) {
			return std::to_string(std::stod((*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables))
				+ std::stod((*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables)));
		}
		if (node_value == table_of_operators[1]) {
			return std::to_string(std::stod((*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables))
				- std::stod((*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables)));
		}
		if (node_value == table_of_operators[2]) {
			return std::to_string(std::stod((*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables))
				/ std::stod((*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables)));
		}
		if (node_value == table_of_operators[3]) {
			return std::to_string(std::stod((*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables))
				* std::stod((*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables)));
		}
	}
}

template <>
std::string CNode<std::string>::node_answer_the_problem(std::vector <std::string>* vactor_of_digits, std::vector <std::string>* vactor_of_variables) {
	if (node_type == type_numbers_0_child) {
		return node_value;
	}
	if (node_type == type_variables) {
		for (int i = 0; i < (*vactor_of_variables).size(); i++) {
			if (node_value == (*vactor_of_variables)[i]) {
				return (*vactor_of_digits)[i];
			}
		}
	}
	if (node_type == type_operators_cons) {
		if (node_value == table_of_operators[0]) {
			return (*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables) +
				(*kids_of_cnode[1]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);
		}

		if (node_value == table_of_operators[1]) {
			return (*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables) + (*kids_of_cnode[1]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);
		}
		if (node_value == table_of_operators[2]) {
			return (*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables) + (*kids_of_cnode[1]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);
		}
		if (node_value == table_of_operators[3]) {
			return (*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables) + (*kids_of_cnode[1]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);
		}
	}

	return "";


}