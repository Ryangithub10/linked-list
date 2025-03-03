#ifndef LIST_H
#define LIST_H

// Node 
typedef struct Node {
	int data;
	struct Node* next;
} Node;

// Linked List
typedef struct LinkedList {
	Node* head;
	Node* tail;
	int size;
} LinkedList;

// Initialize
Node* newNode(int data);
LinkedList* newList();

// Getter
int peek(LinkedList* list);
int size(LinkedList* list);

// Searching
Node* search(LinkedList* list, int target);
Node* at(LinkedList* list, int index);

// Insertion
void add(LinkedList* list, int newData); // Add at front
void push(LinkedList* list, int newData); // Add at back
void insert(LinkedList* list, int index, int newData); // Add at given index

// Deletion
void pop(LinkedList* list);
void shift(LinkedList* list);
void delete(LinkedList* list, int index);

void printList(LinkedList* list);
void freeList(LinkedList* list); // De-Initialize

#endif
