#include "CTree.h"
#include "CNode.h"
#include "ctrees_consts.h"
#include <vector>
#include <iostream>

CTree::CTree() {
	root_node = new CNode();
	
};

CTree::~CTree() {
	//std::cout << "usuwanie\n";
	delete root_node;
};

void CTree::operator=(const CTree& ctree_new_val) {
	// y = x
	// to y to jest to 
	if ((*root_node).get_node_type() != 0) {
		
		delete root_node;
		root_node = new CNode();
	}
	(*root_node).copy_node_value(ctree_new_val.root_node);
	
};

CTree CTree::operator+(const CTree& ctree_new_val) {
	CTree result_ctree; 

	result_ctree = *this;
	(*result_ctree.root_node).find_number_node(ctree_new_val.root_node);

	return result_ctree;
};

bool CTree::create_tree(std::string text, int *index) {
	//*index = (*root_node).add_to_node(text, index) ;
	
	(*root_node).add_to_node(text, index);
	//std::cout << *index << text[*index];
	//czy zawiera 5 syntax error 
	//jesli zawiera 0 to dodajemy 1
	int propery_built = (*root_node).is_properly_built();

	if (propery_built == error_pro_build) {
		return false;

	}else if(propery_built == 0){
		(*root_node).repair_node();
	}
	//if (finished_index+1 < text.length()) {
	if (*index + index_inceaser < text.length()) {
		*index += index_inceaser;
		
		while (text.length() > *index) {
			if(text[*index] != tree_space_char[0]) {
				//std::cout << text[*index];
				//std::cout << error_many_arguments;
				(*index) = text.length();
			}
			*index += 1;
		}
	}
	return true;
}

void CTree::print_tree() {
	root_node->print_this_node();
	std::cout << std::endl;
}

void CTree::vars_ctree() {
	std::vector <std::string>* vector_of_variables ;
	vector_of_variables = new std::vector<std::string>;
	(*root_node).vars_cnode(vector_of_variables);

	//tutaj print
	for (int i = 0; i < (*vector_of_variables).size(); i++) {
		std::cout << (*vector_of_variables)[i] << tree_space_char;
	}

	delete vector_of_variables;

}

int CTree::variables_amount() {
	std::vector <std::string>* vector_of_variables;
	vector_of_variables = new std::vector<std::string>;
	(*root_node).vars_cnode(vector_of_variables);
	int x = (*vector_of_variables).size();

	delete vector_of_variables;

	return x;
}


void CTree::clean_tree() {
	delete root_node;
	root_node = new CNode();
}

double CTree::tree_solve_the_problem(std::vector <std::string>* vactor_of_digits) {
	std::vector <std::string>* vector_of_variables;
	vector_of_variables = new std::vector<std::string>;
	(*root_node).vars_cnode(vector_of_variables);

	double answer = (*root_node).node_answer_the_problem(vactor_of_digits, vector_of_variables);

	delete vector_of_variables;

	return answer;

}