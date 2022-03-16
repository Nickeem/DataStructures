//
//  Heap.cpp
//  Heap
//
//  Created by Dr. John Charlery on 11/10/2021.
//  Copyright (c) 2021 University of the West Indies. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "BinHeap.h"

int main()
    {
        BinHeap* maxHeapTree = new BinHeap();
        BinHeap* minHeapTree = new BinHeap();

        //5, 12, 8, 4, 2, 9, 18, 7, 6, 14

        // ==== Test a MaxHeap =====
        maxHeapTree->addMaxHeap(5);
        maxHeapTree->addMaxHeap(12);
        maxHeapTree->addMaxHeap(8);
        maxHeapTree->addMaxHeap(4);
        maxHeapTree->addMaxHeap(2);
        maxHeapTree->addMaxHeap(9);
        maxHeapTree->addMaxHeap(18);
        maxHeapTree->addMaxHeap(7);
        maxHeapTree->addMaxHeap(6);
        maxHeapTree->addMaxHeap(14);

        // Display the vector for the MaxHeap
        cout << "Display MaxHeap : ";
        cout << maxHeapTree->displayHeap();
    
    
        //Display the sorted contents of the MaxHeap
        cout << "Sorted MaxHeap  : ";
        cout << maxHeapTree->sortMaxHeap();
        cout << "\n";
    
//5, 12, 8, 4, 2, 9, 18, 7, 6, 14
    
        // ==== Test a MinHeap =====
        minHeapTree->addMinHeap(5);
        minHeapTree->addMinHeap(12);
        minHeapTree->addMinHeap(8);
        minHeapTree->addMinHeap(4);
        minHeapTree->addMinHeap(2);
        minHeapTree->addMinHeap(9);
        minHeapTree->addMinHeap(18);
        minHeapTree->addMinHeap(7);
        minHeapTree->addMinHeap(6);
        minHeapTree->addMinHeap(14);

        // Display the vector for the MinHeap
        cout << "Display MinHeap : ";
        cout << minHeapTree->displayHeap();
        
        
        //Display the sorted contents of the MinHeap
        cout << "Sorted MinHeap  : ";
        cout << minHeapTree->sortMinHeap();
        cout << "\n";

        
        
        
        return 0;
    }



