#include <stdio.h>
#include <stdlib.h>
int main()
{
    double number;

    FILE *in_file = fopen("array-data.txt", "r"); // only open a pre - exisiting file in←-read mode .

    if (!in_file) // equivalent to saying if ( in_file == NULL )
    {
        printf("oops , file can 't be read \n");
        exit(-1);
    }

    // attempt to read the next line and store
    // the value in the " number " variable

    double my_array[100];
    int i = 0;

    while (fscanf(in_file, "%lf", &number) == 1)
    {
        printf("We just read % lf\n", number);
        my_array[i] = number;
        i++;
    }

    for (i = 0; i < 10; i++)
    {
        printf("my_array[%d] = %lf \n", i, my_array[i]);
    }
}