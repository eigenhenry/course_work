
/* 

Author: Henry Salgado
Date: 10/27/22
The following program generates the coefficient matrix specified
with respect to a uniform grid */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int k = 3;
    int matrix_size = k * k;
    double A[matrix_size][matrix_size];
    int i, j;

    for (i = 0; i < matrix_size; i++)
    {
        for (j = 0; j < matrix_size; j++)
        {
            if (i == j)
                A[i][j] = 4.0;

            else if ((abs(i - j) == 1 && (i / k == j / k)) || abs(i - j) == k)
            {
                A[i][j] = -1.0;
            } //else-if
            else
                A[i][j] = 0.0;
            printf("A[%d][%d]= %lf \n", i, j, A[i][j]);
        }
    }
}
