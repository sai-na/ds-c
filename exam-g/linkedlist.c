#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node node;

// create new node
node *create_new_node(int data)
{
    node *new = malloc(sizeof(node));
    new->data = data;
    new->link = NULL;
    return new;
}

// insert at front
node *insert_at_head(node *head, node *new)
{

    new->link = head;
    return new;
}

// insert at end
void insert_at_tail(node *head, node *new)
{
    node *temp = head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = new;
}

// delete front
node *delete_head(node *head)
{

    if (head == NULL)
    {
        printf("Nothing to delete!!!\n");
    }
    else
    {
        node *temp = head;
        head = head->link;
        free(temp);
    }

    return head;
}

// delete end
node *delete_tail(node *head)
{

    if (head == NULL)
    {
        printf("Nothing to delete!!!\n");
        return NULL;
    }
    else if (head->link == NULL)
    {
        head = NULL;
        free(head);
        printf("have only one node");
        return NULL;
    }
    else
    {

        node *ptr1 = head;
        node *ptr2 = ptr1->link;

        while (ptr2->link != NULL)
        {
            ptr1 = ptr2;
            ptr2 = ptr2->link;
        }
        ptr1->link = NULL;
        free(ptr2);
        return head;
    }
}

node *reverse(node *head)
{
    if (head == NULL)
        return NULL;
    if (head->link == NULL)
        return head;
    node *rest = reverse(head->link);
    head->link->link = head;
    head->link = NULL;
    return rest;
}

void display(node *head)
{

    node *temp = head;

    printf("\n");
    if (head == NULL)
    {
        printf("empty linked list");
    }

    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->link != NULL)
            printf("->");
        else
            printf("\n");

        temp = temp->link;
    }

    printf("\n \n");
}

void printList(node *head)
{

    node *temp = head;
    printf("\n List is:");
    while (temp != NULL)
    {
        printf(" %d \t", temp->data);
        temp = temp->link;
    }
    printf("\n \n");
}

int main()
{
    node *head = NULL;
    node *tmp;
    int choice = 0, value;

    while (choice != 6)
    {

        printf("\nselect choice \n 1. insert at front\n 2. insert at end\n 3. delete at front\n 4.delete at end\n 5. reverse\n 6. exit \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("input tha value:");
            scanf("%d", &value);
            if (head == NULL)
            {
                head = create_new_node(value);
            }
            else
            {
                tmp = create_new_node(value);
                head = insert_at_head(head, tmp);
            }
            display(head);
            // printList(head);
            break;
        }

        case 2:
        {

            printf("Enter the value :");
            scanf("%d", &value);
            if (head == NULL)
            {
                head = create_new_node(value);
            }
            else
            {
                tmp = create_new_node(value);
                insert_at_tail(head, tmp);
            }
            // printList(head);
            display(head);
            break;
        }

        case 3:
        {

            head = delete_head(head);
            display(head);
            break;
        }

        case 4:
        {
            head = delete_tail(head);
            display(head);
            break;
        }
        case 5:
        {
            head = reverse(head);
            display(head);
            break;
        }
        case 6:
        {
            printf("exit");
        }

        default:
            break;
        }
    }
}