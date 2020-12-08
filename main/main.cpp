#include <stdio.h>
#include "QueueOnList.h"
#include <locale>
int main() {
	setlocale(LC_ALL, "Russian");
	QueueOnList<int> queue;
	std::cout << "���������� �������:"<<std::endl;

	for (int i = 0; i < 10; i++)
	{
		queue.push(i);
		queue.print();
	}
	
	std::cout << "������ ������� � �������:" << std::endl;
	std::cout << queue.front() << std::endl;
	std::cout << "��������� ������� � �������:" << std::endl;
	std::cout << queue.back() << std::endl;
	std::cout << "�������� ��������� �������:" << std::endl;
	queue.print();
	while (!queue.empty())
	{
		queue.pop();
		queue.print();
	}

	int size = 20;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
	std::cout << "������� �� �������:" << std::endl;
	QueueOnList<int> queue2(arr,20);
	queue2.print();
	delete[] arr;
	std::cout << "������������� push -5 � 100 :" << std::endl;
	queue2.sorted_push(-5);
	queue2.sorted_push(100);
	queue2.print();
	return 0;
}