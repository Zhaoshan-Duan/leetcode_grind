#include <stdio.h>   // stardard input/output library
#include <stdbool.h> // standard boolean library: bool, true, false

#define MAXSIZE 100 // top = 99 if stack is full 

bool isEmpty (int* s, int t) {
    return t < 0;
}

bool isFull (int* s, int t) {
    return t >= MAXSIZE - 1;
}

void push(int v, int* s, int* tp) {
  // put v onto the top of the stack s unless it is already full
  if (!isFull(s, *tp)) {
      *tp = *tp + 1; 
      s[*tp] = v;
  } else {
      printf("Attempt to push onto full stack.\n");
}
}


int pop (int* s, int* tp) {
  // return the top entry in the stack unless stack is empty
  // update s and *tp -- requires top to be passed by reference!
  int returnVal = 0;
  
  if (!isEmpty(s, *tp)) {
      returnVal = s[*tp];
      *tp = *tp - 1;
  } else {
      printf("Attempt to pop empty stack.\n");
  }
  return returnVal;
}

int main () {

  int stack1[MAXSIZE]; // array in which stack will live
  int top1 = -1;       // top valid location in stack, -1 == empty
  int stack2[MAXSIZE]; // array in which stack will live
  int top2 = -1;       // top valid location in stack, -1 == empty
  
  printf("pushing: 1, 2, 3, 4, 5 onto first stack\n");
  printf("pushing: 100, 200, 300, 400, 500 onto second stack\n\n");
  push(1, stack1, &top1);
  push(2, stack1, &top1);
  push(3, stack1, &top1);
  push(4, stack1, &top1);
  push(5, stack1, &top1);
  push(100, stack2, &top2);
  push(200, stack2, &top2);
  push(300, stack2, &top2);
  push(400, stack2, &top2);
  push(500, stack2, &top2);

  printf("popping alternating stacks:\n");
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  return 0;
}
