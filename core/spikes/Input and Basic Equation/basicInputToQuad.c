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
	float bSquared, aMult, aDoubled;
	float sqrtResult;
	float x1, x2;


	// Checks to ensure there are exactly 3 
	// arguments inputted from command line
	if (argc < 3 || argc > 4)  
	{ 
		printf("Error: Incorrect number of arguments. ");
	    printf("Please enter 3 numbers as arguments (programName arg1 arg2 arg3).\n"); 
	    return 0; 
	} 

	// Converts string to floating point and assigns to variable
    a = atof(argv[1]);  
    b = atof(argv[2]); 
    c = atof(argv[3]); 

    //printf("%f, %f, %f\n", a, b, c);

    bSquared = b * b;
    //printf("%f\n", bSquared);
    aMult = 4 * a * c;
    //printf("%f\n", aMult);
    aDoubled = 2 * a;
    //printf("%f\n", aDoubled);

    sqrtResult = bSquared - aMult;
    //printf("%f\n", sqResult);
    sqrtResult = sqrtf(sqrtResult);
    //printf("%f\n", sqResult);

    x1 = ((-1 * b) - (sqrtResult)) / aDoubled;
    x2 = ((-1 * b) + (sqrtResult)) / aDoubled;

    printf("%f, %f\n", x1, x2);




	return 0;

}