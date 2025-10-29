#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Allocate a square matrix
int** allocate_matrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    return matrix;
}

// Free a square matrix
void free_matrix(int n, int** matrix) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Standard matrix multiplication
void matrix_mul(int n, int** A, int** B, int** C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Matrix addition
void addMatrix(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Matrix subtraction
void subtract_matrix(int n, int** A, int** B, int** C) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Divide & Conquer matrix multiplication
void matrixmul(int** A, int** B, int** C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    if (n == 2) {
        C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
        return;
    }

    int newSize = n / 2;
    int** A11 = allocate_matrix(newSize);
    int** A12 = allocate_matrix(newSize);
    int** A21 = allocate_matrix(newSize);
    int** A22 = allocate_matrix(newSize);
    int** B11 = allocate_matrix(newSize);
    int** B12 = allocate_matrix(newSize);
    int** B21 = allocate_matrix(newSize);
    int** B22 = allocate_matrix(newSize);
    int** C11 = allocate_matrix(newSize);
    int** C12 = allocate_matrix(newSize);
    int** C21 = allocate_matrix(newSize);
    int** C22 = allocate_matrix(newSize);
    int** temp1 = allocate_matrix(newSize);

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

    matrixmul(A11, B11, C11, newSize);
    matrixmul(A12, B21, temp1, newSize);
    addMatrix(C11, temp1, C11, newSize);

    matrixmul(A11, B12, C12, newSize);
    matrixmul(A12, B22, temp1, newSize);
    addMatrix(C12, temp1, C12, newSize);

    matrixmul(A21, B11, C21, newSize);
    matrixmul(A22, B21, temp1, newSize);
    addMatrix(C21, temp1, C21, newSize);

    matrixmul(A21, B12, C22, newSize);
    matrixmul(A22, B22, temp1, newSize);
    addMatrix(C22, temp1, C22, newSize);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    free_matrix(newSize, A11); free_matrix(newSize, A12);
    free_matrix(newSize, A21); free_matrix(newSize, A22);
    free_matrix(newSize, B11); free_matrix(newSize, B12);
    free_matrix(newSize, B21); free_matrix(newSize, B22);
    free_matrix(newSize, C11); free_matrix(newSize, C12);
    free_matrix(newSize, C21); free_matrix(newSize, C22);
    free_matrix(newSize, temp1);
}

// Strassen's matrix multiplication
void strassen(int n, int** A, int** B, int** C) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int new_n = n / 2;
    int **A11 = allocate_matrix(new_n), **A12 = allocate_matrix(new_n);
    int **A21 = allocate_matrix(new_n), **A22 = allocate_matrix(new_n);
    int **B11 = allocate_matrix(new_n), **B12 = allocate_matrix(new_n);
    int **B21 = allocate_matrix(new_n), **B22 = allocate_matrix(new_n);
    int **C11 = allocate_matrix(new_n), **C12 = allocate_matrix(new_n);
    int **C21 = allocate_matrix(new_n), **C22 = allocate_matrix(new_n);
    int **P1 = allocate_matrix(new_n), **P2 = allocate_matrix(new_n);
    int **P3 = allocate_matrix(new_n), **P4 = allocate_matrix(new_n);
    int **P5 = allocate_matrix(new_n), **P6 = allocate_matrix(new_n);
    int **P7 = allocate_matrix(new_n), **temp1 = allocate_matrix(new_n);
    int **temp2 = allocate_matrix(new_n);

    for (int i = 0; i < new_n; i++) {
        for (int j = 0; j < new_n; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + new_n];
            A21[i][j] = A[i + new_n][j];
            A22[i][j] = A[i + new_n][j + new_n];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + new_n];
            B21[i][j] = B[i + new_n][j];
            B22[i][j] = B[i + new_n][j + new_n];
        }
    }

    subtract_matrix(new_n, B12, B22, temp1);
    strassen(new_n, A11, temp1, P1);

    addMatrix(A11, A12, temp1, new_n);
    strassen(new_n, temp1, B22, P2);

    addMatrix(A21, A22, temp1, new_n);
    strassen(new_n, temp1, B11, P3);

    subtract_matrix(new_n, B21, B11, temp1);
    strassen(new_n, A22, temp1, P4);

    addMatrix(A11, A22, temp1, new_n);
    addMatrix(B11, B22, temp2, new_n);
    strassen(new_n, temp1, temp2, P5);

    subtract_matrix(new_n, A12, A22, temp1);
    addMatrix(B21, B22, temp2, new_n);
    strassen(new_n, temp1, temp2, P6);

    subtract_matrix(new_n, A11, A21, temp1);                    