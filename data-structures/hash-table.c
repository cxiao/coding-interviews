// Implementing a hash table in C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic-array.h"

typedef struct HashTable HashTable;

struct HashTable {
  dynamicArray* values;
  int size; // Number of values in table
};

int hashInit(HashTable* ht, int buckets) {
  daInitFull(ht->values, buckets);
}

int hashDestroy(HashTable* ht) {
  daDestroy(ht->values);
}

int hashValueGet(HashTable* ht, char* key) {
  int index; int value;
  index = hashFunction(key) % ht->values->capacity;
  value = daValueGet(ht->values, index);
  return value;
}

int hashValueSet(HashTable* ht, char* key, int value) {
  int index;
  index = hashFunction(key) % ht->values->capacity;
  if (daValueGet(ht->values, index) == NULL) {
    ht->size++;
  }
  daValueSet(ht->values, index, value);


  return value;
}

int hashFunction(char* key) {
  int i;
  int hash = 0;
  for (i = 0; i < strlen(key); i++) {
    hash += key[i];
  }
  return hash;
}

int main(int argc, char* argv) {
  HashTable stocks;
  hashInit(&stocks, 79);
  hashValueSet(&stocks, "MSFT", 45);
  hashValueSet(&stocks, "GOOG", 27);
  hashValueSet(&stocks, "APPL", 88);
  hashValueSet(&stocks, "AMZN", 900000);
  printf("MSFT Stock: %d\n", hashValueGet(&stocks, "MSFT"));
  printf("APPL Stock: %d\n", hashValueGet(&stocks, "APPL"));
  printf("AMZN Stock: %d\n", hashValueGet(&stocks, "AMZN"));
  printf("GOOG Stock: %d\n", hashValueGet(&stocks, "GOOG"));

  hashDestroy(&stocks);
}
