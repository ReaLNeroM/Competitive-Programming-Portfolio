#include <iostream>

typedef long long ll;

int n;
char val[5001];

int dp[5001][5001];

int min(int a, int b){
	if(a > b){
		return b;
	}

	return a;
}
int find(int i, int j) {
	if (dp[i][j] == n) {
		if (val[i] == val[j]) {
			dp[i][j] = find(i + 1, j - 1);
		} else {
			dp[i][j] = min(find(i + 1, j), find(i, j - 1)) + 1;
		}
	}

	return dp[i][j];
}
int main() {
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> val[i];
		dp[i][i - 1] = 0;
		dp[i][i] = 0;
		for (int j = i + 1; j <= n; j++) {
			dp[i][j] = n;
		}
	}

	std::cout << find(1, n);
	return 0;
}
