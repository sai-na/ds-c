#include <stdio.h>
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
  }
}
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
int main() {
   int arr[50],m,i;
  printf("Enter the Number of terms in the array : ");
  scanf("%d",&m);
  printf("\nEnter the array ELements \n");
  for(i=0;i<m;i++)
  {
  printf("\nElement[%d] : ",i+1);
  scanf("%d",&arr[i]);
  }
  selectionSort(arr, m);
  printf("Sorted array in Acsending Order:\n");
  printArray(arr, m);
}