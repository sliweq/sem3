#pragma once
#include "CNode.h"
#include <vector>
#include <iostream>


class CTree
{
private:
	CNode* root_node;

public:
	CTree(); // -> tworzy nam dziecko roota
	~CTree();  

	bool create_tree(std::string text, int *index);

	CTree operator+(const CTree& ctree_new_val);
	void operator=(const CTree& ctree_new_val);

	void clean_tree();

	void print_tree();
	void vars_ctree();

	int variables_amount();
	//bardziej solve ale trudno nie umiem w ang xd 
	double tree_solve_the_problem(std::vector <std::string>* vactor_of_digits);

};