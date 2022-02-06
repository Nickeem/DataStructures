#ifndef ASSIGN01_H
#define ASSIGN01_H
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
/*
Nickeem Payne-Deacon
ID - 400008889
*/

//  Bucket Sort
void BucketSort ( int table[], int max)
{
	map<int, vector<int>> buckets;
    for(int i =0; i < max; i++) 
    {
        buckets[table[i]/10].push_back(table[i]);  
    }
    int i = 0;
    for(auto bucket: buckets)
    {
        sort(bucket.second.begin(), bucket.second.end());
        for (auto element: bucket.second)
        {
            table[i] = element;
            i++;
        }
    } // for
} // Bucket Sort

void SelectionSort ( int table[], int max)
{
	int temp; // holds variable for swapping
	for(int i = 0; i < max; i++)
	{
		for(int j = i; j < max; j++)
		{
			if (table[j] < table[i])
			{
				temp = table[j];
				table[j] = table[i];
				table[i] = temp;
			}
		}
	}
} // Selection Sort

void InsertionSort ( int table[], int max)
{
	int current; // holds current iteration from table array
	int prv; // previous variable
	for(int i = 1; i < max; i++)
	{
		current = table[i];
		prv = i - 1;
		while (prv >= 0 && table[prv] > current )
		{
			table[prv + 1] = table[prv];
			prv--;
		}
		// prv is decremented 1 last time befor exiting
		table[prv+1] = current;
	}
} // Insertion Sort


void swap(int*, int*);
int partition (int[], int, int);

void QuickSort ( int table[], int max, int min=0, bool first_time=true)
{
	if (first_time) {
		max--; //max must be max - 1 (index of last element) when the function is first called
	}
	if (min < max)
    {
		int p = partition(table, min, max);
		QuickSort(table, p - 1, min, false);
        QuickSort(table, max, p + 1, false);
	}
} // QuickSort
void swap(int* element1, int* element2)
{
    int temp = *element1; // stores element1's value
    *element1 = *element2; // element1 value is set to element2's
    *element2 = temp; // element2's new value is element1 previous
}

int partition (int table[], int min, int max)
{
    int pivot = table[max]; // last element in array
    int i = min - 1;

    for (int j = min; j <= (max - 1); j++)
    {
        if (table[j] <= pivot)
        {
            i++;
            swap(&table[i], &table[j]);
        }
    }
    swap(&table[i + 1], &table[max]);
    return (i + 1); // new partition
}

void merge (int[],int[],int[],int,int);
void MergeSort ( int table[], int max)
{
	if (max < 2) {
		return;
	}
	int  half = max / 2;
	int o_half = max - half;

	int left_half[half];
	int right_half[o_half];

	for (int i = 0; i < o_half; i++)
	{
		if (i == o_half && (o_half%2) != (half%2) )
		{
			right_half[i] = table[i+half];
			continue;
		}
		left_half[i] = table[i];
		right_half[i] = table[i+half];
	}

	MergeSort(left_half, half );
	MergeSort(right_half, o_half);

	merge(table, left_half, right_half, half, o_half);
} // MergeSort

void merge(int table[],int left_half[], int right_half[], int leftLength, int rightLength)
{
	
	int i = 0; int j = 0; int k = 0;
	while (i < leftLength && j < rightLength)
	{
		if (left_half[i] <= right_half[j]) 
		{
			table[k] = left_half[i];
			i++;
		}
		else 
		{
			table[k] = right_half[j];
			j++;
		}
		k++;
	}
	
	// add elements not added after while loop exited
	while (i < leftLength) {
		table[k] = left_half[i];
		i++; k++;
	}
	while (j < rightLength) {
		table[k] = right_half[j];
		j++; k++;
	}


} // merge

#endif
