#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void generateRandomArray(int arr[], int n) {
for (int i = 0; i < n; i++) {
arr[i] = rand() % 100;
}
}
void bubblesort(int *A, int n){
int temp ;
for(int i = 0 ; i < n-1 ; i++ ){
for(int j = 0 ; j< n-i-1 ; j++){
if(A[j]<A[j]+1){
temp = A[i];
A[i] = A[j+1];
A[j+1] = temp ;
}
}
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
bubblesort(arr, n);
}
clock_t end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;
printf("Average time to sort %d elements using Bubble Sort: %f seconds\n", n,
time_taken);
free(arr);
return 0;
}
