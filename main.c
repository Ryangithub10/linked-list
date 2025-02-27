#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
	LinkedList* list = newList();

	// Insert
	push(list, 1);
	push(list, 2);
	push(list, 3);
	push(list, 4);
	push(list, 5);

	printList(list);

	printf("Head -> %d\n", list->head->data);
	printf("Tail -> %d\n", list->tail->data);

	// Search
	Node* m = at(list, 2);
	printf("Middle Node = %d\n", (m) ? m->data : -1);

	// Delete
	delete(list, m);
	printList(list);

	pop(list);
	printList(list);
	
	free(list);
	return 0;
}
