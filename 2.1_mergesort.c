// mergesort with timing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int b[100];  // temporary array

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }

    while (i <= mid)
        b[k++] = arr[i++];

    while (j <= high)
        b[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = b[i];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    clock_t start, end;
    double time_taken;

    start = clock();

    mergeSort(arr, 0, n - 1);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:   ");
    printArray(arr, n);

    printf("Time taken by merge sort: %f seconds\n", time_taken);

    return 0;
}
