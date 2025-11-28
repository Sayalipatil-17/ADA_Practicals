#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int array[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (array[mid] == target) {
            return mid;
        } 
        else if (array[mid] < target) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    return -1;
}

void generate_random_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

int main() {

    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input\n");
        return 1;
    }

    int* array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand((unsigned int)time(NULL));

    generate_random_array(array, n);

    // Sort the array because binary search requires sorted input
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    int target;
    printf("Enter element to search: ");
    scanf("%d", &target);   // <-- FIXED missing semicolon

    clock_t start = clock();

    int result = -1;
    for (int i = 0; i < 1000000; i++) {   // 10 lakh iterations
        result = binary_search(array, n, target);
    }

    clock_t end = clock();

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found\n");
    }

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for 1,000,000 searches: %f seconds\n", time_taken);

    free(array);
    return 0;
}
