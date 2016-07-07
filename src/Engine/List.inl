#include "List.h"


template <class T>
List<T>::List()
	: count(0), tailleMax(LIST_MAX_VALUE)
{
	templateList = new T[tailleMax];
}

template <class T>
List<T>::List(int _setTailleMax)
	: count(0), tailleMax(_setTailleMax)
{
	templateList = new T[tailleMax];
}

template <class T>
List<T>::~List()
{
	delete[] templateList;
}

template <class T>
void List<T>::Add(T _object)
{
	if (templateObject >= LIST_MAX_VALUE)
	{
		listBackup = new T[tailleMax];
		memcpy(listBackup, templateList, sizeof(T) * tailleMax);
		tailleMax *= 2;
		delete[] templateList;
		templateList = new T[tailleMax];
		memcpy(templateList, listBackup, sizeof(T) * tailleMax);
		delete[] listBackup;
	}
	templateList[count] = _object;
	count++;
}

template <T>
void List<T>::Remove()
{

}



