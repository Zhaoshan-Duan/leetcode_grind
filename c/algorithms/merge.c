#include <stdio.h>
#include <stdlib.h>

int* merge(int A[], int B[], int m, int n) {
    int i = 0; int j = 0; int k = 0;
    int* C = malloc((m+n) * sizeof(int));
    while (i < m && j < n) {
        if (A[i] < B[j]) {
            C[k++] = A[i++];
        } else 
            C[k++] = B[j++];
    }

    for (; i < m; i++) {
        C[k++] = A[i];
    }

    for (; j < n; j++) {
        C[k++] = B[j];
    }

    return C;
}

int main() {
    int A[] = {2, 8, 15, 18, 25};
    int B[] = {5, 9, 12, 17};
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);

    int* C = (int*) malloc((m+n) * sizeof(int));
    
    C = merge(A, B, m, n);
    
    int i = 0;
    for (; i < m+n; i++) {
        printf("%d\n", C[i]);
    }

    free(C);

    return 0;
}
