#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

class Sorts
{
public:
	const int ARRAY_SIZE = 20000;
	int temp[ARRAY_SIZE];

	void bubbleSort(int a[], int size);
	void selectionSort(int a[], int size);
	void insertionSort(int a[], int size);
	void shellSort(int a[], int size);
	void mergeSort(int a[], int left, int right);
	void mergeSort(string a[], int left, int right);
	void merge(int a[], int left, int middle, int right);
	void merge(string a[], int left, int middle, int right);
	void quickSort(int a[], int left, int right);
	int partition(int a[], int left, int right);



};