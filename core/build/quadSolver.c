#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <math.h>
#include "quadSolverRoots.h"
#include "../src/logging/logger.h"

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

    Takes in stdin from cmdline as input for three variables.
    Outputs roots of Quadratic Equation in stdout.
*/

//MAXLINE is the max size of legal input
#define MAXLINE 100

//X Line is a structure for passing a line of text
typedef struct {
  int   max;   // size of str array
  char  *str;  // pointer to array of max bytes
}  Line;

// Prototype for validate
int validate(Line *linein, Coef* input);


// Main function for driving interface
// Returns 0 on success
int main(int argc, char *argv[]){
    
    //Placeholder for roots
    double x1, x2;
    // 0 if not validated, 1 if validated
    int validated = 0;
    // 0 if not normal, 1 if normal number
    int success = 0;
    // Array for holding coefficients for normalized number check
    double array[3];
    // Structs for holding linein and the entered coefficients
    Line linein;
    Coef input;

    // Sets maxline for stdin and allocates memory for it
    linein.max = MAXLINE;
    if( (linein.str = malloc(MAXLINE)) == NULL)  {
      fprintf(stderr,"Systems failure no memory for malloc(%d)\n", MAXLINE);
      LOG_PRINT("System failure, could not allocate 100 bytes for input.");
      exit(1); 
    }

    printf("\n****************************************************\n");
    printf("*                                                  *\n");
    printf("*               Quadratic Solver                   *\n");
    printf("*                                                  *\n");

    while(1){

        while(success == 0){
            // Success until fail
            success = 1;

            while(validated == 0){

                printf("****************************************************\n");
                printf("* Input values for a, b, and c separated by spaces *\n");
                printf("*             Type 'quit' to quit program          *\n");
                printf("****************************************************\n");
                printf("> ");

                // Validated until invalidated
                validated = 1;

                // Takes in stdinput and checks if received
                if(fgets(linein.str, linein.max, stdin) == NULL) {
                   printf("%s", linein.str);
                   fprintf(stderr,"Input error: cannot read from stdin\n");
                   LOG_PRINT("Input cannot be read from stdin: %s", linein.str);
                }

                // Utility for quitting program
                if( strncmp(linein.str, "quit", 4) == 0){
                    LOG_PRINT("User manually exited program with %s", linein.str);
                    exit(0);
                }

                // Invalidates and loops around if input is not validate
                // Takes stdin char * linein and the three coefficients 
                // in struct input
                if (validate(&linein, &input) != 0) {
            	   fprintf(stderr, "\n\n\n***Invalid input, "
                    "enter 3 valid numbers separated by spaces***\n\n\n\n");
                   LOG_PRINT("User input could not be validated: %s", linein.str);
                   validated = 0;
                }
            }
            
            // Assigns array for looping normalised, nan, inf check
            array[0] = input.a; array[1] = input.b; array[2] = input.c;

            // Checks for normalized input, nans, and infs
                for(int i = 0; i < 3; i++){
                    if(isnormal(array[i]) == 0){
                        fprintf(stderr, "Error: Argument %d of "
                            "input: %s is not a normalized number\n"
                            , i+1, linein.str);
                        LOG_PRINT("Input contains denormalized number: %s", linein.str);
                        success = 0;
                    }else if(isnan(array[i]) != 0){
                        fprintf(stderr, "Error: Argument %d of "
                            "input: %s is not a number\n", i+1, linein.str);
                        LOG_PRINT("Input contains a nan: %s", linein.str);
                        success = 0;
                    }else if(isinf(array[i]) != 0){
                        fprintf(stderr, "Error: Argument %d of "
                            "input: %s is infinity\n", i+1, linein.str);
                        LOG_PRINT("Input contains infinity: %s", linein.str);
                        success = 0;
                    }
                }
            
            printf("\n");
        }
    
    // Sends coefficients struct input and two root holders x1 and x2
    // to solver equation and prints roots if non-complex numbers
    if( (quadSolverRoots(&input, &x1, &x2)) != -1){
        printf("Coefficients: %f %f %f\n", input.a,input.b,input.c);
        printf("Roots (x1, x2): %f, %f\n", x1, x2);
    }

    // Error checking for roots
    double x1PlugIn = input.a*pow(x1, 2) + input.b*x1 + input.c;
    double x2PlugIn = input.a*pow(x2, 2) + input.b*x2 + input.c;


    // Checks for precision
    if (x1PlugIn >= 0.000001 || x1PlugIn <= -0.000001){
	   fprintf(stderr, "\nx1 error: %f\n", x1PlugIn);
       LOG_PRINT("x1 error: %f, with input: %s", x1PlugIn, linein.str);
    }
    if (x2PlugIn >= 0.000001 || x2PlugIn <= -0.000001){
	   fprintf(stderr, "x2 error: %f\n\n", x2PlugIn);
       LOG_PRINT("x2 error: %f, with input: %s", x2PlugIn, linein.str);
    }

    printf("\n\n\n");
    success = 0;
    validated = 0;


    }

    free(linein.str);

    return 0;

}

// Validates the input to make sure it's 3 doubles
// Takes Line struct linein and Coef struct input
// Returns 1 if invalid, 0 if success
int validate(Line *linein, Coef *input) {
    double a,b,c;
    char ch;
    char d[100];
    char e[100];

    if (sscanf(linein->str, "%lf %lf %lf%c", &a, &b, &c, &ch) != 4) {

        LOG_PRINT("Initial user input error. Arguments: %s", linein->str);

        // Repeat scans to ensure all variables get read for error checking
        sscanf(linein->str, "%s %lf %lf%c", d, &b, &c, &ch);
        sscanf(linein->str, "%s %s %lf%c", d, e, &c, &ch);

        input->a = a;
        input->b = b;
        input->c = c;

        return 1;
    }

    input->a = a;
    input->b = b;
    input->c = c;

    return 0;
}
