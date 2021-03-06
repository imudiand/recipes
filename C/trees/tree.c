
#include "tree.h"



void recursive_insert(node **root, int value){
	node *elem = (node *)malloc(sizeof(node));
	elem->value = value;
	elem->left = NULL;
	elem->right = NULL;

	if (!*root) {
		*root = elem;
		return;
	}

	if ((*root)->value >= value) {
		recursive_insert( &(*root)->left, value );
	} else {
		recursive_insert( &(*root)->right, value );
	}
}

node *recursive_search(node *root, int value){
	if (!root)
		return root;

	if (root->value == value) {
		return root;
	} else if (root->value > value) {
		return recursive_search(root->left, value);
	} else {
		return recursive_search(root->right, value);
	}
}


void print_inorder_traverse(node *root) {
	if (!root)
		return;

	print_inorder_traverse(root->left);
	printf("%d", root->value);
	print_inorder_traverse(root->right);
}

void print_preorder_traverse(node *root) {
	if (!root)
		return;

	printf("%d", root->value);
	print_preorder_traverse(root->left);
	print_preorder_traverse(root->right);
}

void print_postorder_traverse(node *root) {
	if (!root)
		return;
	print_postorder_traverse(root->left);
	print_postorder_traverse(root->right);
	printf("%d", root->value);
}

node *copy(node *root) {
	if (!root)
		return root;
	node *elem = (node *)malloc(sizeof(node));
	elem->value = root->value;
	elem->left = copy(root->left);
	elem->right = copy(root->right);
	return elem;
}

int max(int a, int b) {
	return (a>b?a:b);
}


int depth(node *root) {
	if (!root)
		return 0;

	int left_depth = 1 + depth(root->left);
	int right_depth = 1 + depth(root->right);
	return max(left_depth, right_depth);
}

int num_nodes(node *root) {
	if(!root) {
		return 0;
	}

	int num_left_nodes = num_nodes(root->left);
	int num_right_nodes = num_nodes(root->right);
	return (num_left_nodes + num_right_nodes + 1);
}

void destroy(node **root) {
	if (!*root)
		return;
	destroy(&(*root)->left);
	destroy(&(*root)->right);
	free(*root);
	*root = NULL;
}

int is_identical(node *t1, node *t2) {
	if (!t1 && !t2)
		return 1;
	else if (!t1)
		return 0;
	else if (!t2)
		return 0;

	int is_root_identical = 0;
	int is_left_identical = 0;
	int is_right_identical = 0;


	if (t1->value == t2->value) {
		is_root_identical = 1;
	}

	is_left_identical = is_identical(t1->left, t2->left);
	is_right_identical = is_identical(t1->right, t2->right);

	return (is_root_identical & is_left_identical & is_right_identical);
}

int num_leaves(node *root) {
	if (!root)
		return 0;

	if (!root->left && !root->right) {
		return 1;
	}

	int num_left_leaves = num_leaves(root->left);
	int num_right_leaves = num_leaves(root->right);

	return (num_left_leaves+num_right_leaves);
}