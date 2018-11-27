#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <math.h>
#include "../../build/quadSolverSqrt.h"
#include "../../build/quadSolverRoots.h"

/*
Joshua Peterson and James Eckler
CS 4900
11/18/2018
Absolute/Relative Error Spike
*/

int validate(char *in, double *a, double *b, double *c);

int main(int argc, char *argv[]){
    
    // User inputted argument variables
    double a, b, c;
    double x1, x2;
    int success = 0;
    double array[3];

    while(success == 0){
        printf("\n****************************************************\n");
        printf("* Input values for a, b, and c separated by spaces *\n");
        printf("****************************************************\n");
        printf("> ");

        char *in = malloc(sizeof(char)*100);

        success = 1;

        fgets(in, 100, stdin);

        // Exits program if input is not valid
        if (validate(in, &a, &b, &c) != 0) {
    	   fprintf(stderr, "\n\n***Invalid input, enter 3 valid numbers separated by spaces***\n\n");
           success = 0;
        }

        array[0] = a; array[1] = b; array[2] = c;

        // Checks for normalized input, nans, and infs
            for(int i = 0; i < 3; i++){
                if(isnormal(array[i]) == 0){
                    fprintf(stderr, "Error: Argument %d of input: %s is not a normalized number\n"
                        , i+1, in);
                    //LOG_PRINT("User input contains a denormalized number. Arguments: %s", in);
                    success = 0;
                }else if(isnan(array[i]) != 0){
                    fprintf(stderr, "Error: Argument %d of input: %s is not a number\n", i+1, in);
                    //LOG_PRINT("User input contains a nan. Arguments: %s", in);
                    success = 0;
                }else if(isinf(array[i]) != 0){
                    fprintf(stderr, "Error: Argument %d of input: %s is infinity\n", i+1, in);
                    //LOG_PRINT("User input contains infinity. Arguments: %s", in);
                    success = 0;
                }
            }

        free(in);
        printf("\n");


    }

    quadSolverRoots(array, &x1, &x2);

    double x1PlugIn = a*pow(x1, 2) + b*x1 + c;
    double x2PlugIn = a*pow(x2, 2) + b*x2 + c;

    printf("%f, %f\n", x1, x2);

    if (x1PlugIn >= 0.000001 || x1PlugIn <= -0.000001)
	fprintf(stderr, "x1 error: %f\n", x1PlugIn);
    if (x2PlugIn >= 0.000001 || x2PlugIn <= -0.000001)
	fprintf(stderr, "x2 error: %f\n", x2PlugIn);

    return 0;

}

int validate(char *in, double *a, double *b, double *c) {

    char ch;

    if (sscanf(in, "%lf %lf %lf%c", a, b, c, &ch) != 4) {
        //LOG_PRINT("Initial user input error. Arguments: %s", in);
        return 1;
    }

    return 0;
}
