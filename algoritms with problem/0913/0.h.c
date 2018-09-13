#include <stdio.h>

int sum(int, int);
int arr[10] = { 12, 2, -5, 23, 6, 12, 25, -25, 3, -4 };

int main() {
	int i, j, p, max = 0, max_i = -1, max_j = -1;
	scanf("%d", &p);
	i = p;
	while (i > -1) {
		for (j = p; j < 10; j++) {
			int tmp = sum(i, j);
			if (max < tmp) {
				max = tmp;
				max_i = i;
				max_j = j;
			}
		}
		i--;
	}
	printf("Max value = %d and index i = %d, j = %d", max, max_i, max_j);
	getchar();
	getchar();
	return;
}

int sum(int i, int j) {
	int n = 0;
	int k;
	for (k = i; k <= j; k++) {
		n += arr[k];
	}
	return n;
}