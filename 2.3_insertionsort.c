#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int LinearSearch(int Array[], int n, int key) {
for (int i = 0; i < n; i++) {
if (Array[i] == key) {
return i;
}
}
return -1;
}
int main() {
int n, key, result;
clock_t start, stop;
double time_taken;
printf("Enter the size of the array: ");
if (scanf("%d", &n) != 1 || n <= 0) {
printf("Invalid input. Please enter a positive integer.\n");
return 1;
}
int *Array = (int *)malloc(n * sizeof(int));
if (Array == NULL) {
printf("Memory allocation failed.\n");
return 1;
}
for (int i = 0; i < n; i++) {
Array[i] = i + 1;
}

key = n;
srand(time(NULL));
start = clock();
for (int i = 0; i < 1000; i++) {
result = LinearSearch(Array, n, key);
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
