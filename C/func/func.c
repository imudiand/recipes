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

char *str_cpy(char *dest, const char *src) {
	while(*src != '\0') {
		*dest++ = *src++;
	}
	return dest;
}

int str_cmp(char *s1, char *s2) {
	while(*s1++ == *s2++) {
		if (*s1 == '\0' && *s2 == '\0')
			return 0;
	}
	return (*s1-*s2);
}

char upper_case(char ch) {
	if ('z' >= ch && ch >= 'a') {
		ch = ch - 'a' + 'A';
	}
	return ch;
}

int is_upper_case(char ch) {
	if ('Z' >= ch && ch >= 'A')
		return 1;
	return 0;
}