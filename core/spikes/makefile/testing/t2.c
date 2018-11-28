#include <stdio.h>
#include <stdlib.h>
#include "cunit.h"
#include "mockQuadSolverSqrt.h"
#include "../quadSolverRoots.h"
#include "../../src/logging/logger.h"

int main() {

	double aScratch, bScratch, cScratch;
	double x1, x2, x1Scratch, x2Scratch;
	int ret;
	int count;
	double x;
	char str[100];
	double d;
	double sqrtd;
	Coef input;

	cunit_init();

	x1Scratch = 3.1;
	x2Scratch = 3.3;
	input.a = aScratch = 1.0;
	input.b = bScratch = -x1Scratch - x2Scratch;
	input.c = cScratch = x1Scratch * x2Scratch;

	d = input.b*input.b - 4.0*input.a*input.c;
	sqrtd = sqrt(d);

	mockSetupQuadSolverSqrt(d, sqrtd, cunit_dmacheps*2.0*d);

	ret = quadSolverRoots(&input, &x1, &x2);
	
	assert_eq("ret", ret, 0);
	assert_feqrerr("x1", x1, x2Scratch, 2.0*cunit_dmacheps*3.3);
	assert_feqrerr("x2", x2, x1Scratch, 2.0*cunit_dmacheps*3.1);

	ret = mockCheckQuadSolverSqrt(&count, &x);
	snprintf(str, 99, "count ret = %d x = %20.61e", count, x);
	assert_eq(str, ret, 1);

	exit(0);

}
