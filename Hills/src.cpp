#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 5100;

int n;
int dp[maxn][maxn / 2][2];
int val[maxn];

int dpfunc(int pos, int res, int above){
	if(dp[pos][res][above] != -1)
		return dp[pos][res][above];

	int& ans = dp[pos][res][above];
	ans = 1e9;

	if(res == 0){
		ans = 0;
		return ans;
	} else if(pos >= n){
		return ans;
	}

	ans = dpfunc(pos + 1, res, false);
	ans = std::min(ans, dpfunc(pos + 1, res, true) + std::max(0, val[pos] - val[pos + 1] + 1));

	if(above){
		int next_value = std::min(val[pos + 1], val[pos] - 1);
		int next_cost = val[pos + 1] - next_value;

		ans = std::min(ans, dpfunc(pos + 2, res - 1, false) + next_cost);
		ans = std::min(ans, dpfunc(pos + 2, res - 1, true) + next_cost + std::max(0, next_value - val[pos + 2] + 1));
	}

	return ans;
}

int main(){
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	memset(dp, -1, sizeof(dp));

	for(int i = 1; 2 * i <= n + 1; i++){
		std::cout << dpfunc(0, i, 1) << ' ';
	}
	
	std::cout << '\n';
}
