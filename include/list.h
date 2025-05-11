#ifndef LIST_H
#define LIST_H

// Todo List
// TODO Make LinkedList accept generic
// DONE Delete search function
// DONE Make print format callback for printList()
// DONE Use size_t for lenght/size related
// TODO Add Documentation

#include <stddef.h>

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
	size_t size;
} LinkedList;

// Initialize
Node* newNode(int data);
LinkedList* newList();

// Getter
int peekHead(LinkedList* list);
int peekTail(LinkedList* list);
size_t size(LinkedList* list);

// Displaying
void printList(LinkedList* list, void (*printNode)(Node* current));

// Searching
Node* at(LinkedList* list, unsigned int index);

// Insertion
void pushAtHead(LinkedList* list, int newData); // Add at front
void pushAtTail(LinkedList* list, int newData); // Add at back
void insert(LinkedList* list, int newData, size_t index);

// Deletion
void popAtHead(LinkedList* list); // Delete at front
void popAtTail(LinkedList* list); // Delete at back
void deleteAt(LinkedList* list, size_t index);

// De-Iniatilize
void freeList(LinkedList* list);

#endif
