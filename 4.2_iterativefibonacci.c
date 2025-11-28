#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Iterative Fibonacci function
int fib_iterative(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n, key, result;
    clock_t start, stop;
    double time_taken;

    printf("Enter the value of n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // Key = n (Fibonacci of n)
    key = n;

    // Measure time of 1000 Fibonacci computations
    start = clock();
    for (int i = 0; i < 1000; i++) {
        result = fib_iterative(key);
    }
    stop = clock();

    time_taken = (double)(stop - start) / CLOCKS_PER_SEC;

    // Print result of Fibonacci
    printf("Fibonacci(%d) = %d\n", key, result);
    printf("Time taken for 1000 computations: %.6f seconds\n", time_taken);

    return 0;
}
