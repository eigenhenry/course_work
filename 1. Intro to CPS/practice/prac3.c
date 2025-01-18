#include <stdio.h>

int main()
{

    int x = 0;
    int *age;

    age = &x;

    printf("Age is");
    printf(age);
    printf("X is");
    printf(x);
}