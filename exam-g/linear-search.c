#include <stdio.h>

int main()
{
    int size, k, flag = 0;

    printf("enter the size");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {

        printf("input the number position at %d ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("enter the number to be search ");
    scanf("%d", &k);

    for (int i = 0; i < size; i++)
    {

        if (k == arr[i])
        {
            printf("%d found at position  %d ", k, i + 1);
            if (flag == 0)
                flag = 1;
        }
    }

    if (flag == 0)
    {
        printf("element not found");
    }
}