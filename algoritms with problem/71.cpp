/*
	gray_code Ãâ·Â
*/

#include <iostream>

#define MAX 20
using namespace std;

void print_gray(int *, int, int, int);
void print_code(int *, int);

int main() {
	int code[MAX];
	int n;
	cin >> n;
	cout << endl;
	print_gray(code, n, 0, 0);
	getchar(); getchar();
	return 0;
}

void print_gray(int *code, int n, int index, int reverse) {
	if (index == n) {
		print_code(code, n);
		return;
	}

	code[index] = reverse;
	print_gray(code, n, index + 1, 0);
	code[index] = 1 - reverse;
	print_gray(code, n, index + 1, 1);
}

void print_code(int *code, int len) {
	int i;

	for (i = 0; i < len; i++) {
		cout << code[i];
	}
	cout << endl;
}