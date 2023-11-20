#include "sort.h"
#include <stdio.h>

/**
 *_calloc - A calloc function
 *@nmemb: Num of elements
 *@size: Bit size of each element
 *Return: Pointer to memory assignment
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i =0;
	char *p;

	if (nmemb == 0 || size == 0)
		return ('\0');
	p = malloc(nmemb * size);
	if (p == NULL)
		return ('\0');
	for (i = 0; i < (nmemb * size); i++)
		p[i] = '\0';
	return (p);
}

/**
 *merge - Make a merge
 *@arr: One from start to mid
 *@tmp: Temp array used in merge, was created outside to
 *optimize reducing the system calls
 *@start: First element position
 *@mid: Array middle
 *@end: Last element position
 **/
void merge(int *arr, int *temp, int start, int mid, int end)
{
	/*  sizes and temp arrays */
	int size_left = mid - start + 1, size_right = end - mid;
	int *array_left, *array_right;
	/* counters */
	int left, right, i = 0;

	array_left = &temp[0];
	array_right = &temp[size_right];
	for (left = 0; left < size_left; left++)
		array_left[left] = arr[start + left];
	for (right = 0; right < size_right; right++)
		array_right[right] = arr[mid + 1 + right];
	left = 0, right = 0, i = start;
	/* merging temp arrays into main array*/
	while (left < size_left && right < size_right)
	{
		if (array_left[left] <= array_right[right])
			arr[i] = array_left[left], left++;
		else
			arr[i] = array_right[right], right++;
		i++;
	}

	/* merging remaining left array into main array*/
	while (left < size_left)
		arr[i] = array_left[left], left++, i++;
	/* merging remaining right array into main array*/
	while (right < size_right)
		arr[i] = array_right[right], right++, i++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_left, left);
	printf("[right]: ");
	print_array(array_right, right);
	printf("[Done]: ");
	print_array(&arr[start], left + right);
}

/**
 *mergesort - Function that sorts an array of int
 *in ascending order using Merge sort algorithm
 *@array: Array of integers
 *@tmp: Temp array used in merge, was created outside to
 *optimize reducing the system calls
 *@start: Fisrt element position
 *@end: Last element position
 *Return: Void
 */
void mergesort(int *array, int *temp, int start, int end)
{
	int mid;

	mid = (start + end) / 2;
	if ((start + end) % 2 == 0)
		mid--;
	if (mid >= start)
	{
		mergesort(array, temp, start, mid);
		mergesort(array, temp, mid + 1, end);
		mergesort(array, temp, mid, end);
	}
}

/**
 *merge_sort - Function that sorts an array of int
 *in ascending order using the Merge sort algorithm
 *@size: Size of list
 *@array: Array of int
 *Return: Void
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;
	temp = _calloc(size, sizeof(int));
	mergesort(array, temp, 0, size - 1);
	free(temp);
}
