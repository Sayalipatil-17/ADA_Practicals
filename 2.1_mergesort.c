#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int l, int m, int r) {
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
int *L = (int *)malloc(n1 * sizeof(int));
int *R = (int *)malloc(n2 * sizeof(int));
for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++)
R[j] = arr[m + 1 + j];
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
arr[k++] = L[i++];
} else {
arr[k++] = R[j++];
}
}
while (i < n1) {

arr[k++] = L[i++];
}
while (j < n2) {
arr[k++] = R[j++];
}
free(L);
free(R);
}
void mergeSort(int arr[], int left, int right) {
if (left < right) {
int m = left + (right - left) / 2;
mergeSort(arr, left, m);
mergeSort(arr, m + 1, right);
merge(arr, left, m, right);
}
}
void generateRandomArray(int arr[], int n) {
for (int i = 0; i < n; i++) {
arr[i] = rand() % 100;
}
}
int main() {
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);
int *arr = (int *)malloc(n * sizeof(int));
int *temp = (int *)malloc(n * sizeof(int)); // For copying original array
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
mergeSort(temp, 0, n - 1);
clock_t end = clock();
total_time += ((double)(end - start)) / CLOCKS_PER_SEC;
}
printf("Average time to sort elements whose size is %d : %f seconds\n", n,
total_time / 1000.0);
free(arr);
free(temp);
return 0;
}}
