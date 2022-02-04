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
	int max = 12;
	int table[] = {300,272,0,4333,14, 1020,3,5,7,2,2,1};
	
	cout << "Before: ";
	print(table, max);
	// Selection, Merge, Quick, Bucket, Insertion
	QuickSort(table, max);
	cout << "After: ";
	print(table, max);
}
