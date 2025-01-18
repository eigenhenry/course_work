#include <stdio.h>
#include <stdlib.h> // needed for rand () // Part a

/*
 * Author: Henry Salgado
 * Date: 10/14/22
 * This program determines the maximum value in an array
 * (a) It introduces another library called stdlib.h.
*  (b) It generates an array of a user-defined length n.
*  (c) This program generates a random number by calling rand(), scales it and inputs this number in the
*    array.
*   The function rand() returns a random number of type int but we want to store entries of type
*   double. Hence, we enable this involving the function (double). This enables us to cast the variable
*   as a double instead.
*   (d) Next, this C program stores the entries of the array in a txt file called array-data.txt.
*   (e) It then seeks to calculate the largest entry of this array.
 * 
 */

int main()
{
    int loop, n;

    printf(" enter the number of randomly generated numbers : ");
    scanf("%d", &n);
    // Previous lines ask user to enter array lenght, that n value is passed to the array below
    //Part b)
    double x[n];

    for (int i = 0; i < n; ++i)
    {
        // rand () is a random number generator of type int .
        // This can be a large size int hence by multiplying
        // with 1e -6 , we ensure that the number is not too large .
        // Part C) The for loop iterates through the lenght of the array, the value of x[i] is set to random double value
        x[i] = (double)(rand()) * 1e-6;
        printf("x[%d] = %lf \n", i, x[i]);
    }
    // this creates a file array - data . txt to write into if the file exists ,
    // it will merely open the file to write into it .
    char *filename = "array-data.txt";

    // open the file for writing
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf(" Error opening the file %s", filename);
        return -1; //
    }

    // write to the text file
    for (int i = 0; i < n; i++)
    {
        // PART D: The for loop iterates through the array lenght and writes each value of the array to a text tile
        fprintf(fp, "%lf \n", x[i]);
        // fprintf (fp , " This is the line #%d\n", i + 1) ;
        // fprintf (fp , " This is the entry x[%d ]= % lf\n", i , x[i ]) ;
    }
    // close the file
    fclose(fp);

    double largest;
    largest = x[0];

    // Part E) The largest is set to the first item of the array, the for loop compares all values to this one, if largest is less than current iteration, then that value should be the new max;
    for (loop = 1; loop < n; loop++)
    {
        if (largest < x[loop])
        {
            largest = x[loop];
        } // if condition
        //printf("largest for loop = %d is: %lf \n", loop, largest);
    } // for - loop

    printf("Largest element of array is %lf \n", largest);
}
