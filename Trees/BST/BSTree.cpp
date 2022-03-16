//
//  BSTree.cpp
//  BST
//
//  Created by Dr. John Charlery on 02/15/2022.
//  Copyright (c) 2022 University of the West Indies. All rights reserved.
//

#include<iostream>
#include<fstream>
#include<string>
#include <vector>

using namespace std;

#include "BSTree.h"
#include "VisualizeTree.h"



int main()
    {
        BST* bst = new BST();
        
        // Display the tree
        cout << displayTree(bst);
        
        cout << "After 6 is inserted in the tree:\n";
        bst->insert(6);
        cout << displayTree(bst);
        
        cout << "After 9 is inserted in the tree:\n";
        bst->insert(9);
        cout << displayTree(bst);

        cout << "After 4 is inserted in the tree:\n";
        bst->insert(4);
        cout << displayTree(bst);
        
        cout << "After 2 is inserted in the tree:\n";
        bst->insert(2);
        cout << displayTree(bst);

        cout << "After 7 is inserted in the tree:\n";
        bst->insert(7);
        cout << displayTree(bst);

        cout << "After 8 is inserted in the tree:\n";
        bst->insert(8);
        cout << displayTree(bst);

        cout << "After 5 is inserted in the tree:\n";
        bst->insert(5);
        cout << displayTree(bst);

        
        cout << "\n\nDeleting now:\n";
        cout << "After 6 is deleted form the tree:\n";
        bst->remove(6);
        cout << displayTree(bst);

        cout << "\nAfter 9 is deleted form the tree:\n";
        bst->remove(9);
        cout << displayTree(bst);

        cout << "\nAfter 8 is deleted form the tree:\n";
        bst->remove(8);
        cout << displayTree(bst);

        cout << "\nInorder:\n" << bst->inOrder() << "\n\n";
        
        
        return 0;
    }



