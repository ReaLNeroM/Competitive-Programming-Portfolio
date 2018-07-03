#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
const int INF = 1e9;
int n, start, buy;
int dp[maxn][maxn];

int dpfunc(int made, int soldiers){
	if(dp[made][soldiers] != -1){
		return dp[made][soldiers];
	}

	int& ans = dp[made][soldiers];

	if(made >= n){
		ans = 0;
	} else {
		ans = INF;

		ans = std::min(ans, dpfunc(std::min(n, made + soldiers), soldiers) + 1);
		if(made >= buy){
			ans = std::min(ans, dpfunc(made - buy, soldiers + 1));
		}
	}

	return ans;
}
int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> start >> buy;

	memset(dp, -1, sizeof(dp));

	std::cout << dpfunc(0, start) << '\n';
}