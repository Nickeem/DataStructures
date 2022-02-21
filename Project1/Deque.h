#ifndef  DEQUE_H
#define DEQUE_H
#include <iostream>
#include <"Node.h">
#include <"Queue.h">

class Deque : public Queue{
    pubilc:
        void enqueueHead();
        void dequeueTail(Node*);
};

void Deque::enqueueHead(Node *element) {
    if (isEmpty()) {
        head = element;
        tail = element;
        return;
    }
    element->next = head;
    head = element;
}

void Deque::dequeueTail() {
    if (isEmpty())
        return;
    
    Node *temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    if (head == tail) {
        head = nullptr;
        delete tail;
        tail = nullptr;
        return
    }
    delete tail;
    tail = temp;
    tail->next = nullptr;
    
}

#endif
