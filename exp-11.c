// polynomial addition 

#include<stdio.h>

#include<stdlib.h>

typedef struct {
  int coeff;
  int expo;
}
poly;
void main() {
  int n1, n2, i;
  poly a[10], b[10], c[10];
  printf("First polynomial\n");
  printf("enter degree: ");
  scanf("%d", & n1);
  for (i = n1; i >= 0; i--) {
    printf("Enter coefficient of x^%d: ", i);
    scanf("%d", & a[i].coeff);
    a[i].expo = i;
  }
  printf("your polynomial is: \n");
  for (i = n1; i >= 0; i--) {
    if (a[i].coeff != 0 && a[i].expo != 0) {
      printf("%dx^%d", a[i].coeff, a[i].expo);
      if (i != 0) {
        printf("+");
      }
    }
    if (a[i].expo == 0) {
      printf("%d", a[i].coeff);
    }
  }
  printf("\n");
  printf("Second polynomial\n");
  printf("enter degree: ");
  scanf("%d", & n2);
  for (i = n2; i >= 0; i--) {
    printf("Enter coefficient of x^%d: ", i);
    scanf("%d", & b[i].coeff);
    b[i].expo = i;
  }
  printf("your polynomial is: \n");
  for (i = n2; i >= 0; i--) {
    if (b[i].coeff != 0 && b[i].expo != 0) {
      printf("%dx^%d", b[i].coeff, b[i].expo);
      if (i != 0) {
        printf("+");
      }
    }
    if (b[i].expo == 0) {
      printf("%d", b[i].coeff);
    }
  }
  printf("\n");
  printf("Sum of polynomials: ");
  if (n1 >= n2) {
    if (n1 != n2) {
      b[n1].coeff = 0;
      b[n1].expo = n1;
    }
    for (i = n1; i >= 0; i--) {
      c[i].coeff = a[i].coeff + b[i].coeff;
      c[i].expo = i;
    }
    for (i = n1; i >= 0; i--) {
      if (c[i].coeff != 0 && c[i].expo != 0) {
        printf("%dx^%d", c[i].coeff, c[i].expo);
        if (i != 0) {
          printf("+");
        }
      }
      if (c[i].expo == 0) {
        printf("%d", c[i].coeff);
      }
    }
  } else {
    if (n1 != n2) {
      a[n2].coeff = 0;
      a[n2].expo = n2;
    }
    for (i = n2; i >= 0; i--) {
      c[i].coeff = a[i].coeff + b[i].coeff;
      c[i].expo = i;
    }
    for (i = n2; i >= 0; i--) {
      if (c[i].coeff != 0 && c[i].expo != 0) {
        printf("%dx^%d", c[i].coeff, c[i].expo);
        if (i != 0) {
          printf("+");
        }
      }
      if (c[i].expo == 0) {
        printf("%d", c[i].coeff);
      }
    }
  }
}
