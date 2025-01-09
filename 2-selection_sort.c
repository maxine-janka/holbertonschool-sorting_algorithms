#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: Size of the array (number of elements).
 *
 * Return: nothing.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	/*Iterate through array*/
	for (i = 0; i < size - 1; i++)
	{
		/*Looking for min at each index*/
		min = i;
		for (j = i + 1; j < size; j++)
		{
			/*compare and update min if found*/
			if (array[j] < array[min])
				min = j;
		}
		/*If min is not at current position already, swap*/
		if (min != i)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;

			print_array(array, size);
		}
	}
}
