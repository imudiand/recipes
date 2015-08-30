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


int factorial_recursive(int num) {
	if (num < 0)
		return -1;

	if (num < 2)
		return 1;

	return num*factorial_recursive(num-1);
}


double x_power_n_iterative(float x, int n) {
	int i;
	float res = 1;
	if (n == 0) {
		return res;
	} else if (n < 0) {
		for (i=0; i>n; i--) {
			res *= 1/x;
		}
	} else {
		for (i=0; i<n; i++) {
			res *= x;
		}
	}

	return res;
}