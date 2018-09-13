#include <iostream>
#include <math.h>

using namespace std;
double function(double *, int);

int main() {
		int n;
		unsigned int c;
		cin >> n;
		double *memo = (double *)malloc((n + 1) * (sizeof(double)));
		memset(memo, 0, (n + 1) * sizeof(double));
		cout << "È®·ü : " << function(memo, n);
		getchar(); getchar();
}

double function(double *memo, int n) {
	if (n == 1)
		return memo[n] = 1.0;
	else if (n == 2)
		return memo[n] = 5.0/9.0;
	else if (n == 3)
		return memo[n] = 19.0/27.0;
	if (memo[n] != 0)
		return memo[n];
	return memo[n] = 1.0/3.0*(function(memo, n - 1) + 2.0/9.0*function(memo, n - 2) + 4.0/27.0*function(memo, n - 3));
}