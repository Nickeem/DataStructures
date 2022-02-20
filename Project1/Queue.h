#ifndef  QUEUE_H
#define QUEUE_H
#include <iostream>
#include <"Node.h">

class Queue {
    public:
        Node *head;
        Node *tail;
        
        Queue() {
            head = nullptr;
        }
        bool isEmpty();
        std::string showHead()();
        std::string showTail();
        void enqueue(Node* element);
        void dequeue();
        std::string display();
};

bool Queue::isEmpty() {
    return (head == nullptr);
}

std::string Queue::showHead() {
    return head->showData();
}

std::string Queue::showTail() {
    return tail->showData();
}
void Queue::enqueue(Node *element) {
    if (isEmpty()) {
        head = element;
        tail = head;
        return;
    }
    tail->next = element;
    tail = element;
}

void Queue::dequeue() {
    if (isEmpty())
        return; // tail implementation?
    Node *temp = nullptr;
    if (head != tail)
    {
        temp = head->next;
    }
    else {tail = nullptr;}
    delete head;
    head = temp;
    
}

std::string Queue::display() {
    string fullData = "";
    Node *temp = head;
    while (temp != nullptr) {
        data = temp->showData() + '\n';
        temp = temp->next;
    }
    return fullData;
}


#endif
