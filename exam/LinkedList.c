#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// insert at head of list
node_t *insert_at_head(node_t *head, node_t *node_to_insert)
{
    node_to_insert->next = head;
    return node_to_insert;
}

// insert at tail of list
void insert_at_tail(node_t *head, node_t *node_to_insert)
{
    node_t *temp = head;
    while (temp->next != NULL) // traverse till last node
    {
        temp = temp->next;
    }
    temp->next = node_to_insert;
}

// print nodes
void printList(node_t *head)
{

    node_t *temp = head;
    printf("\n List is:");
    while (temp != NULL)
    {
        printf(" %d \t", temp->data);
        temp = temp->next;
    }
    printf("\n \n");
}

node_t *insert_at_postion(node_t *head, node_t *node_to_insert, int position)
{
    node_t *temp = head;
    int count = 0;
    printf("top %d , p = %d  \t", temp->data, position);
    position = position - 2; // 1st node is 0th position
    while (position)
    {
        --position;
        temp = temp->next;
    }
    printf(" down %d c = %d  \t", temp->data, position);
    node_to_insert->next = temp->next;
    temp->next = node_to_insert;
}

node_t *recursiveReverseLL(node_t *first)
{

    if (first == NULL)
        return NULL; // list does not exist.

    if (first->next == NULL)
        return first; // list with only one node.

    node_t *rest = recursiveReverseLL(first->next); // recursive call on rest.

    first->next->next = first; // make first; next to the last node in the reversed rest.

    first->next = NULL; // since first is the new last, make its next NULL.

    return rest; // rest now points to the head of the reversed list.
}

bool isTail(node_t *head, int position)
{
    node_t *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (count == position)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isGreaterTail(node_t *head, int position)
{
    node_t *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (count < position)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty(node_t *head)
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

node_t *delete_start(node_t *head)
{
    if (head == NULL)
    {
        printf("Nothing to delete!!!\n");
    }

    else
    {
        node_t *ptr = head;
        head = head->next;
        free(ptr);
    }

    return head;
}

// delete last node in linked list

node_t *delete_end(node_t *head)
{
    if (head == NULL)
    {
        printf("Nothing to delete!!!\n");
        return NULL;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ...");
        return NULL;
    }
    else
    {
        node_t *ptr1 = head;
        node_t *ptr = ptr1->next;
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nDeleted Node from the last ...");
        return head;
    }
}

int main()
{

    node_t *head = NULL;
    node_t *tmp;
    int choice = 0;
    int input;

    while (choice != 6)
    {
        printf("Menu \n 1. Insert at head \n 2. Insert at tail \n 3. Insert at position  \n 4. Delete at head \n 5. Delete at tail  \n 6. Print \n 7. Exit \n 8. Reverse \n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        { /*  Insert at head */

            printf("Enter the data: ");
            scanf("%d", &input);

            if (isEmpty(head))
            {
                head = create_new_node(input);
            }
            else
            {
                tmp = create_new_node(input);
                head = insert_at_head(head, tmp);
            }

            printList(head);

            break;
        }
        case 2:
        { /*  Insert at tail */

            printf("Enter the data: ");
            scanf("%d", &input);

            if (head == NULL)
            {
                head = create_new_node(input);
            }
            else
            {
                tmp = create_new_node(input);
                insert_at_tail(head, tmp);
            }

            printList(head);

            break;
        }

        case 3:
        { /*  Insert at a position */
            int position;
            printf("Enter the position & data: ");

            scanf("%d %d", &position, &input);

            tmp = create_new_node(input);

            if (isGreaterTail(head, position))
            {
                printf("Position is greater than list size ! \n");
            }
            else if (isEmpty(head))
            {
                head = tmp;
            }
            else if (isTail(head, position))
            {
                insert_at_tail(head, tmp);
            }

            else
            {
                insert_at_postion(head, tmp, position);
            }

            printList(head);

            break;
        }

        case 4:
        { /*  delete_start */
            head = delete_start(head);
            printList(head);
            break;
        }
        case 5:
        { /*  delete_end */
            head = delete_end(head);
            printList(head);
            break;
        }

        case 6:
        { /*  Print */

            head = recursiveReverseLL(head);
            printList(head);

            break;
        }

        case 7:

        { /*  exit */

            exit(0);
            break;
        }
        case 8:

        { /*  Reverse */

            head = recursiveReverseLL(head);
            printList(head);

            break;
        }
        default:
            break;
        }

    } // end while

    return 0;
}