/*
Nickeem Payne-Deacon
ID - 400008889
*/

//  Bucket Sort
void BucketSort ( int table[], int max)
{

}

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

}

void QuickSort ( int table[], int max)
{

}

void MergeSort ( int table[], int max)
{

}
