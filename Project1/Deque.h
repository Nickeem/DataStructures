#ifndef  DEQUE_H
#define DEQUE_H
#include <iostream>
#include <"Node.h">
#include <"Queue.h">

class Deque : public Queue{
    pubilc:
        void dequeTail();
};

void Deque::dequeTail() {
    if (isEmpty())
        return;
}

#endif
