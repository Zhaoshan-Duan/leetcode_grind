#include<stdio.h>
#include<stdlib.h>

int partition(int arr[], int lo, int hi) { 
    // find a pivot
    int pivot = arr[hi];
    
    // 
    int index = lo - 1;

    int temp;
    // walk from low to high-1 (high is the pivot)
    int i = lo;
    for (;i < hi; i++) {
        if (arr[i] <= pivot) {
            index++;
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
    index++;
    arr[hi] = arr[index];
    arr[index] = pivot;

    return index;
}
void qs(int arr[], int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    // get pivot index
    int pivotIdx = partition(arr, lo, hi);

    // quicksort on left
    qs(arr, lo, pivotIdx-1);

    // quicksort on right
    qs(arr, pivotIdx+1, hi);
}


void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
int main() {
    int arr[] = {10, 16, 8, 12, 15, 6, 3, 9, 5};
    printf("Original array: ");
    printArray(arr, 9);
    printf("\n");
    qs(arr, 0, 9);

    printf("After sorting: ");
    printArray(arr, 9);
    
    return 0;
}
