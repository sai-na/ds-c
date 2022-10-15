#include <stdio.h>
#define MaxSize 5
int queue[5];
int rear = -1;
int front = 0;

void display()
{

	int i;
	printf("The queue is :");
	for (i = front; i <= rear; i++)
		printf("%d \n", queue[i]);
}

int isFull()
{

	if (rear >= MaxSize - 1) // array index
		return 1;
	else
		return 0;
}

int isEmpty()
{

	if (front > rear)
		return 1;
	else
		return 0;
}

void enqueue(int a)
{

	if (isFull())
		printf("Queue Overflow");

	else
	{
		rear++;
		queue[rear] = a;
		display();
	}
}

void dequeue()
{

	if (isEmpty())
		printf("Queue underflow");
	else
	{
		printf(" The popped element  is %d", queue[front]);
		front++;
		display();
	}
}

void main()
{

	int choice, a;

	do
	{

		printf("Enter your choice \n 1. Enqueue \n 2. Dequeue \n 3. Display \n 4 .Exit \n \n");

		scanf("%d", &choice);

		switch (choice)
		{

		case 1:
			printf("Enter element to be added to the queue ");
			scanf("%d", &a);
			enqueue(a);
			break;

		case 2:
			dequeue();
			break;

		case 3:
			display();
			break;

		case 4:
			break;

		default:
			printf("Invalid choice");
		}
	}

	while (choice != 4);
}
