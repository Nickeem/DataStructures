//
//  AVLTree.cpp
//  AVL
//
//  Created by Dr. John Charlery on 02/22/2022.
//  Copyright (c) 2022 University of the West Indies. All rights reserved.
//


#include <iostream>

#include<iostream>
#include<string>
#include<vector>

using namespace std;

#include "AVLTree.h"
#include "VisualizeTree.h"



int main()
{
	
	AVL* avl = new AVL();

    cout <<"\nInserting: 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18\n\n";
    avl->insert(1);
    cout <<"\nDisplaying AVL Tree After Inserting: 1:\n\n";
    cout << displayTree(avl);
    
    avl->insert(2);
    cout <<"\nDisplaying AVL Tree After Inserting: 2:\n\n";
    cout << displayTree(avl);

    avl->insert(3);
    cout <<"\nDisplaying AVL Tree After Inserting: 3:\n\n";
    cout << displayTree(avl);

    avl->insert(4);
    cout <<"\nDisplaying AVL Tree After Inserting: 4:\n\n";
    cout << displayTree(avl);
    
    avl->insert(5);
    cout <<"\nDisplaying AVL Tree After Inserting: 5:\n\n";
    cout << displayTree(avl);
    
    avl->insert(6);
    cout <<"\nDisplaying AVL Tree After Inserting: 6:\n\n";
    cout << displayTree(avl);
    
    avl->insert(7);
    cout <<"\nDisplaying AVL Tree After Inserting: 7:\n\n";
    cout << displayTree(avl);
    
    avl->insert(8);
    cout <<"\nDisplaying AVL Tree After Inserting: 8:\n\n";
    cout << displayTree(avl);
    
    avl->insert(9);
    cout <<"\nDisplaying AVL Tree After Inserting: 9:\n\n";
    cout << displayTree(avl);
    
    avl->insert(10);
    cout <<"\nDisplaying AVL Tree After Inserting: 10:\n\n";
    cout << displayTree(avl);
    
    avl->insert(11);
    cout <<"\nDisplaying AVL Tree After Inserting: 11:\n\n";
    cout << displayTree(avl);
    
    avl->insert(12);
    cout <<"\nDisplaying AVL Tree After Inserting: 12:\n\n";
    cout << displayTree(avl);
    
    avl->insert(13);
    cout <<"\nDisplaying AVL Tree After Inserting: 13:\n\n";
    cout << displayTree(avl);
    
    avl->insert(14);
    cout <<"\nDisplaying AVL Tree After Inserting: 14:\n\n";
    cout << displayTree(avl);
    
    avl->insert(15);
    cout <<"\nDisplaying AVL Tree After Inserting: 15:\n\n";
    cout << displayTree(avl);
    
    avl->insert(16);
    cout <<"\nDisplaying AVL Tree After Inserting: 16:\n\n";
    cout << displayTree(avl);
    
    avl->insert(17);
    cout <<"\nDisplaying AVL Tree After Inserting: 17:\n\n";
    cout << displayTree(avl);
    
    avl->insert(18);
    cout <<"\nDisplaying AVL Tree After Inserting: 18:\n\n";
    cout << displayTree(avl);
    
    avl->insert(6);
    cout <<"\nDisplaying AVL Tree After Inserting: 6 again:\n\n";
    cout << displayTree(avl);
 
    

    cout << "\n\nInorder:\t";
    cout << avl->inOrder();
    cout << "\nPreOrder:\t";
    cout << avl->preOrder();
    cout << "\nPostorder:\t";
    cout << avl->postOrder();
    cout << "\n";

    avl->remove(13);
    cout <<"\n\n\nDisplaying AVL Tree After Deleting: 13:\n\n";
    cout << displayTree(avl);
    

    avl->remove(8);
    cout <<"\n\n\nDisplaying AVL Tree After Deleting: 8:\n\n";
    cout << displayTree(avl);

    cout << "\n\n";

	return 0;
}
