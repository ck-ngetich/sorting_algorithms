#include "sort.h"
/**
 * bubble_sort - function that sorts elements of array in an asceding order
 * @array: array with elements
 * @size: size of an array
 */
void bubble_sort(int *array, size_t size)
{

	size_t i, x, tmp = 0;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
		for (x = 0; x < size; x++)
		{
			if (array[x] > array[x + 1] && array[x + 1])
			{
			tmp = array[x];
			array[x] = array[x + 1];
			array[x + 1] = tmp;
			print_array(array, size);
			}
		}
}
