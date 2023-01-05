#include <math.h>
#include <stdio.h>
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void printArray(int arr[], int n)
{
	int i;
	printf("\n The Sorted Array is : ");
	for (i = 0; i < n; i++)
		printf("\n%d ", arr[i]);
	printf("\n");
}
int main()
{
	int arr[50], m, i;
	printf("Enter the Number of terms in the array : ");
	scanf("%d", &m);
	printf("\nEnter the array ELements \n");
	for (i = 0; i < m; i++)
	{
		printf("\nElement[%d] : ", i + 1);
		scanf("%d", &arr[i]);
	}

	insertionSort(arr, m);
	printArray(arr, m);

	return 0;
}
