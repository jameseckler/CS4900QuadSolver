#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
James Eckler
CS 4900
11/18/2018
IEEE-fp Spike
*/

int main(int argc, char *argv[]){
    
    double a, b, c;

    sscanf(argv[1], "%lf", &a);
    sscanf(argv[2], "%lf", &b);
    sscanf(argv[3], "%lf", &c);

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

    return 0;

}
