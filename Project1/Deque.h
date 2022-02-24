#ifndef  DEQUE_H
#define DEQUE_H
#include <iostream>
#include "Node.h"
#include "Queue.h"

class Deque : public Queue{
    public:
        void enqueueHead(Node*);
        void enqueueTail(Node*);
        void dequeueTail();
};

void Deque::enqueueHead(Node* element) {
    if (isEmpty()) {
        head = element;
        tail = element;
        return;
    }
    element->next = head;
    head = element;
}

void Deque::enqueueTail(Node* element) {
   enqueue(element);     
}

void Deque::dequeueTail() {
    if (isEmpty())
        return;
    
    if (head == tail) {
        head = nullptr;
        delete tail;
        tail = nullptr;
        return;
    }
    
    Node *temp = head;
    while (temp->next != tail ) {
        temp = temp->next;
    }
    
    delete tail;
    tail = temp;
    tail->next = nullptr;
    
}

#endif
