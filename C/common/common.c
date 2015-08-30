#include "common.h"

int factorial_iterative(int num) {
	if (num < 0)
		return -1;

	int res = 1;
	if (num < 2)
		return res;

	while(num != 1) {
		res *= num;
		num--;
	}
	return res;
}