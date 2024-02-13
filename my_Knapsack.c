#include <stdio.h>
#define MAX_ITEMS 5
#define MAX_WEIGHT 20

// Function to find the maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// The knapsack function that returns the maximum value that fits into the knapsack
// and updates selected_bool array to indicate which items are included (1) or not included (0)
int knapSack(int weights[], int values[], int selected_bool[]) {
    int i, w;
    int K[MAX_ITEMS + 1][MAX_WEIGHT + 1];

    // Build table K[][] in bottom-up manner
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

    // Store the result of Knapsack
    int result = K[MAX_ITEMS][MAX_WEIGHT];
    w = MAX_WEIGHT;

    // Reset selected_bool array
    for (i = 0; i < MAX_ITEMS; i++)
        selected_bool[i] = 0;

    for (i = MAX_ITEMS; i > 0 && result > 0; i--) {
        if (result == K[i - 1][w])
            continue;
        else {
            // This item is included.
            selected_bool[i - 1] = 1;

            // Since this weight is included, its value is deducted
            result = result - values[i - 1];
            w = w - weights[i - 1];
        }
    }

    return K[MAX_ITEMS][MAX_WEIGHT];
}

int main() {
    int weights[MAX_ITEMS], values[MAX_ITEMS], selected_bool[MAX_ITEMS];
    char items[MAX_ITEMS] = {'A', 'B', 'C', 'D', 'E'};
    int i;

    printf("Enter the weights and values of the items:\n");
    for (i = 0; i < MAX_ITEMS; i++) {
        printf("Item %c:\n", items[i]);
        printf("Weight: ");
        scanf("%d", &weights[i]);
        printf("Value: ");
        scanf("%d", &values[i]);
    }

    int maxProfit = knapSack(weights, values, selected_bool);
    
    printf("Maximum profit: %d\nItems that give the maximum profit: [", maxProfit);
    int isFirst = 1; // To control the comma printing
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (selected_bool[i]) {
            if (!isFirst) {
                printf(", ");
            }
            printf("%c", items[i]);
            isFirst = 0; // After printing the first item, set it to 0
        }
    }
    printf("]\n");

    return 0;
}
