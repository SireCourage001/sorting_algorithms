#include "sort.h"
#include <stdio.h>

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - Swap two int in an array.
 * @a: The first int to swap.
 * @b: The second int to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp_value;

	temp_value = *a;
	*a = *b;
	*b = temp_value;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of int.
 * @array: An array of int.
 * @size: The size of array.
 * @start: The starting index of sequence in array to sort.
 * @seq: The size of sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t idx, jump = seq / 2;
	
	if (seq > 1)
	{
		for (idx = start; idx < start + jump; idx++)
		{
			if ((flow == UP && array[idx] > array[idx + jump]) ||
			    (flow == DOWN && array[idx] < array[idx + jump]))
				swap_ints(array + idx, array + idx + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Convert an array of int into a bitonic sequence.
 * @array: An array of int.
 * @size: The size of array.
 * @start: The starting index of a block of building bitonic sequence.
 * @seq: The size of a block of building bitonic sequence.
 * @flow: The direction to sort bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str_val = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str_val);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str_val);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of int in ascending
 *                order using bitonic sort algorithm.
 * @array: An array of int.
 * @size: The size of array.
 *
 * Description: Prints array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
