#include "priority_queue.h"
#include <iostream>

CNode* MakeNode(DataType data, int priority) {
  CNode *node = new CNode;
  node->Data = data;
  node->Next = nullptr;
  node->priority = priority;

  return node;
}

void PriorityQueue::push(DataType data, int priority) {
  CNode *node = MakeNode(data, priority);
  if (head) {
    if (head->priority > node->priority) {
      node->Next = head;
      head = node;
    }
    else {
      CNode *pCur = head;
      while (pCur->Next)
        if (pCur->Next->priority <= node->priority)
          pCur = pCur->Next;
        else
          break;
      node->Next = pCur->Next;
      pCur->Next = node;
    }
  } else {
    head = node;
  }
}

void PriorityQueue::print(void) {
  CNode *pCur = head;
  while (pCur) {
    std::cout << "(" << pCur->Data << ", " << pCur->priority << ") -> ";
    pCur = pCur->Next;
  }
  std::cout << "NULL" << std::endl;
}

void PriorityQueue::pop(void) {
  CNode *pCur = head;
  if (pCur) {
    head = head->Next;
    delete pCur;
  }
}

DataType PriorityQueue::top(void) {
  return head->Data;
}

bool PriorityQueue::isEmpty() {
  return head == nullptr;
}

void PriorityQueue::DelPQueue(void) {
  CNode *pCur;
  while (head) {
    pCur = head;
    head = head->Next;
    delete pCur;
  }
}