#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

/** Linked List Documentation
 *
 * == Initialize
 * newNode(int data) -> construct new node
 * @param data -> specify data
 * @return -> Pointer of Node
 *
 * newList() -> construct new Linked List
 * @return Pointer of LinkedList
 *
 * == Searching / Accessing
 * search(LinkedList* list, int target) -> search node by value
 * @param list -> specify linked list pointer
 * @param target
 * @return Node pointer
 *
 * at(LinkedList* list, int index) -> search node by index
 * @param list -> specify linked list pointer
 * @param target
 * @return Node pointer
 *
 * == Insertion
 * add(LinkedList* list, int newData) -> add new node at beginning
 * @param list -> specify linked list pointer 
 * @param newData -> specify data for new node
 *
 * push(LinkedList* list, int newData) -> add new node at end
 * @param list -> specify linked list pointer
 * @param newData -> specify data for new node
 *
 * insert(LinkedList* list, int index, int newData) -> add new node at specify location 
 * @param list -> specify linked list pointer
 * @param index -> specify new node location
 * @param newData -> specify data for new node
 *
 */


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
void add(LinkedList* list, int newData);
void push(LinkedList* list, int newData);
void insert(LinkedList* list, int index, int newData);

// Deletion
void pop(LinkedList* list);
void shift(LinkedList* list);
void delete(LinkedList* list, Node* node);

// Printing
void printList(LinkedList* list, char* prefix, char* postfix, bool isEnter);

#endif
