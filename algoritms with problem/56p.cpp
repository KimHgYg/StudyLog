/*
	입력값 : n
	지각할 확률이 1/2인 피곤해씨
	상사는 3일 연속 지각할시 혼을냄
	n일동안 한번도 혼나지 않을 확률
*/

#include <iostream>
#include <math.h>

using namespace std;
int function(int *, int);

int main() {
	int n;
	unsigned int c;
	cin >> n;
	int *memo = (int *)malloc(n*(sizeof(int)));
	memset(memo, 0, n * sizeof(int) + 4);
	c = function(memo, n);
	double p = c / pow(2.0, n);
	cout << "경우의 수 : " << c << " 확률 : " << p;
	getchar(); getchar();
}

int function(int *memo, int n) {
	if (n == 1)
		return memo[n] = 2;
	else if (n == 2)
		return memo[n] = 4;
	else if (n == 3)
		return memo[n] = 7;
	if (memo[n] != 0)
		return memo[n];
	return memo[n] = (function(memo, n - 1) + function(memo, n - 2) + function(memo, n - 3));
}