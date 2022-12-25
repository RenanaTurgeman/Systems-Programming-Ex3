CC = gcc
AR = ar 
FLAGS = -Wall -g
OBJECCTS_MAIN = main.o 
OBJECTS_SORT = isort.o

all: isort libisort.a

isort: $(OBJECCTS_MAIN) libisort.a
	$(CC) $(FLAGS) -o isort $(OBJECCTS_MAIN) libisort.a -lm

libisort.a: $(OBJECTS_SORT)
	$(AR) -rsc libisort.a $(OBJECTS_SORT)

main.o: main.c isort.h
	$(CC) $(FLAGS) -c main.c

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so isort