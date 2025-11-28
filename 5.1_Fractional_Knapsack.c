#include <stdio.h>

// Function to calculate max value using Fractional Knapsack
float fractionalKnapsack(int n, int capacity, int value[], int weight[]) {
    float ratio[n];

    // Step 1: Calculate value/weight ratio
    for (int i = 0; i < n; i++) {
        ratio[i] = (float)value[i] / weight[i];
    }

    // Step 2: Sort items by ratio (descending order)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {

                // Swap ratio
                float tempR = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempR;

                // Swap value
                int tempV = value[i];
                value[i] = value[j];
                value[j] = tempV;

                // Swap weight
                int tempW = weight[i];
                weight[i] = weight[j];
                weight[j] = tempW;
            }
        }
    }

    // Step 3: Greedy selection
    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            totalValue += value[i];
            capacity -= weight[i];
        } 
        else {
            // take fractional part
            totalValue += ratio[i] * capacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int value[n], weight[n], capacity;

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &value[i]);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    float maxValue = fractionalKnapsack(n, capacity, value, weight);

    printf("Maximum value = %.2f\n", maxValue);

    return 0;
}
