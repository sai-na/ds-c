#include <stdio.h>

void main()
{
        int degree1, degree2, max_degree;

        printf("Enter the degree of the first polynomial : ");
        scanf("%d", &degree1);

        printf("Enter the degree of the second polynomial : ");
        scanf("%d", &degree2);

        if (degree1 > degree2)
        {
                max_degree = degree1;
        }
        else
        {
                max_degree = degree2;
        }

        int polynomial1[max_degree];
        int polynomial2[max_degree];

        if (degree1 > degree2)
        {
                for (int i = degree2; i <= max_degree; i++)
                {
                        polynomial2[i] = 0;
                }
        }

        else
        { // degree2 >= degree1
                for (int i = degree1; i <= max_degree; i++)
                {
                        polynomial1[i] = 0;
                }
        }

        printf("Enter the coefficients of the first polynomial starting from constant term\n");

        for (int i = 0; i <= degree1; i++)
        { // store the first polynomial in polynomial1[]
                scanf("%d", &polynomial1[i]);
        }

        printf("Enter the coefficients of the second polynomial starting from constant term\n");

        for (int i = 0; i <= degree2; i++)
        { ////store the second polynomial in polynomial2[]
                scanf("%d", &polynomial2[i]);
        }

        int polynomial_sum[max_degree];

        for (int i = 0; i <= max_degree; i++)
        {
                polynomial_sum[i] = polynomial1[i] + polynomial2[i];
        }

        printf("\npolynomial 1 is\n");

        for (int i = 0; i <= degree1; i++)
        {

                printf("%d * (x^%d)", polynomial1[i], i); //(polynomial[i] * x ) ^ i

                if (i != degree1)
                {
                        printf(" + ");
                }
                else
                {
                        printf(" \n");
                }
        }

        printf("\npolynomial 2 is\n");
        for (int i = 0; i <= degree2; i++)
        {
                printf("%d * (x^%d)", polynomial2[i], i); //(polynomial[i] * x ) ^ i

                if (i != degree2)
                {
                        printf(" + ");
                }
                else
                {
                        printf(" \n");
                }
        }

        printf("\nSum of the 2 polynomials is\n");
        for (int i = 0; i <= max_degree; i++)
        {
                printf("%d * (x^%d)", polynomial_sum[i], i); //(polynomial[i] * x ) ^ i
                if (i != max_degree)
                {
                        printf(" + ");
                }
                else
                {
                        printf(" \n");
                }
        }
}
