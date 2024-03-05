#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: array size
 * @array:numbers in the list
 */
void selection_sort(int *array, size_t size)
{
	size_t i, x;
	int tmp, swap, flag = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		tmp = i;
		flag = 0;
		for (x = i + 1; x < size; x++)
		{
			if (array[tmp] > array[x])
			{
				tmp = x;
				flag += 1;
			}
		}
		swap = array[i];
		array[i] = array[tmp];
		array[tmp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
