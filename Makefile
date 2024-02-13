.PHONY: clean

CC=gcc
FLAGS= -Wall -g

all: my_graph my_Knapsack
my_graph: my_graph.o my_mat.o
	$(CC) $(FLAGS) my_graph.o my_mat.o -o my_graph
my_graph.o: my_graph.c
	$(CC) $(FLAGS) -c my_graph.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c my_mat.h

my_Knapsack: my_Knapsack.o
	$(CC) $(FLAGS) my_Knapsack.o -o my_Knapsack

# Rule to compile the my_Knapsack source file
my_Knapsack.o: my_Knapsack.c
	$(CC) $(FLAGS) -c my_Knapsack.c



clean:
	rm -f *.o *.a *.so my_graph my_Knapsack
