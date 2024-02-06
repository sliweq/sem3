#pragma once
#include "CNode.h"
#include "CTree_consts.h"
#include <vector>
#include <iostream>


//TODO czy na pewno create_tree jest dobrze zrobione


template< typename T > class CTree
{
private:
	CNode<T>* root_node;

public:
	CTree<T>(); // -> tworzy nam dziecko roota
	~CTree<T>();

	bool create_tree(std::string text, int* index);

	CTree<T> operator+(const CTree<T>& ctree_new_val);
	void operator=(const CTree<T>& ctree_new_val);

	void clean_tree();

	void print_tree();
	void vars_ctree();

	int variables_amount();

	std::string tree_solve_the_problem(std::vector <std::string>* vactor_of_digits);

};

template <typename T>
inline CTree<T>::CTree() {
	root_node = new CNode<T>();
};

template <typename T>
inline CTree<T>::~CTree<T>() {
	//std::cout << "usuwanie\n";
	delete root_node;
};

template <>
inline CTree<int>::~CTree<int>() {
	//std::cout << "usuwanie\n";
	delete root_node;
};

template <typename T>
inline void CTree<T>::operator=(const CTree<T>& ctree_new_val) {

	if ((*root_node).get_node_type() != 0) {
		delete root_node;
		root_node = new CNode<T>();
	}
	(*root_node).copy_node_value(ctree_new_val.root_node);
};

template <typename T>
inline CTree<T> CTree<T>::operator+(const CTree<T>& ctree_new_val) {
	CTree<T> result_ctree;

	result_ctree = *this;
	(*result_ctree.root_node).find_number_node(ctree_new_val.root_node);

	return result_ctree;
};

template <typename T>
inline bool CTree<T>::create_tree(std::string text, int* index) {

	(*root_node).add_to_node(text, index);

	int propery_built = (*root_node).is_properly_built();

	if (propery_built == error_pro_build) {
		return false;
	}

	else if (propery_built == 0) {
		(*root_node).repair_node();
	}
	//if (finished_index+1 < text.length()) {
	if (*index + 1 < text.length()) {
		*index += 1;

		while (text.length() > *index) {
			if (text[*index] != tree_space_char[0]) {
				(*index) = text.length();
			}
			*index += 1;
		}
	}
	return true;
}

template <typename T>
inline void CTree<T>::print_tree() {
	root_node->print_this_node();
	std::cout << std::endl;
}

template <typename T>
inline void CTree<T>::vars_ctree() {

	std::vector <std::string>* vector_of_variables;
	vector_of_variables = new std::vector<std::string>;
	(*root_node).vars_cnode(vector_of_variables);

	//tutaj print
	for (int i = 0; i < (*vector_of_variables).size(); i++) {
		std::cout << (*vector_of_variables)[i] << tree_space_char;
	}

	delete vector_of_variables;
}

template <typename T>
inline int CTree<T>::variables_amount() {

	std::vector <std::string>* vector_of_variables;
	vector_of_variables = new std::vector<std::string>;
	(*root_node).vars_cnode(vector_of_variables);
	int x = (*vector_of_variables).size();

	delete vector_of_variables;

	return x;
}

template <typename T>
inline void CTree<T>::clean_tree() {
	delete root_node;
	root_node = new CNode<T>();
}

template <>
inline std::string CTree<std::string>::tree_solve_the_problem(std::vector <std::string>* vactor_of_digits) {

	std::vector <std::string>* vector_of_variables;
	vector_of_variables = new std::vector<std::string>;
	(*root_node).vars_cnode(vector_of_variables);

	std::string answer = (*root_node).node_answer_the_problem(vactor_of_digits, vector_of_variables);

	delete vector_of_variables;

	return answer;
}

template <typename T>
inline std::string CTree<T>::tree_solve_the_problem(std::vector <std::string>* vactor_of_digits) {

	std::vector <std::string>* vector_of_variables;
	vector_of_variables = new std::vector<std::string>;
	(*root_node).vars_cnode(vector_of_variables);

	std::string answer = (*root_node).node_answer_the_problem(vactor_of_digits, vector_of_variables);
	if (answer == error_division_by_zero1) {
		std::cout << error_division_by_zero_message;
		return tree_space_char;
	}
	delete vector_of_variables;

	return answer;
}

template <>
inline std::string CTree<bool>::tree_solve_the_problem(std::vector <std::string>* vactor_of_digits) {

	std::vector <std::string>* vector_of_variables;
	vector_of_variables = new std::vector<std::string>;
	(*root_node).vars_cnode(vector_of_variables);

	std::string answer = (*root_node).node_answer_the_problem(vactor_of_digits, vector_of_variables);

	if (answer == error_to_many_nodes_tree) {
		std::cout << error_more_than_two_nodes_mess;
		return tree_space_char;
	}

	delete vector_of_variables;

	return answer;
}