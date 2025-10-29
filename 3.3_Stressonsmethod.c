#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Allocate a square matrix of given size
int **allocateMatrix(int size) {
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
        matrix[i] = (int *)calloc(size, sizeof(int));
    return matrix;
}

// Free a square matrix
void freeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++)
        free(matrix[i]);
    free(matrix);
}

// Add two matrices
void addMatrix(int **A, int **B, int **Result, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            Result[i][j] = A[i][j] + B[i][j];
}

// Subtract two matrices
void subtractMatrix(int **A, int **B, int **Result, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            Result[i][j] = A[i][j] - B[i][j];
}

// Strassen's matrix multiplication
void strassenMultiply(int **A, int **B, int **C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    int **A11 = allocateMatrix(newSize), **A12 = allocateMatrix(newSize);
    int **A21 = allocateMatrix(newSize), **A22 = allocateMatrix(newSize);
    int **B11 = allocateMatrix(newSize), **B12 = allocateMatrix(newSize);
    int **B21 = allocateMatrix(newSize), **B22 = allocateMatrix(newSize);
    int **M1 = allocateMatrix(newSize), **M2 = allocateMatrix(newSize);
    int **M3 = allocateMatrix(newSize), **M4 = allocateMatrix(newSize);
    int **M5 = allocateMatrix(newSize), **M6 = allocateMatrix(newSize);
    int **M7 = allocateMatrix(newSize);
    int **tempA = allocateMatrix(newSize), **tempB = allocateMatrix(newSize);

    // Divide matrices into quadrants
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Compute M1 to M7
    addMatrix(A11, A22, tempA, newSize);
    addMatrix(B11, B22, tempB, newSize);
    strassenMultiply(tempA, tempB, M1, newSize);

    addMatrix(A21, A22, tempA, newSize);
    strassenMultiply(tempA, B11, M2, newSize);

    subtractMatrix(B12, B22, tempB, newSize);
    strassenMultiply(A11, tempB, M3, newSize);

    subtractMatrix(B21, B11, tempB, newSize);
    strassenMultiply(A22, tempB, M4, newSize);

    addMatrix(A11, A12, tempA, newSize);
    strassenMultiply(tempA, B22, M5, newSize);

    subtractMatrix(A21, A11, tempA, newSize);
    addMatrix(B11, B12, tempB, newSize);
    strassenMultiply(tempA, tempB, M6, newSize);

    subtractMatrix(A12, A22, tempA, newSize);
    addMatrix(B21, B22, tempB, newSize);
    strassenMultiply(tempA, tempB, M7, newSize);

    // Combine results into C
    int **C11 = allocateMatrix(newSize), **C12 = allocateMatrix(newSize);
    int **C21 = allocateMatrix(newSize), **C22 = allocateMatrix(newSize);

    addMatrix(M1, M4, tempA, newSize);
    subtractMatrix(tempA, M5, tempB, newSize);
    addMatrix(tempB, M7, C11, newSize);

    addMatrix(M3, M5, C12, newSize);
    addMatrix(M2, M4, C21, newSize);

    subtractMatrix(M1, M2, tempA, newSize);
    addMatrix(tempA, M3, tempB, newSize);
    addMatrix(tempB, M6, C22, newSize);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    // Free all allocated submatrices
    int **matrices[] = {
        A11, A12, A21, A22, B11, B12, B21, B22,
        M1, M2, M3, M4, M5, M6, M7,
        C11, C12, C21, C22, tempA, tempB
    };
    for (int i = 0; i < 21; i++)
        freeMatrix(matrices[i], newSize);
}

// Initialize matrix with random values
void initializeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = rand() % 10;
}

int main() {
    srand(time(NULL)); // Seed for randomness
    int sizes[] = {64, 128, 256};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("Matrix Size\tExecution Time (seconds)\n");

    for (int s = 0; s < numSizes; s++) {
        int size = sizes[s];

        // Optional: warn if size is not power of 2
        if (size & (size - 1)) {
            printf("Warning: Size %d is not a power of 2.\n", size);
        }

        int **A = allocateMatrix(size);
        int **B = allocateMatrix(size);
        int **C = allocateMatrix(size);

        initializeMatrix(A, size);
        initializeMatrix(B, size);

        clock_t start = clock();
        strassenMultiply(A, B, C, size);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d x %d\t\t%.4f\n", size, size, time_taken);

        freeMatrix(A, size);
        freeMatrix(B, size);
        freeMatrix(C, size);
    }

    return 0;
}