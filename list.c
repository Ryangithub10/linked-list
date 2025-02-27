#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Start Init */
Node* newNode(int data) {
	Node* node = (struct Node*)malloc(sizeof(struct Node));

	node->data = data;
	node->next = NULL;
	
	return node;
}

LinkedList* newList() {
	LinkedList* list = 
		(struct LinkedList*)malloc(sizeof(struct LinkedList));

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}
/* End Init */

/* Start Search */
Node* search(LinkedList* list, int target) {
	Node* current = list->head;

	while (current) {
		if (current->data == target)
			return current;
		current = current->next;
	}

	return NULL;
}

Node* at(LinkedList* list, int index) {
	Node* current = list->head;
	
	for (int i = 0; i < list->size; i++) {
		if (i == index)
			return current;
		current = current->next;
	}

	return NULL;
}
/* End Search */

/* Start Insert */
void push(LinkedList* list, int newData) {	
	if (!list->head && !list->tail) {
		Node* newTail = newNode(newData);
		list->tail = newTail;
		list->head = newTail;
		list->size++;
	}

	else {
		Node* newTail = newNode(newData);
		Node* prev = list->tail;
		list->tail = newTail;
		prev->next = list->tail;
		list->size++;
	}
}

void add(LinkedList* list, int newData) {
	if (!list->head && !list->tail) {
		Node* newHead = newNode(newData);
		newHead->next = list->head;
		list->head = newHead;
		list->tail = newHead;
		list->size++;
	}

	else {
		Node* newHead = newNode(newData);
		newHead->next = list->head;
		list->head = newHead;
		list->size++;
	}
}
/* End Insert */

/* Start Deletion */
void pop(LinkedList* list) {
	Node* prev = list->head;
	Node* temp = list->tail;

	while (prev->next->next != NULL)
		prev = prev->next;

	list->tail = prev;
	list->tail->next = NULL;
	free(temp);
}

void shift(LinkedList* list) {
	Node* temp = list->head;
	list->head = list->head->next;
	free(temp);
}

void delete(LinkedList* list, Node* node) {
	if (!node) {
		printf("null exception\n");
		return;
	}

	if (list->head == node) {
		list->head = node->next;
		free(node);
		return;
	}

	Node* prev = list->head;
	while (prev->next != node)
		prev = prev->next;

	if (node->next != NULL) {
		prev->next = node->next;
		free(node);
	} 

	else {
		prev->next = NULL;
		free(node);
	}
}
/* End Deletion */

/* Start Print */
void printList(LinkedList* list, char* prefix, char* postfix, bool isEnter) {
	Node* current = list->head;
	while (current) {
		if (!isEnter) 
			printf("%s%d %s ", prefix, current->data, postfix);
		else 
			printf("%s %d %s\n", prefix, current->data, postfix);

		current = current->next;
	}

	if (!isEnter) 
		printf("NULL\n");
}
/* End Print */
