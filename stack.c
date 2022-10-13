#include <stdio.h>
int max = 8;
int stack[8];
int top = -1;

int isEmpty()
{
	if (top <= -1)
		return 1;
	else
		return 0;
}

int isFull()
{

	if (top >= max)
		return 1;
	else
		return 0;
}

void pop()
{

	if (!(isEmpty()))
	{
		int data;
		data = stack[top];
		printf("%d \n", data);
		top = top - 1;
	}
	else
	{

		printf("Under flow");
	}
}

int push(int data)
{

	top = top + 1;

	if (!(isFull()))
	{

		stack[top] = data;
	}
	else
	{
		top = top - 1;

		printf("Coudn't insert");
	}
}

void display()
{

	for (int i = 0; i <= top; i++)
	{
		printf("%d \n", stack[i]);
	}
}

void main()
{
	int choice = 0, a = 0;

	do
	{
		printf("Enter choice \n 1.Push \n 2.Pop  \n 3.Display	\n 4.Exit\n\n");

		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter the element to be added\n");
			scanf("%d", &a);
			push(a);

			break;

		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			break;
		default:
			break;
		}
	} while (choice != 4);
}
