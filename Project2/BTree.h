#ifndef BTree_B_Tree_H
#define BTree_B_Tree_H

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class BNode { 
    public:
        int ClientID;
        char FirstName[10];
        char Surname[10];
        char Destination[15];
        char Membership[10];
        char Booking[10];
        const static int ORDER = 5; // max number of keys before split occurs
        const static int CHILDREN = ORDER+1; // max number of pointer a node can have
        vector<BNode*> keys; // array to hold keys 
        vector<BNode*> children; // array of pointers for children
        bool isLeaf; // determine if node is a leaf
        int no_keys; // number of jeys
        
        BNode (int ID, bool leaf=true) {
            ClientID = ID;
            isLeaf = leaf;
            no_keys = 0;
            keys.resize(ORDER);
            if (!isLeaf) {
                children.resize(CHILDREN);
        }
}
        
        BNode(bool leaf=true) {
            ClientID = 0;
            keys.resize(ORDER);
            isLeaf = leaf;
            if (!isLeaf) {
                children.resize(CHILDREN);
            }
            no_keys = 0;
        }
        
        BNode (Record rec, bool leaf=true) {
            
            ClientID = rec.id;
            strcpy(FirstName , rec.firstname);
            strcpy(Surname, rec.surname);
            strcpy(Destination, rec.destination);
            strcpy(Membership, rec.membership);
            strcpy(Booking, rec.booking);
            
            isLeaf = leaf;
            no_keys = 0;
            keys.resize(ORDER);
            if (!isLeaf) {
                children.resize(CHILDREN);
            }
        }
        void addKey(int, bool); // add key to node ordered
        void addKey(Record, bool);
        void addKey(BNode*);
        string getData();
        // void addKey(Data_Cloud);
        
};

string BNode::getData() {
    string data = "";
    stringstream data_stream;
    
    data_stream << std::left << setw(25) << ClientID 
                << std::left << setw(15) << FirstName
                << std::left << setw(15) << Surname 
                << std::left << setw(15) << Destination
                << std::left << setw(15) << Membership 
                << std::left << setw(15) << Booking 
                << endl; 
    
    data = data_stream.str();
    
    return data;
}
void BNode::addKey(int ID, bool leaf=true) {
    int i = 0;
    while (keys[i] != NULL && keys[i]->ClientID <= ID)
        i++;
    if (keys[i] != NULL && keys[i]->ClientID > ID) {
        for(int j = no_keys; j > i; j--)
            keys[j] = keys[j - 1];
    }
    keys[i] = new BNode(ID, leaf);
    no_keys++;
}

        
void BNode::addKey(Record rec, bool leaf=true) {
    int i = 0;
    while (keys[i] != NULL && keys[i]->ClientID <= rec.id)
        i++;
    if (keys[i] != NULL && keys[i]->ClientID > rec.id) {
        for(int j = no_keys; j > i; j--)
            keys[j] = keys[j - 1];
    }
    keys[i] = new BNode(rec, leaf);
    no_keys++;
}

void BNode::addKey(BNode* node) {
    int i = 0;
    while (keys[i] != NULL && keys[i]->ClientID <= node->ClientID)
        i++;
    if (keys[i] != NULL && keys[i]->ClientID > node->ClientID) {
        for(int j = no_keys; j > i; j--)
            keys[j] = keys[j - 1];
    }
    keys[i] = node;
    no_keys++;
}




struct Data_Cloud { // struct to hold keys that float up B-Tree
    BNode* new_children[2]; // children that will float up when tree splits
    int new_key = 0; // new key value that will float up
};


class BTree {
  public:
    BNode * root;
    
    BTree() {
        root = new BNode(); 
    }
    
    //void addNode(Data_Cloud);
    void insert(Record rec) {
        Data_Cloud* data = insertHelper(root, rec);
        if (data == NULL)
            return;
        BNode* new_node = new BNode(false);
        new_node->addKey(data->new_key, false);
        new_node->children[0] = data->new_children[0];
        new_node->children[1] = data->new_children[1];
        // new root
        root = new_node;
        
    }
    Data_Cloud* insertHelper(BNode*, Record);
    string traverse(BNode*);
    string displayBTree() {return traverse(root);};
};



Data_Cloud* BTree::insertHelper(BNode* node, Record rec) {

    Data_Cloud* data_cloud;
    /*if (node == NULL) {
        BNode* temp_creator = new BNode(ID);
        return NULL;
    } */
    if (node->isLeaf) {
        node->addKey(rec);
        if (node->no_keys == node->ORDER) {
            
            // split nodes
            // move node data to pointers already created
            BNode* new_node1 = new BNode();
            BNode* new_node2 = new BNode();
            new_node1->addKey(node->keys[0]);
            new_node1->addKey(node->keys[1]);
            new_node2->addKey(node->keys[2]);
            new_node2->addKey(node->keys[3]);
            new_node2->addKey(node->keys[4]);
            
            // 
            //cout << "Node is split into 2" << endl;
            data_cloud = new Data_Cloud;
            data_cloud->new_children[0] = new_node1; //node->keys[0];
            data_cloud->new_children[1] = new_node2; //node->keys[2];
            data_cloud->new_key = node->keys[2]->ClientID;
            return data_cloud;
        }
        else {
            //cout << "Inserted and not full" << endl;
            return NULL;
        }
            
        
    }
    else {
        int index = 0;
        while (node->keys[index] != NULL && rec.id > node->keys[index]->ClientID) 
            index++;
        if (node->children[index] == NULL) // overshot by 1 so return to last child's index
            index--;
        Data_Cloud* data = insertHelper(node->children[index], rec);
        if (data == NULL)
            return NULL;
        // else
        delete node->children[index];
        node->children[index] = NULL;
        // shift up all children after index by 1
        
        for (int i = node->CHILDREN-1; i > index; i--)
            node->children[i] = node->children[i-1];
            
        node->children[index] = data->new_children[0]; // replace child deleted
        node->children[index+1] = data->new_children[1]; // next child would be more that node relpaced
        node->addKey(data->new_key, false);
        
         if (node->no_keys == node->ORDER) {
            // split nodes
            BNode* left = new BNode(false); // left split 
            BNode* right = new BNode(false); // right split
            // put first FLOOR(ORDER / 2) nodes in left
            left->addKey(node->keys[0]); // add keys from split node
            left->addKey(node->keys[1]);
            
            // based on current implementation i suspect these lines cause an error sometimes
            
            left->children[0] = node->children[0]; /// copy children from node being split
            left->children[1] = node->children[1];
            left->children[2] = node->children[2];
            //put [FLOOR(ORDER / 2) : ORDER] nodes in right
            right->addKey(node->keys[2]);
            right->addKey(node->keys[3]);
            right->addKey(node->keys[4]);
            right->children[0] = node->children[3];
            right->children[1] = node->children[4];
            right->children[2] = node->children[5];
            /*node->keys[0]->addKey(node->keys[1]->id); 
            node->keys[2]->addKey(node->keys[3]->id); 
            node->keys[2]->addKey(node->keys[4]->id); */
            
            data_cloud = new Data_Cloud;
            data_cloud->new_children[0] = left;
            data_cloud->new_children[1] = right;
            data_cloud->new_key = node->keys[2]->ClientID;
            return data_cloud;
        }
        else
            return NULL;
    }
        // check children
        // when going into a child node, store index went through and delete if the node is split 
        
}

string BTree::traverse(BNode* node) {
    string data = "";
    if (node->isLeaf) {
        for (int i = 0; i < node->no_keys; i ++) {
            data.append(node->keys[i]->getData());
            //data.append(  " ");
        }
        //cout << endl;
    }
    else {
        int i =0;
        while (node->children[i] != NULL && i < node->CHILDREN){
            data.append( traverse(node->children[i]));
            i++;
        }
    }
    
    return data;
}
    
    

/*
int main()
{
    /*BNode * node = new BNode();
    node->addKey(5);
    node->addKey(3);
    node->addKey(1);
    node->addKey(9);
    node->addKey(10);*/
    
    /*
    BTree tree;
    tree.insert(1);
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(35);
    tree.insert(25);
    tree.insert(100);
    tree.insert(2);
    tree.insert(74);
    tree.insert(8);
    tree.insert(6);
    tree.insert(22);
    
    
    tree.insert(102);
    tree.insert(77);
    tree.insert(29);
    tree.insert(88);
    tree.insert(5);
    tree.insert(19);
    tree.insert(45);
    tree.insert(18);
    tree.insert(101);
    
    // what is printed below shows the state of the tree
    // not printing data doesn't work
    cout << tree.root->children[1]->children[1]->keys[1]->id << endl;
    
    //cout << tree.root->children[0]->keys[1]->id << endl;
    cout << endl;
    string data = "";
    //string *p_data = &data;
    data = tree.traverse(tree.root);
    cout << data << endl;
    //tree.insert(1);
    //tree.insert(7);
    return 0; 
} */ // max tested to works: 28

#endif
