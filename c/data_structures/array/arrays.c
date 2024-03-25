#include<stdio.h>


void printArray(int* arr, int size) {
   int i;
    for (i = 0; i < size; i++) {
        printf("%d,", arr[i]);
    }
}

int main() {
    int arr[] = {1,2,3};
    printArray(arr, 3);
}
