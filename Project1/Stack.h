#ifndef  STACK_H
#define STACK_H
#include <iostream>
#include "Node.h"

class Stack {
    public:
        Node *head;
        Node *tail;
        
        Stack() {
            head = nullptr;
            tail = nullptr;
        }
        
        bool isEmpty();
        std::string showHead();
        std::string showTail();
        void push(Node* element);
        void pop();
        std::string display();
};

bool Stack::isEmpty() {
    return (head == nullptr);
}

std::string Stack::showHead() {
    return head->showData();
}

std::string Stack::showTail() {
    return tail->showData();
}

void Stack::push(Node *element) {
    if (isEmpty()) {
        head = element;
        tail = element;
        return;
    }
    element->next = head;
    head = element;
}

void Stack::pop() {
    if(isEmpty())
        return;
    Node *temp = head;
    head = head->next;
    delete temp;
}

std::string Stack::display() {
    std::string fullData = "";
    Node *temp = head;
    while (temp != nullptr) {
        fullData += temp->showData() + '\n';
        temp = temp->next;
    }
    return fullData;
}


#endif
