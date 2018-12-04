all: calc testda

calc: dynamicArray.o calc.o
	gcc -g -Wall -std=c99 -o calc dynamicArray.o calc.o -lm

testda: dynamicArray.o testDynArray.o
	gcc -g -Wall -std=c99 -o testda dynamicArray.o testDynArray.o

calc.o: calc.c dynamicArray.h
	gcc -g -Wall -std=c99 -c calc.c

testDynArray.o: testDynArray.c dynamicArray.h
	gcc -g -Wall -std=c99 -c testDynArray.c

dynamicArray.o: dynamicArray.c dynamicArray.h 
	gcc -g -Wall -std=c99 -c dynamicArray.c	

test:testda calc
	#./testda
	#testing calc......
	#*************************basic test**********************
	#4+5=9
	@./calc 4 5 +
	#4-5=-1
	@./calc 4 5 -
	#4/5=0.8
	@./calc 4 5 /
	#4*5=20
	@./calc 4 5 x
	#4^5=1024
	@./calc 4 5 ^
	#4^2=16
	@./calc 4 ^2 
	#4^3=64
	@./calc 4 ^3
	#abs(-4.1)=4.1
	@./calc -4.1 abs
	#sqrt(16)=4
	@./calc 16 sqrt
	#exp(2)=7.389
	@./calc 2 exp
	#ln(7.389)=2
	@./calc 7.389 ln
	#log(100)=2
	@./calc 100 log
	#*************************custom test**********************
	#ln(e)=1
	@./calc e ln





clean:
	rm dynamicArray.o
	rm calc.o
	rm testDynArray.o
	rm calc
	rm testda
