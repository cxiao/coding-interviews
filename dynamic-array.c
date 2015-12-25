// Implementing a dynamic array in C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int size;
  int capacity;
  int* data;
} dynamicArray;

void daInit(dynamicArray* da, int array_size) {
  da->size = 0; // zero elements in array at beginning
  da->capacity = array_size;
  da->data = malloc(sizeof(int) * da->capacity);
}

int _daExpandArray(dynamicArray* da) {
  da->capacity *= 2;
  int* data_tmp = realloc(da->data, sizeof(int)*da->capacity);
  if (data_tmp == NULL) {
      return -1;
    } else {
      da->data = data_tmp;
      return 0;
    }
}

int _daCheckBounds(dynamicArray* da, int index) {
  if (index > da->size - 1 || index < 0) {
      printf("ERROR: Index %d is out of array bounds.\n", index);
      return -1;
  }
  return 0;
}

int daAppend(dynamicArray* da, int value) {
  int err;
  if (da->size == da->capacity) {
    err = _daExpandArray(da);
    if (err) {
      printf("ERROR: Unable to allocate memory for append operation.\n");
      return;
    }
  }
  memcpy(da->data + da->size, &value, sizeof(int));
  da->size++;
  return 0;
}

int daValueGet(dynamicArray* da, int index) {
  if (_daCheckBounds(da, index) != 0) {return 0;}
  return da->data[index];
}

void daValueSet(dynamicArray* da, int index, int value) {
  if (_daCheckBounds(da, index) != 0) {return;}
  da->data[index] = value;
}

void daInsert(dynamicArray* da, int index, int value) {
  if (_daCheckBounds(da, index) != 0) {return;}

  int err;
  if (da->size == da->capacity) {
    err = _daExpandArray(da);
    if (err) {
        printf("ERROR: Unable to allocate memory for insert operation.\n");
        return;
    }
  }
  int* tmp = malloc((da->size-index)*sizeof(int)); // need to use temporary ptr because source and destination overlap when moving existing contents
  memcpy(tmp, &da->data[index], (da->size-index)*sizeof(int)); // Move existing contents of array
  memcpy(&da->data[index] , &value, sizeof(int)); // Insert new item
  memcpy(&da->data[index+1], tmp, (da->size-index)*sizeof(int)); // Replace old items
  free(tmp);

  da->size++;
}

void daDelete(dynamicArray* da, int index) {
  if (da->size == 1 && index == 0) {
    da->data[0] = 0; // for now, not allowing zero size
    return;
  }
  if (_daCheckBounds(da, index) != 0) {return;}

  int* tmp = malloc((da->size-index-1)*sizeof(int)); // need to use temporary ptr because source and destination overlap when moving existing contents
  memcpy(tmp, &da->data[index+1], sizeof tmp); // Move existing contents of array
  memcpy(&da->data[index], tmp, sizeof tmp); // Replace old item
  free(tmp);

  da->size--;
}

void daDisplay(dynamicArray* da) {
    int STRING_SIZE = da->size * (10 + 2) + 3;
    char displayString[STRING_SIZE];
    int i;
    sprintf(displayString, "[");
    for (i = 0; i < da->size-1; i++) {
      sprintf(displayString, "%s%d, ", displayString, daValueGet(da, i));
    }
    sprintf(displayString, "%s%d]", displayString, daValueGet(da, da->size-1));
    printf("%s\n", displayString);
}

int main() {
  int val;

  dynamicArray da;
  daInit(&da, 2);

  daAppend(&da, 45);
  daAppend(&da, 99);
  daAppend(&da, 37);

  daDisplay(&da);
  printf("Size of array: %d\n", da.size);
  printf("Capacity of array: %d\n", da.capacity);

  val = daValueGet(&da, 17);
  printf("Obtained value: %d\n", val);
  daValueSet(&da, 1, 19);
  daDisplay(&da);

  daInsert(&da, 1, 13);
  daDisplay(&da);

  daDelete(&da, 1);
  daDisplay(&da);

  daDelete(&da, 2);
  daDisplay(&da);

  daDelete(&da, 0);
  daDisplay(&da);

  daDelete(&da, 0);
  daDisplay(&da);

  int i;
  for (i = 0; i < 20000; i++) {
     daAppend(&da, i);
  }
  daDisplay(&da);
}
