#include <stdio.h>
#include <stddef.h>

struct Node {
	int value1;
	float value2;
	char value3;
	char value4;
};

/* Find offset address of an element in a struct */
#define offset_addr(Struct, Elem)	(&((Struct *)0)->Elem)

/* Find offset of an element in a struct */
#define offset(Struct, Elem)	((unsigned int)((char *)&((Struct *)0)->Elem - (char*)0))


unsigned int size_of() {
	typedef struct Node *Node;
	Node *node;

	int size = ((char*)(node+1) - (char *)node);
	return size;
}

int main() {

	printf("%s\n", "--- Find Offset address ---");
	printf("%p\n", offset_addr(struct Node, value1));
	printf("%p\n", offset_addr(struct Node, value2));
	printf("%p\n", offset_addr(struct Node, value3));
	printf("%p\n", offset_addr(struct Node, value4));

	printf("%s\n", "--- Find Offset ---");
	printf("%d\n", offset(struct Node, value1));
	printf("%d\n", offset(struct Node, value2));
	printf("%d\n", offset(struct Node, value3));

	printf("%s\n", "--- Find Offset using offset() func from stddef.h ---");
	printf("%d\n", offsetof(struct Node, value1));
	printf("%d\n", offsetof(struct Node, value2));
	printf("%d\n", offsetof(struct Node, value3));

	printf("%s\n", "--- Size of ---");
	struct Node *Struct = 0;
	printf("%d\n", size_of());

	return 0;
}