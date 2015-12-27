// Implementing a linked list in C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node {
	int value;
	Node* next;
};

typedef struct {
	Node* head;
	int length;
} LinkedList;

Node* nodeInit(int value) {
	Node* n = malloc(sizeof(Node));
	n->value = value;
	n->next = NULL;
	return n;
}

void nodeDestroy(Node* n) {
	free(n);
}

void llInit(LinkedList* ll, int value) {
	ll->head = nodeInit(value);
	ll->length = 1;
}

void llDestroy(LinkedList* ll) {
	Node* before = ll->head;
	Node* current = ll->head->next;
	int i;
	for (i = 0; i < ll->length - 2; i++) {
		nodeDestroy(before);
		before = current;
		current = current->next;
	}
	// Destroy two remaining nodes without moving to next (nonexistent) node
	nodeDestroy(before);
	nodeDestroy(current);
}

Node* _llTraverse(LinkedList* ll, int index) {
	int i;
	Node* current_node = ll->head;
	if (index == 0) {
		return current_node; // Return ptr to the head node
	}
	for (i = 0; i < index; i++) {
		current_node = current_node->next;
	}
	return current_node;
}

int _llCheckBounds(LinkedList* ll, int index) {
  if (index > ll->length - 1 || index < 0) {
      printf("ERROR: Index %d is out of list bounds.\n", index);
      return -1;
  }
  return 0;
}

void llAppend(LinkedList* ll, int value) {
	Node* tail = _llTraverse(ll, ll->length-1);
	Node* new = nodeInit(value);
	tail->next = new;
	ll->length++;
}

void llInsert(LinkedList* ll, int index, int value) {
  if (_llCheckBounds(ll, index) != 0) {return;}
	Node* new = nodeInit(value);
	Node* after = _llTraverse(ll, index);
	if (index == 0) {
		new->next = after;
		ll->head = new;
		ll->length++;
		return;
	}
	Node* before = _llTraverse(ll, index-1);
	before->next = new;
	new->next = after;
	ll->length++;
}

void llDelete(LinkedList* ll, int index) {
  if (_llCheckBounds(ll, index) != 0) {return;}

	if (ll->length == 1) {
		llDestroy(ll);
		return;
	}

	Node* after = _llTraverse(ll, index+1);
	Node* current = _llTraverse(ll, index);

	if (index == 0) {
		ll->head = after;
		ll->length--;
		nodeDestroy(current);
		return;
	}

	Node* before = _llTraverse(ll, index-1);
	before->next = after;
	ll->length--;
	nodeDestroy(current);
}

int llValueGet(LinkedList* ll, int index) {
  if (_llCheckBounds(ll, index) != 0) {return;}
	Node* n = _llTraverse(ll, index);
	return n->value;
}

void llValueSet(LinkedList* ll, int index, int value) {
  if (_llCheckBounds(ll, index) != 0) {return;}
	Node* n = _llTraverse(ll, index);
	n->value = value;
}

void llDisplay(LinkedList* ll) {
	int STRING_SIZE = ll->length * (10+2) + 3;
	char displayString[STRING_SIZE];

	int i;
  sprintf(displayString, "[");
  for (i = 0; i < ll->length-1; i++) {
  	sprintf(displayString, "%s%d, ", displayString, llValueGet(ll, i));
  }
  sprintf(displayString, "%s%d]", displayString, llValueGet(ll, ll->length-1));
  printf("%s\n", displayString);
}

int main() {
	LinkedList l;
	llInit(&l, 45);
	llAppend(&l, 4);
	llAppend(&l, 77);
	llDisplay(&l);
	llInsert(&l, 1, 274);
	llDisplay(&l);
	llInsert(&l, 0, 1);
	llDisplay(&l);
	llDelete(&l, 0);
	llDisplay(&l);
	llDelete(&l, 3);
	llDisplay(&l);
	llDelete(&l, 3);
	llDisplay(&l);
	llDelete(&l, 2);
	llDisplay(&l);
	llDelete(&l, 1);
	llDisplay(&l);
	llDelete(&l, 0);
}
