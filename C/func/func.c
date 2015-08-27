#include "func.h"

void mem_move(void *dest, void *src, int size) {
	char *from = (char *)src;
	char *to = (char *)dest;

	char *ptr = from+size-1;

	while(ptr != from && ptr != to) {
		--ptr;
	}

	if (ptr == to) {
		/* Copy from behind */
		from = from+size-1;
		to = to+size-1;
		while(size--) {
			*to-- = *from--;
		}
		
	} else {
		/* Copy from front */
		while(size--) {
			*to++ = *from++;
		}
	}
}

int atoi(const char *str) {
	int ret=0;
	int is_negative = 0;

	if (*str == '-') {
		is_negative = 1;
		str++;
	}

	while(*str) {
		ret = (*str-'0') + (ret<<1) + (ret<<3);
		str++;
	}

	if (is_negative)
		return (-1)*ret;
	return ret;
}