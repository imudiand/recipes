#include "bit.h"


int main(void) {

	printf("%s\n", "--- set/reset bits ---");
	printf("%d\n", set_nth_bit(8, 2));
	printf("%d\n", clear_nth_bit(8, 3));

	printf("%s\n", "--- toggle bits ---");
	int num = 0;
	printf("%d\n", num = toggle_nth_bit(num, 3));
	printf("%d\n", toggle_nth_bit(num, 3));

	printf("%s\n", "--- int sign ---");
	printf("%d\n", int_sign(8));
	printf("%d\n", int_sign(0));
	printf("%d\n", int_sign(-8));

	printf("%s\n", "--- has opposite signs ---");
	printf("%d\n", has_opposite_signs(8, 4));
	printf("%d\n", has_opposite_signs(-8, 4));
	printf("%d\n", has_opposite_signs(8, -4));
	printf("%d\n", has_opposite_signs(-8, -4));

	printf("%s\n", "--- test nth bit ---");
	printf("%d\n", test_nth_bit(8, 4));
	printf("%d\n", test_nth_bit(8, 3));
	printf("%d\n", test_nth_bit(8, 2));

	printf("%s\n", "--- is power of 2 ---");
	printf("%d\n", is_power_of_2(8));
	printf("%d\n", is_power_of_2(5));
	printf("%d\n", is_power_of_2(16));
	printf("%d\n", is_power_of_2(14));
	printf("%d\n", is_power_of_2(0));

	printf("%s\n", "--- Min/Max ---");
	printf("%d\n", min(8, 2));
	printf("%d\n", max(8, 2));

	printf("%s\n", "--- Merge bits per mask ---");
	// 1000, 0101, 1100 = (0 | 0100) = 0100 = 4
	printf("%d\n", merge_bits(8, 5, 12));

	printf("%s\n", "--- Count bits set ---");
	printf("%d\n", num_set_bits(8));
	printf("%d\n", num_set_bits(31));

	printf("%s\n", "--- Count bits set with Lookup table ---");
	printf("%d\n", num_set_bits_lookup(8));
	printf("%d\n", num_set_bits_lookup(31));

	printf("%s\n", "--- Count parity bits with Lookup table ---");
	printf("%d\n", num_of_parity_bits(8));
	printf("%d\n", num_of_parity_bits(31));
	printf("%d\n", num_of_parity_bits(15));

	printf("%s\n", "--- swap integers ---");
	int a = 4, b = 7;
	printf("%d, %d\n", a, b);
	swap(&a, &b);
	printf("%d, %d\n", a, b);



	return 0;
}