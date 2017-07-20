#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 4005;
int v[maxn][maxn];
int dp[maxn][maxn];
int ind[maxn][maxn];
int n, k;

void calc(int pos, int l, int r, int cl, int cr){
	int mid = (l + r) / 2;
	
	dp[pos][mid] = 1e9;
	for(int i = cl; i <= cr; i++){
		if(dp[pos][mid] > dp[i - 1][mid - 1] + v[pos][pos] - v[pos][i - 1] - v[i - 1][pos] + v[i - 1][i - 1]){
			dp[pos][mid] = dp[i - 1][mid - 1] + v[pos][pos] - v[pos][i - 1] - v[i - 1][pos] + v[i - 1][i - 1];
			ind[pos][mid] = i;
		}
	}
	
	if(l < r){
		calc(pos, l, mid, cl, ind[pos][mid]);
		calc(pos, mid + 1, r, ind[pos][mid], cr);
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	
	std::cin >> n >> k;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			std::cin >> v[i][j];
			v[i][j] += v[i - 1][j];
			v[i][j] += v[i][j - 1];
			v[i][j] -= v[i - 1][j - 1];
		}
	}
		
	for(int i = 0; i < maxn; i++){
		ind[1][i] = 1;
	}
	
	
	for(int i = 2; i <= n; i++){
		calc(i, 0, k - 1, 1, i - 1);
	}
	
	std::cout << dp[n][k] << std::endl;
}