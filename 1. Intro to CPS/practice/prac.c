/*  

 
 

Author: Henry Salgado 

Date: 11/09/22 

The following program is an implemetattion of Jacobi Method.  

It takes in number of variables, matrix values per row and produces solution. 

Assume matrix is diagonally dominant.*/

#include <stdio.h>

#include <math.h>

#include <stdlib.h>

int main()

{

    float a[10][10], b[10], x[10], xn[10], ae, max, t, s, e;

    int n, i, j, r, mxit;

    // Receive input of # variables, matrix values, and b

    printf("Enter the number of variables: \n ");

    scanf("%d", &n);

    printf("Enter the coefficients row-wise of matrix A:\n ");

    for (i = 0; i < n; i++)

        for (j = 0; j < n; j++)

            scanf("%f", &a[i][j]);

    printf("Enter the b vector \n");

    for (i = 0; i < n; i++)

        scanf("%f", &b[i]);

    for (i = 0; i < n; i++)

        x[i] = 0; //initialize x values to zeros

    printf(" Enter the allowed error and maximum number of iteration: ");

    scanf("%f%d", &ae, &mxit);

    printf("Iteration\tx[1]\tx[2]\n");

    for (r = 1; r <= mxit; r++)

    {

        max = 0;

        for (i = 0; i < n; i++)

        {

            s = 0;

            for (i = 0; i < n; i++)
            {
                s = b[i];
                for (j = 0; j < n; j++)
                {
                    if (j != i)
                    {
                        s -= a[i][j] * x[j];
                        xn[i] = s / a[i][i];
                    }
                }
            }

            t = (b[i] - s) / a[i][i];

            e = fabs(x[i] - t);

            x[i] = t;
        }

        printf(" %5d\t", r);

        for (i = 0; i < n; i++)

            printf(" %9.4f\t", x[i]);

        printf("\n");

        if (max < ae)

        {

            printf(" Converges in %3d iteration\n", r);

            for (i = 0; i < n; i++)

                printf("a[%3d]=%7.4f\n", i + 1, x[i]);

            return 0;
        }
    }
}