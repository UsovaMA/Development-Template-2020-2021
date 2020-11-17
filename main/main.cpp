#include <iostream>
#include "priority_queue.h"

int main() {

  PriorityQueue pq;

  std::cout << "Add some elements in priority queue" << std::endl;
  pq.push(3, 1);
  pq.push(5, 4);
  pq.push(6, 4);
  pq.push(0, 5);
  pq.push(5, 7);

  pq.print();

  std::cout << "Add element (3,2)" << std::endl;
  pq.push(3, 2);
  pq.print();

  std::cout << "Add element with eq priority" << std::endl;
  pq.push(6, 5);
  pq.print();

  std::cout << "Add element in HEAD" << std::endl;
  pq.push(14, 0);
  pq.print();

  std::cout << "Add element in TAIL" << std::endl;
  pq.push(7, 10);
  pq.print();

  std::cout << "Add element in HEAD with EQ priority" << std::endl;
  pq.push(4, 0);
  pq.print();

  std::cout << "Check top operation" << std::endl;
  std::cout << "Top: " << pq.top() << std::endl;

  std::cout << "Check pop operation (2 pop)" << std::endl;
  pq.pop();
  pq.pop();
  pq.print();

  std::cout << "Check delete all" << std::endl;
  pq.DelPQueue();
  pq.print();

  return 0;
}