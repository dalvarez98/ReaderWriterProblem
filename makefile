rwmain: main.o readerwriter.o
	gcc main.o readerwriter.o -l pthread -o rwmain

main.o: main.c
	gcc -c main.c

readerwriter.o: readerwriter.c readerwriter.h
	gcc -c readerwriter.c

clean:
	rm *.o rwmain