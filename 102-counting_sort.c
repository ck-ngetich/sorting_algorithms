#include "sort.h"
#include <stdio.h>
/**
 *_calloc - function that perform is a calloc
 *@num_elem: number of elements
 *@size: size of each element
 *Return: pointer to memory
 */
void *_calloc(unsigned int num_elem, unsigned int size)
{
	unsigned int i = 0;
	char *c;

	if (num_elem == 0 || size == 0)
		return ('\0');
	c = malloc(num_elem * size);
	if (*c == '\0')
		return ('\0');
	for (i = 0; i < (num_elem * size); i++)
		c[i] = '\0';
	return (c);
}
/**
 * counting_sort - is a function that counts implemetations by sort method
 * @array: array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int index, maximun = 0, *counter = '\0', *tmp = '\0';
	size_t i;

	if (*array == '\0' || size < 2)
		return;
	for (i = 0; i < size; i++)
		if (array[i] > maximun)
			maximun = array[i];
	counter = _calloc(maximun + 1, sizeof(int));
	tmp = _calloc(size + 1, sizeof(int));
	for (i = 0; i < size; i++)
		counter[array[i]]++;
	for (index = 1; index <= maximun; index++)
		counter[index] += counter[index - 1];
	print_array(counter, maximun + 1);
	for (i = 0; i < size; ++i)
	{
		tmp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	free(tmp);
	free(counter);

}
