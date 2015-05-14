#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <fstream>

#include "Sorts.h"

using namespace std;

void printArray(int a[], int size);
void printArray(string a[], int size);
void fillArray();

//properties

const int ARRAY_SIZE = 50000;
int theArray[ARRAY_SIZE];
int temp[ARRAY_SIZE];


int main()
{
	int testArray[] = { 4, 21, 9, 2, 6, 4, 10, 8, 1, 18};
	
	//int size = sizeof(testArray) / sizeof(testArray[0]);
	int size = sizeof(theArray) / sizeof(theArray[0]);
	
	//fire up the randomizer
	time_t seconds;
	time(&seconds);
	srand((unsigned int)seconds);

	//clocks for time tracking
	clock_t timeStart;
	clock_t timeStop;
	int difference;

	////fill array with randm numbers
	fillArray();
	
	//test the sort
	//cout << "Unsorted list: " << endl;
	//printArray(extArray, size);
	//printArray(theArray, size);
	//printArray(theArray, size);

	//BUBBLE SORT
	cout << "***** Bubble Sort *****" << endl;
	timeStart = clock();
	Sorts::bubbleSort(theArray, size);
	//stop the timer ad calc the difference
	timeStop = clock();
	difference = timeStop - timeStart;

	//display results
	cout << endl << "Sorted list: " << endl;
	cout << "It took " << (timeStop - timeStart) << " ticks to complete the sort." << endl << endl;
	fillArray();


	//SELECTION SORT
	cout << "***** Selection Sort *****" << endl;
	timeStart = clock();
	Sorts::selectionSort(theArray, size);
	//stop the timer ad calc the difference
	timeStop = clock();
	difference = timeStop - timeStart;

	//display results
	cout << "Sorted list: " << endl;
	cout << "It took " << (timeStop - timeStart) << " ticks to complete the sort." << endl << endl;
	fillArray();


	//INSERTION SORT
	cout << "***** Insertion Sort *****" << endl;
	timeStart = clock();
	Sorts::insertionSort(theArray, size);
	//stop the timer ad calc the difference
	timeStop = clock();
	difference = timeStop - timeStart;

	//display results
	cout << "Sorted list: " << endl;
	cout << "It took " << (timeStop - timeStart) << " ticks to complete the sort." << endl << endl;
	fillArray();


	//SHELL SORT
	cout << "***** Shell Sort *****" << endl;
	timeStart = clock();
	Sorts::shellSort(theArray, size);
	//stop the timer ad calc the difference
	timeStop = clock();
	difference = timeStop - timeStart;

	//display results
	cout << "Sorted list: " << endl;
	cout << "It took " << (timeStop - timeStart) << " ticks to complete the sort." << endl << endl;
	fillArray();


	//MERGE SORT
	cout << "***** Merge Sort *****" << endl;
	timeStart = clock();
	Sorts::mergeSort(theArray, 0, size - 1);
	//stop the timer ad calc the difference
	timeStop = clock();
	difference = timeStop - timeStart;

	//display results
	cout << "Sorted list: " << endl;
	cout << "It took " << (timeStop - timeStart) << " ticks to complete the sort." << endl << endl;
	fillArray();


	//QUICK SORT
	cout << "***** Quick Sort *****" << endl;
	timeStart = clock();
	Sorts::quickSort(theArray, 0, size - 1);
	//stop the timer ad calc the difference
	timeStop = clock();
	difference = timeStop - timeStart;

	//display results
	cout << "Sorted list: " << endl;
	cout << "It took " << (timeStop - timeStart) << " ticks to complete the sort." << endl << endl;
	
	
	//print sorted array to file
	//printArray(extArray, size);
	//printArray(testArray, size);
	printArray(theArray, size);

	_getch();
	return 0;
}

//PRINT ARRAY - print entire array, one element per line
void printArray(int a[], int size)
{
	fstream outFile;
	outFile.open("output.txt");

	for (int i = 0; i < size; i++)
	{
		//cout << i+1 << ":    " << a[i] << endl;
		outFile << i+1 << ":   " << a[i] << endl;
	}
}
void printArray(string a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ":    " << a[i] << endl;
	}
}

void fillArray()
{
	//fill array with randm numbers
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		temp[i] = rand();
		//cout << theArray[i] << endl;

	}

	std::copy(&temp[0], &temp[ARRAY_SIZE - 1], theArray);
}


	



////quick sort
////divide array into high and low based on a pivot point, then recursively call
//void quickSort(int a[], int left, int right)
//{
//	if (left < right)
//	{
//		int pivotIndex = partition(a, left, right);   //Calling Procedure to Find Pivot
//
//		quickSort(a, left, pivotIndex - 1);         // Subsort left (Recursion)
//		quickSort(a, pivotIndex + 1, right);	      // Subsort right (Recursion)
//	}
//}
////find partition point in array 
//int partition(int a[], int left, int right)
//{
//	int p = left, pivot = a[left], location;
//
//	for (location = left + 1; location <= right; location++)
//	{
//		//compare remaining elements to pivot
//		if (pivot > a[location])
//		{
//			//move pivot to final place
//			a[p] = a[location];
//			a[location] = a[p + 1];
//			a[p + 1] = pivot;
//
//			p++;
//		}
//	}
//	return p;
//}

