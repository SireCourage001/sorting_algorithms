#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two int in an array.
 * @a: The first int to swap.
 * @b: The second int to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp_val;

	temp_val = *a;
	*a = *b;
	*b = temp_val;
}

/**
 * max_heapify - Turn binary tree into a complete binary heap.
 * @array: An array of int, representing a binary tree.
 * @size: The size of array/tree.
 * @base: The index of base row of the tree.
 * @root: Root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t val_left, right_val, val_largest;

	val_left = 2 * root + 1;
	right_val = 2 * root + 2;
	val_largest = root;

	if (val_left < base && array[val_left] > array[val_largest])
		val_largest = val_left;
	if (right_val < base && array[right_val] > array[val_largest])
		val_largest = right_val;

	if (val_largest != root)
	{
		swap_ints(array + root, array + val_largest);
		print_array(array, size);
		max_heapify(array, size, base, val_largest);
	}
}

/**
 * heap_sort - Sort an array of int in ascending
 *             order using heap sort algorithm.
 * @array: An array of int.
 * @size: The size of array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int idx;

	if (array == NULL || size < 2)
		return;

	for (idx = (size / 2) - 1; idx >= 0; idx--)
		max_heapify(array, size, size, idx);

	for (idx = size - 1; idx > 0; idx--)
	{
		swap_ints(array, array + idx);
		print_array(array, size);
		max_heapify(array, size, idx, 0);
	}
}
