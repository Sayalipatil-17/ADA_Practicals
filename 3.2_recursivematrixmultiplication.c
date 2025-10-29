#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int **allocateMatrix(int size) {
int **matrix = (int **)malloc(size * sizeof(int *));
for (int i = 0; i < size; i++)
matrix[i] = (int *)calloc(size, sizeof(int));
return matrix;
}
void addMatrix(int **A, int **B, int **Result, int size) {
for (int i = 0; i < size; i++)
for (int j = 0; j < size; j++)
Result[i][j] = A[i][j] + B[i][j];
}
void subtractMatrix(int **A, int **B, int **Result, int size) {

for (int i = 0; i < size; i++)
for (int j = 0; j < size; j++)
Result[i][j] = A[i][j] - B[i][j];
}
void multiplyRecursive(int **A, int **B, int **C, int size) {
if (size == 1) {
C[0][0] = A[0][0] * B[0][0];
return;
}
int newSize = size / 2;
int **A11 = allocateMatrix(newSize);
int **A12 = allocateMatrix(newSize);
int **A21 = allocateMatrix(newSize);
int **A22 = allocateMatrix(newSize);
int **B11 = allocateMatrix(newSize); int
**B12 = allocateMatrix(newSize); int
**B21 = allocateMatrix(newSize); int
**B22 = allocateMatrix(newSize); int
**C11 = allocateMatrix(newSize); int
**C12 = allocateMatrix(newSize); int
**C21 = allocateMatrix(newSize); int
**C22 = allocateMatrix(newSize); int
**temp1 = allocateMatrix(newSize);
int **temp2 = allocateMatrix(newSize);
for (int i = 0; i < newSize; i++) {
for (int j = 0; j < newSize; j++) {
A11[i][j] = A[i][j];
A12[i][j] = A[i][j + newSize];
A21[i][j] = A[i + newSize][j];
A22[i][j] = A[i + newSize][j + newSize];
B11[i][j] = B[i][j];
B12[i][j] = B[i][j + newSize];
B21[i][j] = B[i + newSize][j];
B22[i][j] = B[i + newSize][j + newSize]; }
}
multiplyRecursive(A11, B11, temp1, newSize);

multiplyRecursive(A12, B21, temp2, newSize);
addMatrix(temp1, temp2, C11, newSize);
multiplyRecursive(A11, B12, temp1, newSize);
multiplyRecursive(A12, B22, temp2, newSize);
addMatrix(temp1, temp2, C12, newSize);
multiplyRecursive(A21, B11, temp1, newSize);
multiplyRecursive(A22, B21, temp2, newSize);
addMatrix(temp1, temp2, C21, newSize);
multiplyRecursive(A21, B12, temp1, newSize);
multiplyRecursive(A22, B22, temp2, newSize);
addMatrix(temp1, temp2, C22, newSize);
for (int i = 0; i < newSize; i++) {
for (int j = 0; j < newSize; j++) {
C[i][j] = C11[i][j];
C[i][j + newSize] = C12[i][j];
C[i + newSize][j] = C21[i][j];
C[i + newSize][j + newSize] = C22[i][j];
}
}
int **matrices[] =
{A11,A12,A21,A22,B11,B12,B21,B22,C11,C12,C21,C22,temp1,temp2}
; for (int i = 0; i < 14; i++)
for (int j = 0; j < newSize; j++)
free(matrices[i][j]);
for (int i = 0; i < 14; i++)
free(matrices[i]);
}
void initializeMatrix(int **matrix, int size) {
for (int i = 0; i < size; i++)
for (int j = 0; j < size; j++)
matrix[i][j] = rand() % 10;
}
int main() {
int sizes[] = {64, 128, 256};
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
multiplyRecursive(A, B, C, size);
clock_t end = clock();
double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
printf("%d x %d\t\t%.4f\n", size, size, time_taken);
for (int i = 0; i < size; i++) {
free(A[i]); free(B[i]); free(C[i]);
}
free(A); free(B); free(C);
}
return 0;
}
