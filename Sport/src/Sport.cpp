#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	string str[2];
	cin >> str[0] >> str[1];
	int n;
	n = str[0].size();

	int empty = 0;
	for (int i = 0; i < n; i++) {
		if (str[0][i] == 'P' and str[1][i] == 'P') {
			empty++;
		}
	}

	if (empty == n) {
		cout << -1;
	} else {
		int dp[n + 1][5];

		for (int k = 0; k < 5; k++) {
			dp[0][k] = 0;
		}

		for (int i = 1; i <= n; i++) {
			for (int k = 0; k < 5; k++) {
				if (str[0][i - 1] == 'P' and str[1][i - 1] == 'P') {
					dp[i][k] = dp[i - 1][k] + 1;
				} else if (str[0][i - 1] == 'P' and str[1][i - 1] == 'S') {
					dp[i][k] = min(dp[i - 1][1] + (k == 0) + (k == 2), dp[i - 1][3] + (k == 0) + (k != 3));
				} else if (str[0][i - 1] == 'S' and str[1][i - 1] == 'P') {
					dp[i][k] = min(dp[i - 1][2] + (k == 0) + (k == 1), dp[i - 1][4] + (k == 0) + (k != 4));
				} else {
					dp[i][k] = dp[i - 1][k];
				}
			}
		}

		cout << dp[n][0];
	}
	return 0;
}
