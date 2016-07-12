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

	void Add(T _object);
	void Remove(int _target);
	void RemoveFirst();
	void RemoveLast();
	void MoveToLast(int _target);
	void Insert(); //TO DO, DONT WORK YET
	int Count() const { return this->count; }
	T operator[](int i);

private:

	T* templateList;
	T* listBackup;
	
	int count;
	int tailleMax;
};

#include "List.inl"

