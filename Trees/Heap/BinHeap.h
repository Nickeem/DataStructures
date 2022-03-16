//
//  BinHeap.h
//  BinHeap
//
//  Created by Dr. John Charlery on 11/10/2021.
//  Copyright (c) 2021 University of the West Indies. All rights reserved.
//

#ifndef BINHEAP_H
#define BINHEAP_H

class BinHeap
    {
        private:
                vector <int> elements;
        
        public:
                BinHeap(){elements.resize(1);}
    
                void addMaxHeap(int);               // Add to MaxHeap
                void addMinHeap(int);               // Add to MinHeap
                void maxHeapify(unsigned int);      // Heapify MaxHeap
                void minHeapify(unsigned int);      // Heapify MinHeap
                void deleteMaxHeapVal(int);         // Delete element from MaxHeap
                void deleteMinHeapVal(int);         // Delete element from MinHeap
                void removeMaxRoot();
                void removeMinRoot();
                string displayHeap();
                string sortMaxHeap();
                string sortMinHeap();
    };


//===================================================================================
// Add new element to MaxHeap
//===================================================================================
void BinHeap::addMaxHeap(int val)
    {
        elements.push_back(val);
        maxHeapify(elements.size() - 1);
    }


//===================================================================================
// Add new element to MinHeap
//===================================================================================
void BinHeap::addMinHeap(int val)
    {
        elements.push_back(val);
        minHeapify(elements.size() - 1);
    }



//===================================================================================
// Recursive heapify function for a MaxHeap
//===================================================================================
void BinHeap::maxHeapify(unsigned int index)
    {
        unsigned int left, right, maxx;
        left = 2*index;
        right = 2*index + 1;
    
        // Base case
        if (index == 0)
            return;
    
        // Check the children, if they exist and pick the larger for swapping
        if (left < elements.size() && elements[left] > elements[index])
            maxx = left;
        else
            maxx = index;
    
        if (right < elements.size() && elements[right] > elements[maxx])
            maxx = right;
    
        if (maxx != index)
            {
                int temp = elements[maxx];
                elements[maxx] = elements[index];
                elements[index] = temp;
                maxHeapify(maxx);
            }
    
        // Now check the parent, if it exists
        maxHeapify(index/2);
    }






//===================================================================================
// Recursive heapify function for a MinHeap
//===================================================================================
void BinHeap::minHeapify(unsigned int index)
    {
        unsigned int left, right, minn;
        left = 2*index;
        right = 2*index + 1;
    
        // Base case
        if (index == 0)
            return;
    
        // Check the children, if they exist and pick the larger for swapping
        if (left < elements.size() && elements[left] < elements[index])
            minn = left;
        else
            minn = index;
    
        if (right < elements.size() && elements[right] < elements[minn])
            minn = right;
    
        if (minn != index)
            {
                int temp = elements[minn];
                elements[minn] = elements[index];
                elements[index] = temp;
                minHeapify(minn);
            }
    
        // Now check the parent, if it exists
        minHeapify(index/2);
    }









void BinHeap::deleteMinHeapVal(int value)
    {
        
        int x = 0;
        
        while ( x <= elements.size() )
            {
                if ( value == elements[x] )
                    {
                        elements[x] = elements[ (elements.size() - 1) ];
                        
                        elements.pop_back();
                        
                        minHeapify(x);              // parent
                        minHeapify((2 * x) +1);     // left child
                        minHeapify((2 * x) +2 );    // right child
                        break;      //No need to search further
                    }
                x++;
            }
    }





void BinHeap::deleteMaxHeapVal(int value)
    {
        
        int x = 0;
        
        while ( x <= elements.size() )
            {
                if ( value == elements[x] )
                    {
                        elements[x] = elements[ (elements.size() - 1) ];
                        
                        elements.pop_back();
                        
                        maxHeapify(x);              // parent
                        maxHeapify((2 * x) +1);     // left child
                        maxHeapify((2 * x) +2 );    // right child
                        break;      //No need to search further
                    }
                x++;
            }
    }
    
    
void BinHeap::removeMaxRoot()
    {
        if (elements.size() < 2)
            return;
        else
            {
                elements[1] = elements[elements.size() - 1];
                elements.resize(elements.size() - 1);
                maxHeapify(1);
            }
    }

    
void BinHeap::removeMinRoot()
    {
    if (elements.size() < 2)
        return;
    else
        {
            elements[1] = elements[elements.size() - 1];
            elements.resize(elements.size() - 1);
            minHeapify(1);
        }
    
    }

    
string BinHeap::sortMaxHeap()
    {
        string str ="";
        
        while (elements.size() > 1)
            {
                str.append(to_string(elements[1]));
                str.append("\t");
                removeMaxRoot();
            }
        str.append("\n");
        return str;
    }

    
string BinHeap::sortMinHeap()
    {
        string str ="";
        
        while (elements.size() > 1)
        {
            str.append(to_string(elements[1]));
            str.append("\t");
            removeMinRoot();
        }
        str.append("\n");
        return str;
    }


string BinHeap::displayHeap()
{
    string str = "";
    for (int x = 1; x < elements.size(); x++)
        {
            str.append(to_string(elements[x]));
            str.append("\t");
        }
    str.append("\n");
    return str;
}


#endif
