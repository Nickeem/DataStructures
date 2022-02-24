#ifndef NODE_H
#define NODE_H
#include <iostream> 

class Node {
    private:
        std::string data;
    public:
        Node *next;
        int ID;
        
        Node(std::string Data) {
            next = nullptr;
            data = Data;
        }
        
        Node(std::string Data, int id) {
            next = nullptr;
            ID = id;
            data = Data;
        }
        
        std::string showData();
        void setID(int);
        int getID();
};

std::string Node::showData() {
    return data;
}

void Node::setID(int id) {
    ID = id;
}

int Node::getID() {
    return ID;
}

#endif
