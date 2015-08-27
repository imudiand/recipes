#include "func.h"

int main(void) {
	char *name = "Harshit Imudianda";
	char dummy[18];

	mem_move(dummy, name, 18);

	printf("%s\n", name);
	printf("%s\n", dummy);	

	int retval;
	retval = atoi("-11");
	printf("%d\n", retval);

	return 0;
}