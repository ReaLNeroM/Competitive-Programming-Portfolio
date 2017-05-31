#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 20;
const int maxpow2 = 262144;
const ll mod = 1e9 + 7;
ll dp[maxpow2][maxn][maxn];
int n, s, e;
ll res = 0;

ll dfs(int bit, int pos, int par){
	if(dp[bit][pos][par] == -1){
		ll &ans = dp[bit][pos][par];
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
					}
				}
			} 
			if(pos <= par){
				for(int i = pos + 1; i < n; i++){
					if(!(bit & (1 << i))){
						ans += dfs(bit | (1 << i), i, pos);
					}
				}
			}
		}
	}

	return dp[bit][pos][par];
}

int main(){
	std::ios::sync_with_stdio(false);

	for(n = 2; n <= 20; n++){
		for(s = 0; s < n; s++){
			for(e = s + 1; e < n; e++){
				for(int i = 0; i < maxpow2; i++){
					for(int j = 0; j < n; j++){
						for(int k = 0; k < n; k++){
							dp[i][j][k] = -1;
						}
					}
				}
				std::cout << dfs(1 << s, s, s);
				if(s != n - 2 or e != n - 1){
					std::cout << ", ";
				}
				std::cerr << s << ' ' << e << std::endl;
			}
		}
		std::cout << std::endl;
	}
}