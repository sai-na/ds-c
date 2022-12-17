#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node_t;

node_t *create_new_node(int data)
{
    node_t *result = malloc(sizeof(node_t));
    result->data = data;
    result->next = NULL;
    return result;
}

// insert at head of ll
node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
}

// print nodes
void printList(node_t *head)
{
    node_t *temp = head;
    while (temp != NULL)
    {
        printf(" %d \t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{

    node_t *head;
    node_t *tmp;

    tmp = create_new_node(23);
    head = tmp;

    // inset at the beginning
    tmp = create_new_node(63);
    insert_at_head(&head, tmp);

    printList(head);

    return 0;
}