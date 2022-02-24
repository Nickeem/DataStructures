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
    if (head->getID() > element->getID()) {
        element->next = head;
        head = element;
        return;
    }
    Node *temp = head;
     do{
        if (temp->next == nullptr) {break;}
        temp = temp->next;
    } while (temp->next->getID() < element->getID());
    
    if (temp->next == nullptr) {
        temp->next = element;
        tail = element;
        return;
    }
    
   element->next = temp->next;
   temp->next = element;
    
}

#endif
