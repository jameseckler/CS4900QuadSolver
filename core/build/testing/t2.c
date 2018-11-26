#include <stdio.h>
#include <stdlib.h>
#include "cunit.h"
#include "mockQuadSolverSqrt.h"
#include "../quadSolverRoots.h"

int main() {

	double a, b, c, aScratch, bScratch, cScratch;
	double x1, x2, x1Scratch, x2Scratch;
	int ret;
	int count;
	double x;
	char str[100];
	double d;
	double sqrtd;


	printf("Running T2 driver.\n");

	cunit_init();

	x1Scratch = 3.1;
	x2Scratch = 3.3;
	a = aScratch = 1.0;
	b = bScratch = -x1Scratch - x2Scratch;
	c = cScratch = x1Scratch * x2Scratch;

	d = b*b - 4.0*a*c;
	sqrtd = sqrt(d);

	mockSetupQuadSolverSqrt(d, sqrtd, cunit_dmacheps*2.0*d);

	double arr[] = {a, b, c};

	ret = quadSolverRoots(arr, &x1, &x2);

	double g = 2.0*cunit_dmacheps*3.3;

	//printf("Rerr: %.40f\n", g);
	printf("x1,x2: %f %f\n", x1Scratch,x2Scratch);
	
	assert_eq("ret", ret, 0);
	assert_feqrerr("x1", x1, x2Scratch, 2.0*cunit_dmacheps*3.3);
	assert_feqrerr("x2", x2, x1Scratch, 2.0*cunit_dmacheps*3.1);

	ret = mockCheckQuadSolverSqrt(&count, &x);
	snprintf(str, 99, "count ret = %d x = %20.61e", count, x);
	assert_eq(str, ret, 1);

	exit(0);

}
