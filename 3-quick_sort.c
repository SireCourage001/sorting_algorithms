#include "sort.h"

/**
*swap - Positions two elements into an array
*@array: Array
*@item1: Array element
*@item2: Array element
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int temp;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}

/**
 *lomuto_partition - lomuto partition sorting scheme implementation
 *@array: Array
 *@first: First array element
 *@last: Last array element
 *@size: Size array
 *Return: Return position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);

}

/**
 *qs - quicksort algorithm implementation
 *@array: Array
 *@first: First array element
 *@last: Last array element
 *@size: Array size
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}

/**
 *quick_sort - prepare the terrain to quicksort algorithm
 *@array: Array
 *@size: Array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
