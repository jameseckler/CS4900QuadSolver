CFLAGS = -Wall -pedantic -std=c99
CC = gcc
LIBS = -lm

quadSolver: quadSolver.o quadSolverRoots.o quadSolverSqrt.o
	${CC} -o quadSolver quadSolver.o quadSolverRoots.o quadSolverSqrt.o ${LIBS}

all: quadSolver test

test: t1 t2

t1: testing/t1.o quadSolverRoots.o quadSolverSqrt.o cunit/cunit.o
	${CC} -o testing/t1 testing/t1.o quadSolverRoots.o quadSolverSqrt.o cunit/cunit.o ${LIBS}

t2: testing/t2.o quadSolverRoots.o cunit/cunit.o testing/mockQuadSolverSqrt.o
	${CC} -o testing/t2 testing/t2.o quadSolverRoots.o quadSolverSqrt.o cunit/cunit.o testing/mockQuadSolverSqrt.o ${LIBS}

use:
	./quadSolver 1 -3 -10
	./quadSolver 1 -5 -6
	./quadSolver 1 7 6
	./quadSolver t3 g 5
	./quadSolver 2 4 
	./quadSolver
	./quadSolver 32 4 1

clean-all: clean clean-test

clean:
	-rm -f ${EXES} core *.log *.o *.exe quadSolver *.tar

clean-test:
	-rm -f ${EXES} core testing/*.log testing/*.o testing/*.exe \
	testing/t1 testing/t2 *.tar

#Dependencies

quadSolverSqrt.o: quadSolverSqrt.h
quadSolverRoots.o: quadSolverRoots.h quadSolverSqrt.h
quadSolver.o: quadSolverRoots.h
testing/mockQuadSolverSqrt.o: testing/mockQuadSolverSqrt.h quadSolverSqrt.h
cunit/cunit.o: cunit/cunit.h
