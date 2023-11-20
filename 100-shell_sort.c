#include "sort.h"

/**
*swap - Positions of two elements into an array
*@array: Array
*@item1: Array element
*@item2: Array element
*/
void swap(int *array, int item1, int item2)
{
	int temp;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}

/**
 * shell_sort - Function that sorts an array of int in ascending
 * order, using Shell sort algorithm & the Knuth sequence
 * @size: Size of the array
 * @array: List with numbers
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, index = 0;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (index = i; index >= gap &&
			 (array[index] < array[index - gap]); index -= gap)
				swap(array, index, index - gap);
		print_array(array, size);
		gap /= 3;
	}
}
