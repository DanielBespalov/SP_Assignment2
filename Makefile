CC=gcc
FLAGS= -Wall -g

# Target to build the final executable
all: my_Knapsack

# Rule to link the my_Knapsack program
my_Knapsack: my_Knapsack.o
	$(CC) $(FLAGS) my_Knapsack.o -o my_Knapsack

# Rule to compile the my_Knapsack source file
my_Knapsack.o: my_Knapsack.c
	$(CC) $(FLAGS) -c my_Knapsack.c

# Phony target for clean
.PHONY: clean
clean:
	rm -f *.o my_Knapsack
