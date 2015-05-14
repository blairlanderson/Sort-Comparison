#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

class Sorts
{
private:
	static const int ARRAY_SIZE = 20000;
	//static int temp[ARRAY_SIZE];

public:
	static void bubbleSort(int a[], int size);
	static void selectionSort(int a[], int size);
	static void insertionSort(int a[], int size);
	static void shellSort(int a[], int size);

	static void mergeSort(int a[], int left, int right);
	static void merge(int a[], int left, int middle, int right);
	static void quickSort(int a[], int left, int right);
	static int partition(int a[], int left, int right);
};
