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


	return 0;
}