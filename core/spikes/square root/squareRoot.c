/*
	James Eckler
	CS4900
	Quad Solver
*/

/*
	Spike to test accuracy of square root function
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){

	float x;

	// Input is not a number
	if (sscanf(argv[1], "%f", &x) != 1) {
		printf("Error: Input is not a number\n");

		return 0;
	}
	// Input is less than 0
	else if (x < 0) {
		printf("Error: Input is less than 0\n");
	
		return 0;
	}

	printf("%f\n", sqrtf(x));
	
	

	return 0;
}
