#include <stdlib.h>
#include "cunit.h"
#include "../quadSolverRoots.h"

int main() {
	double x1 = 3.1f;
	double x1Copy;
	double x2 = 3.3f;
	double x2Copy;
	double a = 1.0f;
	double b = -x1 - x2;
	double c = x1*x2;
	double arr[] = {a, b, c};
	int ret;

	cunit_init();

	ret = quadSolverRoots(arr, &x1Copy, &x2Copy);

	assert_eq("ret", ret, 0);
	assert_feqrerr("x1", x1Copy, x2, 10.0*cunit_dmacheps);
	assert_feqrerr("x2", x2Copy, x1, 10.0*cunit_dmacheps);

	exit(0);
}
