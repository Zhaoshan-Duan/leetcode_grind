#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node_t;

node_t* createNode(int data) {
    node_t* temp = (node_t*) malloc(sizeof(node_t));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printNode(node_t* node) {
    while( node != NULL ) {
        printf("%d->", node->data);
        node = node->next;
    }
}

void freeNode(node_t* node) {
    free(node);
}

int main() {
    // static 
    node_t node1;
    node_t node2;
    node_t node3;

    node1.data = 1;
    node2.data = 2;
    node3.data = 3;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    printf("first call\n");
    printNode(&node1);
    printf("\n");
    node_t* head = createNode(10);
    node_t* second = createNode(20);
    node_t* third = createNode(30);

    head->next = second;
    second->next = third;

    node_t* cur = head;

    printf("second call\n");
    printNode(cur);

    return 0;
}
