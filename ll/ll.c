#include "ll.h"

void append(node **head, int value) {
	node *ptr = (node *)malloc(sizeof(node));
	ptr->next = NULL;
	ptr->value = value;

	if (!*head) {
		*head = ptr;
		return;
	}

	node *iter = *head;
	while(iter->next) {
		iter=iter->next;
	}
	iter->next = ptr;
	return;
}

void print(node *head) {
	if (!head)
		return;

	while(head){
		printf("%d", head->value);
		head=head->next;
	}
	printf("\n");
}

node *concatenate(node *l1, node *l2) {
	if (!l1)
		return l2;

	if (!l2)
		return l1;

	node *iter = l1;
	while(iter->next) {
		iter=iter->next;
	}

	iter->next = l2;
	return l1;
}