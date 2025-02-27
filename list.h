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

// Searching
Node* search(LinkedList* list, int target);
Node* at(LinkedList* list, int index);

// Insertion
void push(LinkedList* list, int newData);
void enqueue(LinkedList* list, int newData);
void insert(LinkedList* list, int index, int newData);

// Deletion
void pop(LinkedList* list);
void dequeue(LinkedList* list);
void delete(LinkedList* list, Node* node);

// Printing
void printList(LinkedList* list);

#endif
