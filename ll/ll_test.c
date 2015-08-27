#include "ll.h"



int main(void) {
	int i;
	node *l1, *l2, *l3;

	/* append() */
	printf("=== Tesing Append ===\n");
	l1 = NULL;
	for (i=0; i<10; i++) {
		append(&l1, i);
	}
	print(l1);


	/* concatenate() */
	printf("=== Tesing Concatenate ===\n");
	l1 = NULL;
	l2 = NULL;
	for (i=0; i<10; i++) {
		append(&l1, i);
		append(&l2, (20+i));
	}
	l3 = concatenate(l1, l2);
	print(l3);

	/* iterative_reverse */
	printf("=== Iterative Reverse ===\n");
	l1 = NULL;
	for (i=0; i<10; i++) {
		append(&l1, i);
	}
	iterative_reverse(&l1);
	print(l1);

	/* recursivee_reverse */
	printf("=== Recursive Reverse ===\n");
	l1 = NULL;
	for (i=0; i<10; i++) {
		append(&l1, i);
	}
	l2 = recursive_reverse(NULL, l1);
	print(l2);

	/* Destroy */
	printf("=== Destroy ===\n");
	l1 = NULL;
	for (i=0; i<10; i++) {
		append(&l1, i);
	}
	destoy(&l1);
	if (!l1) {
		printf("List was Destroyed\n");
	}

	/* Delete */
	printf("=== Delete 3, 5, 6, 9 ===\n");
	l1 = NULL;
	for (i=0; i<10; i++) {
		append(&l1, i);
	}
	print(l1);
	delete(&l1, 0);
	delete(&l1, 5);
	delete(&l1, 6);
	delete(&l1, 8);
	delete(&l1, 9);

	print(l1);



	return 0;
}