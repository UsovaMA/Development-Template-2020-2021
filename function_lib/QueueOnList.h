#pragma once
#include "TList.h"
#include <iostream>
#include <vector>

template<class T>
class QueueOnList
{
private:
	TList<T> list;
public:
	QueueOnList<T>();
	QueueOnList<T>(T*arr, int size);
	void pop();
	void push(T val);
	void sorted_push(T val);
	int size();
	bool empty();
	T front();
	T back();
	void print();
};

template<class T>
inline void QueueOnList<T>::pop()
{
	if (empty())
	{
		throw std::exception("queue is empty!");
	}
	list.DelLast();
}

template<class T>
inline void QueueOnList<T>::push(T val)
{
	list.InsFirst(val);
}

template<class T>
inline void QueueOnList<T>::sorted_push(T val)
{
	list.sorted_push(val);
}

template<class T>
inline int QueueOnList<T>::size()
{
	return list.GetListLenght();
}

template<class T>
inline bool QueueOnList<T>::empty()
{
	if (list.GetListLenght() == 0)
	{
		return true;
	}
	return false;
}

template<class T>
inline T QueueOnList<T>::front()
{
	if (empty())
	{
		throw std::exception("queue is empty!");
	}
	return list.get(list.GetListLenght()-1);
}

template<class T>
inline T QueueOnList<T>::back()
{
	if (empty())
	{
		throw std::exception("queue is empty!");
	}
	return list.get(0);
}

template<class T>
inline void QueueOnList<T>::print()
{
	for (int i = 0;i<list.GetListLenght();i++)
	{
		std::cout << list.get(i)<<" ";
	}
	std::cout << "  size = "<<size();
	std::cout << "\n";
}

template<class T>
inline QueueOnList<T>::QueueOnList()
{
}

template<class T>
inline QueueOnList<T>::QueueOnList(T* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		push(arr[i]);
	}
}
