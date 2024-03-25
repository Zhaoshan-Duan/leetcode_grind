// name: Zhaoshan Duan
// email: duan.zha@northeastern.edu
#include<stdio.h>
#include<stdlib.h>

// Define the linked list node structure
struct ListNode {
    int val;
    struct ListNode* next;
};

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

int getLength(struct ListNode* head) {
    int i = 0;
    struct ListNode* cur = head;
    while (cur) {
        i++;
        cur = cur->next;
    }
    return i;
}

struct ListNode* merge(struct ListNode* l1, struct ListNode* l2, struct ListNode* cur){
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;    
        }

        cur = cur->next;
    }

    if(l1) cur->next = l1;
    else cur->next = l2;

    while (cur->next) cur = cur->next;
    return cur;
}
// split a subsection based on the width
struct ListNode* split(struct ListNode* head, int width){
    // if width is 1, the group is the node itself
    
    while(width > 1 && head) {
        head = head->next;
        width--;
    }

    if (!head) return head;

    struct ListNode* nextStart = head->next;
    
    head->next = NULL;

    return nextStart;
}


struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) return head;
    
    // setup 
   
    // get lengt of the list 
    int length = getLength(head);

    // dummy point that points to the head of the list
    struct ListNode dummy;
    dummy.next = head;

    // starting subsection width
    int width = 1;

    // track start of each subsection
    struct ListNode* startOfSub; 

    // traverse the original list
    struct ListNode* cur; 

    struct ListNode* l1;
    struct ListNode* l2;
    
    // continue until width of subsections is equal or greater than list size
    while (width < length) {
        // each iteration, restart to the beginning of the list
        cur = &dummy;
        startOfSub = dummy.next;
        
        // iterate through each subsection
        while (startOfSub) { 
            // split based on width 
            l1 = startOfSub;

            // seperate l1 from list, give back pointer to the next subsection
            l2 = split(l1, width);

            // seperate l2 from the list, give back pointer to the next subsection
            startOfSub = split(l2, width);
            // merge
            cur = merge(l1, l2, cur);
        } 
        // once start null, it's at the end of the list, increase the size by 2 
        width *= 2;
    }

    return dummy.next;
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
