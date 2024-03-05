#include "sort.h"

/**
 * swap - swaps two values in an array
 *
 * @array: data to sort
 * @i: first value in an array
 * @j: second value in an array
 * Return: Nthing
 */
void swap(int *array, int i, int j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/**
 * partition - function to  sorts a partition of data in relation to a pivot
 * @array: array data to sort
 * @min: min-valued element i n an array
 * @max: max-valued element in an array
 * @size: size of dat in an array
 * Return: New Pivot
 */
int partition(int *array, int min, int max, size_t size)
{
	int i, j, pivot = array[max];

	for (i = min, j = max; 1; i++, j--)
	{
		while (array[i] < pivot)
			i++;

		while (array[j] > pivot)
			j--;

		if (i >= j)
			return (i);
		swap(array, i, j);
		print_array(array, size);
	}
}

/**
 * quicksort -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Lomuto partition scheme
 * @array: array of data to sort
 * @min: min-valued element
 * @max: max-valued element
 * @size: size of array
 * Return: Nothing
 */
void quicksort(int *array, int min, int max, size_t size)
{
	int p;

	if (min < max)
	{
		p = partition(array, min, max, size);
		quicksort(array, min, p - 1, size);
		quicksort(array, p, max, size);
	}
}

/**
 * quick_sort_hoare - function that sorts an array of integers in ascending order using the
 * Quick sort algorithm Hoare partition scheme
 * @array: element in an array to sort
 * @size: size of array
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
