/*
	입력값 : n, m (n >= m )
	m개의 자연수를 더해서 n을 만드는 모든 방법을 출력
*/

#include <iostream>
#include <time.h>

#define max 10

using namespace std;

void func(int, int, int, int);
void print_arr(int *);
void m_sum(int, int, int *, int);
int nn, m;

int main() {
	clock_t start, end;
	double result_1, result_2;
	cout << "n, m 을 입력해 주십시오 (n >=m, m < " << max << ")" << endl;
	cin >> nn >> m;
	int num[max] = { 0 };
	start = clock();
	func(nn, 1, 0, 1);
	end = clock();
	result_1 = (double)(end - start);
	start = clock();
	m_sum(nn, m, num,0);
	end = clock();
	result_2 = (double)(end - start);
	cout << result_1 << "  " << result_2;
	getchar(); getchar();
}

void func(int n, int k, int d, int sum) {
	static int arr[max] = { 0 };
	arr[d] = k;
	if (d == (m - 1)) {
		if ((sum = n) > nn)
			return;
		arr[d] = n;
		print_arr(arr);
		return;
	}
	else if ((n - k) <= 0)
		return;
	if (k > n)
		return;
	func(n - k, 1, d + 1, sum + 1);
	func(n, k + 1, d, sum + k + 1);
}
//책 해설

void m_sum(int n, int m, int *num, int index) {
	int i;
	if (index == m) {
		if (n == 0)
			print_arr(num);
		return;
	}
	for (i = 1; i <= n; i++) {
		num[index] = i;
		m_sum(n - i, m, num, index + 1);
	}
}

void print_arr(int *arr) {
	for (int i = 0; i < m; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}