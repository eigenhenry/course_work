#include <stdio.h>
/*
This program uses pointers to swap values. 
Date: 09-28-22
Author: Henry Salgado
*/

void swap(int *, int *);

int main()
{
    int a = 1;
    int b = 2;

    printf("before swap a = %d\n", a);
    printf("before swap b = %d\n", b);
    swap(&a, &b);
    printf("after swap a = %d\n", a);
    printf("after swap b = %d\n", b);

    return 0;
}

// function to swap
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
