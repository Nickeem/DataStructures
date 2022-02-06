#include <iostream>
#include "Assign01.h"

void print(int arr[], int max) {
	for (int i = 0; i < max; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	int max = 7;
	int table[max];

	for (int i = 0; i < max; i++)
	{
		table[i] = rand()%1000;
	}
	
	cout << "Before: ";
	print(table, max);
	// Selection, Merge, Quick, Bucket, Insertion
	BucketSort(table, max);
	cout << "Bucket After: ";
	print(table, max);
	cout << endl;	
	
	//next
	for (int i = 0; i < max; i++)
	{
		table[i] = rand()%1000;
	}
	
	cout << "Before: ";
	print(table, max);
	// Selection, Merge, Quick, Bucket, Insertion
	QuickSort(table, max);
	cout << "Quick After: ";	
	print(table, max);
	cout << endl;	

	// next
	for (int i = 0; i < max; i++)
	{
		table[i] = rand()%1000;
	}
	
	cout << "Before: ";
	print(table, max);
	SelectionSort(table, max);
	cout << "Selection After: ";
	print(table, max);
	cout << endl;

	// next
	for (int i = 0; i < max; i++)
	{
		table[i] = rand()%1000;
	}
	
	cout << "Before: ";
	print(table, max);
	MergeSort(table, max);
	cout << "Merge After: ";
	print(table, max);
	cout << endl;	
	
	// next
	for (int i = 0; i < max; i++)
	{
		table[i] = rand()%1000;
	}
	
	cout << "Before: ";
	print(table, max);
	InsertionSort(table, max);
	cout << "Insertion After: ";
	print(table, max);
	
}
