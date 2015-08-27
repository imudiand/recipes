#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node node;
struct Node {
	int value;
	node *left;
	node *right;
};

void recursive_insert(node **root, int value);
node *recursive_search(node *root, int value);

void print_inorder_traverse(node *root);
void print_preorder_traverse(node *root);
void print_postorder_traverse(node *root);

node *copy(node *root);
int depth(node *root);
int num_nodes(node *root);
void destroy(node **root);
int is_identical(node *t1, node *t2);
int num_leaves(node *root);