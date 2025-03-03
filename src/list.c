#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/list.h"

/* Start Init */
Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));

	node->data = data;
	node->next = NULL;
	
	return node;
}

LinkedList* newList() {
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}
/* End Init */

/* Start Getter */ 
int peek(LinkedList* list) {
    return list->tail->data;
}

int size(LinkedList* list) {
    return list->size;
}
/* End Getter */

/* Start Search */
Node* search(LinkedList* list, int target) {
	if (!list->size) {
		fprintf(stderr, "[!] List is Empty\n");
		return NULL;
	}

	Node* current = list->head;

	while (current) {
		if (current->data == target)
			return current;
		current = current->next;
	}

	return NULL;
}

Node* at(LinkedList* list, int index) {
	if (!list->size) {
		fprintf(stderr, "[!] List is Empty\n");
		return NULL;
	}

	Node* current = list->head;
	
	for (int i = 0; i < list->size; i++) {
		if (i == index)
			return current;
		current = current->next;
	}

	fprintf(stderr, "[!] You outbound the list\n");
	return NULL;
}
/* End Search */

/* Start Insert */
void push(LinkedList* list, int newData) {	
	Node* newTail = newNode(newData);

	if (!list->head) {
		list->head = newTail;
		list->tail = newTail;
	}

	else {
		Node* prev = list->tail;
		list->tail = newTail;
		prev->next = list->tail;
	}

	list->size++;
}

void add(LinkedList* list, int newData) {
	Node* newHead = newNode(newData);

	if (!list->head) {
		newHead->next = list->head;
		list->tail = newHead;
	}

	else
		newHead->next = list->head;

	list->head = newHead;
	list->size++;
}

void insert(LinkedList* list, int index, int newData) {
	Node* prev = at(list, index-1);
	Node* target = prev->next;

	Node* node = newNode(newData);

	prev->next = node;
	node->next = target;
	list->size++;
}
/* End Insert */

/* Start Deletion */
void pop(LinkedList* list) {
	Node* prev = list->head;
	Node* temp = list->tail;

	bool isOneNode = prev == temp;

	while (prev->next != temp && !isOneNode)
		prev = prev->next;

	if (!isOneNode) {
		list->tail = prev;
		list->tail->next = NULL;
	} 
	else {
		list->tail = NULL;
		list->head = NULL;
	}

	list->size--;
	free(temp);
}

void shift(LinkedList* list) {
	Node* temp = list->head;
	list->head = list->head->next;
	if (!list->head)
		list->tail = NULL;
	list->size--;
	free(temp);
}

// TODO make error handling if index is outbound
void delete(LinkedList* list, int index) {
	if (index == 0) {
		shift(list);
		return;
	}

	Node* target = at(list, index);
	Node* prev = list->head;

	while (prev->next != target)
		prev = prev->next;

	prev->next = prev->next->next;
	list->size--;
	free(target);
}
/* End Deletion */


void printList(LinkedList* list) {
	if (!list->size) {
		fprintf(stderr, "[!] List is Empty\n");
		return;
	}

	Node* current = list->head;
	while (current) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

void freeList(LinkedList* list) {
	while (list->size)
		shift(list);

	free(list);
}
