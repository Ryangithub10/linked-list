#ifndef LIST_H
#define LIST_H

// Node 
typedef struct Node {
	int data;
	struct Node* next;
    struct Node* prev;
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
int peekHead(LinkedList* list);
int peekTail(LinkedList* list);
int size(LinkedList* list);

// Searching
Node* search(LinkedList* list, int target);
Node* at(LinkedList* list, unsigned int index);

// Insertion
void pushAtHead(LinkedList* list, int newData); // Add at front
void pushAtTail(LinkedList* list, int newData); // Add at back
void insert(LinkedList* list, int index, int newData); // Add at given index

// Deletion
void popAtHead(LinkedList* list); // Delete at front
void popAtTail(LinkedList* list); // Delete at back
void deleteAt(LinkedList* list, unsigned int index);

// Misc.
void printList(LinkedList* list);
void freeList(LinkedList* list);

#endif
