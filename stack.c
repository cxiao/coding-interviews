// Implementing a stack in C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked-list.h"

typedef struct {
  LinkedList* data;
  int size;
} Stack;

void stInit(Stack* st) {
  llInit(st->data);
  st->size = 0;
}

int stPop(Stack* st) {
  if (st->size == 0) {
    printf("ERROR: Stack has no more items to pop.\n");
    return -1;
  }
  int topval;
  topval = st->data->head->value;
  llDelete(st->data, 0);
  st->size--;
  return topval;
}

void stPush(Stack* st, int value) {
  llInsert(st->data, 0, value);
  st->size++;
}

int stPeek(Stack* st) {
  return st->data->head->value;
}

void stDestroy(Stack* st) {
  llDestroy(st->data);
}

int main() {
  Stack s;
  stInit(&s);
  stPush(&s, 2);
  stPush(&s, 3);
  stPush(&s, 6);
  printf("Peeked: %d\n", stPeek(&s));
  printf("Popped: %d\n", stPop(&s));
  printf("Peeked: %d\n", stPeek(&s));
  printf("Popped: %d\n", stPop(&s));
  printf("Peeked: %d\n", stPeek(&s));
  printf("Popped: %d\n", stPop(&s));
  printf("Peeked: %d\n", stPeek(&s));
  printf("Popped: %d\n", stPop(&s));
  stPush(&s, 19);
  printf("Peeked: %d\n", stPeek(&s));
  printf("Popped: %d\n", stPop(&s));
  printf("Popped: %d\n", stPop(&s));
  stDestroy(&s);
}
