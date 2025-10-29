#include <stdio.h>
#include <stdlib.h>
typedef struct {
int value, weight;
float ratio;
} Item;
int compare(const void *a, const void *b) {
return ((Item *)b)->ratio > ((Item *)a)->ratio ? 1 : -1;
}
float fractionalKnapsack(Item items[], int n, int W) {
for (int i = 0; i < n; i++)
items[i].ratio = (float)items[i].value / items[i].weight;
qsort(items, n, sizeof(Item), compare);
float totalValue = 0.0;
for (int i = 0; i < n && W > 0; i++) {
if (items[i].weight <= W) {
W -= items[i].weight;
totalValue += items[i].value;
} else {
totalValue += items[i].ratio * W;
W = 0;
}
}
return totalValue;
}
int main() {
int n = 3, W = 50;

Item items[] = {
{60, 10}, {100, 20}, {120, 30}
};
float maxValue = fractionalKnapsack(items, n, W);
printf("Maximum value in Fractional Knapsack = %.2f\n", maxValue);
return 0;
}