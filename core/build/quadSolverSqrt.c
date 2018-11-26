#include <math.h>
#include "quadSolverSqrt.h"

double quadSolverSqrt(double x) {

	if (x < 0) {
		return -1.0;
	}

	return sqrt(x);
}
