/*
Mock object for testing quadSolverSqrt function
*/

#include <math.h>
#include "mockQuadSolverSqrt.h"
#include "../quadSolverSqrt.h"

static double x = -1.0; // Argument passed to quadSolverSqrt()
static double ex = -1.0; // Expected argument to quadSolverSqrt()
static double eps = -1.0; // Absolute error allowed in x
static double sqrtx = -1.0; // Result to return from quadSolverSqrt(), sqrt(x)
static int count = 0; // Count of calls made to quadSolverSqrt()
static int flag = -1;

/*
Sets up mock object for use
Input:
	double lx - Argument to be passed to quadSolverSqrt
	double lsqrtx - Result to be returned from quadSolverSqrt; sqrt(x)
	double leps - Absolute error allowed in x
*/
void mockSetupQuadSolverSqrt(double lx, double lsqrtx, double leps) {

	ex = x;
	eps = leps;
	sqrtx = lsqrtx;
	count = 0;
	flag = 0;

}

/*

*/
double getQuadSolverSqrt(double lx) {
	if(fabs(ex - lx) > eps) {
		flag = 1;
	}
	x = lx;
	count++;
	return sqrtx;
}

int mockCheckQuadSolverSqrt(int *lcount, double*lx) {
	
	int ret;
	*lcount = count;
	*lx = x;

	if ((flag == 0) && (count == 1))
		ret = 0;
	else
		ret = 1;
	
	return ret;

}

void mockTeardownQuadSolverSqrt() {

	x = -1.0;
	ex = -1.0;
	eps = -1.0;
	sqrtx = -1.0;
	count = 0;
	flag = -1;
	return;

}
