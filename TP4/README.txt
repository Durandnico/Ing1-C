1 - Compilation
	
	-Dans le terminal :
	 	"make all" ou "make"
	  OU
	  	gcc -c ApproximationDeSqrt2.c -Wall -Wextra
		gcc -c ApproximationDePi.c -Wall -Wextra -lm
		gcc -c main.c -Wall -Wextra -lm
		gcc main.o ApproximationDePi.o ApproximationDeSqrt2.o -o Main -lm
		

2 - Lancer le programme
	
	-Dans le terminal
		./Main 

3 - Doxygen
	
	Genérer le doxygen:
	-Dans le terminal
		Doxygen DoxyFile
	  OU
		make doc


	Pour ouvrir le doxygen :
	-Dans le terminal
		firefox html/index.html

