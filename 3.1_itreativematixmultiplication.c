#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void multiplyMatrices(int **A, int **B, int **C, int size) {
for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
C[i][j] = 0;
for (int k = 0; k < size; k++) {
C[i][j] += A[i][k] * B[k][j];
}
}
}
}
int **allocateMatrix(int size) {
int **matrix = (int **)malloc(size * sizeof(int *));
for (int i = 0; i < size; i++)
matrix[i] = (int *)malloc(size * sizeof(int));
return matrix;
}
void initializeMatrix(int **matrix, int size) {
for (int i = 0; i < size; i++)
for (int j = 0; j < size; j++)
matrix[i][j] = rand() % 10;
}
void freeMatrix(int **matrix, int size) {
for (int i = 0; i < size; i++)
free(matrix[i]);
free(matrix);
}

int main() {
int sizes[] = {100, 200, 300, 400, 500};
int numSizes = sizeof(sizes) / sizeof(sizes[0]);
printf("Matrix Size\tExecution Time (seconds)\n");
for (int s = 0; s < numSizes; s++) {
int size = sizes[s];
int **A = allocateMatrix(size);
int **B = allocateMatrix(size);
int **C = allocateMatrix(size);
initializeMatrix(A, size);
initializeMatrix(B, size);
clock_t start = clock();
multiplyMatrices(A, B, C, size);
clock_t end = clock();
double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
printf("%d x %d\t\t%.4f\n", size, size, time_taken);
freeMatrix(A, size);
freeMatrix(B, size);
freeMatrix(C, size);
}
return 0;
}
