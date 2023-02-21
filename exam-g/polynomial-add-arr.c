#include <stdio.h>

void add_polynomials(int poly1[], int poly2[], int result[], int size)
{
    for (int i = 0; i <= size; i++)
    {
        result[i] = poly1[i] + poly2[i];
    }
}

int main()
{
    int size;
    printf("Enter the degree of the polynomials: ");
    scanf("%d", &size);

    int poly1[size + 1], poly2[size + 1], result[size + 1];

    printf("Enter the coefficients of the first polynomial: ");
    for (int i = 0; i <= size; i++)
    {
        printf("coefficient of x^%d =", i);
        scanf("%d", &poly1[i]);
    }

    printf("Enter the coefficients of the second polynomial: ");
    for (int i = 0; i <= size; i++)
    {
        printf("coefficient of x^%d =", i);

        scanf("%d", &poly2[i]);
    }

    add_polynomials(poly1, poly2, result, size);

    printf("Result: ");

        for (int i = 0; i <= size; i++)
    {
        // printf("%d ", result[i]);
        printf(" %d(x^%d) ", result[i], i);

        if (i == size)
        {
            printf("\n");
            break;
        }
        printf("+");
    }

    return 0;
}
