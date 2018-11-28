// Initialize to expect 1 call to quadSolverSqrt()
void mockSetupQuadSolverSqrt(double lx, double lsqrtx, double leps);

// Check results
int mockCheckQuadSolverSqrt(int *lcount, double *lx);

// Reset internal values to initial state
void mockTeardownQuadSolverSqrt();
