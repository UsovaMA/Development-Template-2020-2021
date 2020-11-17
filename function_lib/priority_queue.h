#ifndef INCLUDE_PRIORITY_QUEUE_H_
#define INCLUDE_PRIORITY_QUEUE_H_

typedef int DataType;

struct CNode {
  DataType Data;
  CNode *Next;
  int priority;
};

CNode* MakeNode(DataType data, int priority);

class PriorityQueue {
  CNode *head;
  CNode *tail;
  // int DataCount;
 public:
    PriorityQueue() {
      head = nullptr;
      tail = nullptr;
    };

    ~PriorityQueue() {
      DelPQueue();
    };

    void push(DataType data, int priority);
    void pop(void);
    DataType top(void);
    bool isEmpty();
    void DelPQueue(void);
    void print(void);
};

#endif  // INCLUDE_PRIORITY_QUEUE_H_