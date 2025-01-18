#include <stdio.h>

/*
 * Author: Henry Salgado
 * Date: 10/14/22
 * This program determines the maximum value in an array
 * 
 */

int main()
{
    int n_array[9];
    int input;
    int max = 0;

    for (int i = 0; i < 9; i++)
    {
        printf("Enter number:\n");
        scanf("%d", &n_array[i]);
    }

    for (int i = 0; i < 9; i++)
    {
        if (n_array[i] > max)
        {
            max = n_array[i];
        }
    }

    printf("Overall Largest = %d \n", max);
}