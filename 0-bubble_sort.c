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
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm.
 *
 * @array: A pointer to the array (first element) to be sorted.
 * @size: The size (number of elements) of the array.
 *
 * Return: nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL)
		return;

	/*number of complete traversals*/
	/*size - 1, largest bubbles up to correct position*/
	for (i = 0; i < size - 1; i++)
	{

		/*compare adjacent elements*/
		/*j < size -i - 1, only compare unsorted*/
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/*swap_int takes ptrs not actual values*/
				swap_int(&array[j], &array[j] + 1);
				print_array(array, size);
			}
		}
	}
}
