#pragma once
#pragma once
#include <vector>
#include <iostream>
#include "CNode_consts.h"
#include <random>
#include <cmath>
#include <string>
#include <string.h>

template <typename T> class CNode
{
private:
	int node_type;
	std::string node_value;

	std::vector <CNode<T>*> kids_of_cnode; //kids_vector

public:
	~CNode<T>();
	CNode<T>();
	int add_to_node(std::string text, int* index);
	void print_this_node();
	int get_type_of_char(char value);
	bool set_node(std::string value, int type); // node value type T 

	int build_typed_value(int* index, std::string);

	void vars_cnode(std::vector <std::string>* vactor_of_variables);
	void copy_node_value(CNode<T>* originalNode);
	int get_node_type();


	void find_number_node(CNode<T>* originalNode);
	int is_properly_built();

	void repair_node();
	std::string node_answer_the_problem(std::vector <std::string>* vactor_of_digits, std::vector <std::string>* vactor_of_variables);
};

template <typename T>
inline CNode<T>::CNode() {
	node_type = type_not_added;
};

template <typename T>
inline CNode<T>::~CNode<T>() {
	if (node_type == type_sin_cos || node_type == type_operators_cons) {
		for (CNode* node : kids_of_cnode) {
			delete node;
		}
	}
};

template <typename T>
inline bool CNode<T>::set_node(std::string value, int type) {
	node_value = value;
	node_type = type;
	return true;
}

/*---------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------*/

template <>
inline int CNode<std::string>::add_to_node(std::string text, int* index) {
	*index += 1;
	if (*index >= text.length()) {

		return *index;
	}
	if (text[*index] != node_space_char[0]) {
		node_type = error_type;
		return *index;
	}

	while (*index < text.length() && text[*index] == node_space_char[0]) {
		*index += 1;
	}
	if (*index >= text.length()) {
		return *index;
	}

	int type_of_char = get_type_of_char(text[*index]);

	if (type_of_char == get_type_of_char_mark) {

		*index = build_typed_value(index, text);
		return *index;
	}

	if (type_of_char == get_type_of_char_letter) {

		*index = build_typed_value(index, text);
		return *index;

	}
	if (type_of_char == get_type_of_char_operator) {
		if (*index + 1 >= text.length()) {

			set_node(std::string(1, text[*index]), type_operators_cons);
			return *index;
		}
		// enter + 1 2 
		set_node(std::string(1, text[*index]), type_operators_cons);
		//std::cout << *index;
		//std::cout << "|" << text[*index + 1] <<"|";
		if (text[*index + 1] == node_space_char[0]) {
			while (*index < text.length() && kids_of_cnode.size() < double_index_inc) {

				CNode* one_child = new CNode();
				kids_of_cnode.push_back(one_child);
				(*one_child).add_to_node(text, index);
			}
			return *index;
		}
	}
	node_type = error_type;
	*index = text.length();
	return *index;
}

template <>
inline int CNode<std::string>::build_typed_value(int* index, std::string text) {
	//"  a  asd "a"
	std::string tmp_text = "";
	bool does_contains_mark = false;

	if (get_type_of_char(text[*index]) == get_type_of_char_mark) {
		*index += 1;
		does_contains_mark = true;
	}
	if (*index + 1 >= text.size()) {
		if (does_contains_mark) {
			node_type = error_type;
			*index = text.length();
			return *index;
		}
		else {
			set_node(std::string(1, text[*index]), type_variables);
			return *index;
		}
	}

	while (*index < text.length() &&
		(get_type_of_char(text[*index]) == get_type_of_char_letter
			|| get_type_of_char(text[*index]) == get_type_of_char_mark)) {

		if (get_type_of_char(text[*index]) == get_type_of_char_mark) {
			if (does_contains_mark) {
				set_node(tmp_text, type_numbers_0_child);
				//std::cout << "|" << tmp_text << "|";
				return *index;
			}
			else {
				node_type = error_type;
				*index = text.length();
				return *index;
			}

		}

		tmp_text += text[*index];
		*index += 1;
	}

	if (*index >= text.length()) {
		if (does_contains_mark) {
			node_type = error_type;
			*index = text.length();
			return *index;
		}
		set_node(tmp_text, type_variables);
		return *index;
	}

	if (get_type_of_char(text[*index]) == get_type_of_char_space) {
		if (does_contains_mark) {
			node_type = error_type;
			*index = text.length();
			return *index;
		}
		*index -= 1;
		set_node(tmp_text, type_variables);
		return *index;
	}
	node_type = error_type;
	*index = text.length();
	return *index;
}

/*---------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------*/

template <typename T>
inline int CNode<T>::add_to_node(std::string text, int* index) {
	*index += 1;
	if (*index >= text.length()) {

		return *index;
	}
	if (text[*index] != node_space_char[0]) {
		node_type = error_type;
		return *index;
	}

	while (*index < text.length() && text[*index] == node_space_char[0]) {
		*index += 1;
	}
	if (*index >= text.length()) {
		return *index;
	}

	int type_of_char = get_type_of_char(text[*index]);

	if (type_of_char == get_type_of_char_int || zero_var_string[0] == text[*index]) {
		*index = build_typed_value(index, text);
		return *index;
	}
	if (type_of_char == get_type_of_char_operator) {
		if (*index + 1 >= text.length()) {

			set_node(std::string(1, text[*index]), type_operators_cons);
			return *index;
		}
		// enter + 1 2 
		set_node(std::string(1, text[*index]), type_operators_cons);
		//std::cout << *index;
		//std::cout << "|" << text[*index + 1] <<"|";
		if (text[*index + 1] == node_space_char[0]) {
			while (*index < text.length() && kids_of_cnode.size() < double_index_inc) {
				CNode* one_child = new CNode();
				kids_of_cnode.push_back(one_child);
				(*one_child).add_to_node(text, index);
			}
			return *index;
		}
	}
	if (type_of_char == get_type_of_char_letter) {
		std::string tmp_text = "";
		tmp_text += text[*index];

		//sprawdzamy czy to sinus
		if (text[*index] == table_of_trygonometric_operators[0][0]) {

			*index += 1;
			int trygonometric_index = 1;
			bool is_same_as_trygonometric = true;

			while (*index < text.length() && trygonometric_index < sin_size && get_type_of_char(text[*index]) == get_type_of_char_letter) {
				tmp_text += text[*index];
				if (text[*index] != table_of_trygonometric_operators[0][trygonometric_index]) {

					is_same_as_trygonometric = false;
					trygonometric_index = sin_size;
				}
				*index += 1;
				trygonometric_index += 1;
			}

			if (*index > text.length()) {
				if (is_same_as_trygonometric) {
					set_node(table_of_trygonometric_operators[0], type_sin_cos);
					return *index;
				}
				set_node(tmp_text, type_variables);
				return *index;

			}
			if (get_type_of_char(text[*index]) == get_type_of_char_space) {
				if (is_same_as_trygonometric) {

					*index -= 1;
					set_node(table_of_trygonometric_operators[0], type_sin_cos);
					CNode* one_child = new CNode();
					kids_of_cnode.push_back(one_child);
					(*one_child).add_to_node(text, index);
					return *index;
				}
				set_node(tmp_text, type_variables);
				*index -= 1;
				return *index;
				//ustawiamy jako zmienna i odejmujemy index
			}
			if (get_type_of_char(text[*index]) == get_type_of_char_letter) {
				*index -= 1;
			}
			else {
				node_type = error_type;
				*index = text.length();
				return *index;
			}

		}
		//sprawdzamy czy to cos
		if (text[*index] == table_of_trygonometric_operators[1][0]) {
			*index += 1;
			int trygonometric_index = 1;
			bool is_same_as_trygonometric = true;

			while (*index < text.length() && trygonometric_index < sin_size && get_type_of_char(text[*index]) == get_type_of_char_letter) {
				tmp_text += text[*index];
				if (text[*index] != table_of_trygonometric_operators[1][trygonometric_index]) {
					is_same_as_trygonometric = false;
					trygonometric_index = sin_size;
				}
				trygonometric_index += 1;
				*index += 1;
			}

			if (*index > text.length()) {
				if (is_same_as_trygonometric) {
					set_node(table_of_trygonometric_operators[1], type_sin_cos);
					return *index;
				}
				set_node(tmp_text, type_variables);
				return *index;

			}
			if (get_type_of_char(text[*index]) == get_type_of_char_space) {
				if (is_same_as_trygonometric) {
					*index -= 1;
					set_node(table_of_trygonometric_operators[1], type_sin_cos);
					CNode* one_child = new CNode();
					kids_of_cnode.push_back(one_child);
					(*one_child).add_to_node(text, index);
					return *index;
				}
				set_node(tmp_text, type_variables);
				*index -= 1;
				return *index;
				//ustawiamy jako zmienna i odejmujemy index
			}
			if (get_type_of_char(text[*index]) == get_type_of_char_letter) {
				*index -= 1;
			}
			else {
				node_type = error_type;
				*index = text.length();
				return *index;
			}
		}
		*index += 1;
		while (*index < text.length() && get_type_of_char(text[*index]) == get_type_of_char_letter) {
			tmp_text += text[*index];
			*index += 1;
		}
		if (*index >= text.length()) {
			set_node(tmp_text, type_variables);
			return *index;
		}
		if (get_type_of_char(text[*index]) == get_type_of_char_space) {
			set_node(tmp_text, type_variables);
			*index -= 1;
			return *index;
		}
		std::cout << "||" << tmp_text;
	}

	node_type = error_type;
	*index = text.length();
	return *index;
}

template <>
inline int CNode<int>::build_typed_value(int* index, std::string text) {
	std::string tmp_text = "";

	if (*index + 1 >= text.size()) {
		if (text[*index] == zero_var_string[0]) {
			node_type = error_type;
			*index = text.length();
			return *index;
		}
		set_node(std::string(1, text[*index]), type_numbers_0_child);
		return *index;
	}

	while (*index < text.length() && get_type_of_char(text[*index]) == get_type_of_char_int) {
		tmp_text += text[*index];
		*index += 1;
	}

	if (*index >= text.length()) {
		if (std::stoi(tmp_text) == 0) {
			node_type = error_type;
			*index = text.length();
			return *index;
		}
		set_node(tmp_text, type_numbers_0_child);
		return *index;
	}

	if (get_type_of_char(text[*index]) == get_type_of_char_space) {
		*index -= 1;
		set_node(tmp_text, type_numbers_0_child);
		return *index;
	}
	node_type = error_type;
	*index = text.length();
	return *index;
}

template <typename T>
inline int CNode<T>::build_typed_value(int* index, std::string text) {
	std::string tmp_text = "";
	bool does_contains_dot = false;

	if (*index + 1 >= text.size()) {
		if (text[*index] == zero_var_string[0]) {
			node_type = error_type;
			*index = text.length();
			return *index;
		}
		set_node(std::string(1, text[*index]), type_numbers_0_child);
		return *index;
	}

	while (*index < text.length() &&
		(get_type_of_char(text[*index]) == get_type_of_char_int || get_type_of_char(text[*index]) == get_type_of_char_dot
			|| text[*index] == zero_var_string[0])) {
		if (get_type_of_char(text[*index]) == get_type_of_char_dot) {
			if (does_contains_dot) {
				node_type = error_type;
				*index = text.length();
				return *index;
			}
			if (tmp_text == "") {
				node_type = error_type;
				*index = text.length();
				return *index;
			}
			does_contains_dot = true;
		}
		tmp_text += text[*index];
		*index += 1;
	}

	if (*index >= text.length()) {
		if (std::stod(tmp_text) == 0) {
			node_type = error_type;
			*index = text.length();
			return *index;
		}
		set_node(tmp_text, type_numbers_0_child);
		return *index;
	}

	if (get_type_of_char(text[*index]) == get_type_of_char_space) {
		*index -= 1;
		set_node(tmp_text, type_numbers_0_child);
		return *index;
	}
	node_type = error_type;
	*index = text.length();
	return *index;
}

/*---------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------*/

template <>
inline int CNode<bool>::build_typed_value(int* index, std::string text) {
	std::string tmp_text = "";

	if (*index + 1 >= text.size()) {
		set_node(std::string(1, text[*index]), type_numbers_0_child);
		return *index;
	}

	if (get_type_of_char(text[*index + 1]) != get_type_of_char_space) {
		node_type = error_type;
		*index = text.length();
		return *index;
	}
	else {
		set_node(std::string(1, text[*index]), type_numbers_0_child);
		return *index;
	}
}

template <>
inline int CNode<bool>::add_to_node(std::string text, int* index) {
	*index += 1;
	if (*index >= text.length()) {

		return *index;
	}
	if (text[*index] != node_space_char[0]) {
		node_type = error_type;
		return *index;
	}

	while (*index < text.length() && text[*index] == node_space_char[0]) {
		*index += 1;
	}
	if (*index >= text.length()) {
		return *index;
	}

	int type_of_char = get_type_of_char(text[*index]);

	if (text[*index] == table_of_bool[1][0] || text[*index] == table_of_bool[0][0]) {
		//zadanie 
		*index = build_typed_value(index, text);
		return *index;
	}

	if (type_of_char == get_type_of_char_operator) {
		if (*index + 1 >= text.length()) {

			set_node(std::string(1, text[*index]), type_operators_cons);
			return *index;
		}
		// enter + 1 2 
		set_node(std::string(1, text[*index]), type_operators_cons);

		if (text[*index + 1] == node_space_char[0]) {
			while (*index < text.length() && kids_of_cnode.size() < max_kids_amount) {
				CNode* one_child = new CNode();
				kids_of_cnode.push_back(one_child);
				(*one_child).add_to_node(text, index);
			}
			return *index;
		}
	}

	if (type_of_char == get_type_of_char_letter) {
		std::string tmp_text = "";
		tmp_text += text[*index];

		*index += 1;
		while (*index < text.length() && get_type_of_char(text[*index]) == get_type_of_char_letter) {
			tmp_text += text[*index];
			*index += 1;
		}
		if (*index >= text.length()) {
			set_node(tmp_text, type_variables);
			return *index;
		}
		if (get_type_of_char(text[*index]) == get_type_of_char_space) {
			set_node(tmp_text, type_variables);
			*index -= 1;
			return *index;
		}
		//std::cout << "||" << tmp_text;
	}

	node_type = error_type;
	*index = text.length();
	return *index;
}

/*---------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------*/

template <typename T>
inline int CNode<T>::get_type_of_char(char value) {
	if (value == zero_var_string[0]) {
		return get_type_of_char_zero1;
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
inline void CNode<std::string>::print_this_node() {
	if (node_type == type_numbers_0_child) {
		std::cout << quote_mark_char;
		std::cout << node_value;
		std::cout << quote_mark_char;
		std::cout << node_space_char;
	}
	else {
		std::cout << node_value << node_space_char;
	}

	for (int i = 0; i < kids_of_cnode.size(); i++) {
		if ((*kids_of_cnode[i]).node_type != 0) {
			(*kids_of_cnode[i]).print_this_node();
		}

	}
}

template <typename T>
inline void CNode<T>::print_this_node() {
	//std::cout << "value:" << node_value << std::endl;
	std::cout << node_value << node_space_char;
	//std::cout << "type:" << node_type << std::endl;
	//std::cout << node_type << node_space_char;
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
inline void CNode<T>::vars_cnode(std::vector <std::string>* vector_of_variables) {
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
inline void CNode<T>::copy_node_value(CNode<T>* originalNode) {

	node_type = (*originalNode).node_type;
	node_value = (*originalNode).node_value;

	for (int i = 0; i < (*originalNode).kids_of_cnode.size(); i++) {
		//std::cout << "|" << node_value << "|";
		CNode* copied_child;

		copied_child = new CNode();
		(*copied_child).copy_node_value((*originalNode).kids_of_cnode[i]);

		kids_of_cnode.push_back(copied_child);
	}
}

template <typename T>
inline int CNode<T>::get_node_type() {
	return node_type;
}

template <typename T>
inline void CNode<T>::find_number_node(CNode<T>* originalNode) {
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
inline int CNode<T>::is_properly_built() {
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
			if (node_type == type_sin_cos) {
				if (kids_of_cnode.size() == 0) {
					CNode<T>* one_child = new CNode<T>();
					kids_of_cnode.push_back(one_child);
				}
			}
			else if (node_type == type_operators_cons) {
				if (kids_of_cnode.size() == 0) {
					CNode<T>* one_child = new CNode<T>();
					kids_of_cnode.push_back(one_child);
					CNode<T>* two_child = new CNode<T>();
					kids_of_cnode.push_back(two_child);
				}
				if (kids_of_cnode.size() == 1) {
					CNode<T>* one_child = new CNode<T>();
					kids_of_cnode.push_back(one_child);
				}
			}

			bool contains_not_added = false;
			for (int i = 0; i < kids_of_cnode.size(); i++) {
				if ((*kids_of_cnode[i]).is_properly_built() == error_type) {
					return error_type;
				}
				if ((*kids_of_cnode[i]).is_properly_built() == type_not_added) {
					contains_not_added = true;
				}
			}
			if (contains_not_added) {
				return type_not_added;
			}
			return node_type;
		}
	}
}

template <typename T>
inline void CNode<T>::repair_node() {
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
inline void CNode<std::string>::repair_node() {
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
inline std::string CNode<T>::node_answer_the_problem(std::vector <std::string>* vactor_of_digits, std::vector <std::string>* vactor_of_variables) {
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
		std::string answer_node_one = (*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);
		std::string answer_node_two = (*kids_of_cnode[1]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);

		if (get_type_of_char(answer_node_one[0]) == get_type_of_char_letter ||
			get_type_of_char(answer_node_two[0]) == get_type_of_char_letter) {
			return error_division_by_zero;
		}

		if (node_value == table_of_operators[0]) {
			return std::to_string(std::stod(answer_node_one) + std::stod(answer_node_two));
		}
		if (node_value == table_of_operators[1]) {
			return std::to_string(std::stod(answer_node_one) - std::stod(answer_node_two));
		}
		if (node_value == table_of_operators[2]) {
			if (get_type_of_char(std::to_string(std::stod(answer_node_two))[0]) == get_type_of_char_zero1) {
				return error_division_by_zero;
			}

			return std::to_string(std::stod(answer_node_one) / std::stod(answer_node_two));
		}
		if (node_value == table_of_operators[3]) {
			return std::to_string(std::stod(answer_node_one) * std::stod(answer_node_two));
		}
	}
	return "";
}

template <>
inline std::string CNode<std::string>::node_answer_the_problem(std::vector <std::string>* vactor_of_digits, std::vector <std::string>* vactor_of_variables) {
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
			std::string string_one = (*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);
			std::string string_two = (*kids_of_cnode[1]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);

			int string_one_size = string_one.length();
			int string_two_size = string_two.length();

			if (string_two_size == 0 || string_one_size == 0 || string_one_size < string_two_size) {
				return string_one;
			}

			for (int i = string_one_size - string_two_size; i >= 0; --i) {
				int substring_iterator;
				for (substring_iterator = 0; substring_iterator < string_two_size; ++substring_iterator) {
					if (string_one[i + substring_iterator] != string_two[substring_iterator]) {
						substring_iterator = 2 * string_two_size;
					}
				}

				if (substring_iterator == string_two_size) {
					int tmp_index = 0;
					std::string new_string_to_return = "";
					while (tmp_index < string_one_size) {
						if (tmp_index < i || tmp_index >= string_two_size + i) {
							new_string_to_return += string_one[tmp_index];
						}
						tmp_index += 1;
					}
					return new_string_to_return;
				}
			}
			return string_one;
		}
		if (node_value == table_of_operators[2]) {
			std::string string_one = (*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);
			std::string string_two = (*kids_of_cnode[1]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);

			int string_one_size = string_one.length();
			int string_two_size = string_two.length();

			if (string_two_size == 0 || string_one_size == 0 || string_one_size < string_two_size) {
				return string_one;
			}
			std::string new_string_to_return = "";
			int tmp_index = 0;

			while (tmp_index < string_one_size) {
				if (string_one[tmp_index] == string_two[0]) {
					tmp_index += 1;
					int inside_tmp_counter = tmp_index;
					bool is_matched = true;

					for (int i = 1; i < string_two_size; i++) {
						if (inside_tmp_counter >= string_one_size) {
							is_matched = false;
							i = string_two_size;
						}
						if (string_one[inside_tmp_counter] != string_two[i]) {
							inside_tmp_counter -= i;
							is_matched = false;
							i = string_two_size;
						}
						inside_tmp_counter += 1;
					}

					if (is_matched) {
						new_string_to_return += string_one[tmp_index - 1];
						tmp_index = inside_tmp_counter;
					}

				}
				if (tmp_index < string_one_size) {
					new_string_to_return += string_one[tmp_index];

				}

				tmp_index += 1;
			}


			return new_string_to_return;
		}
		if (node_value == table_of_operators[3]) {

			std::string string_one = (*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);
			std::string string_two = (*kids_of_cnode[1]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);

			int string_one_size = string_one.length();
			int string_two_size = string_two.length();

			if (string_two_size == 0 || string_one_size == 0) {
				return string_one;
			}
			std::string new_string_to_return = "";

			for (int i = 0; string_one_size > i; i++) {
				if (string_one[i] == string_two[0]) {
					new_string_to_return += string_two;

				}
				else {
					new_string_to_return += string_one[i];
				}
			}
			return new_string_to_return;
		}
	}

	return "";


}

template <>
inline std::string CNode<bool>::node_answer_the_problem(std::vector <std::string>* vactor_of_digits, std::vector <std::string>* vactor_of_variables) {
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
		if (kids_of_cnode.size() <= 2) {
			std::string answer_node_one = (*kids_of_cnode[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);
			std::string answer_node_two = (*kids_of_cnode[1]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);

			if (get_type_of_char(answer_node_one[0]) == get_type_of_char_letter ||
				get_type_of_char(answer_node_two[0]) == get_type_of_char_letter) {
				return error_to_many_nodes;
			}

			if (node_value == table_of_operators[0] || node_value == table_of_operators[3]) {
				if (answer_node_one[0] == table_of_bool[1][0] && answer_node_two[0] == table_of_bool[1][0]) {
					return answer_node_one;
				}
				return table_of_bool[0];
			}
			if (node_value == table_of_operators[1] || node_value == table_of_operators[2]) {
				if (answer_node_one[0] == table_of_bool[0][0] || answer_node_two[0] == table_of_bool[0][0]) {
					return answer_node_one;
				}
				return table_of_bool[1];
			}

		}
		else {
			return error_to_many_nodes;
		}
	}
	return "";

}