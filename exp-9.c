// Binary Search

#include<stdio.h>

#include<stdlib.h>

#define n 5
int queue[n], front = -1, rear = -1, data;
void enqueue();
void dequeue();
void display();
void main() {
  int a;
  while (a != 4) {
    printf("Menu\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", & a);
    switch (a) {
    case 1: {
      enqueue();
      display();
      break;
    }
    case 2: {
      dequeue();
      display();
      break;
    }
    case 3: {
      display();
      break;
    }
    case 4: {
      exit(-1);
    }
    default: {
      printf("Enter valid choice.");
      break;
    }
    }
  }
}
void enqueue() {
  if (front == -1 && rear == -1) {
    front = 0;
  }
  if ((front == 0) && (rear == (n - 1)) || (front != 0 && front == rear + 1)) {
    printf("queue overflow");

    exit(-1);
  } else {
    if (rear == (n - 1) && front != 0) {
      rear = 0;
      printf("enter data: ");
      scanf("%d", & data);
      queue[rear] = data;
    } else {
      rear = rear + 1;
      printf("enter data: ");
      scanf("%d", & data);
      queue[rear] = data;
    }
  }
}
void dequeue() {
  if (front == -1 && rear == -1) {
    printf("queue underflow\n");
    return;
  }
  if (front == rear) {
    printf("your element is %d\n", queue[rear]);
    front = -1;
    rear = -1;
  } else {
    printf("your element is %d\n", queue[front]);
    if (front == n - 1) {
      front = 0;
    } else {
      front = front + 1;
    }
  }
}
void display() {
  if (front == -1 && rear == -1) {
    printf("queue empty\n");
    return;
  } else if (front <= rear) {
    int i;
    printf("your queue is: \n");

    for (i = front; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
    printf("\n");
  } else {
    int i;
    printf("your queue is: \n");
    for (i = front; i <= n - 1; i++) {
      printf("%d ", queue[i]);
    }
    for (i = 0; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
    printf("\n");
  }
}
