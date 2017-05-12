// SortingFramework.cpp
// Program to generate an array of random integers and print it on the output screen.
// sort it using different types of sorting algorithms.

#include <iostream>
#include <stdlib.h>

static int *makeRandomArray(const int size, const int max, const int seed);
static void printArrayContents(const int * const array, const int size);

static void bubbleSort(int *array, const int size);
static void shuttleSort(int *array, const int size);
static void selectionSort(int *array, const int size);
static void insertionSort(int *array, const int size);

int main (int argc, char * const argv[])
{
	// to be altered according to needs
	const int arraySize = 23;
	const int maxArrayVal = 23;
	const int seed = 23;

	int *array = makeRandomArray(arraySize, maxArrayVal, seed);

	printArrayContents(array, arraySize);

	//bubbleSort(array, arraySize);

	shuttleSort(array, arraySize);
	//selectionSort(array, arraySize);
	//insertionSort(array, arraySize);

  printArrayContents(array, arraySize);

	delete[] array;

	return 0;
}
static void Swap(int* a, int* b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}


static int *makeRandomArray(const int size, const int max, const int seed)
{
	srand(seed);
	int *array = new int[size];
	for (int i = 0; i < size; i++)
	   array[i] = rand() % max;

	return array;
}

static void printArrayContents(const int * const array, const int size)
{
	std::cout << "Array contents : { ";
	for (int i = 0; i < size; i++)
	   std::cout << array[i] << " ";
	std::cout << "}" << std::endl;
}

static void bubbleSort(int *array, const int size)
{
	// TODO : implement the bubble sort algorithm
	int count{0};
	while(count != size)
	{
	int temp;
	for(int i{0}; i<size; i++)
	{
        if(array[i]>array[i+1])
        {
            temp = array[i+1];
            array[i+1] = array[i];
            array[i] = temp;

        }
	}
	count++;
	}
}

static void shuttleSort(int *array, const int size)
{
	// TODO : implement the shuttle sort algorithm
	while (1)
	{
		char flag;
		int start[2] = { 1, size - 1 };
		int end[2] = { size, 0 };
		int inc[2] = { 1, -1 };

		for (int i{0}; i < 2; i++)
		{
			flag = 1;

			for (int i = start[i]; i != end[i]; i += inc[i])
			{
				if (array[i - 1] > array[i])
				{
					Swap(array + i - 1, array + i);
					flag = 0;
				}
			}

			if (flag)
                return;
		}
	}

}

static void selectionSort(int *array, const int size)
{
  // TODO : implement the selection sort algorithm
}

static void insertionSort(int *array, const int size)
{
	// TODO : implement the insertion sort algorithm
}



