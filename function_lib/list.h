#pragma once

class Node {
public:
    int data;
    Node* next;

    Node(int new_data)
    {
        data = new_data;
        next = nullptr;
    }
};

class List {
public:
    Node* head;
    int size;

    List()
    {
        size = 0;
        head = nullptr;
    }
    void push(int new_data)
    {
        if (!head)
            head = new Node(new_data);
        else
        {
            Node* current = head;
            while (current->next != nullptr)
                current = current->next;
            current->next = new Node(new_data);
        }
        size++;
    }

    bool HareTurtleLoopDetect();
    bool ReverseLoopDetect();
};