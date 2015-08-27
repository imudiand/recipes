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

void iterative_reverse(node **head) {
	if (!*head) {
		return;
	}

	node *prev = NULL;
	node *cur = *head;
	node *next;

	while(cur) {
		next = cur->next;
		cur->next = prev;
		prev=cur;
		cur=next;
	}

	*head=prev;
}

node *recursive_reverse(node *prev, node *cur) {
	if (!cur) {
		return prev;
	}

	node *next = cur->next;
	cur->next = prev;
	return recursive_reverse(cur, next);
}


void destoy(node **head) {
	node *next;
	while(*head) {
		next = (*head)->next;
		free(*head);
		*head = next;
	}
}

void delete(node **head, int value) {
	if (!*head)
		return;

	node *tmp = NULL;
	if ((*head)->value == value) {
		tmp = *head;
		(*head) = (*head)->next;
		free(tmp);
		return;
	}

	node *iter = *head;

	while(iter->next) {
		if (iter->next->value == value) {
			tmp = iter->next;
			iter->next = tmp->next;
			free(tmp);
		} else {
			iter=iter->next;
		}
	}
}