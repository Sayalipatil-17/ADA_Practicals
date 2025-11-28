#include <stdio.h>

int knapSack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {

            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (wt[i - 1] <= j)
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt(i-1)],dp[i-1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}

int main() {
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n], W;

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int maxValue = knapSack(W, wt, val, n);

    printf("Maximum value = %d\n", maxValue);

    return 0;
}
