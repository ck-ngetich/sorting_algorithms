#include "sort.h"

/**
*swap -function that swaps the positions of two elements into an array
*@array: array
*@item1: 1st array element
*@item2: last array element
*/
void swap(int *array, int item1, int item2)
{

	int value;

	value = array[item1];
	array[item1] = array[item2];
	array[item2] = value;
}
/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: array size
 * @array: numbers in the list
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, x = 0;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (x = i; x >= gap &&
			 (array[x] < array[x - gap]); x -= gap)
				swap(array, x, x - gap);
		print_array(array, size);
		gap /= 3;
	}
}
