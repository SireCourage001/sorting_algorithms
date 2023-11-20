#include "sort.h"

/**
 * selection_sort - Function that sorts an array of int in ascending
 * order using the Selection sort algorithm
 * @size: Size of array
 * @array: List with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t i, index;
	int temp, swap, flag = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		temp = i;
		flag = 0;
		for (index = i + 1; index < size; index++)
		{
			if (array[temp] > array[index])
			{
				temp = index;
				flag += 1;
			}
		}
		swap = array[i];
		array[i] = array[temp];
		array[temp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
