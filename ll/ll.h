#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
struct Node {
	int value;
	node *next;
};


/* Declarations */
void append(node **head, int value);
void print(node *head);
node *concatenate(node *l1, node *l2);
void iterative_reverse(node **head);
node *recursive_reverse(node *prev, node *cur);