CFLAGS = -Wall -pedantic -std=c99
CC = gcc
LIBS = -lm

quadSolver: quadSolver.o quadSolverRoots.o quadSolverSqrt.o
	${CC} -o quadSolver quadSolver.o quadSolverRoots.o quadSolverSqrt.o ${LIBS}

use:
	./quadSolver 1 -3 -10
	./quadSolver 1 -5 -6
	./quadSolver 1 7 6
	./quadSolver t3 g 5
	./quadSolver 2 4 
	./quadSolver
	./quadSolver 32 4 1

clean:
	-rm -f ${EXES} core *.log *.o *.exe quadSolver *.tar

#Dependencies

quadSolverSqrt.o: quadSolverSqrt.h
quadSolverRoots.o: quadSolverRoots.h quadSolverSqrt.h
quadSolver.o: quadSolverRoots.h
