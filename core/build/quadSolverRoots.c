#include <stdio.h>
#include "quadSolverRoots.h"
#include "quadSolverSqrt.h"

int quadSolverRoots(float *coef, float *x1, float *x2) {

	float a = coef[0];
	float b = coef[1];
	float c = coef[2];

	float bSquared, aMult, aDoubled;
	float sqrtResult;
	float d = b * b - 4 * a * c;

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
