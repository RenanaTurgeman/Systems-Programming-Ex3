CC = gcc
AR = ar 
FLAGS = -Wall -g
OBJECCTS_MAIN = main.o 
OBJECCTS_MAIN2 = main2.o 
OBJECTS_SORT = isort.o
OBJECTS_TXT = txtfind.o

all: isort libisort.a txtfind libtxt.a

isort: $(OBJECCTS_MAIN) libisort.a
	$(CC) $(FLAGS) -o isort $(OBJECCTS_MAIN) libisort.a -lm

txtfind: $(OBJECCTS_MAIN2) libtxt.a
	$(CC) $(FLAGS) -o txtfind $(OBJECCTS_MAIN2) libtxt.a -lm

libisort.a: $(OBJECTS_SORT)
	$(AR) -rsc libisort.a $(OBJECTS_SORT)

libtxt.a: $(OBJECTS_TXT)
	$(AR) -rsc libtxt.a $(OBJECTS_TXT)

main.o: main.c isort.h
	$(CC) $(FLAGS) -c main.c

main2.o: main2.c txtfind.h
	$(CC) $(FLAGS) -c main2.c

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so isort txtfind