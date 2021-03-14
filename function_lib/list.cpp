#include "list.h"

bool List::HareTurtleLoopDetect()
{
    Node* slow_p = head, * fast_p = head;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}

bool List::ReverseLoopDetect()
{
    Node* current = head;
    Node* prev = nullptr, * next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;

        if (next != head)
            current = next;
        else
        {
            current = next;
            head->next = prev;

            prev = nullptr, next = nullptr;

            while (current != nullptr)
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            head = prev;

            return 1;
        }
    }
    head = prev;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    return 0;
}
