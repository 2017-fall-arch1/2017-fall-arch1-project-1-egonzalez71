
CFLAGS=-g -O3

BTreeTest:BTree.o BTreeTest.o
	cc BTree.o BTreeTest.o -o test

BTree.o:BTree.c BTree.h
	cc -c $(CFLAGS) BTree.c

BTreeTest.o:BTreeTest.c BTree.h
	cc -c $(CFLAGS) BTreeTest.c

clean:
	rm -f *.o BTreeTest

demo: test
	./test
