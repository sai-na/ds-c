#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int value)
{
    Node *ptr;
    ptr = malloc(sizeof(Node));
    ptr->data = value;
    ptr->next = NULL;
    if ((front == NULL) && (rear == NULL))
    {
        front = rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
    printf("Node is Inserted\n\n");
}
int dequeue()
{
    if (front == NULL)
    {
        printf("\nUnderflow\n");
        return -1;
    }
    else
    {
        Node *temp = front;
        int temp_data = front->data;
        front = front->next;
        free(temp);
        return temp_data;
    }
}
void display()
{
    Node *temp;
    if ((front == NULL) && (rear == NULL))
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("The queue is \n");
        temp = front;
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
            if (temp != NULL)
            {
                printf("-->");
            }
        }
        printf("\n\n");
    }
}
int main()
{
    int choice = 0, value;
    printf("\nImplementation of Queue using Linked List\n");
    while (choice != 4)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            display();
            break;
        case 2:
            printf("Popped element is :%d\n", dequeue());
            display();
            break;
        case 3:
            display();
            break;
        case 4:

            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
    return 0;
}
