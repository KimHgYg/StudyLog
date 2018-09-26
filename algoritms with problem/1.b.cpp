/*
	입력값 : 줄 수 k
	파스칼 삼각형 출력하기
*/
#include <iostream>

using namespace std;
#define max 10
void combination(int , int, int);
int rev_comb(int, int);

int memo[max][max];

int main() {
	int k;
	cin >> k;
	memset(memo, 0, (max)*(max) * sizeof(int));
	//combination(1, 1, k);
	rev_comb(k, k);
	int i = 1, j = 1;
	while (1) {
		cout << memo[i][j] << " ";
		if (i == j) {
			cout << endl;
			if (j == k)
				break;
			i++; j = 1;
			continue;
		}
		j++;
	}
	getchar(); getchar();
}

void combination(int n, int r, int k) {
	if (n == r) {
		memo[n][r] = 1;
		if (r == k)
			return;
		combination(n + 1, 1, k);
	}
	else {
		memo[n][r] = memo[n - 1][r - 1] + memo[n - 1][r];
		combination(n, r + 1, k);
	}
}

int rev_comb(int n, int r) {
		if (memo[n][r] != 0)
			return memo[n][r];
		if (n == r) {
			memo[n][r] = 1;
			if (r == 1)
				return 1;
		}
		else if (r == 1) {
			memo[n][r] = 1;
			return rev_comb(n - 1, n - 1);
		}
		else
			memo[n][r] = rev_comb(n - 1, r - 1) + rev_comb(n - 1, r);
		rev_comb(n, r - 1);
}