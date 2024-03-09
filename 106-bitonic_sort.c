#include "sort.h"
#include <stdio.h>
/**
 * swap - function that changes two values in ascending or descending order
 * @arr: array
 * @item1: one item of the array
 * @item2: another item of an array
 * @order: 1: ascending order
 * 	   0:descending order
 */
void swap(int arr[], int item1, int item2, int order)
{
	int temp;

	if (order == (arr[item1] > arr[item2]))
	{
		temp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = temp;
	}
}
/**
 * merge -function that  sort bitonic sequences recursively in both orders
 * @arr: array
 * @low: first element of an array
 * @nelemnt:number of element
 * @order: 1: ascending order, 0 descending order
 */
void merge(int arr[], int low, int nelemnt, int order)
{
	int mid, i;

	if (nelemnt > 1)
	{
		mid = nelemnt / 2;
		for (i = low; i < low + mid; i++)
			swap(arr, i, i + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}
/**
 * bitonicsort - function to implement  bitonic sort algorithm
 * @arr: array where functionwill be implemented
 * @low: first element
 * @num_elem: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: size of an array
 */
void bitonicsort(int arr[], int low, int num_elem, int order, int size)
{
	int mid;

	if (num_elem > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", num_elem, size);
			print_array(&arr[low], num_elem);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", num_elem, size);
			print_array(&arr[low], nelemnt);
		}
		mid = num_elem / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		merge(arr, low, num_elem, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", num_elem, size);
			print_array(&arr[low], num_elem);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", num_elem, size);
			print_array(&arr[low], num_elem);
		}
	}
}
/**
 * bitonic_sort - function that  prepare the terrain to bitonic sort algorithm
 * @array: array to sort
 * @size: size of an array
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
