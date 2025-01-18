#include <stdio.h>

/*
This program provides an error message is printed to the screen 
if the user inputs a numeric grade which is not non-negative integer. 
Date: 09-28-22
Author: Henry Salgado
*/
int main()
{
	int numeric_grade = -10; //initializing the int variable.
	printf("Enter the numeric grade: ");
	scanf("%d", &numeric_grade);
	//& is the address of variable operator

	if (numeric_grade < 0)
	{
		printf("Error, this is a negative number \n");
	}

	else if (numeric_grade > 60)
	{
		printf("Congrats you have passed! \n");
	}
	else if (numeric_grade < 60)
	{
		printf("Sorry you have failed \n");
	}
	return 0;
}
