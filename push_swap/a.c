#include <stdio.h>
#include <stdlib.h>

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

void quickSort(int *arr, int start, int end)
{
	if (start < end)
	{
		int	pivot = sort(arr, start, end);

		quickSort(arr, start, pivot - 1);
		quickSort(arr, pivot + 1, end);
	}
}

int main()
{
	int arr[] = {3,4,2,1,5,6,8,5,8,9,4,2,2,5,6,8,4,6};
	quickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	for (int i = 0 ; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
}