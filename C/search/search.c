#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/* O(n) */
int linear_search(int *list, int size, int num) {
	int i;
	for (i=0; i<size; i++) {
		if (list[i] == num)
			return i;
	}
	return -1;
}

/* O(log n)*/
/* Only works on sorted lists */
int binary_search_iterative(int *list, int size, int num) {
	int start=0, end=size, mid;

	while(1){
		mid = (end+start)/2;
		if (num == list[mid]) {
			return mid;
		} else if (num < list[mid]) {
			end = mid-1;
		} else {
			start = mid+1;
		}
	}
}

int binary_search_recursive(int *list, int start, int end, int num) {
	int mid = (end+start)/2;
	if (num == list[mid]) {
		return mid;
	} else if (num < list[mid]) {
		return binary_search_recursive(list, start, mid-1, num);
	} else {
		return binary_search_recursive(list, mid+1, end, num);
	}
}


int main(void) {
	int list[10] = {1,2,3,4,5,6,7,8,9,10};

	printf("%d\n", linear_search(list, 10, 6));
	printf("%d\n", binary_search_iterative(list, 10, 6));

	printf("%d\n", binary_search_recursive(list, 0, 9, 6));


	return 0;
}