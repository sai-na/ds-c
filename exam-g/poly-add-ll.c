#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int expo;
    struct node *link;
};

typedef struct node Node;

Node *insert(Node *head, int co, int ex)
{
    Node *temp = head;
    Node *newP = malloc(sizeof(Node));
    newP->coeff = co;
    newP->expo = ex;

    // if there is no node in the list OR given exponent is greater than the first node exponent
    if (head == NULL || ex > head->expo)
    {
        newP->link = head;
        head = newP;
    }
    else
    {
        // temp = head;
        while (temp->link != NULL && temp->link->expo > ex)
        {
            temp = temp->link;
        }
        newP->link = temp->link;
        temp->link = newP;
    }
    return head;
}

Node *create(Node *head)
{
    int n, i;
    int co;
    int ex;

    printf("no of elements ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the coefficient for term %d ", i + 1);
        scanf("%d", &co);
        printf("Enter the exponent for term %d ", i + 1);
        scanf("%d", &ex);
        head = insert(head, co, ex);
    }
    return head;
}

void print(Node *head)
{

    if (head == NULL)
    {
        printf("No Polynomial");
    }
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            printf(" (%dX^%d) ", temp->coeff, temp->expo);
            temp = temp->link;
            if (temp != NULL)
            {
                printf("+");
            }
            else
            {
                printf("\n");
            }
        }
    }
}

Node *polyAdd(Node *head1, Node *head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    Node *head3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->link;
        }
        else if (ptr2->expo > ptr1->expo)
        {
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    while (ptr1 != NULL)
    {

        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->link;
    }
    while (ptr2 != NULL)
    {

        head3 = insert(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->link;
    }
    return head3;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head3 = NULL;

    printf("Enter the polynomial \n");
    head1 = create(head1);
    print(head1);
    printf("Enter the polynomial \n");
    head2 = create(head2);
    print(head2);
    head3 = polyAdd(head1, head2);
    printf("Added polynomial is :");
    print(head3);
    return 0;
}