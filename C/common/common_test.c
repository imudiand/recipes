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
}