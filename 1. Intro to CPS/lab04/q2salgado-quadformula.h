#include <stdio.h>
#include <math.h>

/*
This program is a header file that takes in a,b,c and computes discriminant, denominator, and roots of a,b,c,.  
Date: 09-30-22
Author: Henry Salgado
*/

float disc(int a, int b, int c)
{
    float discriminant;
    discriminant = sqrt(b * b - 4 * a * c);
    return (discriminant);
}

float deno(int a, int b, int c)
{
    float denominator;
    denominator = 2 * a;
    return (denominator);
}

float root_1(int a, int b, int c)
{

    float root1;

    root1 = -b / (2 * a) + disc(a, b, c) / (2 * a);

    return (root1);
}

float root_2(int a, int b, int c)
{

    float root2;

    root2 = -b / (2 * a) - disc(a, b, c) / (2 * a);
    return (root2);
}