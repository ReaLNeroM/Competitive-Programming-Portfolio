#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll n, mod;
std::string s;
ll filled[maxn][3][3];
ll ans[maxn][3][3];

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> mod;
	std::cin >> s;

	for(ll j = 0; j < 3; j++){
		for(ll k = 0; k < 3; k++){
			filled[0][j][k] = 1;
		}
	}

	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < 3; j++){
			for(ll k = 0; k < 3; k++){
				if(j != 2){
					filled[i][j][k] += filled[i - 1][j + 1][std::max(k - 1, 0LL)];
				}
				if(k != 2){
					filled[i][j][k] += filled[i - 1][std::max(j - 1, 0LL)][k + 1];
				}
				filled[i][j][k] %= mod;
			}
		}
	}

	for(ll i = n; i >= 0; i--){
		for(ll worstSumL = 0; worstSumL < 3; worstSumL++){
			for(ll worstSumP = 0; worstSumP < 3; worstSumP++){
				ll& res = ans[i][worstSumL][worstSumP];
				if(i == n){
					res = 1;
					continue;
				}

				if(s[i] == 'L' and worstSumL != 2){
					res += ans[i + 1][worstSumL + 1][std::max(0LL, worstSumP - 1)];
					res %= mod;
				}

				if(s[i] == 'P'){
					if(worstSumL != 2){
						res += filled[n - i - 1][worstSumL + 1][std::max(0LL, worstSumP - 1)];
						res %= mod;
					}
					
					if(worstSumP != 2){
						res += ans[i + 1][std::max(0LL, worstSumL - 1)][worstSumP + 1];
						res %= mod;
					}
				}
			}
		}
	}

	std::cout << ans[0][0][0] << '\n';
}
