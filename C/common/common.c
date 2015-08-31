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

long max_subarray(int *list, int size) {
	int max_num = 0;
	int max_in_iter = 0;
	int i,j;

	for(i=0; i<(size-1); i++) {
		max_in_iter = 0;
		for(j=i; j<(size-1); j++) {
			max_in_iter += list[j];
			max_num = (max_num>max_in_iter)?max_num:max_in_iter;
		}
	}
	return max_num;
}

int fib_iterative(int num) {
	if (num < 0) {
		return -1;
	}
	if (num == 0) {
		return 0;
	}
	if (num < 3) {
		return 1;
	}


	int i;
	int prev=1, res=1;
	int temp;

	for (i=3; i<=num; i++) {
		temp = res;
		res += prev;
		prev = temp;
	}
	return res;
}

int fib_recursive(int num) {
	if (num<0)
		return -1;
	if (num == 0)
		return 0;
	if (num < 3)
		return 1;

	return fib_recursive(num-1)+fib_recursive(num-2);
}

/*	
	Little Endian: lower order byte in lowest address
	Example: for int i = 1;
	value:	0001 0000 0000 0000
	addr: 	0x0	 0x1  0x2  0x3  	0x4
	Here; lowest address is at location 0x0 & the value at that byte is 1;

	Bign Endian: lower order byte in highest address
*/
void endianness(int num) {
	if (*((char *)(&num)) == 1) {
		printf("%s\n", "Little Endian");
	} else {
		printf("%s\n", "Big Engian");
	}
}