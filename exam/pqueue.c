#include <stdio.h>
#include <stdlib.h>

int rear = -1;
int front = -1;
int pqueue[5];
int size = 5;

int isFull(int rear)
{
  if (rear == size - 1)
  {
    printf("queue is full");
    return 1;
  }
  else
    return 0;
}

int isEmpty()
{
  if (rear == -1)
  {
    printf("queue is empty");
    return 1;
  }
  else
    return 0;
}

int enqueue(int data)
{
  int temp, i;
  if (front == -1)
  {
    front = 0;
    rear = 0;
    pqueue[rear] = data;
  }
  else
  {
    if (!isFull(rear))
    {
      rear++;
      pqueue[rear] = data;

      for (i = rear; i > front; i--)
      {

        if (pqueue[i] < pqueue[i - 1])
        {
          temp = pqueue[i];
          pqueue[i] = pqueue[i - 1];
          pqueue[i - 1] = temp;
        }
      }
    }
  }
}

int dequeue()
{
  int d, flag = 0;
  if (!isEmpty())
  {
    printf("enter the data to be removed:");
    scanf("%d", &d);
    for (rear = 0; rear < size; rear++)
    {
      if (d == pqueue[rear])
      {
        printf("%d is removed\n", pqueue[rear]);
        flag = 1;
        break;
      }
    }
  }
  if (flag == 0)
  {
    printf("there is no such data");
  }
  else
  {
    // shift left
    while (rear < size)
    {
      pqueue[rear] = pqueue[rear + 1];
      rear++;
    }
  }
}

int display()
{
  int i;
  if (!isEmpty())
    for (i = 0; i <= rear; i++)
    {
      printf("%d\n", pqueue[i]);
    }
}

int main()
{
  int choice, data;
  while (1)
  {
    printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\nenter your choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("enter the data:\n");
      scanf("%d", &data);
      enqueue(data);
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    case 4:
      exit(1);
    default:
      printf("enter a valid choice");
      break;
    }
  }
}
