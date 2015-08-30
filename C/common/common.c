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

double x_power_n_recursive(float x, int n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	if (n == -1)
		return 1/x;

	if (n>1) {
		return x*x_power_n_recursive(x, n-1);
	} else {
		return 1/x*x_power_n_recursive(x, n+1);
	}
}

int is_even(int num) {
	return ((num%2) == 0);
}

double x_power_n_recursive_div_conquer(float x, int n) {
	int res;
	if (n==0)
		return 1;
	if (n==1)
		return x;
	if (n == -1)
		return 1/x;

	if (n>1) {
		if (is_even(n)) {
			res = x_power_n_recursive_div_conquer(x, n/2) * x_power_n_recursive_div_conquer(x, n/2);
		} else {
			res = x_power_n_recursive_div_conquer(x, n/2) * x_power_n_recursive_div_conquer(x, (n/2)+1);
		}
	} else {
		if (is_even(n)) {
			res = x_power_n_recursive_div_conquer(x, n/2) * x_power_n_recursive_div_conquer(x, n/2);
		} else {
			res = x_power_n_recursive_div_conquer(x, n/2) * x_power_n_recursive_div_conquer(x, (n/2)-1);
		}
	}
	return res;
}