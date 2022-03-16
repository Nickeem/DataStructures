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
                int data;            // Node value
    
        public:
                SplayNode *left;  	// pointer to left subtree
                SplayNode *right;    // pointer to right subtree
    
                //Constructor
                SplayNode( int val ) {data = val; left = right= 0;}
                SplayNode() {left = 0; right= 0;}
    
                //Accessors
                int getData()      const { return data; }
                SplayNode* getLeft()  const { return left;}
                SplayNode* getRight() const { return right;}
    
    
                //Mutators
                void setValue(int val)     { data = val; }
                void setLeft(SplayNode* ptr)  { left = ptr; }
                void setRight(SplayNode* ptr) { right = ptr; }
    };




class SplayTree
    {
        private:
                SplayNode *root;
    
                    // Utility functions
                SplayNode* RightRotate(SplayNode*);
                SplayNode* LeftRotate(SplayNode*);
                SplayNode* Splay(int, SplayNode*);
                SplayNode* InsertHelper(int, SplayNode*);
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
                void Insert(int);
                string InOrder(){ return InOrderHelper(root);}
                string PreOrder(){ return PreOrderHelper(root);}
                string PostOrder(){ return PostOrderHelper(root);}
                void insertSplayNode( int );
                string displayNodes();
                void remove(int);
    };




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
                if(key < root->getData())
                    {
                        if(root->left == NULL)
                            break;
                    
                        if(key < root->left->getData())
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
                else if(key > root->getData())
                        {
                            if(root->right == NULL)
                                break;
                            if(key > root->right->getData())
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
                if  (ptr->getData() == val)        // Found it!
                        {
                            return ptr;
                        }
            
                if (val < ptr->getData() )
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
                        if (ptr->getData() < cur->getData())
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






SplayNode* SplayTree::InsertHelper(int key, SplayNode* root)
    {
        SplayNode* newnode = new SplayNode(key);
    
        if(root == NULL)
            return newnode;
    
        SplayNode* parent_temp = new SplayNode();
        SplayNode* temp = root;
    
        while(temp != NULL)
            {
                parent_temp = temp;
            
                if(key <= temp->getData())
                    temp = temp->left;
                else
                    temp = temp->right;
            }
    
        if(key <= parent_temp->getData())
            parent_temp->left = newnode;
        else
            parent_temp->right = newnode;
    
        root = Splay(key, root);
        return (root);
    }




void SplayTree::Insert(int key)
{
    root = InsertHelper(key, root);

}



string SplayTree::InOrderHelper(SplayNode* ptr)
    {
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( InOrderHelper(ptr->left) );
            
                str.append( to_string(ptr->getData()) );
                str.append( "  ");
            
                str.append( InOrderHelper(ptr->right) );
              }
		return str;
    }


string SplayTree::PreOrderHelper(SplayNode* ptr)
    {
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( to_string(ptr->getData()) );
                str.append( "  ");
            
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
            
                str.append( to_string(ptr->getData()) );
                str.append( "  ");
            
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
                node2Zap->setValue(successor->getData());
            
            
                if ( parent == NULL)
                    root = successorChild;
                else if (successor == parent->left)
                        parent->left = successorChild;
                    else
                        parent->right = successorChild;
                
                if (successor != node2Zap)
                    node2Zap->setValue(successor->getData());
            
                delete successor;

            }
 
    }


#endif
