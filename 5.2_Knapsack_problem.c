#include <stdio.h>

// 0/1 Knapsack implementation using Dynamic Programming
int zeroOneKnapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = (val[i-1] + dp[i-1][w - wt[i-1]] > dp[i-1][w])
                            ? val[i-1] + dp[i-1][w - wt[i-1]]
                            : dp[i-1][w];
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    int maxValue = zeroOneKnapsack(W, wt, val, n);
    printf("Maximum value in 0/1 Knapsack = %d\n", maxValue);

    return 0;
}