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

void SelectioSort ( int table[], int max)
{
	int i, j, temp;
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
	int prv;
	for(int i = 1; i < max; i++)
	{
		current = table[i];
		prv = i - 1;
		while (prv >= 0 && table[prv] > current )
		{
			table[prv + 1] = table[prv];
			prv--;
		}
		// prv is decrement 1 last time befor exiting
		table[prv+1] = current;
	}
} // Insertion Sort
void swap(int*, int*);
int partition (int[], int, int);

void QuickSort ( int table[], int max, int min)
{
	if (min < max)
    {
		int p = partition(table, min, max);
		quickSort(table, min, p - 1);
        quickSort(table, p + 1, max);
	}
} // QuickSort
void swap(int* element1, int* element2)
{
    int temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}

int partition (int table[], int min, int max)
{
    int pivot = table[max];
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

	while (i < leftLength) {
		table[k] = left_half[i];
		i++; k++;
	}
	while (j < rightLength) {
		table[k] = right_half[j];
		j++; k++;
	}


} // merge
