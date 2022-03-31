//
//  AVLTree.h
//  AVL
//
//  Created by Dr. John Charlery on 02/22/2022.
//  Copyright (c) 2022 University of the West Indies. All rights reserved.
//

#ifndef AVL_AVLTree_H
#define AVL_AVLTree_H

#include <cstring>


class AVLNode
    {
        private:
            int ClientID;
            char FirstName[10];
            char Surname[10];
            char Destination[15];
            char Membership[10];
            char Booking[10];
            
            int height;
            AVLNode* left;
            AVLNode* right;

        public:
            // Constructor functions
            AVLNode()        {ClientID = -99; height = 0; right = left = NULL;}
            AVLNode(Record rec) {
                height = 0;
                
                ClientID = rec.id; 
                right = left = NULL;
                
                strcpy(FirstName , rec.firstname);
                strcpy(Surname, rec.surname);
                strcpy(Destination, rec.destination);
                strcpy(Membership, rec.membership);
                strcpy(Booking, rec.booking);
            }
    
            // Mutator functions
            void setID(int ud)       {ClientID = id;}
            void setData(int id, char* fname, char * sname, char * dest, char * membership, char * booking) {
                strcpy(FirstName , fname);
                strcpy(Surname, sname);
                strcpy(Destination, dest);
                strcpy(Membership, membership);
                strcpy(Booking, booking);
            }
            void setHeight(int ht)      {height = ht;}
            void setLeft(AVLNode* ptr)  {left = ptr;}
            void setRight(AVLNode* ptr) {right = ptr;}

            // Accessor functions
            int getID()       { return ClientID;}
            char* getFirstName()       { return FirstName;}
            char* getSurname()       { return Surname;}
            char* getDestination()       { return Destination;}
            char* getMembership()       { return Membership;}
            char* getBooking()       { return Booking;}
            int getHeight()     { return height;}
            string getData();
            AVLNode* getLeft()  { return left;}
            AVLNode* getRight() { return right;}
     };


string AVLNode::getData() {
    string data = "";
    stringstream data_stream;
    string left_child = "NULL";
    string right_child = "NULL";
    if (this->getLeft() != NULL) 
        left_child = to_string(this->getLeft()->getID());
    if (this->getRight() != NULL) 
        right_child = to_string(this->getRight()->getID());
    
    
    data_stream << ClientID << " [" << left_child << ", " << right_child << "]"
                << "     " 
                << std::left << setw(20) << FirstName
                << std::left << setw(20) << Surname 
                << std::left << setw(20) << Destination
                << std::left << setw(20) << Membership 
                << std::left << setw(20) << Booking 
                << endl; 
    
    data = data_stream.str();
    
    return data;
}



class AVL
    {
        private:
            AVLNode* root;
    
            AVLNode* insertHelper(AVLNode*, Record);       // Recursive counterpart of insert
            AVLNode* deleteNode(AVLNode*, int);         // Recursive counterpart of delete
            string   preOrderHelper(AVLNode* );         // Recursive counterpart of preorder
            string   postOrderHelper(AVLNode* );        // Recursive counterpart of postorder
            string   inOrderHelper(AVLNode* );          // Recursive counterpart of inorder
            AVLNode* rotateRight(AVLNode* );
            AVLNode* rotateLeft(AVLNode* );
            AVLNode* rotateDoubleRight(AVLNode* );
            AVLNode* rotateDoubleLeft(AVLNode* );
            AVLNode* rotateLeftRight(AVLNode* );
            AVLNode* rotateRightLeft(AVLNode* );
            int      calcHeight(AVLNode* );
            int      calcBalance(AVLNode* );
        
        public:
            AVL() { root = NULL;}
    
            AVLNode* getRoot()       { return root;}
            void     insert(Record rec) { root = insertHelper(root, rec); }
            void     remove(int id) { root = deleteNode(root, id); }
            string   preOrder()      { return preOrderHelper(root); }
            string   postOrder()     { return postOrderHelper(root); }
            string   inOrder()       { return inOrderHelper(root); }
            void     purge()         { root = NULL; }
            
    };





AVLNode* AVL::insertHelper(AVLNode* ptr, Record rec)
    {
        if ( ptr == NULL )
            {
                ptr = new AVLNode(rec);
            }
        
        else        // Tree is is not empty
            {
                if(rec.id >= ptr->getID())      // insert in right subtree; OP definition
                   {
                        ptr->setRight( insertHelper(ptr->getRight(), rec));
                        if(calcBalance(ptr) == -2)          // Too heavy on the right
                            {
                                if(rec.id >= (ptr->getRight())->getID() )  // Regular right-heavy
                                    ptr = rotateDoubleRight(ptr);
                                else                        // It's a special case: ">"
                                    ptr = rotateRightLeft(ptr);
                            }
                    }
            
                else
                    if( rec.id < ptr->getID() )  // Insert it in ptr's left subtree
                        {
                            ptr->setLeft(insertHelper(ptr->getLeft(), rec));
                            if(calcBalance(ptr) == 2)       // Too heavy on the left
                                {
                                    if( rec.id <= (ptr->getLeft())->getID() ) // Regular left-heavy
                                        ptr = rotateDoubleLeft(ptr);
                                    else                    // It's a special case: "<"
                                        ptr = rotateLeftRight(ptr);
                                }
                        }
            
                ptr->setHeight(calcHeight(ptr));
            }
        
        return(ptr);
    }





AVLNode*  AVL::deleteNode(AVLNode* ptr, int id)
{
    
    if ( ptr == NULL)           // Node location is empty
        {
            return NULL;
        }
    
    // else the tree/subtree is not empty
        AVLNode* successor;
    
        if( id > ptr->getID() )            // Search in Right sub-tree of ptr
            {
                ptr->setRight(deleteNode(ptr->getRight(), id));
                if ( calcBalance(ptr) == 2)        // Subtree is too heavy on the left of ptr
                    {
                        if(calcBalance(ptr->getLeft()) >= 0)
                            ptr = rotateDoubleLeft(ptr);
                        else
                            ptr = rotateLeftRight(ptr);
                    }
            }
        else
            if( id < ptr->getID() )              // Search the Left sub-tree
                {
                    ptr->setLeft( deleteNode(ptr->getLeft(), id));
                    if( calcBalance(ptr) == -2 )     // Rebalance: ptr is too heavy on the right
                        {
                            if( calcBalance(ptr->getRight()) <= 0)
                                ptr = rotateDoubleRight(ptr);
                            else
                                ptr = rotateRightLeft(ptr);
                        }
                }
            else
                {
                    //Node to to be deleted is found
                    if ( ptr->getRight() != NULL)
                        {  //Go right and deep left
                            successor = ptr->getRight();
                            while ( successor->getLeft() != NULL)
                                successor = successor->getLeft();
                            
                            ptr->setData( successor->getID(), successor->getFirstName(), successor->getSurname(), successor->getDestination(), successor->getMembership(), successor->getBooking() );
                            ptr->setRight( deleteNode( ptr->getRight(), ptr->getID() ));
                            if(calcBalance(ptr) == 2) // Rebalance: ptr is too heavy on the left
                                {
                                    if(calcBalance(ptr->getLeft()) >= 0)
                                        ptr = rotateDoubleLeft(ptr);
                                    else
                                        ptr = rotateLeftRight(ptr);
                                }
                    }
                else
                    return(ptr->getLeft());
                
                }
    ptr->setHeight(calcHeight(ptr));
    return(ptr);
}







AVLNode*  AVL::rotateRight(AVLNode* ptr)
    {
        AVLNode* newParent;
    
        newParent = ptr->getLeft();
        ptr->setLeft( newParent->getRight());
        newParent->setRight( ptr );
        ptr->setHeight(calcHeight(ptr));
        newParent->setHeight(calcHeight(newParent));
    
        return ( newParent );
    }





AVLNode*  AVL::rotateLeft(AVLNode* ptr)
    {
        AVLNode* newParent;
    
        newParent = ptr->getRight();
        ptr->setRight( newParent->getLeft() );
        newParent->setLeft( ptr );
        ptr->setHeight(calcHeight(ptr));
        newParent->setHeight(calcHeight(newParent));
    
        return ( newParent );
    }





AVLNode*  AVL::rotateDoubleRight(AVLNode* ptr)
    {
        ptr = rotateLeft(ptr);
        return(ptr);
    }





AVLNode*  AVL::rotateDoubleLeft(AVLNode* ptr)
    {
        ptr = rotateRight(ptr);
        return(ptr);
    }





AVLNode*  AVL::rotateLeftRight(AVLNode* ptr)
    {
        ptr->setLeft( rotateLeft(ptr->getLeft()));
        ptr = rotateRight(ptr);
        return(ptr);
    }






AVLNode*  AVL::rotateRightLeft(AVLNode* ptr)
    {
        ptr->setRight( rotateRight( ptr->getRight()) );
        ptr = rotateLeft(ptr);
        return(ptr);
    }





int AVL::calcHeight(AVLNode* ptr)
    {
        int leftHeight, rightHeight;
        
        if( ptr == NULL)
            return(0);
        
        if(ptr->getLeft() == NULL)
            leftHeight = 0;
        else
            leftHeight = 1 + ptr->getLeft()->getHeight();
        
        if(ptr->getRight() == NULL)
            rightHeight = 0;
        else
            rightHeight = 1 + ptr->getRight()->getHeight();

    
        if(leftHeight > rightHeight)
            return(leftHeight);
    
        return(rightHeight);
    }





int AVL::calcBalance(AVLNode* ptr)
    {
        int leftHeight, rightHeight;
    
        if(ptr == NULL)
            return (0);
    
        if(ptr->getLeft() == NULL)
            leftHeight = 0;
        else
            leftHeight = 1 + ptr->getLeft()->getHeight();
    
        if(ptr->getRight() == NULL)
            rightHeight = 0;
        else
            rightHeight = 1 + ptr->getRight()->getHeight();
    
        return(leftHeight - rightHeight);
    }






string AVL::inOrderHelper(AVLNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( inOrderHelper(ptr->getLeft()) );
            
                 str.append( ptr->getData() );
            
                str.append( inOrderHelper(ptr->getRight()) );
              }
		return str;
	}




string AVL::preOrderHelper(AVLNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( ptr->getData() );

            
                str.append( preOrderHelper(ptr->getLeft()) );
                str.append( preOrderHelper(ptr->getRight()) );
              }
		return str;
	}




string AVL::postOrderHelper(AVLNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( inOrderHelper(ptr->getLeft()) );
                str.append( inOrderHelper(ptr->getRight()) );
            
                 str.append( ptr->getData() );
             }
		return str;
	}




#endif // defined(AVL_AVLTree_H)
