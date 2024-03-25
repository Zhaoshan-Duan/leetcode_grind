#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
} node_t;

node_t* createNode(int data) {
    node_t* temp = (node_t*) malloc(sizeof(node_t));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void printNode(node_t* node) {
    while (node != NULL) {
        printf("%d->", node->data);
        node = node->next;
    }
}

int main() {
    node_t* head = createNode(10);
    node_t second;
    node_t third;
    
    head->next = &second;
    
    second.data = 20;
    second.next = &third;
    second.prev = head;

    third.data = 30;
    third.prev = &second;
    return 0;
}
