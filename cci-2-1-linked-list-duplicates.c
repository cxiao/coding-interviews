// 2.1 Write code to remove duplicates from an unsorted linked list.

#include <stdlib.h>
#include "data-structures/linked-list.h"

// For each node in list:
// Search the rest of the list for duplicates
// Once a duplicate is found, delete it right away,
// Then continue searching in the rest of the list
// Once finished searching for duplicates of the first node,
// repeat the process with the rest of the list.
// Time complexity: O(n^2).

void removeDuplicates(LinkedList* ll) {
  Node* currentNode;
  Node* searchNode;
  currentNode = ll->head;
  searchNode = currentNode;
  while (currentNode->next != NULL) {
    while (searchNode->next != NULL) {
      if (currentNode->value == searchNode->next->value) {
        // Delete the duplicate node
        Node* after = searchNode->next->next;
        searchNode->next = after;
        ll->length--;
      }
      searchNode = searchNode->next;
    }
    currentNode = currentNode->next;
    searchNode = currentNode;
  }
}

// Alternatively, keep track of duplicate entries in a hash table.
// Iterate twice.
// First iteration: check for and count the number of duplicates
// Second iteration: check each element's value and match it to the value in the
// hash table, using the element's value as the key.
// If the number of duplicates is above 0, then delete that element.

int main() {
  LinkedList ll;
  llInit(&ll);
  llAppend(&ll, 2); llAppend(&ll, 5); llAppend(&ll, 2);
  llDisplay(&ll);
  removeDuplicates(&ll);
  llDisplay(&ll);
  llDestroy(&ll);
}
