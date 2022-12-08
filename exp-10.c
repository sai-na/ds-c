//Linked List

#include<stdio.h>

#include<stdlib.h>

#define n 10
int deque[n], front = -1, rear = -1, data;
void insertrear();
void insertfront();
void deleterear();
void deletefront();
void display();
void main() {
  int a = 0;
  while (a != 6) {
    printf("Menu:\n1. Insert at rear\n2. Insert at front\n3. Delete at front\n4. Delete at rear\n5. Display\n6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", & a);
    switch (a) {
    case 1: {
      insertrear();
      display();
      break;
    }
    case 2: {
      insertfront();
      display();
      break;
    }
    case 3: {
      deletefront();
      display();
      break;
    }
    case 4: {
      deleterear();
      display();
      break;
    }
    case 5: {
      display();
      break;
    }
    case 6: {
      exit(-1);
    }

    default: {
      printf("Enter valid choice");
    }
    }
  }
}
void insertrear() {
  if (front == -1 && rear == -1) {
    front = 0;
  }
  if (rear == (n - 1)) {
    printf("queue overflow");
    exit(-1);
  } else {
    printf("enter data: ");
    scanf("%d", & data);
    rear++;
    deque[rear] = data;
  }
}
void insertfront() {
  if (front <= 0) {
    printf("cannot add element");
    exit(-1);
  } else {
    printf("enter data: ");
    scanf("%d", & data);
    front--;
    deque[front] = data;
  }
}
void deleterear() {
  if (rear == -1) {
    printf("cannot delete element");
    exit(-1);
  } else {
    printf("your element is %d\n", deque[rear]);
    if (rear == front) {
      front = -1;
      rear = -1;
      printf("queue empty");
      exit(-1);

    } else {
      rear--;
    }
  }
}
void deletefront() {
  if (front < 0) {
    printf("queue underflow");
    exit(-1);
  } else {
    printf("your element is %d\n", deque[front]);
    front++;
    if (front > rear) {
      front = -1;
      rear = -1;
      printf("queue empty");
      exit(-1);
    }
  }
}
void display() {
  int i;
  printf("your queue is: \n");
  for (i = front; i <= rear; i++) {
    printf("%d ", deque[i]);
  }
  printf("\n");
}
