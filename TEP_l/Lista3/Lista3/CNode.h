#pragma once
#include <vector>
#include <iostream>

class CNode
{
private:
	//0 - not added yet
	//1 - sin;cos 1 children
	//2 - operator +-/*
	//3 - number 0 childrens
	//4 - var a,b,c etc 0 childrens 
	//5 - error
	//6 - super sum
	int node_type; 
	std::string node_value;
	
	std::vector <CNode*> childrens;

public:
	~CNode();
	CNode();
	int add_to_node(std::string text, int *index);
	void print_this_node();
	int get_type_of_char(char value);
	bool set_node(std::string value, int type);
	void vars_cnode(std::vector <std::string>* vactor_of_variables);
	void copy_node_value(CNode *originalNode);
	int get_node_type();

	
	void find_number_node(CNode* originalNode);
	int is_properly_built();

	void repair_node();
	double node_answer_the_problem(std::vector <std::string>* vactor_of_digits , std::vector <std::string>* vactor_of_variables);
};