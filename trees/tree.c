
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