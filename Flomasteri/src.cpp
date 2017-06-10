#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
ll dp2[105][32768];
ll dp[maxn];
ll found[maxn];
ll pow2[maxn];
ll n, m;
ll val[maxn];

ll dfs(ll pos){
    if(dp[pos] == -1){
        if(pos == 0){
            dp[pos] = 1;
        } else {
            dp[pos] = 0;
  
            ll subset = pos & -pos;
  
            do {
                dp[pos] += dfs(pos ^ subset) * pow2[found[subset]];
                dp[pos] %= mod;
  
                subset = (subset - pos) & pos;
            } while(subset > 0);
        }
    }
  
    return dp[pos];
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> m;

	for(ll i = 0; i < n; i++){
		ll gen = 0;
		ll flomasteri;
		std::cin >> flomasteri;

		for(ll j = 0; j < flomasteri; j++){
			ll ind;
			std::cin >> ind;
			ind--;
			gen |= (1 << ind);
		}
		val[i] = gen;
		found[gen]++;
	}

	if(n <= 103LL){
		for(ll i = 0; i < 105; i++){
			for(ll j = 0; j < 32768; j++){
				dp2[i][j] = 0;
			}
		}

		for(ll i = n; i >= 0; i--){
			for(ll j = 0; j < (1 << m); j++){
				if(i == n){
					if(j == (1 << m) - 1){
						dp2[i][j] = 1;
					} else {
						dp2[i][j] = 0;
					}
				} else {
					dp2[i][j] = dp2[i + 1][j] + dp2[i + 1][j | val[i]];
					dp2[i][j] %= mod;
				}
			}
		}

		std::cout << dp2[0][0] << std::endl;
		return 0;
	}

	std::fill(dp, dp + maxn, -1);

    pow2[0] = 1;
  
    for(ll i = 1; i < maxn; i++){
        pow2[i] = pow2[i - 1] * 2;
        pow2[i] %= mod;
    }
  
    for(ll i = 0; i < maxn; i++){
        pow2[i]--;
  
        if(pow2[i] < 0){
            pow2[i] += mod;
        }
    }
  
    if(m >= 18){
        std::cout << pow2[n] << std::endl;
        return 0;
    }
  
    ll res = dfs((1 << n) - 1) * (pow2[found[0]] + 1);
    std::cout << res % mod << std::endl;
}