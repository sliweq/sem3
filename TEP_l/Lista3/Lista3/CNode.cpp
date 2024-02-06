#include "CNode.h"
#include "CTree.h"
#include <vector>
#include <iostream>
#include "cnodes_consts.h"
#include <random>
#include <cmath>
#include <string>

CNode::CNode() {
	node_type = type_not_added;
	//0 - not added yet
	//1 - sin;cos 1 children
	//2 - operator +-/*
	//3 - number 0 childrens
	//4 - var a,b,c etc 0 childrens
	//5 - error
	// 6 - super sum

};

CNode::~CNode() {
	// jeœli jest typem 0,3,4 -> nie ma dzieci wiêc nie musimy usuwaæ

	if (node_type == type_sin_cos || node_type == type_operators_cons || node_type == type_supersum) {
		for (CNode* node : childrens) {
			delete node;
		}
	}
};

bool CNode::set_node(std::string value, int type){
	node_value = value;
	node_type = type; 
	return true;
}

// 0 - illegal argument
//1 - number
//2 - operator +/-*
//3 - letter

int CNode::add_to_node(std::string text, int *index){
	//sprawdzamy tak d³ugo jak jest " " lub gdy bedzie koniec tekstu
	//jesli operator to tworzymy pierwsze jedo dzeicko póŸniej drugi 
	//std::cout << *index;
	*index += 1;
	if (*index >= text.length()){
		
		return *index;
	}
	if (text[*index] != node_space_char[0]) {
		node_type = error_type;
		return *index;
		//skoro mamy z³¹ skladniê to przy sprawdzaniu gdy wêze³ ma wartoœ 0 to usuwa nam swtorzeone drzewo
		//kounikat o z³ej sk³adni, synatax error
	}
	*index += 1;
	if (*index >= text.length()) {
		//komunikat o za ma³o zmiennych, auto, uzupe³nianie

		return *index;
	}
	
	int type_of_char = get_type_of_char(text[*index]);
	if (type_of_char == type_variables) {
		while (*index+1 >= text.length() && type_of_char == type_variables) {
			*index += 1;
			type_of_char = get_type_of_char(text[*index]);
		}
		if (*index >= text.length() || type_of_char == type_variables) {
			//komunikat o za ma³o zmiennych, auto, uzupe³nianie
			return *index;
		}
	}

	if (type_of_char == get_type_of_char_int) {
		if (*index + 1 >= text.length()) {
			set_node(std::string(1, text[*index]), type_numbers_0_child);
			return *index;
		}
		if (text[*index + 1] != node_space_char[0]) {
			node_type = error_type;
			return *index;
		}
		set_node(std::string(1, text[*index]), type_numbers_0_child);
		return *index;
	}
	else if (type_of_char == get_type_of_char_operator) {

		set_node(std::string(1, text[*index]), type_numbers_0_child);

		if (*index + double_index_inc >= text.length()) {
			return *index;
		}
		while (*index + 1 < text.length() && childrens.size() < double_index_inc) {

			CNode* one_child = new CNode();
			childrens.push_back(one_child);
			(*one_child).add_to_node(text, index);

			if (*index + 1 >= text.length()) {
				return *index;
			}

		}
		
		return *index;
	}
	else {
		//skoro mamy listere to trzba sprawdziæ czy to pojedyczna zmienna czy coœ innego
		if (get_type_of_char(text[*index]) == get_type_of_char_illegal_arg) {
			node_type = error_type;
			return *index;
		}
		if ((*index) + 1 >= text.length()) {
			if (get_type_of_char(text[*index]) == get_type_of_char_illegal_arg) {
				node_type = error_type;
				return *index;
			}
			set_node(std::string(1, text[*index]), type_variables);
			return *index;
		}
		else {
			if (text[(*index) + 1] == node_space_char[0]) {
				node_type = type_variables;
				node_value = text[(*index)];
				return (*index);
			}
			//albo syntaxerror albo sin cos 

			else if (text[*index] == table_of_trygonometric_operators[0][0]){ 
				if (text[*index + 1] == table_of_trygonometric_operators[0][1]) {
					*index += 1;
					for (int i = 1; i < sin_size; i++) {
						if ((*index) >= text.length()) {
							node_type = error_type;
							return *index;
						}
						if (text[*index] != table_of_trygonometric_operators[0][i]) {
							node_type = error_type;
							return *index;
						}
						*index += 1;
					}
					//jest git bo sinus

					*index -= 1;
					set_node(table_of_trygonometric_operators[0], 1);

					CNode* one_child = new CNode();
					childrens.push_back(one_child);
					(*one_child).add_to_node(text, index);
					return *index;
				}
				
				else if(text[*index + 1] == super_sum_operator[1]){
					*index += 1;
					for (int i = 1; i < super_sum_operator.size(); i++) {
						if ((*index) >= text.length()) {
							node_type = error_type;
							return *index;
						}
						if (text[*index] != super_sum_operator[i]) {
							node_type = error_type;
							return *index;
						}
						*index += 1;
					}

					*index -= 1;
					
					set_node(super_sum_operator, 6);

					if (*index + double_index_inc >= text.length()){
						return *index+1;
					}
					while (*index + 1 < text.length() && childrens.size() < 4) {

						CNode* one_child = new CNode();
						childrens.push_back(one_child);
						(*one_child).add_to_node(text, index);

						if (*index + 1 >= text.length()) {
							return *index;
						}

					}
					return *index;

				}

				

			}
			else if (text[*index] == table_of_trygonometric_operators[1][0]) {


				*index += 1;
				for (int i = 1; i < sin_size; i++) {
					if ((*index) >= text.length()) {
						node_type = error_type;
						return *index;
					}
					if (text[*index] != table_of_trygonometric_operators[1][i]) {
						node_type = error_type;
						return *index;
					}
					*index += 1;
				}
				//jest git bo cos

				*index -= 1;
				set_node(table_of_trygonometric_operators[1], 1);

				CNode* one_child = new CNode();
				childrens.push_back(one_child);
				(*one_child).add_to_node(text, index);
				//set dziecko jeszcze

				return *index;
			}


			node_type = error_type;
			return text.length();
		}
	}
}

// 0 - illegal argument
//1 - number
//2 - operator +/-*
//3 - letter
//4 - space
int CNode::get_type_of_char(char value) {
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

	return get_type_of_char_illegal_arg;
}

void CNode::print_this_node() {
	std::cout << node_value << node_space_char ;
	//std::cout << node_type << node_space_char;
	//std::cout << "value:" << node_value << std::endl;
	//std::cout << "type:" << node_type << std::endl;
	//std::cout << childrens.size();
	for (int i = 0; i < childrens.size(); i++) {
		if ((*childrens[i]).node_type != 0) {
			(*childrens[i]).print_this_node();
		}
		if ((*childrens[i]).node_type == 0) {
			(*childrens[i]).print_this_node();
		}
	}
}
/*
*/

void CNode::vars_cnode(std::vector <std::string>* vector_of_variables) {
	if (node_type != 4) {
		for (int i = 0; i < childrens.size(); i++) {
			(*childrens[i]).vars_cnode(vector_of_variables);
		}
		//sprawdzanie dzieci
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
		//srpawdzenie tego
	}
}

void CNode::copy_node_value(CNode *originalNode) {

	node_type = (*originalNode).node_type;
	node_value = (*originalNode).node_value;
	//std::cout << node_value << (*originalNode).childrens.size();
	for (int i = 0; i < (*originalNode).childrens.size(); i++) {
		//std::cout << "|" << node_value << "|";
		CNode* copied_child;
		copied_child = new CNode();
		(*copied_child).copy_node_value((*originalNode).childrens[i]);

		childrens.push_back(copied_child);
	}
}


int CNode::get_node_type() {
	return node_type;
}

void CNode::find_number_node(CNode* originalNode) {
	if (node_type == type_numbers_0_child || node_type == type_variables) {
		copy_node_value(originalNode);
	}
	else {
		if (node_type == 1) {
			(*childrens[0]).find_number_node(originalNode);
		}
		else {
			//typ 2 +-/*

			//losowo
			/*
			std::random_device rd;
			std::mt19937 gen(rd());

			std::uniform_int_distribution<> distribution(0, childrens.size());
			int random_number = distribution(gen);
			(*childrens[random_number]).find_number_node(originalNode);
			*/
			//idziemy na lewo
			(*childrens[0]).find_number_node(originalNode);
		}
	}
}

int CNode::is_properly_built(){
	//std::cout << node_value; 
	//std::cout << node_type;
	if (node_type == type_supersum) {
		int size_supersum = childrens.size();
		for (int i = 0; i < (super_sum_kids - size_supersum); i++) {
			CNode* child_one = new CNode();
			childrens.push_back(child_one);
			
		}
		for (int i = 0; i < childrens.size(); i++) {
			if ((*childrens[i]).is_properly_built() == error_type) {
				return error_type;
			}
			if ((*childrens[i]).is_properly_built() == type_not_added) {
				return type_not_added;
			}
		}
	}
	if (node_type == type_not_added) {
		return type_not_added;
	}else if(node_type == error_type){
	
		std::cout << error_syntax; 
		return error_type;
	}
	else {
		if (node_type == type_variables || node_type == type_numbers_0_child) {
			return node_type;
		}
		else {
			for (int i = 0; i < childrens.size(); i++) {
				if((*childrens[i]).is_properly_built() == error_type){
					return error_type;
				}
				if ((*childrens[i]).is_properly_built() == type_not_added) {
					return type_not_added;
				}
			}
			return node_type;
		}
	}
}

void CNode::repair_node() {
	if (node_type == type_not_added) {
		node_type = type_numbers_0_child;

		//const value
		node_value = table_of_numbers[0];
	}
	else {
		for (int i = 0; i < childrens.size(); i++) {
			(*childrens[i]).repair_node();
		}
	}
}

double CNode::node_answer_the_problem(std::vector <std::string>* vactor_of_digits, std::vector <std::string>* vactor_of_variables) {
	//1 - sin;cos 1 children
	//2 - operator +-/*
	//4 - var a,b,c etc 0 childrens
	
	if (node_type == 3) {
		return std::stod(node_value);
	}
	if (node_type == 4) {
		for (int i = 0; i < (*vactor_of_variables).size(); i++) {
			if (node_value == (*vactor_of_variables)[i]) {
				return std::stod((*vactor_of_digits)[i]);
			}
		}
	}
	if (node_type == 1) {
		if (table_of_trygonometric_operators[0] == node_value) {
			return (double) sin((*childrens[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables));
		}
		else {
			return (double) cos((*childrens[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables));
		}
	}
	if (node_type == 2) {
		//{ "+","-","/","*" };
		if(node_value == table_of_operators[0]){
			return (*childrens[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables) + (*childrens[1]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);
		}
		if (node_value == table_of_operators[1]) {
			return (*childrens[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables) - (*childrens[1]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);
		}
		if (node_value == table_of_operators[2]) {
			return (*childrens[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables) / (*childrens[1]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);
		}
		if (node_value == table_of_operators[3]) {
			return (*childrens[0]).node_answer_the_problem(vactor_of_digits, vactor_of_variables) * (*childrens[1]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);
		}
	}
	if (node_type == type_supersum) {
		
		double super_sum_sum = 0.0;
		for (int i = 0; i < super_sum_kids; i++) {
			super_sum_sum += (*childrens[i]).node_answer_the_problem(vactor_of_digits, vactor_of_variables);
		}
		//std::cout << super_sum_sum;
		return super_sum_sum;
	}
	
}
