# makefile for Quad Solver
# James Eckler and Joshua Peterson
# CS4900 Fall 2018
# Quadratic Equation Solver Assignment
#
# quadSolver: Solver that takes in 3 coefficients to be computed into 
#	their roots through the quadratic equation
#
#   quadSolverSqrt.c    - wrapper mysqrt() for the math lib sqrt() function
#	quadSolverSqrt.h 	- THe prototypes for quadSolverSqrt.c
#   quadSolver.c 		- Contains interface and main function for running quadSolver
#   quadSolverRoots.h   - The prototypes for quadSolverRoots.c 
#   quadSolverRoots.c   - contains solver for quadratic function
#	
#
# t1                - first unit testing driver for qsolve() accounting for roundoff error
# t2                - second unit testing driver containing mockQuadSolverSqrt.c
# in.txt			- runs listed input cases through stdin and writes to out.txt
# in2.txt			- runs listed input cases through stdin and writes to out2.txt
# out.txt			- contains output of in.txt test cases
# out2.txt			- contains output of in2.txt test cases
# expectedOut.txt	- used to compare expected output with real output
# expectedOut2.txt	- used to compare expected output with real output
# 
# logging.c 		- contains code for simple logging system
# logging.h			- contains prototypes for logging system
#

bin_PROGRAMS = quadSolver
quadSolver_SOURCES = quadSolver.c

CFLAGS = -Wall -pedantic -std=c99
CC = gcc
LIBS = -lm

# Primary make, compiles and generates quadSolver object for executing
quadSolver: quadSolver.o quadSolverRoots.o quadSolverSqrt.o ../src/logging/logger.o
	${CC} -o quadSolver quadSolver.o quadSolverRoots.o quadSolverSqrt.o ../src/logging/logger.o ${LIBS}

all: quadSolver test log

# Compiles and runs tests
test: t1 t2
	testing/t1
	testing/t2

# Compiles and generates test 1
t1: testing/t1.o quadSolverRoots.o quadSolverSqrt.o testing/cunit.o ../src/logging/logger.o
	${CC} -o testing/t1 testing/t1.o quadSolverRoots.o quadSolverSqrt.o testing/cunit.o ../src/logging/logger.o ${LIBS}

# Compiles and generates test 2
t2: testing/t2.o quadSolverRoots.o testing/cunit.o testing/mockQuadSolverSqrt.o
	${CC} -o testing/t2 testing/t2.o quadSolverRoots.o testing/cunit.o testing/mockQuadSolverSqrt.o ../src/logging/logger.o ${LIBS}

# Runs log for debugging purposes
log: ../src/logging/logger.o quadSolver.o quadSolverRoots.o quadSolverSqrt.o
	${CC} -o ../src/logging/logger ../src/logging/logger.o quadSolver.o quadSolverRoots.o quadSolverSqrt.o ${LIBS}
	../src/logging/logger

# Creates tar file for core
tar:
	tar --exclude='quadSolver.tar.gz' -czvf quadSolver.tar.gz ../

use:
	./quadSolver < testing/in.txt > testing/out.txt
	diff testing/out.txt testing/expectedOut.txt
	./quadSolver < testing/in2.txt > testing/out2.txt
	diff testing/out2.txt testing/expectedOut2.txt

# Cleans all temp files and program objects
clean-all: clean clean-test clean-log

# Cleans program objects and temp files
clean:
	-rm -f ${EXES} core *.log *.o *.exe quadSolver *.tar

# Cleans test objects and temp files
clean-test:
	-rm -f ${EXES} core testing/*.log testing/*.o testing/*.exe \
	testing/t1 testing/t2 *.tar

# Cleans log files
clean-log:
	-rm -f ${EXES} core ../src/logging/*.log ../src/logging/*.o ../src/logging/*.exe \
	../src/logging/logger *.tar ../src/log.txt

# Installer
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
quadSolverRoots.o: quadSolverRoots.h quadSolverSqrt.h ../src/logging/logger.h
quadSolver.o: quadSolverRoots.h ../src/logging/logger.h
testing/mockQuadSolverSqrt.o: testing/mockQuadSolverSqrt.h quadSolverSqrt.h
testing/cunit.o: testing/cunit.h
../src/logging/logger.o: ../src/logging/logger.h
