#include <stdio.h>
#include <math.h>

/*
This program takes in a,b,c and computes roots, it is the first attempt and does not include created header files.   
Date: 09-30-22
Author: Henry Salgado
*/

float a, b, c;

float root1, root2;
float numerator, denominator;
float discriminant;

int main()
{

    printf("Enter values of a \n");
    scanf("%f", &a);

    printf("Enter values of b \n");
    scanf("%f", &b);

    printf("Enter values of c \n");
    scanf("%f", &c);

    numerator = sqrt(b * b - 4 * a * c);
    denominator = 2 * a;
    discriminant = numerator;

    if (discriminant > 0)
    {
        printf("The quadratic has two distinct real number solutions.\n");
    }

    else if (discriminant < 0)
    {
        printf("The quadratic has repeated real number solution\n");
    }
    else if (discriminant == 0)
    {
        printf("The quadratic has neither of the solutions are real numbers.\n");
    }

    if (discriminant > 0 || discriminant == 0)
    {
        root1 = -b / (2 * a) + discriminant / (2 * a);
        root2 = -b / (2 * a) - discriminant / (2 * a);
    }

    printf("First root = %f\n", root1);
    printf("Second Root = %f\n", root2);

    return 0;
}