//
//  RBTree.cpp
//  RBT
//
//  Created by Dr. John Charlery on 10/25/2021.
//  Copyright (c) 2021 University of the West Indies. All rights reserved.
//


#include <iostream>

#include<iostream>
#include<string>
#include <vector>

using namespace std;

#include "RBTree.h"
#include "VisualizeTree.h"



int main()
{
	
	RBT* rbt = new RBT();
 
    cout <<"\n\t Inserting: 5, 8 ,4, 2, 9, 18, 7, 6, 14\n\n";

    rbt->insert(5);
    cout <<"\nDisplaying Red-Black Tree After Inserting: 5:\n\n";
    cout << displayTree(rbt);
    
    rbt->insert(8);
    cout <<"\nDisplaying Red-Black Tree After Inserting: 8:\n\n";
    cout << displayTree(rbt);

    rbt->insert(4);
    cout <<"\nDisplaying Red-Black Tree After Inserting: 4:\n\n";
    cout << displayTree(rbt);
    
    rbt->insert(2);
    cout <<"\nDisplaying Red-Black Tree After Inserting: 2:\n\n";
    cout << displayTree(rbt);
    
    rbt->insert(9);
    cout <<"\nDisplaying Red-Black Tree After Inserting: 9:\n\n";
    cout << displayTree(rbt);
    
    rbt->insert(18);
    cout <<"\nDisplaying Red-Black Tree After Inserting: 18:\n\n";
    cout << displayTree(rbt);
    
    rbt->insert(7);
    cout <<"\nDisplaying Red-Black Tree After Inserting: 7:\n\n";
    cout << displayTree(rbt);
    
    rbt->insert(6);
    cout <<"\nDisplaying Red-Black Tree After Inserting: 6:\n\n";
    cout << displayTree(rbt);
    
    rbt->insert(14);
    cout <<"\nDisplaying Red-Black Tree After Inserting: 14:\n\n";
    cout << displayTree(rbt);
    
    cout << "\n\n=================DELETING========================\n";
    
    rbt->remove(2);
    cout <<"\n\n\nDisplaying Red-Black Tree After Deleting: 2:\n\n";
    cout << displayTree(rbt);
    

    rbt->remove(8);
    cout <<"\n\n\nDisplaying Red-Black Tree After Deleting: 8:\n\n";
    cout << displayTree(rbt);

    rbt->remove(7);
    cout <<"\n\n\nDisplaying Red-Black Tree After Deleting: 7:\n\n";
    cout << displayTree(rbt);

	return 0;
}
