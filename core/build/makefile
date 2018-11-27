bin_PROGRAMS = quadSolver
quadSolver_SOURCES = quadSolver.c

CFLAGS = -Wall -pedantic -std=c99
CC = gcc
LIBS = -lm

quadSolver: quadSolver.o quadSolverRoots.o quadSolverSqrt.o ../src/logging/logger.o
	${CC} -o quadSolver quadSolver.o quadSolverRoots.o quadSolverSqrt.o ../src/logging/logger.o ${LIBS}

all: quadSolver test log

test: t1 t2
	testing/t1
	testing/t2

t1: testing/t1.o quadSolverRoots.o quadSolverSqrt.o testing/cunit.o
	${CC} -o testing/t1 testing/t1.o quadSolverRoots.o quadSolverSqrt.o testing/cunit.o ${LIBS}

t2: testing/t2.o quadSolverRoots.o testing/cunit.o testing/mockQuadSolverSqrt.o
	${CC} -o testing/t2 testing/t2.o quadSolverRoots.o testing/cunit.o testing/mockQuadSolverSqrt.o ${LIBS}

log: ../src/logging/logger.o quadSolver.o quadSolverRoots.o quadSolverSqrt.o
	${CC} -o ../src/logging/logger ../src/logging/logger.o quadSolver.o quadSolverRoots.o quadSolverSqrt.o ${LIBS}
	../src/logging/logger

use:
	./quadSolver < testing/in.txt > testing/out.txt
	diff testing/out.txt testing/expectedOut.txt
	./quadSolver < testing/in2.txt > testing/out2.txt
	diff testing/out2.txt testing/expectedOut2.txt

clean-all: clean clean-test clean-log

clean:
	-rm -f ${EXES} core *.log *.o *.exe quadSolver *.tar

clean-test:
	-rm -f ${EXES} core testing/*.log testing/*.o testing/*.exe \
	testing/t1 testing/t2 *.tar

clean-log:
	-rm -f ${EXES} core ../src/logging/*.log ../src/logging/*.o ../src/logging/*.exe \
	../src/logging/logger *.tar ../src/log.txt

PREFIX = /usr/local

.PHONY: install
install: quadSolver
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp $< ${DESTDIR}${PREFIX}/bin/quadSolver

.PHONY: uninstall
uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/quadSolver

#Dependencies

quadSolverSqrt.o: quadSolverSqrt.h
quadSolverRoots.o: quadSolverRoots.h quadSolverSqrt.h
quadSolver.o: quadSolverRoots.h
testing/mockQuadSolverSqrt.o: testing/mockQuadSolverSqrt.h quadSolverSqrt.h
testing/cunit.o: testing/cunit.h
../src/logging/logger.o: ../src/logging/logger.h
