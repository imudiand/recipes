#include "bit.h"

int set_nth_bit(int number, int n) {
	return number |= 1<<n;
}

int clear_nth_bit(int number, int n) {
	return number & ~(1<<n);
}

int toggle_nth_bit(int number, int n) {
	return number ^= 1<<n;
}

signed int int_sign(int n) {
	return (n>0)-(n<0);
}

unsigned int has_opposite_signs(int a, int b) {
	return (a^b)<0;
}

unsigned int test_nth_bit(int num, int n) {
	num &= 1<<n;
	return (num != 0);
}

unsigned int is_power_of_2(int num) {
	return num && !(num & (num-1));
}

int min(int a, int b) {
	return a<b?a:b;
}

int max(int a, int b) {
	return a>b?a:b;
}

int merge_bits(int a, int b, int mask) {
	/* Merge bits in a & b according to a mask */
	return (a & ~mask) | (b & mask);
}

void swap(int *a, int *b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int num_set_bits(int num) {
	int count = 0;
	while(num) {
		num &= (num-1);
		count++;
	}
	return count;
}

/* Solutions employing lookup tables */

#define B2(n)	n,	n+1,	n+1,	n+2
#define B4(n)	B2(n),	B2(n+1),	B2(n+1),	B2(n+2)
#define B6(n)	B4(n),	B4(n+1),	B4(n+1),	B4(n+2)
#define B8(n)	B6(n),	B6(n+1),	B6(n+1),	B6(n+2)

/* 4*4 = 256 ==> hence use char */
static const unsigned char set_bits_lookup[256] = {B8(0)};

unsigned int num_set_bits_lookup(int num) {
	unsigned int count;
	count = set_bits_lookup[num & 0xff] + set_bits_lookup[num>>8 & 0xff] + set_bits_lookup[num>>16 & 0xff] + set_bits_lookup[num>>24 & 0xff];
	return count;
}



#define P2(n)	n,	n^1,	n^1,	n
#define P4(n)	P2(n),	P2(n^1),	P2(n^1),	P2(n)
#define P6(n)	P4(n),	P4(n^1),	P4(n^1),	P4(n)
#define P8(n)	P6(n),	P6(n^1),	P6(n^1),	P6(n)

/* 4*4 = 256 ==> hence use char */
static unsigned char parity_lookup[256] = {P8(0)};

unsigned int num_of_parity_bits(int num) {
	unsigned int count;
	count = parity_lookup[num & 0xff] ^ parity_lookup[num>>8 & 0xff] ^ parity_lookup[num>>16 & 0xff] ^ parity_lookup[num>>24 & 0xff];
	return count;
}

