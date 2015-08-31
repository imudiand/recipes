#include "common.h"

int main(void) {
	printf("%s\n", "--- Factorial ---");
	printf("%d\n", factorial_iterative(5));
	printf("%d\n", factorial_recursive(5));

	printf("%s\n", "--- x^n ---");
	printf("%f\n", x_power_n_iterative(2,-4));
	printf("%f\n", x_power_n_iterative(2,4));

	printf("%s\n", "--- x^n ---");
	printf("%f\n", x_power_n_recursive(2,-4));
	printf("%f\n", x_power_n_recursive(2,4));

	printf("%s\n", "--- x^n ---");
	printf("%f\n", x_power_n_recursive_div_conquer(2,-4));
	printf("%f\n", x_power_n_recursive_div_conquer(2,4));

	printf("%s\n", "--- max sub_array ---\n");
	int list[10] = {3,4,2,1,-2,4,2,-2,1,-6};
	printf("%ld\n", max_subarray(list,10));

	printf("%s\n", "--- fibonacci iterative ---\n");
	printf("%d\n", fib_iterative(7));

	printf("%s\n", "--- fibonacci recursive ---\n");
	printf("%d\n", fib_recursive(7));

	printf("%s\n", "--- endianness ---\n");
	endianness(1);

	return 0;
}