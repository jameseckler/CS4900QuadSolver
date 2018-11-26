#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <math.h>
#include "quadSolverRoots.h"

/*
Joshua Peterson and James Eckler
CS 4900
11/18/2018
Quadratic Equation Solver
*/

/*
    Primary build for Quadratic Equation Solver
*/

/* 
    Main driver for taking command line input as 
    floating point values and inserting them into a
    quadratic equation to solve with single precision.
*/

int validate(char *in, double *a, double *b, double *c);

int main(int argc, char *argv[]){
    
    // User inputted argument variables
    double a, b, c;
    double x1, x2;
    
    printf("Input values for a, b, and c separated by spaces: ");

    char *in = malloc(sizeof(char)*100);

    fgets(in, 100, stdin);

    // Exits program if input is not valid
    if (validate(in, &a, &b, &c) != 0) {
	fprintf(stderr, "Invalid input: Exiting...\n");
	exit(1);
    }

    free(in);

    double array[] = {a, b, c};

    // Checks for normalized input, nans, and infs
    for(int i = 0; i < 3; i++){
        if(isnormal(array[i]) == 0){
            fprintf(stderr, "Error: %f is not a normalized number\n"
                , array[i]);
            return 0;
        }else if(isnan(array[i]) != 0){
            fprintf(stderr, "Error: %f is not a number\n", array[i]);
            return 0;
        }else if(isinf(array[i]) != 0){
            fprintf(stderr, "Error: %f is infinity\n", array[i]);
            return 0;
        }
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
        return 1;
    }

    return 0;
}
