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
    Node *temp;
    Node *newP = malloc(sizeof(Node));
    newP->coeff = co;
    newP->expo = ex;
    newP->link = NULL;

    // If there is no node in the list OR given exponent is than
    // the first node exponent
    if (head == NULL || ex > head->expo)
    {
        newP->link = head;
        head = newP;
    }
    else
    {
        temp = head;
        while (temp->link != NULL && temp->link->expo >= ex)
            temp = temp->link;
        newP->link = temp->link;
        temp->link = newP;
    }
    return head;
}

Node *create(Node *head)
{
    int n, i;
    int coeff;
    int expo;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%d", &coeff);

        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &expo);

        head = insert(head, coeff, expo);
    }
    return head;
}

void print(Node *head)
{
    if (head == NULL)
        printf("No Polynomial.");
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            printf("(%d)x^(%d)", temp->coeff, temp->expo);
            temp = temp->link;
            if (temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}

void polyMult(Node *head1, Node *head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    Node *head3 = NULL;

    // Check if first or second polynomial is NULL
    if (head1 == NULL || head2 == NULL)
    {
        printf("Zero polynomial\n");
        return;
    }

    // Multiplication of two polynomials
    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            head3 = insert(head3, ptr1->coeff * ptr2->coeff, ptr1->expo + ptr2->expo);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
        ptr2 = head2;
    }
    printf("Polynomial 1\n");
    print(head1);
    printf("Polynomial 2\n");
    print(head2);
    // printf("\nBefore simplification: \n");
    printf("Product\n");
    // print(head3);

    // Adding the like terms (terms with the same exponent) for simplification
    Node *ptr3 = head3;
    Node *temp = NULL;

    while (ptr3->link != NULL)
    {
        if (ptr3->expo == ptr3->link->expo)
        {
            ptr3->coeff = ptr3->coeff + ptr3->link->coeff;
            temp = ptr3->link;
            ptr3->link = ptr3->link->link;
            free(temp);
        }
        else
        {
            ptr3 = ptr3->link;
        }
    }
    // printf("\n After simplification: \n");
    print(head3);
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    printf("Enter the first polynomial\n ");
    head1 = create(head1);
    printf("Enter the second polynomial\n ");
    head2 = create(head2);

    polyMult(head1, head2);
    return 0;
}
