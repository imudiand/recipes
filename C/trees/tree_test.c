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

	printf("=== Copy Tree ===\n");
	t2=copy(t1);
	print_inorder_traverse(t1);
	printf("\n");
	print_inorder_traverse(t2);
	printf("\n");

	printf("=== Depth ===\n");
	int _d = depth(t1);
	printf("%d\n", _d);
	printf("\n");


	printf("=== Num Nodes ===\n");
	int _n = num_nodes(t1);
	printf("%d\n", _n);
	printf("\n");

	printf("=== Destroy ===\n");
	destroy(&t1);
	print_inorder_traverse(t1);
	printf("\n");


	printf("=== Is Identical ===\n");
	t1=NULL;
	t2=NULL;

	for (i=0; i<10; i++) {
		recursive_insert(&t1,tree_values[i]);
		recursive_insert(&t2,tree_values[i]);
	}

	int identical = is_identical(t1, t2);
	if (identical)
		printf("%s\n", "Trees are identical");
	else
		printf("%s\n", "Trees are not identical");
	printf("\n");


	printf("=== Num of Leaves ===\n");
	int leaves = num_leaves(t1);
	printf("%d\n", leaves);
	printf("\n");

}