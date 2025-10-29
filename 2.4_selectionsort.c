#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void generateRandomArray(int arr[], int n) {
for (int i = 0; i < n; i++) {
arr[i] = rand() % 100;
}
}
void selectionsort(int*A, int n){
int indexofmin ;
for(int i = 0 ; i< n ; i++){
indexofmin = i;
for(int j = 0 ; j< n; j++){
if(A[indexofmin]> A[j])
indexofmin = j;
}
// swap index of index of min with i
int temp = A[indexofmin];
A[indexofmin] = A[i];
A[i] = temp ;
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
selectionsort(arr, n);
}
clock_t end = clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;
printf("Average time to sort %d elements using Selection Sort: %f seconds\n", n,
time_taken);
free(arr);
return 0;
}
