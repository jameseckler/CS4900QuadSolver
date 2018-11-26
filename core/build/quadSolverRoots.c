/*
Purpose: Solves a quadratic equation for given input
Input: Float array coef with indices 0 = a, 1 = b, and 2 = c; pointers for x1 and x2 so they can be passed back to where the function was called from
Return: Integer referencing a specific error
*/

#include <stdio.h>
#include "quadSolverRoots.h"
#include "quadSolverSqrt.h"

int quadSolverRoots(double *coef, double *x1, double *x2) {

	double a = coef[0];
	double b = coef[1];
	double c = coef[2];

	double bSquared, aMult, aDoubled;
	double sqrtResult;
	double d = b * b - 4 * a * c;

	if(d < 0){
	        fprintf(stderr, "Roots are complex numbers.\n");
	        fprintf(stderr, "Roots of quadratic equation are: \n");
	        fprintf(stderr, "%.3f%+.3fi",-b/(2*a),quadSolverSqrt(-d)/(2*a));
	        fprintf(stderr, ", %.3f%+.3fi\n",-b/(2*a),-quadSolverSqrt(-d)/(2*a));

		return -1;
	}

	bSquared = b * b;

	aMult = 4 * a * c;

	aDoubled = 2 * a;


	sqrtResult = bSquared - aMult;

	sqrtResult = quadSolverSqrt(sqrtResult);

	*x1 = ((-1 * b) + (sqrtResult)) / aDoubled;
	*x2 = ((-1 * b) - (sqrtResult)) / aDoubled;

	return 0;

}
