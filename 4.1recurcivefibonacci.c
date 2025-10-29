
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int fib_recursive(int n) {
if (n == 0) return 0;
if (n == 1) return 1;
return fib_recursive(n - 1) + fib_recursive(n - 2);
}
int main() {
int n, key, result;
clock_t start, stop;
double time_taken;
printf("Enter the size");
if (scanf("%d", &n) != 1 || n <= 0) {
printf("Invalid input. Please enter a positive integer.\n");
return 1;
}
int *Array = (int *)malloc(n * sizeof(int));
if (Array == NULL) {
printf("Memory allocation failed.\n");
return 1;
}
key = n;
srand(time(NULL));
start = clock();
for (int i = 0; i < 1000; i++) {
result = fib_recursive(key);
}
stop = clock();
time_taken = ((double)(stop - start)) / CLOCKS_PER_SEC;
if (result != -1) {
printf("Element %d found at index %d.\n", key, result);
} else {
printf("Element %d not found.\n", key);
}
printf("Time taken for 1000 searches: %.6f seconds\n", time_taken);
free(Array);
return 0;
}