#include <stdio.h>

#define MAX_SIZE 5

int arr[MAX_SIZE]; // Static array to store elements
int front = -1;    // Index of the front of the deque
int rear = -1;     // Index of the rear of the deque
int size = 0;      // Current size of the deque

// Function to check if the deque is empty
int isEmpty()
{
    return (size == 0);
}

// Function to check if the deque is full
int isFull()
{
    return (size == MAX_SIZE);
}

// Function to add an element to the rear of the deque
void addRear(int value)
{
    if (isFull())
    {
        printf("Deque is full. Cannot add element.\n");
        return;
    }
    if (rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX_SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    arr[rear] = value;
    size++;
    printf("added %d at rear ", value);
}

// Function to remove an element from the front of the deque
void removeFront()
{

    int value = arr[front];
    if (isEmpty())
    {
        printf("Deque is empty. Cannot remove element.\n");
        return;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX_SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    size--;

    printf("removed %d from front ", value);
}

// Function to display the deque
void display()
{
    if (isEmpty())
    {
        printf("ceque is empty.\n");
        return;
    }
    int i;
    printf("Deque: ");
    for (i = front; i != rear; i = (i + 1) % MAX_SIZE)
    {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[i]);
}

int main()
{

    addRear(20);
    display();

    addRear(40);
    display();

    addRear(60);
    display();

    removeFront();
    display();

    removeFront();
    display();

    removeFront();
    display();
}