#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *da_buffa);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of int.
 * @array: An array of int.
 * @size: Size of the array.
 *
 * Return: Maximum int in the array.
 */
int get_max(int *array, int size)
{
	int max_val, idx;

	for (max_val = array[0], idx = 1; idx < size; idx++)
	{
		if (array[idx] > max_val)
			max_val = array[idx];
	}

	return (max_val);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of int in
 *                       ascending order using the counting sort algorithm.
 * @array: An array of int.
 * @size: The size of array.
 * @sig: The significant digit to sort on.
 * @da_buffa: A buffer to store sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *da_buffa)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t idx;

	for (idx = 0; idx < size; idx++)
		count[(array[idx] / sig) % 10] += 1;

	for (idx = 0; idx < 10; idx++)
		count[idx] += count[idx - 1];
	for (idx = size - 1; (int)idx > 0; idx--)
	{
		da_buffa[count[(array[idx] / sig) % 10] - 1] = array[idx];
		count[(array[idx] / sig) % 10] -= 1;
	}

	for (idx = 0; idx < size; idx++)
		array[idx] = da_buffa[idx];
}

/**
 * radix_sort - Sort an array of int in ascending
 *              order using radix sort algorithm.
 * @array: An array of int.
 * @size: The size of array.
 *
 * Description: Implements the LSD radix sort algorithm.
 * Prints array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max_val, sig, *da_buffa;

	if (array == NULL || size < 2)
		return;

	da_buffa = malloc(sizeof(int) * size);
	if (da_buffa == NULL)
		return;

	max_val = get_max(array, size);
	for (sig = 1; max_val / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, da_buffa);
		print_array(array, size);
	}
	
	free(da_buffa);
}
