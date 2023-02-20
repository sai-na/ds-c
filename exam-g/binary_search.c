#include <stdio.h>
int found = 0;
int binary_search(int array[], int low, int high, int element)
{

        if (high >= low)
        {
                int mid = (high + low) / 2;

                if (array[mid] == element)
                {
                        found = 1;
                        return mid;
                }

                else if (array[mid] > element)
                {
                        return binary_search(array, low, mid - 1, element);
                }

                else
                {
                        return binary_search(array, mid + 1, high, element);
                }
        }

        return -1;
}

void bubble_sort(int array[], int no_of_elements)
{
        int i, j, temp;
        for (i = 0; i < no_of_elements; i++)
        {
                for (j = 0; j < no_of_elements - i; j++)
                {
                        if (array[j] > array[j + 1])
                        {
                                // swap the elements
                                temp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = temp;
                        }
                }
        }
}

int main()
{
        int no_of_elements, element, index_of_element;

        printf("Enter number of elements of the array :");
        scanf("%d", &no_of_elements);

        int array[no_of_elements];

        for (int i = 0; i < no_of_elements; i++)
        {

                printf("Enter element at index %d : ", i);
                scanf("%d", &array[i]);
        }

        printf("Array before sorting!!!\n");
        for (int i = 0; i < no_of_elements; i++)
        {
                printf("%d\t", array[i]);
        }

        bubble_sort(array, no_of_elements-1);

        printf("\nArray after sorting!!!\n");
        for (int i = 0; i <= no_of_elements - 1; i++)
        {
                printf("%d\t", array[i]);
        }

        printf("\nEnter element to be searched :");
        scanf("%d", &element);

        index_of_element = binary_search(array, 0, no_of_elements - 1, element);

        if (found == 1)
        {
                printf("Element found at index %d\n", index_of_element);
        }

        else
        {
                printf("Element not found!!!\n");
        }
}
