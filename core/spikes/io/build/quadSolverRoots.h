// struct for coefficient holding
typedef struct {
  double	a;
  double	b;
  double	c;
} Coef;

// quadSolverRoots prototype
int quadSolverRoots(Coef *input, double *x1, double *x2);
