#include "tree.h"

int main(void) {
	int i;
	node *t1, *t2, *t3;

	/* recursive_insert() */
	printf("=== Tesing Insert Recursive ===\n");
	t1 = NULL;

	int tree_values[10] = {5, 8, 3, 6, 1, 4, 9, 0, 7, 2};

	for (i=0; i<10; i++) {
		recursive_insert(&t1,tree_values[i]);
	}

	printf("=== Inorder Traversal ===\n");
	print_inorder_traverse(t1);
	printf("\n");


	printf("=== PreOrder Traversal ===\n");
	print_preorder_traverse(t1);
	printf("\n");

	printf("=== PostOrder Traversal ===\n");
	print_postorder_traverse(t1);
	printf("\n");

	node *elem;
	printf("=== Recursive Search ===\n");
	elem = recursive_search(t1, 5);
	printf("%d\n", elem->value);
	printf("%d\n", elem->left->value);
	printf("%d\n", elem->right->value);
	printf("\n");
}