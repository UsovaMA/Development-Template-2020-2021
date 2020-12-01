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
	return 0;
}