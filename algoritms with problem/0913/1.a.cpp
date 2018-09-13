#include <iostream>

using namespace std;

double func(int, int);

int main() {
	int n, k;
	cin >> n >> k;
	//Àç±Í
	cout << func(n, k) <<endl;
	//ºñÀç±Í
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