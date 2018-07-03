#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 2e3 + 1e2;
const ll alpha = 31;
const ll mod = 1e14 + 31;
ll n;
ll hash[maxn][maxn];
ll ppow[maxn];
std::string s;
ll val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> s;
	ll n = s.size();

	ppow[0] = 1LL;
	for(int i = 1; i <= n; i++){
		ppow[i] = ppow[i - 1] * alpha;
		ppow[i] %= mod;
	}

	for(int i = 0; i < n; i++){
		ll total_hash = 1523;
		for(int j = i; j < n; j++){
			total_hash *= alpha;
			total_hash += s[j] - 'a' + 1LL;
			total_hash %= mod;

			hash[i][j] = total_hash;
		}
	}

	ll res = 0LL;

	for(ll i = 0; i < n; i++){
		for(ll j = i; j < n; j++){
			ll length = j - i + 1;
			for(ll k = 0; k + length <= i; k++){
				if(hash[i][j] == hash[k][k + length - 1]){
					res = std::max(res, length);
				}
			}
			for(ll k = j + 1; k + length <= n; k++){
				if(hash[i][j] == hash[k][k + length - 1]){
					res = std::max(res, length);
				}
			}

			for(ll k = i - 1; k >= 0; k--){
				ll alength = i - k;
				ll blength = length - alength;

				if(hash[k][i - 1] == hash[i][i + alength - 1] and hash[i + alength][j] == hash[j + 1][j + blength]){
					res = std::max(res, length);
				}
			}
		}
	}

	std::cout << res << '\n';
}
