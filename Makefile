CC=gcc
FLAGS= -Wall -g

all: connections
connections: my_graph.o my_mat.o
	$(CC) $(FLAGS) my_graph.o my_mat.o -o connections
my_graph.o: my_graph.c
	$(CC) $(FLAGS) -c my_graph.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c my_mat.h

.PHONY: clean
clean:
	rm -f *.o *.a *.so connections
