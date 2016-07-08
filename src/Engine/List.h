#pragma once

#include <iostream>
#include <vector>

#define LIST_MAX_VALUE 100

template <class T>
class List
{
public:
	List();
	List(int _setTailleMax);
	~List();

	void List::Add(T _object);
	void List::Remove(); ///TO DO( NOT WORKING YET)
	const int List::Count() const { return this->count; }

private:

	T* listBackup;
	T* templateList;
	
	int count;
	int tailleMax;
};

#include "List.inl"

