//
//  BSTree.h
//  BST
//
//  Created by Dr. John Charlery on 02/15/2022.
//  Copyright (c) 2022 University of the West Indies. All rights reserved.
//
//  Edited By Nickeem Payne-Deacon for Data Structures Project

#ifndef BST_BSTree_h
#define BST_BSTree_h

#include <cstring>

class BSTNode
    {
        private:
            int ClientID;
            char FirstName[10];
            char Surname[10];
            char Destination[15];
            char Membership[10];
            char Booking[10];
            BSTNode* left;
            BSTNode* right;

        public:
            // Constructor functions
            BSTNode(){right = left = NULL; ClientID = -99;}
            BSTNode(int id, char* fname, char * sname, char * dest, char * membership, char * booking ){
                ClientID = id; 
                right = left = NULL;
                
                strcpy(FirstName , fname);
                strcpy(Surname, sname);
                strcpy(Destination, dest);
                strcpy(Membership, membership);
                strcpy(Booking, booking);
}
    
            // Accessor functions
            BSTNode* getLeft()  {return left;};
            BSTNode* getRight() {return right;}
            int getID()       {return ClientID;}
            char* getFirstName() {return FirstName;}
            char* getSurname() { return Surname;}
            char* getDestination() {return Destination; }
            char* getMembership() {return Membership;}
            char* getBooking() {return Booking;}
            string getData();

            // Mutator functions
            void setData(int val)       {ClientID = val;}
            void setLeft(BSTNode* ptr)  {left = ptr;}
            void setRight(BSTNode* ptr) {right = ptr;}
            void copyData(BSTNode*);
     };

string BSTNode::getData() {
    string data = "";
    data += ClientID;
    data += "\t";
    
    data += FirstName;
    data += "\t";
    
    data += Surname;
    data += "\t";

    data += Destination;
    data += "\t";

    data += Membership;
    data += "\t";
    
    data += Booking;
    
    return data;
}
void BSTNode::copyData(BSTNode* ptr)
    {
        // Copy all te attributes from ptr
        ClientID = ptr->getID();
        strcpy(FirstName, ptr->getFirstName());
        strcpy(Surname, ptr->getSurname());
        strcpy(Destination, ptr->getDestination());
        strcpy(Membership, ptr->getMembership());
        strcpy(Booking, ptr->getBooking());
    }





class BST
    {
        private:
            BSTNode* root;
    
            // Recursive counterpart for inserting a node
            BSTNode* insertHelper(BSTNode*, int, char*, char*, char*, char*, char*);
    
            // Recursive counterpart for deleting a node
            BSTNode* deleteNode(BSTNode*, int);
            BSTNode* deleteHelper(BSTNode*, int);

    
            // Recursive counterpart of preorder traversal
            string preOrderHelper(BSTNode* );
    
            // Recursive counterpart of postorder traversal
            string postOrderHelper(BSTNode* );

            // Recursive counterpart of inorder traversal
            string inOrderHelper(BSTNode* );
    
        public:
            //  Constructor function
            BST() { root = NULL;}
    
            // Mutator functions
            void purge()         { root = NULL;}
            void insert(int id, char* fname, char* sname, char* dest, char* membership, char* booking) { root = insertHelper(root, id, fname, sname, dest, membership, booking); }
            void remove(int val) { root = deleteHelper(root, val);}
        
            // Accessor functions
            BSTNode* getRoot() { return root;}
            string preOrder()  { return preOrderHelper(root); }
            string postOrder() { return postOrderHelper(root); }
            string inOrder()   { return inOrderHelper(root); }
    
    };





BSTNode* BST::insertHelper(BSTNode* ptr, int id, char* fname, char* sname, char* dest, char* membership, char* booking)
    {
        if ( ptr == NULL )         // The tree is empty - new first node!
            {
                ptr = new BSTNode(id, fname, sname, dest, membership, booking);
            }
        else                       // choose which sub-tree to follow
            {
                if (id >= ptr->getID())          // insert in right subtree - Operational defn.
                    ptr->setRight(insertHelper(ptr->getRight(), id, fname, sname, dest, membership, booking ));
                else                                                    // insert in left subtree
                    ptr->setLeft(insertHelper(ptr->getLeft(), id, fname, sname, dest, membership, booking));
            }
        return ptr;
    }







BSTNode* BST::deleteHelper(BSTNode* ptr, int id)
    {
        // Base condition
        if (ptr == NULL)
            {
                return NULL;
            }
        
        // Otherwise...
        
        BSTNode* successor;

        if (id > ptr->getID())                               // Search for id in right sub-tree
            ptr->setRight(deleteHelper(ptr->getRight(), id));
        
        else if (id < ptr->getID())                           // Search for id in left sub-tree
                ptr->setLeft(deleteHelper(ptr->getLeft(), id));
        
            else    //Found it! ptr is the node to be deleted
                {
                   if (ptr->getRight() !=  NULL)
                       {  // delete its inorder succesor
                           successor = ptr->getRight();                 // Go right...
                           while ( successor->getLeft() != NULL )       // ...and then go deep left
                               successor = successor->getLeft();
                           
                           // Transfer data from successor to ptr
                           ptr->copyData( successor );

                           // Now reset ptr's right child
                           ptr->setRight(deleteHelper( ptr->getRight(), ptr->getID() ));
                       }
                   else
                       if (ptr->getLeft() !=  NULL)         // It has a left child, but no right child
                           {
                               ptr->copyData(ptr->getLeft());
                               ptr->setLeft(deleteHelper( ptr->getLeft(), ptr->getID() ));
                               return ptr;
                           }
                       else                     // It has neither left nor right child
                           return NULL;
                    
                            /* The entire else block (Lines 143 - 151) can be replaced with:
                             
                               else
                                   return (ptr->getLeft());
                             
                             */
                }
        return ptr;
    }







string BST::inOrderHelper(BSTNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( inOrderHelper(ptr->getLeft()) );
            
                str.append( to_string(ptr->getID()) );
                str.append( "  ");
            
                str.append( inOrderHelper(ptr->getRight()) );
              }
		return str;
	}




string BST::preOrderHelper(BSTNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( to_string(ptr->getID()) );
                str.append( "  ");
            
                str.append( preOrderHelper(ptr->getLeft()) );
                str.append( preOrderHelper(ptr->getRight()) );
              }
		return str;
	}




string BST::postOrderHelper(BSTNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( postOrderHelper(ptr->getLeft()) );
                str.append( postOrderHelper(ptr->getRight()) );
            
                str.append( to_string(ptr->getID()) );
                str.append( "  ");
             }
		return str;
	}



#endif
