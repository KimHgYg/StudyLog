/*
	입력값 n,k
	1~n 까지의 각 수의 k제곱의 합을 구함
*/
#include <iostream>

using namespace std;

double func(int, int);

int main() {
	int n, k;
	cin >> n >> k;
	//재귀
	cout << func(n, k) <<endl;
	//비재귀
	double sum = 0;
	for (int i = 0; i <= n; i++) {
		sum += pow(i, k);
	}
	cout << sum;
	getchar(); getchar();
}

double func(int n, int k) {
	if (n == 1) {
		return 1;
	}

	return pow(n, k) + func(n - 1, k);
}