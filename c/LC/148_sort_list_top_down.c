// name: Zhaoshan Duan
// email: duan.zha@northeastern.edu
#include<stdio.h>
#include<stdlib.h>

// Define the linked list node structure
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* merge(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    tail->next = NULL;
     while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1) 
        tail->next = list1;
    else if (list2) 
        tail->next = list2;
    
    return dummy.next;
}

struct ListNode* findMid(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;

    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

   if(prev) prev->next = NULL;

    return slow;
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) 
        return head;


    struct ListNode* mid = findMid(head);
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);

    return merge(left, right);
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

    head = sortList(head);

    printf("Sorted List: ");
    printList(head);


    return 0;
}
