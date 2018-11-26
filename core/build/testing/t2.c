#include <stdio.h>
#include <stdlib.h>
#include "../cunit/cunit.h"
#include "mockQuadSolverSqrt.h"
#include "../quadSolverRoots.h"

int main() {

	float a, b, c, aScratch, bScratch, cScratch;
	float x1, x2, x1Scratch, x2Scratch;
	int ret;
	int count;
	double x;
	char str[100];
	float d;
	float sqrtd;

	cunit_init();

	x1Scratch = 3.1f;
	x2Scratch = 3.3f;
	a = aScratch = 1.0f;
	b = bScratch = -x1 - x2;
	c = cScratch = x1 * x2;

	d = b*b - 4.0*a*c;
	sqrtd = sqrt(d);

	mockSetupQuadSolverSqrt(d, sqrtd, cunit_dmacheps*2.0*d);

	float arr[] = {a, b, c};

	ret = quadSolverRoots(arr, &x1, &x2);
	
	assert_eq("ret", ret, 0);
	assert_feqrerr("x1", x1, x2Scratch, 2.0*cunit_dmacheps*3.3);
	assert_feqrerr("x2", x2, x1Scratch, 2.0*cunit_dmacheps*3.1);

	ret = mockCheckQuadSolverSqrt(&count, &x);
	snprintf(str, 99, "count ret = %d x = %20.61e", count, x);
	assert_eq(str, ret, 1);

	exit(0);

}
