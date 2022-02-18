#ifndef NODE_H
#define NODE_H
#include <iostream> 

class Node {
    private:
        std::string *data;
    public:
        Node *next;
        
        Node(std::string *data) {
            next = nullptr;
            this.data = data;
        }
        
        std::string showData();
};

std::string Node::showData() {
    return *data;
}

#endif