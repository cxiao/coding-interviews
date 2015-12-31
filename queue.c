// Queue implementation in C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic-array.h"

typedef struct {
  dynamicArray* data;
  int size;
} Queue;

void qInit(Queue* q) {
  daInit(q->data, 2);
  q->size = 0;
}

void qEnqueue(Queue* q, int value) {
  daAppend(q->data, value);
  q->size++;
}

int qDequeue(Queue* q) {
  int value;
  value = daValueGet(q->data, 0);
  daDelete(q->data, 0);
  q->size--;
  return value;
}

void qDestroy(Queue* q) {
  daDestroy(q->data);
}

int main() {
  Queue q;
  qInit(&q);
  qEnqueue(&q, 33);
  qEnqueue(&q, 44);
  qEnqueue(&q, 54);
  printf("Dequeued: %d\n", qDequeue(&q));
  printf("Dequeued: %d\n", qDequeue(&q));
  qEnqueue(&q, 17);
  printf("Dequeued: %d\n", qDequeue(&q));
  printf("Dequeued: %d\n", qDequeue(&q));
  qDestroy(&q);
}
