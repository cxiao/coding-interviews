// linked-list.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node {
	int value;
	Node* next;
};

struct LinkedList {
	Node* head;
	int length;
};

Node* nodeInit(int value);
void nodeDestroy(Node* n);
void llInit(LinkedList* ll);
void llAppend(LinkedList* ll, int value);
void llInsert(LinkedList* ll, int index, int value);
void llDelete(LinkedList* ll, int index);
int llValueGet(LinkedList* ll, int index);
void llValueSet(LinkedList* ll, int index, int value);
void llDisplay(LinkedList* ll);

#endif
