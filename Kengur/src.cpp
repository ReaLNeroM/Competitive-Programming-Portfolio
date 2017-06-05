#include <bits/stdc++.h>

const int maxn = 205;
const int mod = 1e9 + 7;
int dp[maxn][maxn][maxn];
int n, s, e;

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> s >> e;

	dp[1][1][1] = 1;
	dp[2][1][2] = 1;
	dp[2][2][1] = 1;
	dp[2][1][1] = 0;
	dp[2][2][2] = 0;

	int si, sj;
	for(int x = 3; x <= n; x++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				si = i, sj = j;
				if(i > j){
					si = n - i;
					sj = n - j;
				}
				
				if(si == 1){
					if(n % 2 == 1){
						dp[x][1][sj] = dp[x][1][sj - 1] - dp[x - 1][1][sj - 1];
						dp[x][1][sj] %= mod;
					} else {
						dp[x][1][sj] = dp[x][1][sj - 1] + dp[x - 1][1][sj - 1];
						dp[x][1][sj] %= mod;
					}
				} else if(si == 2){
					dp[x][2][sj] = dp[x][1][sj] + dp[x - 1][1][sj - 1];
				} else {
					dp[x][si][sj] = 2 * dp[x][si - 1][sj] - dp[x][si - 2][sj] - dp[x - 2][si - 2][sj - 2];
					dp[x][si][sj] %= mod;
				}
			}
		}
	}

	if(s > e){
		s = n - s;
		e = n - e;
	}

	std::cout << dp[3][1][2];
}
