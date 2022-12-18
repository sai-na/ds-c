#include <stdio.h>
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int arr[], int N, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < N && arr[left] > arr[largest])
		largest = left;
	if (right < N && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, N, largest);
	}
}
void heapSort(int arr[], int N)
{

	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);
	for (int i = N - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}
void printArray(int arr[], int N)
{
    printf("\n The Sorted Array is : ");
	for (int i = 0; i < N; i++)
		printf("\n%d ", arr[i]);
	printf("\n");
}
int main()
{
	int arr[50],m,i;
	//int N = sizeof(arr) / sizeof(arr[0]);
printf("Enter the Number of terms in the array : ");
	scanf("%d",&m);
	printf("\nEnter the array ELements \n");
	for(i=0;i<m;i++)
	{
	printf("\nElement[%d] : ",i+1);
	scanf("%d",&arr[i]);
	}
	// Function call
	heapSort(arr, m);
	printf("Sorted array is\n");
	printArray(arr, m);
}

// This code is contributed by _i_plus_plus_.
