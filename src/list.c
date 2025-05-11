#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "../include/list.h"

/* Start Init */
Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));

	if (!node) {
		fprintf(stderr, "[err] Failed to allocate memory");
		return NULL;
	}

	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	
	return node;
}

LinkedList* newList() {
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

	if (!list) {
		fprintf(stderr, "[err] Failed to allocate memory");
		return NULL;
	}

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}
/* End Init */

/* Start Getter */ 
int peekHead(LinkedList* list) {
	if (!list || list->size == 0) {
		fprintf(stderr, "[err] List is Empty/Undefined\n");
		return -1;
	}
	return list->head->data;
}

int peekTail(LinkedList* list) {
	if (!list || list->size == 0) {
		fprintf(stderr, "[err] List is Empty/Undefined\n");
		return -1;
	}
	return list->tail->data;
}

size_t size(LinkedList* list) {
	if (!list) {
		fprintf(stderr, "[err] List is Undefined");
		return -1;
	}
	return list->size;
}
/* End Getter */

// Displaying
void printList(LinkedList* list, void (*printNode)(Node* current)) {
	if (!list || list->size == 0) {
		fprintf(stderr, "[err] List is Empty/Undefined\n");
		return;
	}

	Node* current = list->head;
	while (current) {
		printNode(current);
		current = current->next;
	}

	printf("\n");
}

// Searching
Node* at(LinkedList* list, unsigned int index) {
	if (!list || list->size == 0) {
		fprintf(stderr, "[err] List is Empty/Undefined\n");
		return NULL;
	}

	if (index >= list->size) {
		fprintf(stderr, "[err] outbound index of list");
		return NULL;
	} else if (index < 0) {
		fprintf(stderr, "[err] inbound index of list");
		return NULL;
	}

	Node* current = list->head;

	for (int i = 0; i < list->size; i++) {
		if (i == index) break;
		current = current->next;
	}

	return current;
}

/* Start Insert */
void pushAtHead(LinkedList* list, int newData) {
	Node* newHead = newNode(newData);

	newHead->next = list->head;

	if (!list->head) list->tail = newHead;
	else list->head->prev = newHead;

	list->head = newHead;
	list->size++;
}

void pushAtTail(LinkedList* list, int newData) {	
	Node* newTail = newNode(newData);

	newTail->prev = list->tail;

	if (!list->head) list->head = newTail;
	else list->tail->next = newTail;

	list->tail = newTail;
	list->size++;
}

void insert(LinkedList* list, int newData, size_t index) {
	if (index == 0) pushAtHead(list, newData);
	else if (index == list->size) pushAtTail(list, newData);
	else if (index >= list->size) fprintf(stderr, "[err] outbound index of list");
	else if (index < 0) fprintf(stderr, "[err] inbound index of list");
	else {
		Node* target = at(list, index);
		Node* prev = target->prev;

		Node* node = newNode(newData);

		node->next = target;
		node->prev = prev;

		prev->next = node;
		target->prev = node;

		list->size++;
	}
}
/* End Insert */

/* Start Deletion */
void popAtHead(LinkedList* list) {
	Node* temp = list->head;
	list->head = list->head->next;

	if (!list->head) list->tail = NULL;

	list->size--;
	free(temp);
}

void popAtTail(LinkedList* list) {
	Node* temp = list->tail;
	list->tail = list->tail->prev;
	list->tail->next = NULL;

	if (!list->tail) list->head = NULL;

	list->size--;
	free(temp);
}

void deleteAt(LinkedList* list, size_t index) {
	if (index == 0) popAtHead(list);
	else if (index == list->size - 1) popAtTail(list);
	else if (index >= list->size) fprintf(stderr, "[err] outbound index of list");
	else if (index < 0) fprintf(stderr, "[err] inbound index of list");
	else {
		Node* target = at(list, index);
		Node* prev = target->prev;
		Node* next = target->next;

		prev->next = prev->next->next;
		next->prev = next->prev->prev;
		list->size--;
		free(target);
	}
}
/* End Deletion */

// De-Initialize
void freeList(LinkedList* list) {
	while (list && list->size) popAtHead(list);
	free(list);
}

