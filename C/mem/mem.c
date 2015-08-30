#include <stdio.h>


/* Find offset address of an element in a struct */
#define offset_addr(Struct, Elem)	(&((Struct *)0)->Elem)

/* Find offset of an element in a struct */
#define offset(Struct, Elem)	((unsigned int)((char *)&((Struct *)0)->Elem - (char*)0))

struct Node {
	int value1;
	float value2;
	char value3;
};

int main() {

	printf("%p\n", offset_addr(struct Node, value1));
	printf("%p\n", offset_addr(struct Node, value2));
	printf("%p\n", offset_addr(struct Node, value3));

	printf("%d\n", offset(struct Node, value1));
	printf("%d\n", offset(struct Node, value2));
	printf("%d\n", offset(struct Node, value3));

	return 0;
}