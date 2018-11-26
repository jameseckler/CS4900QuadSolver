/*
Purpose: Takes square root of a double
Input: Double x to have square root performed on
Output: Square root of double x
*/

#include <math.h>
#include "quadSolverSqrt.h"

double quadSolverSqrt(double x) {

	if (x < 0) {
		return -1.0;
	}

	return sqrt(x);
}
