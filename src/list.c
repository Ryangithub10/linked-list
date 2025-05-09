#include <stdio.h>
#include <stdlib.h>
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

int size(LinkedList* list) {
	if (!list) {
		fprintf(stderr, "[err] List is Undefined");
		return -1;
	}
	return list->size;
}
/* End Getter */

/* Start Search */
Node* search(LinkedList* list, int target) {
	if (!list->size) {
		fprintf(stderr, "[err] List is Empty\n");
		return NULL;
	}

	Node* current = list->head;

	while (current) {
		if (current->data == target)
			return current;
		current = current->next;
	}

	fprintf(stderr, "[err] %d not in the list", target);
	return NULL;
}

Node* at(LinkedList* list, unsigned int index) {
	if (!list || list->size == 0) {
		fprintf(stderr, "[err] List is Empty/Undefined\n");
		return NULL;
	}

	if (index >= list->size) {
		fprintf(stderr, "[err] you outbound the list; the list size is %d", list->size);
		return NULL;
	}

	Node* current = list->head;

	for (int i = 0; i < list->size; i++) {
		if (i == index)
			break;
		current = current->next;
	}

	return current;
}
/* End Search */

/* Start Insert */
void pushAtHead(LinkedList* list, int newData) {
	Node* newHead = newNode(newData);

	if (!list->head) {
		newHead->next = list->head;
		list->tail = newHead;
	} else {
        newHead->next = list->head;
        list->head->prev = newHead;
    }

	list->head = newHead;
	list->size++;
}

void pushAtTail(LinkedList* list, int newData) {	
	Node* newTail = newNode(newData);

	if (!list->head) {
		list->head = newTail;
		list->tail = newTail;
	} else {
		Node* prev = list->tail;
		list->tail = newTail;
		prev->next = list->tail;
		list->tail->prev = prev;
	}

	list->size++;
}

void insert(LinkedList* list, int index, int newData) {
	if (index == 0) pushAtHead(list, newData);
	else if (index == list->size) pushAtTail(list, newData);

	else {
		Node* prev = at(list, index-1);
		Node* target = prev->next;

		Node* node = newNode(newData);

		prev->next = node;
		node->next = target;
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

void deleteAt(LinkedList* list, unsigned int index) {
	if (index == 0) {
		popAtHead(list);
		return;
	}

    if (index >= list->size) {
        fprintf(stderr, "[err] you outbound the list; list size is %d\n", list->size);
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
	if (!list || list->size == 0) {
		fprintf(stderr, "[err] List is Empty/Undefined\n");
		return;
	}

	Node* current = list->head;
	printf("NULL ");
	while (current) {
		printf("%d <-> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

void freeList(LinkedList* list) {
	while (list && list->size) popAtHead(list);
	free(list);
}
