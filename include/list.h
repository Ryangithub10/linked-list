#ifndef LIST_H
#define LIST_H

// Todo List
// DONE Make LinkedList accept generic
// DONE Delete search function
// DONE Make print format callback for printList()
// DONE Use size_t for length/size related
// DONE Add NULL handling for insertion function
// TODO Add Documentation

#include <stddef.h>

// MACRO
#define GET_NODE_DATA(type, node) (*((type*)((node)->data)))
#define PEEK_HEAD(type, list) (*(type*)peekHead(list))
#define PEEK_TAIL(type, list) (*(type*)peekTail(list))

// Node 
typedef struct Node {
	void* data;
	struct Node* next;
	struct Node* prev;
} Node;

// Linked List
typedef struct LinkedList {
	Node* head;
	Node* tail;
	size_t length;
	size_t nodeSize;
} LinkedList;

// Initialize
Node* newNode(void* data, size_t dataSize);
LinkedList* newList(size_t dataSize);

// Getter
void* peekHead(const LinkedList* list);
void* peekTail(const LinkedList* list);
size_t lengthList(const LinkedList* list);

// Displaying
void printList(LinkedList* list, void (*printNode)(Node* current));

// Searching
Node* at(LinkedList* list, unsigned int index);

// Insertion
void pushAtHead(LinkedList* list, void* newData); // Add at front
void pushAtTail(LinkedList* list, void* newData); // Add at back
void insert(LinkedList* list, void* newData, size_t index);

// Deletion
void popAtHead(LinkedList* list); // Delete at front
void popAtTail(LinkedList* list); // Delete at back
void deleteAt(LinkedList* list, size_t index);

// De-Iniatilize
void freeList(LinkedList* list);

#endif
