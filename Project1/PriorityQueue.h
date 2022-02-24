#ifndef  PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <iostream>
#include "Node.h"
#include "Queue.h"

class PriorityQueue: public Queue {
    public:
        void enqueue(Node* element);
    
};

void PriorityQueue::enqueue(Node* element) {
    if (isEmpty()) {
        head = element;
        tail = element;
        return;
    }
    
    if (element->getID() < head->getID()) {
        element->next = head;
        head = element;
        return;
    }
    
    Node * temp = head;
    while (temp->next != nullptr) {
        if (element->getID() < temp->next->getID() )
        {
            element->next = temp->next;
            temp->next = element;
            return;
        }
        temp = temp->next;
    }
    tail->next = element;
    tail = element;
    
}

#endif
