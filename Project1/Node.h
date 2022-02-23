#ifndef NODE_H
#define NODE_H
#include <iostream> 

class Node {
    private:
        std::string *data;
    public:
        Node *next;
        int ID;
        
        Node(std::string *data) {
            next = nullptr;
            this->data = data;
        }
        
        Node(std::string *data, int id) {
            next = nullptr;
            this->ID = id;
            this->data = data;
        }
        
        std::string showData();
        void setID(int);
        int getID();
};

std::string Node::showData() {
    return *data;
}

void Node::setID(int id) {
    this->ID = id;
}

int Node::getID() {
    return ID;
}

#endif
