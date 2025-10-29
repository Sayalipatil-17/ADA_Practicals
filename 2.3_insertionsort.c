#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void generateRandomArray(int arr[], int n) {
for (int i = 0; i < n; i++) {
arr[i] = rand() % 100;
}
}
void insertionSort(int *A , int n ){
int key ;
for(int i = 0 ; i< n ; i++){
key = A[i];
int j = i-1;
while(A[j]< key){
A[j+1] = A[j];
j--;
}
A[j+1] = key ;
}
}
int main() {
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);

int *arr = (int *)malloc(n * sizeof(int));
if (arr == NULL) {
printf("Memory allocation failed\n");
return 1;
}
srand(time(NULL));
clock_t start = clock();
for (int i = 0; i < 1000; i++) {
generateRandomArray(arr, n);
insertionSort(arr, n);
}
clock_t end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;
printf("Average time to sort %d elements using Insertion Sort: %f seconds\n", n,
time_taken);
free(arr);
return 0;
}
