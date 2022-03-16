//
//  SplayTree.cpp
//  Splay
//
//  Created by Dr. John Charlery on 11/2/2021.
//  Copyright (c) 2021 University of the West Indies. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "SplayTree.h"
#include "VisualizeAllTrees.h"



int main()
    {
        SplayTree* splay = new SplayTree();
        
/*

    cout <<"\n\t Inserting: 5,12,8,4,2,9,18,7,6,14,8\n\n";
    splay->Insert(5);
    cout <<"\nDisplaying splay Tree After Inserting: 5:\n\n";
    cout << displayTree(splay);
    
    splay->Insert(2);
    cout <<"\nDisplaying splay Tree After Inserting: 2:\n\n";
    cout << displayTree(splay);

    splay->Insert(3);
    cout <<"\nDisplaying splay Tree After Inserting: 3:\n\n";
    cout << displayTree(splay);

    splay->Insert(4);
    cout <<"\nDisplaying splay Tree After Inserting: 4:\n\n";
    cout << displayTree(splay);
    
    splay->Insert(1);
    cout <<"\nDisplaying splay Tree After Inserting: 1:\n\n";
    cout << displayTree(splay);
    
    splay->Insert(6);
    cout <<"\nDisplaying splay Tree After Inserting: 6:\n\n";
    cout << displayTree(splay);
    
    splay->Insert(7);
    cout <<"\nDisplaying splay Tree After Inserting: 7:\n\n";
    cout << displayTree(splay);
    
    splay->Insert(8);
    cout <<"\nDisplaying splay Tree After Inserting: 8:\n\n";
    cout << displayTree(splay);
    
    splay->Insert(13);
    cout <<"\nDisplaying splay Tree After Inserting: 13:\n\n";
    cout << displayTree(splay);
    
    splay->Insert(11);
    cout <<"\nDisplaying splay Tree After Inserting: 11:\n\n";
    cout << displayTree(splay);
    
    splay->Insert(12);
    cout <<"\nDisplaying splay Tree After Inserting: 12:\n\n";
    cout << displayTree(splay);
    
    splay->Insert(18);
    cout <<"\nDisplaying splay Tree After Inserting: 18:\n\n";
    cout << displayTree(splay);
    
    
    splay->Insert(9);
    cout <<"\nDisplaying splay Tree After Inserting: 9:\n\n";
    cout << displayTree(splay);
    
    splay->Insert(14);
    cout <<"\nDisplaying splay Tree After Inserting: 14:\n\n";
    cout << displayTree(splay);
    
    splay->Insert(17);
    cout <<"\nDisplaying splay Tree After Inserting: 17:\n\n";
    cout << displayTree(splay);
    
     


    splay->remove(3);
    cout <<"\n\n\nDisplaying splay Tree After Deleting: 3:\n\n";
    cout << displayTree(splay);
*/
    
    splay->Insert(5);
    cout <<"\nDisplaying splay Tree After Inserting: 5:\n\n";
    cout << displayTree(splay);

    splay->Insert(12);
    cout <<"\nDisplaying splay Tree After Inserting: 12:\n\n";
    cout << displayTree(splay);

    splay->Insert(8);
    cout <<"\nDisplaying splay Tree After Inserting: 8:\n\n";
    cout << displayTree(splay);

    splay->Insert(4);
    cout <<"\nDisplaying splay Tree After Inserting: 4:\n\n";
    cout << displayTree(splay);

    splay->Insert(2);
    cout <<"\nDisplaying splay Tree After Inserting: 2:\n\n";
    cout << displayTree(splay);

    splay->Insert(9);
    cout <<"\nDisplaying splay Tree After Inserting: 9:\n\n";
    cout << displayTree(splay);

    splay->Insert(18);
    cout <<"\nDisplaying splay Tree After Inserting: 18:\n\n";
    cout << displayTree(splay);
    
    splay->Insert(7);
    cout <<"\nDisplaying splay Tree After Inserting: 7:\n\n";
    cout << displayTree(splay);

    splay->Insert(6);
    cout <<"\nDisplaying splay Tree After Inserting: 6:\n\n";
    cout << displayTree(splay);

    splay->Insert(14);
    cout <<"\nDisplaying splay Tree After Inserting: 14:\n\n";
    cout << displayTree(splay);

            return 0;
    }
