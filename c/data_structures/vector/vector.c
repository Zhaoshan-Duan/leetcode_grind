#include<stdio.h>
#include<stdlib.h>

typedef struct vector {
    int* data;
    int capacity;
    int size;
} vector_t;

void allocationFailure() {
    printf("Memory Allocation failed");
}

vector_t* constructor(int initCapacity) {
    vector_t* p_vector = (vector_t*) malloc(sizeof(vector_t));

    if (p_vector == NULL) {
        allocationFailure();
        return NULL;
    }

    p_vector->data = (int*) malloc(sizeof(int) * initCapacity);

    if (p_vector->data == NULL) {
        allocationFailure();
        return NULL;
    }

    p_vector->capacity = initCapacity;
    p_vector->size = 0;
    
    return p_vector;
}

void freeVector(vector_t* vector) {
    if (vector == NULL) {
        printf("null pointer");
        return;
    }
    // free delete the data array
    if (vector->data != NULL) {
        free(vector->data);
    }

    // free 
    free(vector);
}

void printVector(vector_t* vector) {
    if (vector == NULL) 
        return;
    if (vector->data == NULL)
        return;
    
    int i;
    printf("[");
    for (i = 0; i < vector->size; i++) {
        printf("%d,", vector->data[i]);
    }
    printf("]\n");
}

int resize(vector_t* vector) {
    if (vector == NULL)  {
        return 0;
    }
    
    vector->capacity  = vector->capacity * 2;
    int* newData = (int*) malloc(sizeof(int) * vector->capacity);

        if(newData == NULL || vector->data == NULL) {
            return 0;
        }

        // copy data
        int i;
        for (i = 0; i < vector->size; i++) {
            newData[i] = vector->data[i];
        }
        
        //  free old array 
        free(vector->data);
        vector->data = newData;
        return 1;
}
int append(vector_t* vector, int element) {
    if (vector == NULL) {
        allocationFailure();
        return 0;
    }

    if (vector->data == NULL) {
        return 0;
    }

    // check if enough room
    if (vector->size == vector->capacity) {
        int resizeSucess = resize(vector);
        if( resizeSucess == 0) {
            return 0;
        }
    }

    // append to the back of the array
    vector->data[vector->size] = element;
    vector->size += 1;
    
    return 1;
}


int insert(vector_t* vector, int pos, int element) {
    
    if (vector == NULL) 
        return 0;
    

    // invalid position 
    if (pos < 0) 
        return 0;
    

    // insert at the end of the array
    if (pos == vector->size) 
        return append(vector, element);
    
    // if not enough room
    if (vector->size == vector->capacity) {
        int resizeSucess = resize(vector);
        if (resizeSucess == 0) {
            return 0;
        }
    }

    if (vector->data == NULL) 
        return 0;
    

    // shifting array elements to the right, starting from the last element
    int i;
    for (i = vector->size-1; i >= pos; i--) {
        // write data on left to right 
        vector->data[i+1] = vector->data[i];
    }
    
    vector->data[pos] = element; 
    vector->size += 1;
    return 1;
    }


int push_front(vector_t* vector, int element) {
    return insert(vector, 0, element);
}

int main() {
    vector_t* v1 = constructor(2);
    append(v1, 2);
    append(v1, 4);
    append(v1, 6);
    append(v1, 8);
    append(v1, 9);
    printf("Before front: ");
    printVector(v1);
    printf("After insert: ");
    push_front(v1, 1);
    printVector(v1);
    
    freeVector(v1);
    return 0;
}

