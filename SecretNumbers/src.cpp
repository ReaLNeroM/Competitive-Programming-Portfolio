#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
// #include <iostream>
#include <stack>

typedef long long ll;

class SecretNumbers{
	const ll mod = 1e9 + 7;
	ll dp[105][1005][2];
	ll suma[105][1005][2];
	ll vlijanie[105];
	std::string s;
	ll dfs(ll pos, ll left, ll follow){
		if(dp[pos][left][follow] == -1){
			ll &ans = dp[pos][left][follow];
			ll &sans = suma[pos][left][follow];
			ans = 0;

			if(pos == s.size()){
				if(left == 0){
					ans = 1;
				} else {
					ans = 0;
				}
			} else {
				if(!follow){
					for(ll i = 0; i < 10; i++){
						if(left >= i){
							ans  +=  dfs(pos + 1, left - i, follow);
							ans  %= mod;
							sans += suma[pos + 1][left - i][follow];
							sans +=  dfs(pos + 1, left - i, follow) * vlijanie[pos] * i;
							sans %= mod;
						}
					}
				} else {
					for(ll i = 0; i < (s[pos] - '0'); i++){
						if(left >= i){
							ans  +=  dfs(pos + 1, left - i, false);
							ans  %= mod;
							sans += suma[pos + 1][left - i][false];
							sans +=  dfs(pos + 1, left - i, false) * vlijanie[pos] * i;
							sans %= mod;
						}
					}

					if(left >= s[pos] - '0'){
						ans +=   dfs(pos + 1, left - (s[pos] - '0'), follow);
						ans %= mod;
						sans += suma[pos + 1][left - (s[pos] - '0')][follow];
						sans += dfs(pos + 1, left - (s[pos] - '0'), follow) * vlijanie[pos] * (s[pos] - '0');
						sans %= mod;
					}
				}
			}
		}

		return dp[pos][left][follow];
	}
public:
	ll findSum(std::string N, ll K){
		s = N;
		for(ll i = 0; i < 105; i++){
			for(ll j = 0; j < 1005; j++){
				for(ll k = 0; k < 2; k++){
					dp[i][j][k] = -1;
					suma[i][j][k] = 0;
				}
			}
		}

		vlijanie[N.size() - 1] = 1;
		for(ll i = N.size() - 2; i >= 0; i--){
			vlijanie[i] = (vlijanie[i + 1] * 10LL) % mod;
		}

		dfs(0, K, true);

		return suma[0][K][true];
	}
};

// int main(){
// 	SecretNumbers x;
// 	x.findSum("100", 3);
// }