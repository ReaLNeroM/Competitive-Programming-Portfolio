#include <bits/stdc++.h>

const int maxn = 18;
const int maxpow2 = 200000;
const int mod = 1e9 + 7;
int dp[maxpow2][maxn][maxn];
int n, s, e;

int dfs(int bit, int pos, int par){
	if(dp[bit][pos][par] == -1){
		int &ans = dp[bit][pos][par];
		ans = 0;

		if(bit == (1 << n) - 1){
			if(pos == e){
				ans = 1;
			} else {
				ans = 0;
			}
		} else {
			if(par <= pos){
				for(int i = 0; i < pos; i++){
					if(!(bit & (1 << i))){
						ans += dfs(bit | (1 << i), i, pos);
						if(ans > mod){
							ans -= mod;
						}
					}
				}
			} 
			if(pos <= par){
				for(int i = pos + 1; i < n; i++){
					if(!(bit & (1 << i))){
						ans += dfs(bit | (1 << i), i, pos);
						if(ans > mod){
							ans -= mod;
						}
					}
				}
			}
		}
	}

	return dp[bit][pos][par];
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> s >> e;
	s--, e--;

	for(int i = 0; i < maxpow2; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				dp[i][j][k] = -1;
			}
		}
	}

	std::cout << dfs(1 << s, s, s);
}
