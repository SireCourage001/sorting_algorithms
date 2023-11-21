#include "sort.h"
#include <stdio.h>

/**
 * swap - Change two values in ascending or descending order
 * @arr: Array
 * @item1: Item one
 * @item2: Item two
 * @order: 1: ascending order, 0 descending order
 */
void swap(int arr[], int item1, int item2, int order)
{
	int temp;

	if (order == (arr[item1] > arr[item2]))
	{
		temp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = temp;
	}
}


/**
 * merge - Sort bitonic sequences recursively in both orders
 * @arr: Array
 * @low: First element
 * @nele: Elements num.
 * @order: 1: ascending order, 0 descending order
 */
void merge(int arr[], int low, int nele, int order)
{
	int mid, i;

	if (nele > 1)
	{
		mid = nele / 2;

		for (i = low; i < low + mid; i++)
			swap(arr, i, i + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}

/**
 * bitonicsort - bitonic sort algorithm implementation
 * @arr: Array
 * @low: First element
 * @nele: Num of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array lenght
 */
void bitonicsort(int arr[], int low, int nele, int order, int size)
{
	int mid;

	if (nele > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nele, size);
			print_array(&arr[low], nele);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nele, size);
			print_array(&arr[low], nele);
		}
		mid = nele / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		merge(arr, low, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nele, size);
			print_array(&arr[low], nele);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nele, size);
			print_array(&arr[low], nele);
		}
	}
}

/**
 * bitonic_sort - Prepare terrain to bitonic sort algorithm
 * @array: Array
 * @size: Array lenght
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;

	bitonicsort(array, 0, size, order, size);
}



