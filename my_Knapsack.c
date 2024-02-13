#include <stdio.h>
#define MAX_ITEMS 5
#define MAX_WEIGHT 20

// Function to find the maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// The knapsack function
int knapSack(int weights[], int values[], int selected_bool[]) {
    int i, w;
    int K[MAX_ITEMS + 1][MAX_WEIGHT + 1];

    for (i = 0; i <= MAX_ITEMS; i++) {
        for (w = 0; w <= MAX_WEIGHT; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    int result = K[MAX_ITEMS][MAX_WEIGHT];
    w = MAX_WEIGHT;
    for (i = 0; i < MAX_ITEMS; i++) selected_bool[i] = 0;
for (i = MAX_ITEMS - 1; i >= 0 && result > 0; i--) {
    if (result != K[i][w]) {
        selected_bool[i] = 1;
        result -= values[i];
        w -= weights[i];
    }
}


    return K[MAX_ITEMS][MAX_WEIGHT];
}

int main() {
    char items[MAX_ITEMS];
    int weights[MAX_ITEMS], values[MAX_ITEMS], selected_bool[MAX_ITEMS];
    int i;


    for (i = 0; i < MAX_ITEMS; i++) {
        // To consume any newline or space before the character
        scanf(" %c", &items[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }

    int maxProfit = knapSack(weights, values, selected_bool);


printf("Maximum profit: %d\nSelected items:", maxProfit);

for (i = 0; i < MAX_ITEMS; i++) {
    if (selected_bool[i]) {
        printf(" %c", items[i]); // Print the item
    }
}

    return 0;
}
