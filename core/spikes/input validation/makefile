all:
	gcc -Wall -Wpedantic -std=c99 -g inputValidation.c -o inputValidation -lm

use:
	./inputValidation 1 -3 -10
	./inputValidation 1 7 6
	./inputValidation 1 2 t
	./inputValidation TR342 7.444444444444 fa
	./inputValidation 1 7 6..5555555555
	./inputValidation 7fasf 6..5555555555 ^
	./inputValidation 1 2 3 4

