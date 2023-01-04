#include <stdio.h>

void main()
{
    int no_of_elements, element, found = 0;

    printf("Enter number of elements of the array :");
    scanf("%d", &no_of_elements);

    int array[no_of_elements];

    for (int i = 0; i <= no_of_elements - 1; i++)
    {

        printf("Enter element at index %d : ", i);
        scanf("%d", &array[i]);
    }

    printf("Enter element to be searched :");
    scanf("%d", &element);

    for (int i = 0; i <= no_of_elements - 1; i++)
    {
        if (array[i] == element)
        {
            printf("Element found at index %d\n", i);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Element not found\n");
    }
}
