//
//  SplayTree.h
//  Splay
//
//  Created by Dr. John Charlery on 11/2/2021.
//  Copyright (c) 2021 University of the West Indies. All rights reserved.
//

#ifndef SPLAYTREE_H
#define SPLAYTREE_H


class SplayNode
    {
        private:
                int ClientID;
                char FirstName[10];
                char Surname[10];
                char Destination[15];
                char Membership[10];
                char Booking[10];
    
        public:
                SplayNode *left;  	// pointer to left subtree
                SplayNode *right;    // pointer to right subtree
    
                //Constructor
                SplayNode( Record rec ) {
                    ClientID = rec.id; 
                    right = left = NULL;
                    
                    strcpy(FirstName , rec.firstname);
                    strcpy(Surname, rec.surname);
                    strcpy(Destination, rec.destination);
                    strcpy(Membership, rec.membership);
                    strcpy(Booking, rec.booking);   
                }
                SplayNode() {left = 0; right= 0;}
    
                //Accessors
                int getID()       { return ClientID;}
                char* getFirstName()       { return FirstName;}
                char* getSurname()       { return Surname;}
                char* getDestination()       { return Destination;}
                char* getMembership()       { return Membership;}
                char* getBooking()       { return Booking;}
                string getData();
                SplayNode* getLeft()  const { return left;}
                SplayNode* getRight() const { return right;}
    
    
                //Mutators
                void setID(int id)       {ClientID = id;}
                void setData(int id, char* fname, char * sname, char * dest, char * membership, char * booking) {
                    strcpy(FirstName , fname);
                    strcpy(Surname, sname);
                    strcpy(Destination, dest);
                    strcpy(Membership, membership);
                    strcpy(Booking, booking);
                }
                void setFirstName(char* fname)  {strcpy(FirstName , fname);}
                void setSurname(char* sname)  {strcpy(Surname , sname);}
                void setDestination(char* dest)  {strcpy(Destination , dest);}
                void setMembership (char* membership)  {strcpy(Membership , membership);}
                void setBooking(char* booking)  {strcpy(Booking , booking);}
                void setLeft(SplayNode* ptr)  { left = ptr; }
                void setRight(SplayNode* ptr) { right = ptr; }
    };

string SplayNode::getData() {
    string data = "";
    stringstream data_stream;
    string left_child = "NULL";
    string right_child = "NULL";
    if (this->getLeft() != NULL) 
        left_child = to_string(this->getLeft()->getID());
    if (this->getRight() != NULL) 
        right_child = to_string(this->getRight()->getID());
    
    
    string idData = to_string(ClientID) + "[" + left_child + ", " + right_child + "]";
    data_stream << std::left << setw(25) << idData 
                << std::left << setw(15) << FirstName
                << std::left << setw(15) << Surname 
                << std::left << setw(15) << Destination
                << std::left << setw(15) << Membership 
                << std::left << setw(15) << Booking 
                << endl; 
    
    data = data_stream.str();
    
    return data;
}


class SplayTree
    {
        private:
                SplayNode *root;
    
                    // Utility functions
                SplayNode* RightRotate(SplayNode*);
                SplayNode* LeftRotate(SplayNode*);
                SplayNode* Splay(int, SplayNode*);
                SplayNode* insertHelper(Record, SplayNode*);
                string InOrderHelper(SplayNode*);
                string PreOrderHelper(SplayNode*);
                string PostOrderHelper(SplayNode*);
                void insertSplayNodeHelper(SplayNode **, int );
                string displayNodesHelper( SplayNode * ) const;
                void deleteSplayNode( SplayNode* );
                SplayNode* findSplayNode( int );
                SplayNode* getSuccessor(SplayNode* );
                SplayNode* getParent(SplayNode* );
                SplayNode* getMinimum( SplayNode* );

    
            public:
                SplayTree(){ root = 0; };
    
                SplayNode* getRoot(){return root;}
                void insert(Record);
                string inOrder(){ return InOrderHelper(root);}
                string preOrder(){ return PreOrderHelper(root);}
                string postOrder(){ return PostOrderHelper(root);}
                void insertSplayNode( Record );
                string displayNodes();
                void remove(int);
                string findNodeData(int id);
    };

string SplayTree::findNodeData(int id) {
    SplayNode* node = root;
    while (node != NULL) {
        if (node->getID() == id)
            return node->getData();
        if (id >= node->getID())
            node = node->getRight();
        else
            node = node->getLeft();
    }
    return "No Entry Found";
}


SplayNode* SplayTree::RightRotate(SplayNode* ptr)
{
    SplayNode* leftchild = ptr->left;
    ptr->left = leftchild->right;
    leftchild->right = ptr;
    return leftchild;
}




SplayNode* SplayTree::LeftRotate(SplayNode* ptr)
{
    SplayNode* rightchild = ptr->right;
    ptr->right = rightchild->left;
    rightchild->left = ptr;
    return rightchild;
}





SplayNode* SplayTree::Splay(int key, SplayNode* root)
    {
        if(root == NULL)
            return NULL;
        
        SplayNode* header = new SplayNode();
        
        SplayNode* LeftTreeMax = header;
        SplayNode* RightTreeMin = header;
        
        /* loop until root->left == NULL || root->right == NULL; then break!
         The zig/zag mode would only happen when cannot find key and will reach
         null on one side after RR or LL Rotation.
         */
        while(root->left != NULL || root->right != NULL)
            {
                if(key < root->getID())
                    {
                        if(root->left == NULL)
                            break;
                    
                        if(key < root->left->getID())
                            {
                                root = RightRotate(root); /* Only zig-zig mode need to rotate once,
                                                        because zig-zag mode is handled as zig
                                                        mode, which doesn't require rotate,
                                                        just linking it to R Tree */
                                if(!root->left)
                                    break;
                            }
                    
                        /* Link to Right Tree */
                        RightTreeMin->left = root;
                        RightTreeMin = RightTreeMin->left;
                        root = root->left;
                        RightTreeMin->left = NULL;
                    }
                else if(key > root->getID())
                        {
                            if(root->right == NULL)
                                break;
                            if(key > root->right->getID())
                                {
                                    root = LeftRotate(root);/* only zag-zag mode need to rotate once,
                                                        because zag-zig mode is handled as zag
                                                        mode, which doesn't require rotate,
                                                        just linking it to L Tree */
                                    if(root->right == NULL)
                                        break;
                                }
                            /* Link to Left Tree */
                            LeftTreeMax->right = root;
                            LeftTreeMax = LeftTreeMax->right;
                            root = root->right;
                            LeftTreeMax->right = NULL;
                        }
                    else
                        break;
                }
            /* assemble Left Tree, Middle Tree and Right tree together */
            LeftTreeMax->right = root->left;
            RightTreeMin->left = root->right;
            root->left = header->right;
            root->right = header->left;
            return root;
    }




SplayNode* SplayTree::findSplayNode(int val)
    {
        SplayNode* ptr = root;
        
        while ( ptr != NULL )
            {
                if  (ptr->getID() == val)        // Found it!
                        {
                            return ptr;
                        }
            
                if (val < ptr->getID() )
                    {
                        ptr = ptr->left;
                    }
                else
                    {
                        ptr = ptr->right;
                    }
            }
    
        return NULL;            // Tree is empty OR did not find it
    }






SplayNode* SplayTree::getParent(SplayNode* ptr)
    {
        if (ptr == NULL)
            return NULL;
        
        if (ptr == root)
            return NULL;
        
        SplayNode* cur = root;
        
        while ( cur != NULL )
            {
                if (cur->left == ptr || cur->right == ptr)        // Found it!
                    {
                        return cur;
                    }
                else
                    {
                        if (ptr->getID() < cur->getID())
                            cur = cur->left;
                        else
                            cur = cur->right;
                    }
            }
         return cur;            // Parent for ptr is NOT found
    }




SplayNode* SplayTree::getSuccessor(SplayNode* ptr)
{
    if (ptr->right == NULL)
        return ptr->left;
    else
        return(getMinimum(ptr->right));
}




SplayNode* SplayTree::getMinimum(SplayNode *ptr)
{
    while(ptr->left != NULL)
        ptr = ptr->left;

    return ptr;
}






SplayNode* SplayTree::insertHelper(Record rec, SplayNode* root)
    {
        SplayNode* newnode = new SplayNode(rec);
    
        if(root == NULL)
            return newnode;
    
        SplayNode* parent_temp = new SplayNode();
        SplayNode* temp = root;
    
        while(temp != NULL)
            {
                parent_temp = temp;
            
                if(rec.id <= temp->getID())
                    temp = temp->left;
                else
                    temp = temp->right;
            }
    
        if(rec.id <= parent_temp->getID())
            parent_temp->left = newnode;
        else
            parent_temp->right = newnode;
    
        root = Splay(rec.id, root);
        return (root);
    }




void SplayTree::insert(Record rec)
{
    root = insertHelper(rec, root);

}



string SplayTree::InOrderHelper(SplayNode* ptr)
    {
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( InOrderHelper(ptr->left) );
            
                str.append( ptr->getData() );
            
                str.append( InOrderHelper(ptr->right) );
              }
		return str;
    }


string SplayTree::PreOrderHelper(SplayNode* ptr)
    {
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( ptr->getData() );
            
                str.append( PreOrderHelper(ptr->left) );
                str.append( PreOrderHelper(ptr->right) );
              }
		return str;
    }


string SplayTree::PostOrderHelper(SplayNode* ptr)
    {
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( PostOrderHelper(ptr->left) );
                str.append( PostOrderHelper(ptr->right) );
            
                str.append( ptr->getData() );
            
              }
		return str;
    }





void SplayTree::remove(int str)
    {
        SplayNode* markedSplayNode = findSplayNode(str);
        deleteSplayNode(markedSplayNode);
    }





void SplayTree::deleteSplayNode(SplayNode* node2Zap)
    {

        if (node2Zap == NULL)    //If node2Zap is NULL then do nothing.
            return;
        else
            {
                SplayNode *successor, *successorChild, *parent;
            
                if (node2Zap->left == NULL || node2Zap->right == NULL)
                    successor = node2Zap;
                else                                        // node2Zap has 2 children
                    successor = getSuccessor(node2Zap);
            
 
                successorChild = successor->right;
                parent = getParent(successor);
            
            
                // Transfer data from successor to node2Zap
                node2Zap->setData( successor->getID(), successor->getFirstName(), successor->getSurname(), successor->getDestination(), successor->getMembership(), successor->getBooking() );
            
            
                if ( parent == NULL)
                    root = successorChild;
                else if (successor == parent->left)
                        parent->left = successorChild;
                    else
                        parent->right = successorChild;
                
                if (successor != node2Zap)
                    node2Zap->setData( successor->getID(), successor->getFirstName(), successor->getSurname(), successor->getDestination(), successor->getMembership(), successor->getBooking() );
            
                delete successor;

            }
 
    }


#endif
