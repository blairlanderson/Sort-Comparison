#include "Sorts.h"

//BUBBLE SORT
//compare each set of two elements in turn, move the smaller unit to the left
void Sorts::bubbleSort(int a[], int size)
{
	int outer, inner;
	for (outer = size; outer > 0; outer--)
	{
		// counting down
		for (inner = 0; inner < outer - 1; inner++)
		{
			// bubbling up
			if (a[inner] > a[inner + 1])
			{
				// if out of order swap
				int temp = a[inner];
				a[inner] = a[inner + 1];
				a[inner + 1] = temp;
			}//end if
		}//end inner loop
	}//end outer loop
}//end bubbleSort()

//SELECTION SORT
//search through array for smalles and move to index, index++
void Sorts::selectionSort(int a[], int size)
{
	int outer, inner, min;
	for (outer = 0; outer < size - 1; outer++)
	{
		// outer counts down
		min = outer;
		for (inner = outer + 1; inner < size; inner++)
		{
			if (a[inner] < a[min])
			{
				min = inner;
			}
		}//end inner for

		// a[min] is least among a[outer]..a[a.length - 1]
		int temp = a[outer];
		a[outer] = a[min];
		a[min] = temp;
	}//end outer for
}//end selectionSort

//INSERTION SORT
//check element with elements before it and insert into proper place
void Sorts::insertionSort(int a[], int size)
{
	int i, j, tmp;
	for (i = 1; i < size; i++)
	{
		j = i;

		//shift element to the left until it finds its spot
		while (j > 0 && a[j - 1] > a[j])
		{
			tmp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = tmp;
			j--;
		} //end of while loop
	} //end of for loop
}//end insertionSort

//SHELL SORT
//compare element  with element that is INCREMENT away, half the increment each major iteration
void Sorts::shellSort(int a[], int size)
{
	int i, j, increment, temp;
	for (increment = size / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i<size; i++)
		{
			temp = a[i];
			for (j = i; j >= increment; j -= increment)
			{
				if (temp < a[j - increment])
				{
					a[j] = a[j - increment];
				}
				else
				{
					break;
				}
			}//end inner loop

			a[j] = temp;
		}//end middle loop
	}//end outermost loop
}//end shellSort

//MERGE SORT
//recursively break list into half sized lists
void Sorts::mergeSort(int a[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}//end merge sort

//merge subarrays back into one large array, by comparing elements of two subarrays
void Sorts::merge(int a[], int left, int mid, int right)
{
	int leftIndex = left;
	int tempIndex = left;
	int i;
	int rightIndex = mid + 1;
	static int temp[ARRAY_SIZE];



	while ((leftIndex <= mid) && (rightIndex <= right))
	{
		if (a[leftIndex] < a[rightIndex])
		{
			temp[tempIndex] = a[leftIndex];
			leftIndex++;
		}
		else
		{
			temp[tempIndex] = a[rightIndex];
			rightIndex++;
		}
		tempIndex++;
	}

	if (leftIndex > mid)
	{
		for (i = rightIndex; i <= right; i++)
		{
			temp[tempIndex] = a[i];
			tempIndex++;
		}
	}
	else
	{
		for (i = leftIndex; i <= mid; i++)
		{
			temp[tempIndex] = a[i];
			tempIndex++;
		}
	}

	for (i = left; i <= right; i++)
	{
		a[i] = temp[i];
	}

}

//quick sort
//divide array into high and low based on a pivot point, then recursively call
void Sorts::quickSort(int a[], int left, int right)
{
	if (left < right)
	{
		int pivotIndex = partition(a, left, right);   //Calling Procedure to Find Pivot

		quickSort(a, left, pivotIndex - 1);         // Subsort left (Recursion)
		quickSort(a, pivotIndex + 1, right);	      // Subsort right (Recursion)
	}
}
//find partition point in array 
int Sorts::partition(int a[], int left, int right)
{
	int p = left, pivot = a[left], location;

	for (location = left + 1; location <= right; location++)
	{
		//compare remaining elements to pivot
		if (pivot > a[location])
		{
			//move pivot to final place
			a[p] = a[location];
			a[location] = a[p + 1];
			a[p + 1] = pivot;

			p++;
		}
	}
	return p;
}