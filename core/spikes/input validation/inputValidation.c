#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <math.h>

/*
Joshua Peterson
CS 4900
10/20/2018
Quadratic Equation Solver
*/

/*
	Spike to test basic cmd line input into a basic quadratic
	equation.
*/

int main(int argc, char *argv[]){
    
	float a, b, c;
    
	// Checks to ensure there are exactly 3 
	// arguments inputted from command line
	if (argc != 4)  
	{ 
		printf("Error: Incorrect number of arguments. ");
	    printf("Please enter 3 numbers as arguments (programName arg1 arg2 arg3).\n"); 
	    return 0; 
	} 

	// Converts string to floating point and assigns to variable
    // validInput 0 (true) | 1 (false)
    int validInput = 0;

    if(sscanf(argv[1], "%f", &a) != 1){
        printf("%s must be a valid number.\n", argv[1]);
        validInput = 1;
    }
    if(sscanf(argv[2], "%f", &b) != 1){
        printf("%s must be a valid number.\n", argv[2]);
        validInput = 1;
    }
    if(sscanf(argv[3], "%f", &c) != 1){
        printf("%s must be a valid number.\n", argv[3]);
        validInput = 1;
    }
    if(validInput == 1){return 0;}

    float array[] = {a, b, c};

    // Checks for normalized input
    for(int i = 0; i < 3; i++){
        if(isnormal(array[i]) == 0){
            printf("Error: %f is not a normalized number\n", array[i]);
        }else if(isnan(array[i]) != 0){
            printf("Error: %f is not a number\n", array[i]);
        }else if(isinf(array[i]) != 0){
            printf("Error: %f is infinity\n", array[i]);
        }
    }

    printf("%f\n", a);
    printf("%f\n", b);
    printf("%f\n", c);

	return 0;

}
