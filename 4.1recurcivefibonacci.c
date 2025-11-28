#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fib_recursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int main() {
    int n, result;
    clock_t start, stop;
    double time_taken;

    printf("Enter the Fibonacci term (n): ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    // Time recursive Fibonacci 1000 times
    start = clock();

    for (int i = 0; i < 1000; i++) {
        result = fib_recursive(n);
    }

    stop = clock();

    time_taken = ((double)(stop - start)) / CLOCKS_PER_SEC;

    printf("Fibonacci(%d) = %d\n", n, result);
    printf("Time taken for 1000 recursive calls: %.6f seconds\n", time_taken);

    return 0;
}
