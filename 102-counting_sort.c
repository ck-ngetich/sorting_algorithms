#include "sort.h"
#include <stdio.h>
/**
 *_calloc - this is a calloc function
 *@nmemb: the number of elements
 *@size: bit size of each element
 *Return: pointer to memory assignment
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *c;

	if (nmemb == 0 || size == 0)
		return ('\0');
	c = malloc(nmemb * size);
	if (*c == '\0')
		return ('\0');
	for (i = 0; i < (nmemb * size); i++)
		c[i] = '\0';
	return (c);
}
/**
 * counting_sort - function that implements a counting sort method algorithm
 * @array: array with elements to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int idx, max = 0, *counter = '\0', *value = '\0';
	size_t i;

	if (*array == '\0' || size < 2)
		return;
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	counter = _calloc(max + 1, sizeof(int));
	value = _calloc(size + 1, sizeof(int));
	for (i = 0; i < size; i++)
		counter[array[i]]++;
	for (idx = 1; idx <= max; idx++)
		counter[idx] += counter[idx - 1];
	print_array(counter, max + 1);
	for (i = 0; i < size; ++i)
	{
		value[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = value[i];
	free(value);
	free(counter);

}
