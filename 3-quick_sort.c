#include "sort.h"

/**
 * swap_int - Swaps two integers.
 *
 * @a: Integer to be swapped with b.
 * @b: Integer to be swapped with a.
 *
 * Return: nothing.
 */

void swap_int(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions an array around the pivot value
 *             to help Quick sort.
 *
 * @array: A pointer to the array to partition.
 * @low: Element at starting index.
 * @high: Element at ending index.
 * @size: The size of the array (Number of elements).
 *
 * Return: The new pivot index.
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j;
	int pivot_value = array[high]; /*pivot value is the last element*/

	i = low;
	for (j = low; j < high; j++) /*Set both to low index*/
	{
		/*Only increment i, if j is <= pivot and swap*/
		if (array[j] <= pivot_value)
		{
			if (i != j) /*Only print if theres a swap*/
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high) /*Only print when pivot is moved*/
	{
		/*Move pivot to correct spot at index i*/
		swap_int(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i); /*Give new pivot index back to recursive function*/
}

/**
 * quicksort_recursion - Recursivley divides the array into subarrays
 *                       to help Quick sort.
 *
 * @array: A pointer to the array to Quick sort.
 * @low: Element at starting index.
 * @high: Element at ending index.
 * @size: The size of the array (Number of elements).
 *
 * Return: nothing.
 */
void quicksort_recursion(int *array, int low, int high, size_t size)
{
	/*Basecase for recursion*/
	if (low < high)
	{
		/*partition array given low and high index of array*/
		int pivot_index = partition(array, low, high, size);

		/*Left sub-array from low index*/
		quicksort_recursion(array, low, pivot_index - 1, size);
		/*Right sub-array to high index*/
		quicksort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm and Lomuto partition scheme.
 *
 * @array: A pointer to the array to quick sort.
 * @size: The size of the array (Number of elements).
 *
 * Return: nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/*Give first and last element to recursion func*/
	quicksort_recursion(array, 0, size - 1, size);
}
