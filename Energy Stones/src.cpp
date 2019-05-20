#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e2 + 10;
const ll maxbit = (1 << 17);
const ll INF = 1000000000000000010;

static int dp[maxn][maxn * maxn];
int n;
std::vector<int> v[maxn];

int dfs(int pos, int time){
	if(pos == n){
		return 0;
	}

	if(dp[pos][time] != -1){
		return dp[pos][time];
	}

	int& ans = dp[pos][time];
	ans = 0;

	for(int i = pos; i < n; i++){
		ans = std::max(ans, dfs(i + 1, time + v[i][2]) + std::max(0, v[i][1] - v[i][0] * time));
	}

	return dp[pos][time];
}

bool cmp(std::vector<int> const &x, std::vector<int> const &y){
	if(x[0] != y[0]){
		return x[0] > y[0];
	}

	return x[2] < y[2];
}

int main(){
	std::ios::sync_with_stdio(false);

	ll testCases;
	std::cin >> testCases;

	for(ll testcase = 1; testcase <= testCases; testcase++){

		std::cout << "Case #" << testcase << ": ";

		std::cin >> n;

		int sum = 0;

		for(int i = 0; i < n; i++){
			v[i].resize(3);

			std::cin >> v[i][2] >> v[i][1] >> v[i][0];
			sum += v[i][2];
		}

		std::sort(v, v + n, cmp);

		for(int i = n; i >= 0; i--){
			for(int j = sum; j >= 0; j--){
				if(i == n){
					dp[i][j] = 0;
				}

				int& ans = dp[i][j];
				ans = 0;

				for(int k = i; k < n; k++){
					ans = std::max(ans, dp[k + 1][j + v[k][2]] + std::max(0, v[k][1] - v[k][0] * j));
				}
			}
		}

		std::cout << dp[0][0];

		std::cout << '\n';
	}
}
