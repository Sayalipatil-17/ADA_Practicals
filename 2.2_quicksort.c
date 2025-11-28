//quick sort
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Partition function
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = (low + 1);
    int j = high;

        do {
            while (i <= high && arr[i] <= pivot) {
                i++;
            }
    
            while (arr[j] > pivot){
                j--;
            }
    
            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        } while (i < j);
    
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
    
        return j;
    }


// QuickSort function
void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void generateRandomArray(int arr[],int size){
    for(int i=0; i<size; i++){
        arr[i]=rand()%100;
    }
}


// Main function to test the QuickSort implementation
int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);

    int *arr=(int*)malloc(n*sizeof(int));
    int *temp=(int*)malloc(n*sizeof(int));
    if (arr == NULL || temp == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    generateRandomArray(arr, n);

    double total_time = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < n; j++) {
            temp[j] = arr[j];

        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();

        total_time += ((double)(end - start)) / CLOCKS_PER_SEC;
    }

    printf("Average time to sort %d elements over 1000 runs: %f seconds\n", n, total_time / 1000.0);

    free(arr);
    free(temp);

    return 0;
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}
}

