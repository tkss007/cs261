default: prog


clean:
	-rm *.o
	-rm testLinkedList
	-rm linkedListMain
	-rm prog
#***********************cirListDeque**************************
cirListDeque.o: cirListDeque.c cirListDeque.h
	gcc -Wall -g -std=c99 -c cirListDeque.c	

testCirListDeque.o: cirListDeque.h testCirListDeque.c
	gcc -Wall -g -std=c99 -c testCirListDeque.c

prog: cirListDeque.o testCirListDeque.o
	gcc -Wall -g -std=c99 -o prog cirListDeque.o testCirListDeque.o
		
#***********************Linkedlist****************************
linkedList.o: linkedList.c linkedList.h
	gcc -Wall -g -std=c99 -c linkedList.c
linkedListMain.o: linkedList.h linkedListMain.c
	gcc -Wall -g -std=c99 -c linkedListMain.c
#testLinkedList.o: linkedList.h testLinkedList.c
#	gcc -Wall -g -std=c99 -c testLinkedList.c

testLinkedList: testLinkedList.o linkedList.o
	gcc -Wall -g -std=c99 -o testLinkedList linkedList.o testLinkedList.c

linkedListMain: linkedListMain.o linkedList.o
	gcc -Wall -g -std=c99 -o linkedListMain linkedList.o linkedListMain.o

linkedListMainRM: linkedList.o
	gcc -Wall -g -std=c99 -o linkedListMainRM linkedList.o linkedListMainRM.c
#*********************dynamicArray****************************
dynamicArray.o: dynamicArray.c dynamicArray.h
	gcc -Wall -g -std=c99 -c dynamicArray.c
dynamicArrayMain:dynamicArray.o
	gcc -Wall -g -std=c99 -o dynamicArrayMain dynamicArray.o dynamicArrayMain.c
#************************test*********************************
test:test1 test2 test3
	echo success
test1:testLinkedList
	./testLinkedList
test2: linkedListMain linkedListMainRM dynamicArrayMain
	@-rm massif.out.*
	@-valgrind --tool=massif ./linkedListMain
	@-valgrind --tool=massif ./linkedListMainRM
	@-valgrind --tool=massif ./dynamicArrayMain
	for i in `ls massif.out.*`; do echo $i; ms_print $i> $i.dump ; done
test3:prog
	./prog