#include <stdio.h>
#include <stdlib.h>

// Structure to create a node with data and the next pointer
struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;

Node *top = NULL;

// Push() operation on a  stack
void push(int value)
{

    Node *newNode = malloc(sizeof(Node));
    newNode->data = value; // assign value to the node
    if (top == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top; // Make the node as top
    }
    top = newNode; // top always points to the newly created node
    printf("Node is Inserted\n\n");
}

int pop()
{
    if (top == NULL)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        Node *temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);
        return temp_data;
    }
}

void display()
{
    // Display the elements of the stack
    if (top == NULL)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        printf("The stack is \n");
        Node *temp = top;
        while (temp->next != NULL)
        {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL\n\n", temp->data);
    }
}

int main()
{
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            display();
            break;
        case 2:
            printf("Popped element is :%d\n", pop());
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}
