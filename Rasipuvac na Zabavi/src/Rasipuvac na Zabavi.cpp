#include <iostream>
#include <cmath>

typedef long long ll;

int gcd(int a, int b) {
	if (a < b) {
		std::swap(a, b);
	}
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

int p, on;
std::pair <int, int> dp[1001][1001];

std::pair <int, int> find(int first, int second) {
	if (dp[first][second].first == -1) {
		if (on - first == p - 1 or on - second == p - 1) {
			dp[first][second].first = 0;
		} else {
			std::pair<int, int> x = find(first + 1, second);
			std::pair<int, int> y = find(first, second + 1);
			dp[first][second].first = x.first * y.second + x.second * y.first + x.second * y.second * 2;
			dp[first][second].second = x.second * y.second * 2;
		}
	}

	return dp[first][second];
}

int main() {
	std::cin >> p >> on;

	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			dp[i][j].first = -1;
			dp[i][j].second = 1;
		}
	}

	std::cout << find(0, 0).first / gcd(find(0, 0).first, find(0, 0).second) << ' ' << find(0, 0).second / gcd(find(0, 0).first, find(0, 0).second);
	return 0;
}
