// dynamic-array.h

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct dynamicArray dynamicArray;

struct dynamicArray {
  int size;
  int capacity;
  int* data;
};

void daInit(dynamicArray* da, int array_size);
int daAppend(dynamicArray* da, int value);
int daValueGet(dynamicArray* da, int index);
void daValueSet(dynamicArray* da, int index, int value);
void daInsert(dynamicArray* da, int index, int value);
void daDelete(dynamicArray* da, int index);
void daDisplay(dynamicArray* da);
void daDestroy(dynamicArray* da);

#endif
