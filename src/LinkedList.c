#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/LinkedList.h"

/* Start Init */
Node* newNode(void* data, size_t dataSize) {
	Node* node = malloc(sizeof(Node));
	if (!node) {
		fprintf(stderr, "[err] Failed to allocate memory");
		return NULL;
	}

	node->data = malloc(dataSize);
	if (!node->data) {
		fprintf(stderr, "[err] Failed to allocate memory");
		free(node);
		return NULL;
	}

	memcpy(node->data, data, dataSize);

	node->next = NULL;
	node->prev = NULL;
	
	return node;
}

LinkedList* newList(size_t dataSize) {
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

	if (!list) {
		fprintf(stderr, "[err] Failed to allocate memory");
		return NULL;
	}

	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	list->nodeSize = dataSize;

	return list;
}
/* End Init */

/* Start Getter */ 
void* peekHead(const LinkedList* list) {
	if (!list || list->length == 0) {
		fprintf(stderr, "[err] List is Empty/Undefined\n");
		return NULL;
	}
	return list->head->data;
}

void* peekTail(const LinkedList* list) {
	if (!list || list->length == 0) {
		fprintf(stderr, "[err] List is Empty/Undefined\n");
		return NULL;
	}
	return list->tail->data;
}

size_t lengthList(const LinkedList* list) {
	if (!list) {
		fprintf(stderr, "[err] List is Undefined");
		return 0;
	}
	return list->length;
}
/* End Getter */

// Displaying
void printList(LinkedList* list, void (*printNode)(Node* current)) {
	if (!list || list->length == 0) {
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
Node* at(LinkedList* list, size_t index) {
	if (!list || list->length == 0) {
		fprintf(stderr, "[err] List is Empty/Undefined\n");
		return NULL;
	}

	if (index >= list->length) {
		fprintf(stderr, "[err] Index %zu out of bounds (length: %zu)", index, list->length);
		return NULL;
	} 

	Node* current = list->head;

	for (int i = 0; i < index; i++)
		current = current->next;

	return current;
}

/* Start Insert */
void pushAtHead(LinkedList* list, void* newData) {
	Node* newHead = newNode(newData, list->nodeSize);

	if (!newHead) return;

	newHead->next = list->head;

	if (!list->head) list->tail = newHead;
	else list->head->prev = newHead;

	list->head = newHead;
	list->length++;
}

void pushAtTail(LinkedList* list, void* newData) {	
	Node* newTail = newNode(newData, list->nodeSize);

	if (!newTail) return;

	newTail->prev = list->tail;

	if (!list->head) list->head = newTail;
	else list->tail->next = newTail;

	list->tail = newTail;
	list->length++;
}

void insertAt(LinkedList* list, void* newData, size_t index) {
	if (index == 0) pushAtHead(list, newData);
	else if (index == list->length) pushAtTail(list, newData);
	else if (index >= list->length) fprintf(stderr, "[err] Index %zu out of bounds (length: %zu)", index, list->length);
	else {
		Node* target = at(list, index);
		Node* prev = target->prev;

		Node* node = newNode(newData, list->nodeSize);

		if (!node) return;

		node->next = target;
		node->prev = prev;

		prev->next = node;
		target->prev = node;

		list->length++;
	}
}
/* End Insert */

/* Start Deletion */
void popAtHead(LinkedList* list) {
	Node* temp = list->head;
	list->head = list->head->next;

	if (!list->head) list->tail = NULL;

	list->length--;
	free(temp->data);
	free(temp);
}

void popAtTail(LinkedList* list) {
	Node* temp = list->tail;
	list->tail = list->tail->prev;

	if (list->tail) list->tail->next = NULL;

	if (!list->tail) list->head = NULL;

	list->length--;
	free(temp->data);
	free(temp);
}

void deleteAt(LinkedList* list, size_t index) {
	if (index == 0) popAtHead(list);
	else if (index == list->length - 1) popAtTail(list);
	else if (index >= list->length) fprintf(stderr, "[err] Index %zu out of bounds (length: %zu)", index, list->length);
	else {
		Node* target = at(list, index);
		Node* prev = target->prev;
		Node* next = target->next;

		prev->next = next;
		next->prev = prev;

		list->length--;
		free(target->data);
		free(target);
	}
}
/* End Deletion */

// De-Initialize
void freeList(LinkedList* list) {
	while (list && list->length) popAtHead(list);
	free(list);
}

