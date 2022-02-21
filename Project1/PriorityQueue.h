#ifndef  PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <iostream>
#include <"Node.h">
#include <"Queue.h">

class PriorityQueue {
    public:
        void enqueue(Node* element);
    
}

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
    while (temp->next != nullptr || temp->next->getID() < element->getID())
        temp = temp->next;
    
    if (temp->next == nullptr) {
        temp->next = element;
        tail = element;
        return;
    }
    
   element->next = temp->next;
   temp->next = element;
    
}
