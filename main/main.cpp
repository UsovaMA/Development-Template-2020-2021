#include <stdio.h>
#include "QueueOnList.h"
#include <locale>
int main() {
	setlocale(LC_ALL, "Russian");
	QueueOnList<int> queue;
	std::cout << "Заполнение очереди:"<<std::endl;

	for (int i = 0; i < 10; i++)
	{
		queue.push(i);
		queue.print();
	}
	
	std::cout << "Первый элемент в очереди:" << std::endl;
	std::cout << queue.front() << std::endl;
	std::cout << "Последний элемент в очереди:" << std::endl;
	std::cout << queue.back() << std::endl;
	std::cout << "Удаление элементов очереди:" << std::endl;
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
	std::cout << "Очередь из массива:" << std::endl;
	QueueOnList<int> queue2(arr,20);
	queue2.print();
	delete[] arr;
	std::cout << "Упорядоченный push -5 и 100 :" << std::endl;
	queue2.sorted_push(-5);
	queue2.sorted_push(100);
	queue2.print();
	return 0;
}