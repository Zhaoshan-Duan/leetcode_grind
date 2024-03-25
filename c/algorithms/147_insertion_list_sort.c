// name: Zhaoshan Duan
// email: duan.zha@northeastern.edu

#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* insertionSortList(struct ListNode* head) {

    if (!head || !head->next) return head;

    // dummy node to keep track of the entire list
    struct ListNode dummy;
    dummy.next = head;

    // helper pointers
    struct ListNode* prev = head;
    struct ListNode* cur = head->next;

    // traverse the list
    while (cur) {
        // already in-order
        if (prev->val <= cur->val) {
            prev = cur;
            cur = cur->next;
        } else {
            struct ListNode* temp = &dummy;
            
            // starting from the beginning, check if cur node is smaller
            while(cur->val > temp->next->val) 
                temp = temp->next;

            // find the stop when cur is < temp->next
            prev->next = cur->next;
            cur->next = temp->next;
            temp->next = cur;

            cur = prev->next;
        }
    }
    return dummy.next;
}



struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void printList(struct ListNode* head) {
    while(head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf(" NULL");

}

int main() {
    struct ListNode* head = createNode(4);
    head->next = createNode(2);
    head->next->next = createNode(1);
    head->next->next->next = createNode(3);
    
    printf("Original list: ");
    printList(head);
    printf("\n");

    head = insertionSortList(head);

    printf("Sorted List: ");
    printList(head);


    return 0;
}
