/* 

Student: Henry Salgado
Date: 10/27/22
The following program is an implemetattion of Jacobi method using openmp parallel programming. 
Assume matrix is diagonally dominant.*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define EPSILON 0.001
#include <omp.h> //OpenMP header.

int n;
int flag;

//This method prints the value of Unknowns
void print(int iter, float values[n])
{
    printf("Iteration %d ", iter);
    for (int i = 0; i < n; i++)
        printf("value[%d]=%f ", i + 1, values[i]);
    printf("\n");
}

void jacobi(float a[][n + 1], int maxIterations, float old_x[n])
{
    int i, j, k, iteration;
    float sum = 0;
    float x_new[n];
    for (iteration = 1; iteration <= maxIterations; iteration++)
    {
        for (i = 0; i < n; i++)
        {
            sum = 0;
            for (j = 0; j < n; j++)
            {
                if (i != j)
                    sum += a[i][j] * old_x[j];
            }
            x_new[i] = (a[i][n] - sum) / a[i][i];
        }

        //Let's check to see if we meet error
        for (k = 0; k < n; k++)
        {
            if (fabs(old_x[k] - x_new[k]) < EPSILON)
            {
                continue;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            // print final values
            print(iteration, x_new);
            return;
        }
        flag = 0;

        print(iteration, x_new); //Printing intermediate values of unknowns

        //copy new values of unknowns to old value array
        for (k = 0; k < n; k++)
            old_x[k] = x_new[k];

    } //end of iteration loop
    print(iteration, x_new);

} //end of findValues()

int main()
{
    int i, j, k, x, y, maxIter;
    float ratio;
    printf("Enter the number of Unknowns\n");
    scanf("%d", &n);
    printf("Enter the number of iterations\n");
    scanf("%d", &maxIter);
    float a[n][n + 1];
    float values[n];

    printf("Enter the Augmented Matrix A\n");
    printf("\n");

#pragma omp for

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
            scanf("%f", &a[i][j]);
    }
    printf("Matrix was inputed by thread %d. \n", omp_get_thread_num());
    printf("\n");

    printf("Results\n");
#pragma omp for
    for (int i = 0; i < n; i++)
        values[i] = 0;
    jacobi(a, maxIter, values);
    printf("Results calcultaed by thread %d. \n", omp_get_thread_num());
    return 0;
}