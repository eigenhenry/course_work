#include <stdio.h>
#include <math.h>
/*
This program executes the newton method on specified function. 
Date: 09-28-22
Author: Henry Salgado
*/

// initializing f(x) and f'(x)
float f(float);
float derivative(float);

int main()
{
    // Approximation
    float(x);
    //Iterations
    float n;
    int i = 1;

    //ERROR CALC
    float error;
    float y;
    y = f(x);

    //User input
    printf("Enter initial x0: ");
    scanf("%f", &x);

    printf("Enter number of iterations: ");
    scanf("%f", &n);

    printf("Enter error tolerance : ");
    scanf("%f", &error);

    // Perform while n is less than iterations or until error tolerance is reached
    while (i <= n || fabsf(y) > error)
    {
        x = x - f(x) / derivative(x);
        i++;
    }
    printf("Approximate root %f \n", x);
    //printf("Finished at iteration \n", i);
    return 0;
}

//Functions were hardcoded

float f(float x)
{
    return ((x * x * x * x * x * x) - x - 1);
}

float derivative(float x)
{
    return ((6 * pow(x, 5)) - 1);
}