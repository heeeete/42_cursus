#include "./include/push_swap.h"

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int sort(int *arr, int start, int end)
{
	int	i;
	int	j;
	int	pivot;

	i = start - 1;
	j = start;
	pivot = arr[end];
	while (j <= end - 1)
	{
		if (arr[j] >= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[end]);
	return (i + 1);
}

void quicksort(int **arr, int start, int end)
{
	int pivot;

	if (start < end)
	{
		pivot = sort(*arr, start, end);

		quicksort(arr, start, pivot - 1);
		quicksort(arr, pivot + 1, end);
	}
}
