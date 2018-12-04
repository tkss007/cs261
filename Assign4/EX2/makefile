all: Iterative Recursive

Iterative: bst.o compare.o bstMain.o
	gcc -g -Wall -std=c99 -o Iterative bst.o compare.o bstMain.o

Recursive: bstRecur.o compare.o bstMain.o
	gcc -g -Wall -std=c99 -o Recursive bstRecur.o compare.o bstMain.o

compare.o: compare.c
	gcc -g -Wall -std=c99 -c compare.c 
		
bst.o: bst.c bst.h
	gcc -g -Wall -std=c99 -c bst.c bst.h

bstRecur.o: bstRecur.c bstRecur.h
	gcc -g -Wall -std=c99 -c bstRecur.c bstRecur.h

bstMain.o: bstMain.c
	gcc -g -Wall -std=c99 -c bstMain.c

clean:	
	rm bst.o
	rm compare.o
	rm prog
