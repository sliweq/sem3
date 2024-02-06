#pragma once
#include <iostream>

class Class_with_table {

private:
	std::string class_name;
	int* table;
	int table_length;

public:
	Class_with_table();
	Class_with_table(std::string input_name, int input_table_size);
	Class_with_table(Class_with_table& input_class);
	~Class_with_table();

	void set_name(std::string input_name);
	bool set_new_size(int input_size);

	Class_with_table* clone_class();
};