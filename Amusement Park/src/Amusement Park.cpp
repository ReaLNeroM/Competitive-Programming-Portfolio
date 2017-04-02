#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1005;
int dp[maxn][maxn];
int val[maxn][maxn];
int sum[maxn][maxn];

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	int n, k;
	cin >> n >> k;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> val[i][j];
			if(j < i){
				val[i][j] = 0;
			}
			if(i > 0){
				val[i][j] += val[i - 1][j];
			}
			if(j > 0){
				val[i][j] += val[i][j - 1];
			}
			if(i > 0 and j > 0){
				val[i][j] -= val[i - 1][j - 1];
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			if(i - 1 >= 0){
				sum[i][j] = val[j][j] - val[i - 1][j] - val[j][i - 1] + val[i - 1][i - 1];
			} else {
				sum[i][j] = val[j][j];
			}
		}
	}

	for(int i = 1; i <= n; i++){
		dp[i][0] = 1e9;
	}

	for(int x = 1; x <= k; x++){
		for(int i = 0; i < n; i++){
			dp[i + 1][x] = 1e9;
			for(int j = 0; j <= i; j++){
				dp[i + 1][x] = min(dp[i + 1][x], dp[j][x - 1] + sum[j][i]);
			}
		}
	}
	cout << dp[n][k];
}
