#pragma once
#include "CMySmartPointer.h"
#include <vector>
#include <iostream>

template< typename T > class CMySmartPointer;

template< typename T > class CRefCounter{
public:
	CRefCounter();
	int iAdd();
	int iDec();
	int iGet();
	void vAddNewPointer(CMySmartPointer<T>* new_pointer);
	bool vRemovePointer(CMySmartPointer<T>* new_pointer);
private:
	int i_count;
	std::vector <CMySmartPointer<T>*> cRefCounter_owners;

};

template <typename T>
CRefCounter<T>::CRefCounter<T>() { 
	i_count = 0; 
}

template <typename T>
int CRefCounter<T>::iAdd() { return(++i_count); }

template <typename T>
int CRefCounter<T>::iDec() { return(--i_count); }

template <typename T>
int CRefCounter<T>::iGet() { return(i_count); }

template <typename T>
void CRefCounter<T>::vAddNewPointer(CMySmartPointer<T>* new_pointer) {
	cRefCounter_owners.push_back(new_pointer);
	//std::cout << "New amount of v: " << cRefCounter_owners.size() << "\n";
}

template <typename T>
bool CRefCounter<T>::vRemovePointer(CMySmartPointer<T>* new_pointer){

	for (int index = cRefCounter_owners.size() - 1; index >= 0; --index) {
		if (cRefCounter_owners[index] == new_pointer) {
			cRefCounter_owners.erase(cRefCounter_owners.begin() + index);
			return true;
		}
	}


	return false;
}
