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
int main(int argc, char *argv[]){
    
    // User inputted argument variables and d
    float a, b, c;
    float x1, x2;
    

    // Checks to ensure there are exactly 3 
    // arguments inputted from command line
    if (argc != 4)  
    { 
        fprintf(stderr, "Error: Incorrect number of arguments. ");
        fprintf(stderr, "Please enter 3 numbers as arguments"); 
        fprintf(stderr, " (programName arg1 arg2 arg3).\n");
        return 0; 
    } 

    // Converts string to floating point and assigns to variable
    // validInput 0 (true) | 1 (false)
    int validInput = 0;

    if(sscanf(argv[1], "%f", &a) != 1){
        fprintf(stderr, "Error: %s must be a valid number.\n", argv[1]);
        validInput = 1;
    }
    if(sscanf(argv[2], "%f", &b) != 1){
        fprintf(stderr, "Error: %s must be a valid number.\n", argv[2]);
        validInput = 1;
    }
    if(sscanf(argv[3], "%f", &c) != 1){
        fprintf(stderr, "Error: %s must be a valid number.\n", argv[3]);
        validInput = 1;
    }
    if(validInput == 1){return 0;}

    float array[] = {a, b, c};

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

    float x1PlugIn = a*pow(x1, 2) + b*x1 + c;
    float x2PlugIn = a*pow(x2, 2) + b*x2 + c;

    printf("%f, %f\n", x1, x2);

    if (x1PlugIn >= 0.000001 || x1PlugIn <= -0.000001)
	printf("x1 error: %f\n", x1PlugIn);
    if (x2PlugIn >= 0.000001 || x2PlugIn <= -0.000001)
	printf("x2 error: %f\n", x2PlugIn);

    return 0;

}
