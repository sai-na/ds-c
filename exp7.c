// linear search

#include<stdio.h>


void main() {
  int i, number[10], n, searchfor, x = 0;
  printf("Enter number of elements: ");
  scanf("%d", & n);
  printf("Enter elements: \n");
  for (i = 0; i < n; i++) {
    printf("enter data %d: ", i + 1);
    scanf("%d", & number[i]);
  }
  printf("Enter element to be searched: ");
  scanf("%d", & searchfor);
  for (i = 0; i < n; i++) {
    if (number[i] == searchfor) {
      printf("The element %d is found at position = %d \n", searchfor, i + 1);
      x++;
    }
  }
  if (x == 0) {
    printf("Element not found");
  }
}
