#include "List.h"


template <class T>
List<T>::List()
	: count(0), tailleMax(LIST_MAX_VALUE)
{
	templateList = new T*[tailleMax];
}

template <class T>
List<T>::List(int _setTailleMax)
	: count(0), tailleMax(_setTailleMax)
{
	templateList = new T*[tailleMax];
}

template <class T>
List<T>::~List()
{
	delete[] templateList;
}

template <class T>
void List<T>::Add(T* _object)
{
	if (count >= tailleMax)
	{
		listBackup = new T*[tailleMax];
		memcpy(listBackup, templateList, sizeof(T) * tailleMax);
		tailleMax *= 2;
		delete[] templateList;
		templateList = new T*[tailleMax];
		memcpy(templateList, listBackup, sizeof(T) * tailleMax);
		delete[] listBackup;
	}
	templateList[count] = _object;
	count++;
}

template <class T>
void List<T>::Remove(int _target)
{
	listBackup = new T*[tailleMax];
	memcpy(listBackup, templateList, sizeof(T) * tailleMax);
	delete[] templateList;
	templateList = new T*[tailleMax];

	for (int i = 0; i < _target; i++)
	{
		templateList[i] = listBackup[i];
	}

	count--;

	for (int i = _target; i < count; i++)
	{
		templateList[i] = listBackup[i + 1];
	}
}

template <class T>
void List<T>::RemoveFirst()
{
	//create a new backup List
	listBackup = new T*[tailleMax];

	//copy templatelist from array position 2 to last one into listBackup
	for (int i = 0, i < count - 2; i++)
	{
		listBackup[i] = templateList[i + 1];
	}

	//delete template list and initiate a new empty one
	delete[] templateList;
	templateList = new T*[tailleMax];

	//copy templateList that contains all the information of the initial template list exept the first one into the new template list
	memcpy(listBackup, templateList, sizeof(T) * tailleMax);

	//delete the backup list
	delete[] listBackup;

	//adjust count variable
	count--;
}

template <class T>
void List<T>::RemoveLast()
{
	//overide the last initialized object of the list by a new empty(trash) one 
	templateList[count - 1] = new T*();

	//adjust count variable
	count--;
}

template <class T>
void List<T>::Insert()
{

}

template <class T>
T* List<T>::Get(int i)
{
	return templateList[i];
}

template <class T>
void List<T>::MoveToLast(int _target)
{
	int counting = 0;

	memcpy(listBackup, templateList, sizeof(T) * tailleMax);
	delete[] templateList;
	templateList = new T*[tailleMax];

	for (int i = 0; i < _target; i++)
	{
		templateList[i] = listBackup[i];
		counting++;
	}
	for (int i = _target; i < count - 1; i++)
	{
		templateList[i] = listBackup[i + 1];
		counting++;
	}
	templateList[counting] = listBackup[_target];
}