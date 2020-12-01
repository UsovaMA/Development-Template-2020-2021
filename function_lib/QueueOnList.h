#pragma once
#include <list>
#include <iostream>
#include <vector>

template<class T>
class QueueOnList
{
private:
	std::list<T> list;
public:
	void pop();
	void push(T val);
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
	list.pop_back();
}

template<class T>
inline void QueueOnList<T>::push(T val)
{
	list.push_front(val);
}

template<class T>
inline int QueueOnList<T>::size()
{
	return list.size();
}

template<class T>
inline bool QueueOnList<T>::empty()
{
	if (list.size() == 0)
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
	return list.back();
}

template<class T>
inline T QueueOnList<T>::back()
{
	if (empty())
	{
		throw std::exception("queue is empty!");
	}
	return list.front();
}

template<class T>
inline void QueueOnList<T>::print()
{
	for (const auto& i : list)
	{
		std::cout << i<<" ";
	}
	std::cout << "  size = "<<size();
	std::cout << "\n";
}
