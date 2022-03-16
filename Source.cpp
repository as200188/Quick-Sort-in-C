#include <stdio.h>
#include <stdlib.h>
#include <random>

#define SWAP(a, b){ \
	int temp = 0; \
	temp = *a; \
	*a = *b; \
	*b = temp; \
}

void q_sort(int *arr, int front, int tail) {
	if (!(front < tail && front >= 0))
		return;

	int pivot = tail;
	int cur = front;
	int mid = front;

	while (cur < pivot) {
		
		if (arr[cur] <= arr[pivot]) {
			SWAP(&arr[mid], &arr[cur]);
			mid++;
		}
		
		cur++;
	}

	SWAP(&arr[mid], &arr[pivot]);

	q_sort(arr, front, mid-1);
	q_sort(arr, mid+1, tail);
}

int main() {
	int MAX_SIZE = 100;
	int *arr_ptr = (int *)malloc(MAX_SIZE * sizeof(int));

	if (arr_ptr) {

		for (int i = 0; i < MAX_SIZE; i++) {
			arr_ptr[i] = rand();
		}

		
		q_sort(arr_ptr, 0, 99);

		for (int i = 0; i < MAX_SIZE; i++) {
			printf("%d\n", arr_ptr[i]);
		}
		

		free(arr_ptr);
	}


	return 0;
}