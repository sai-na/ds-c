#include <stdio.h>
#define SIZE 10
int htable[SIZE] = {NULL};
int hashkey(int x)
{
    return x % SIZE;
}
void insert(int x)
{
    int ind = hashkey(x);
    if (htable[ind] == NULL)
    {
        htable[ind] = x;
        printf("Inserted successfully\n");
        return;
    }
    else
    {
        for (int i = ind + 1; i < SIZE; i++)
        {
            if (htable[i] == NULL)
            {
                htable[i] = x;
                printf("Inserted successfully\n");
                return;
            }
        }
        printf("Could not insert\n");
    }
}
void find(int x)
{
    for (int i = hashkey(x); i < SIZE; i++)
    {
        if (htable[i] == x)
        {
            printf("Value found at index %d\n", i);
            return;
        }
    }
    printf("Value not found\n");
}
void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", htable[i]);
    }
    printf("\n");
}
int main()
{
    int op, e;
    do
    {
        printf("1.Insert 2.Search 3.Display 4.Exit\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &e);
            insert(e);
            break;
        case 2:
            printf("Enter the element to search : ");
            scanf("%d", &e);
            find(e);
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Invalid option\n");
        }
    } while (op != 4);
}
