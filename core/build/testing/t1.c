#include <stdlib.h>
#include "../cunit/cunit.h"
#include "../quadSolverRoots.h"

int main() {
	float x1 = 3.1f;
	float x1Copy;
	float x2 = 3.3f;
	float x2Copy;
	float a = 1.0f;
	float b = -x1 - x2;
	float c = x1*x2;
	float arr[] = {a, b, c};
	int ret;

	cunit_init();

	ret = quadSolverRoots(arr, &x1Copy, &x2Copy);

	assert_eq("ret", ret, 0);
	assert_feqrerr("x1", x1Copy, x2, 10.0*cunit_dmacheps);
	assert_feqrerr("x2", x2Copy, x1, 10.0*cunit_dmacheps);

	exit(0);
}
