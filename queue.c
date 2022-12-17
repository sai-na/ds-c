#include <stdio.h>
#define MaxSize 5
int queue[MaxSize], front = -1, rear = -1;

// display

void display()
{
	if (isEmpty())
		printf("\n Queue underflow error : the queue is empty \n");
	else
	{
		printf("\n The queue is :");
		for (int i = front; i <= rear; i++)
			printf("%d ", queue[i]);
		printf("\n");
	}
}

int isEmpty()
{
	if ((front > rear))
		return 1;
	else
		return 0;
}

int isFull()
{
	if (rear >= (MaxSize - 1))
		return 1;
	else
		return 0;
}

// enqueue
void enqueue(int data)
{

	if (isFull())
		printf("Queue is full");
	else
	{
		if (front == -1)
			front = 0;
		rear++;
		queue[rear] = data;
		display();
	}
}

// dequeue

void dequeue()
{

	if (isEmpty())
		printf("\n Queue underflow error : the queue is empty \n");
	else
	{
		printf("\n The removed element is %d \n ", queue[front]);
		front++;
		display();
	}
}

void main()
{
	printf("Enter your choice:");

	int flag, data;
	do
	{
		printf("1.Enqueu\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("enter your choice: ");
		scanf("%d", &flag);
		switch (flag)
		{
		case 1:
			printf("enter data to be added: ");
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
			break;
			;
		default:
			printf("invalid choice\n");
		}
	} while (flag != 4);
}
