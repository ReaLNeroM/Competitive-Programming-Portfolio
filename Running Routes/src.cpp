#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 5e2;
int n;
static int mat[maxn][maxn];
static int dp[maxn][maxn];

int dpfunc(int a, int b){
	if(dp[a][b] != -1){
		return dp[a][b];
	}

	int& ans = dp[a][b];
	ans = 0;
	if(b <= 1){
		return ans;
	}

	if(n >= 2 and mat[a][(n + a + b - 1) % n]){
		ans = std::max(ans, 1 + dpfunc((a + 1) % n, n - 2));
	}
	ans = std::max(ans, dpfunc((a + 1) % n, n - 1));
	ans = std::max(ans, dpfunc(a, n - 1));

	return ans;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cin >> mat[i][j];
		}
	}

	int best = 0;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; i++){
		best = std::max(best, dpfunc(i, n));
	}
	std::cout << best << '\n';
}
