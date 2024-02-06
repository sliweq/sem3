#pragma once
#include "CRefCounter.h"

template< typename T > class CMySmartPointer {
public:
	CMySmartPointer(T* pcPointer);
	CMySmartPointer(const CMySmartPointer& pcOther);
	~CMySmartPointer();
	void operator=(const CMySmartPointer& pcOther);
	T& operator*();
	T* operator->();
private:
	CRefCounter<T>* pc_counter;
	T* pc_pointer;
};

template <typename T>
CMySmartPointer<T>::CMySmartPointer(T* pcPointer) {
	pc_pointer = pcPointer;
	pc_counter = new CRefCounter<T>();
	pc_counter->iAdd();
	pc_counter->vAddNewPointer(this);
};

template <typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer& pcOther) {
	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
	pc_counter->vAddNewPointer(this);
};

template <typename T>
CMySmartPointer<T>::~CMySmartPointer() {
	pc_counter->vRemovePointer(this);

	if (pc_counter->iDec() == 0) {
		delete pc_pointer;
		delete pc_counter;
	}
};

template <typename T>
void CMySmartPointer<T>::operator=(const CMySmartPointer& pcOther) {
	if (pc_counter->iDec() != 0) {
		pc_counter->vRemovePointer(this);
	}

	if (pc_counter->iDec() == 0) {
		delete pc_pointer;
		delete pc_counter;
	}

	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
	pc_counter->vAddNewPointer(this);
};

template <typename T>
T& CMySmartPointer<T>::operator*() { return(*pc_pointer); };

template <typename T>
T* CMySmartPointer<T>::operator->() { return(pc_pointer); };