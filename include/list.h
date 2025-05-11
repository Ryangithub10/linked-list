#ifndef LIST_H
#define LIST_H

// Todo List
// TODO Make LinkedList accept generic
// TODO Delete search function
// TODO Make print format callback for printList()
// TODO Use size_t for lenght/size related

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

// Displaying
void printList(LinkedList* list);

// Searching
Node* at(LinkedList* list, unsigned int index);

// Insertion
void pushAtHead(LinkedList* list, int newData); // Add at front
void pushAtTail(LinkedList* list, int newData); // Add at back
void insert(LinkedList* list, int index, int newData);

// Deletion
void popAtHead(LinkedList* list); // Delete at front
void popAtTail(LinkedList* list); // Delete at back
void deleteAt(LinkedList* list, unsigned int index);

// De-Iniatilize
void freeList(LinkedList* list);

#endif
