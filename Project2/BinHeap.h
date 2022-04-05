//
//  BinHeap.h
//  BinHeap
//
//  Created by Dr. John Charlery on 11/10/2021.
//  Copyright (c) 2021 University of the West Indies. All rights reserved.
//

#ifndef BINHEAP_H
#define BINHEAP_H

#include <vector>
#include <algorithm>

class HeapNode
    {
        private:
            
            char FirstName[10];
            char Surname[10];
            char Destination[15];
            char Membership[10];
            char Booking[10];

        public:
            int ClientID;
            // Constructor functions
            HeapNode(){ ClientID = -99;}
            
            HeapNode(Record rec) {
                ClientID = rec.id; 
                strcpy(FirstName , rec.firstname);
                strcpy(Surname, rec.surname);
                strcpy(Destination, rec.destination);
                strcpy(Membership, rec.membership);
                strcpy(Booking, rec.booking);
            }
    
            // Accessor functions
            int getID()       {return ClientID;}
            char* getFirstName() {return FirstName;}
            char* getSurname() { return Surname;}
            char* getDestination() {return Destination; }
            char* getMembership() {return Membership;}
            char* getBooking() {return Booking;}
            //string getData();

            // Mutator functions
            void setID(int id)       {ClientID = id;}
            void setFirstName(char* fname)  {strcpy(FirstName , fname);}
            void setSurname(char* sname)  {strcpy(Surname , sname);}
            void setDestination(char* dest)  {strcpy(Destination , dest);}
            void setMembership (char* membership)  {strcpy(Membership , membership);}
            void setBooking(char* booking)  {strcpy(Booking , booking);}
     };



class BinHeap
    {
        private:
                vector <HeapNode> elements;
        
        public:
                BinHeap(){elements.resize(1);}
    
                void addMaxHeap(int);               // Add to MaxHeap
                void addMinHeap(Record);               // Add to MinHeap
                void maxHeapify(unsigned int);      // Heapify MaxHeap
                void minHeapify(unsigned int);      // Heapify MinHeap
                void deleteMaxHeapVal(int);         // Delete element from MaxHeap
                void deleteMinHeapVal(int);         // Delete element from MinHeap
                void removeMaxRoot();
                void removeMinRoot();
                string displayHeap();
                string sortMaxHeap();
                string sortMinHeap();
                string nodeChildren(int);
    };


//===================================================================================
// Add new element to MaxHeap
//===================================================================================

string BinHeap::nodeChildren (int index) {
    string children = "["; // hold child data in format [left, right]
    unsigned int left, right, minn;
    left = 2*index;
    right = 2*index + 1;
    if (left < elements.size())
        children += to_string(elements[left].ClientID);
    else
        children += "NULL";
    children += ", ";
    if (right < elements.size()) 
        children += to_string(elements[right].ClientID);
    return children;
}
/* void BinHeap::addMaxHeap(int val)
    {
        elements.push_back(val);
        maxHeapify(elements.size() - 1);
    } */


//===================================================================================
// Add new element to MinHeap
//===================================================================================
void BinHeap::addMinHeap(Record rec)
    {
        elements.push_back(HeapNode(rec));
        minHeapify(elements.size() - 1);
    }



//===================================================================================
// Recursive heapify function for a MaxHeap
//===================================================================================
/*
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

*/




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
        if (left < elements.size() && elements[left].ClientID < elements[index].ClientID)
            minn = left;
        else
            minn = index;
    
        if (right < elements.size() && elements[right].ClientID < elements[minn].ClientID)
            minn = right;
    
        if (minn != index)
            {
                HeapNode temp = elements[minn];
                elements[minn] = elements[index];
                elements[index] = temp;
                minHeapify(minn);
            }
    
        // Now check the parent, if it exists
        minHeapify(index/2);
    }









void BinHeap::deleteMinHeapVal(int id)
    {
        
        int x = 0;
        
        while ( x <= elements.size() )
            {
                if ( id == elements[x].ClientID )
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




/*
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
    } */
    
  /*  
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
    } */

    
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

/*
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
    } */

    
string BinHeap::sortMinHeap()
    {
        string str ="";
        
        while (elements.size() > 1)
        {
            //str.append(elements[1].getData());
            removeMinRoot();
        }
        return str;
    }


string BinHeap::displayHeap()
{
    string data = "";
    stringstream data_stream;
    for (int x = 1; x < elements.size(); x++)
        {
            
            string idData = to_string(elements[x].ClientID) + nodeChildren(x);
            data_stream << std::left << setw(25) << idData 
                        << std::left << setw(15) << elements[x].getID()
                        << std::left << setw(15) << elements[x].getSurname()
                        << std::left << setw(15) << elements[x].getDestination()
                        << std::left << setw(15) << elements[x].getMembership()
                        << std::left << setw(15) << elements[x].getBooking()
                        << endl; 
            
            data += data_stream.str();
            data_stream.str("");
        }
    return data;
}


#endif
