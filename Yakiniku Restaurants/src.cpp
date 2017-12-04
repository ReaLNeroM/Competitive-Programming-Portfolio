#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 5e3 + 1e2;
const ll maxk = 205;
ll val[maxk][maxn];
ll v[maxn];
ll best[maxk];

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	
	ll n, k;
	std::cin >> n >> k;

	for(ll i = 1; i < n; i++){
		std::cin >> v[i];
	}

	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < k; j++){
			std::cin >> val[j][i];
		}
	}

	ll res = 0;
	for(ll i = 0; i < n; i++){
		std::fill(best, best + k, 0);
		ll sum = 0;
		for(ll j = i; j < n; j++){
			if(j != i){
				sum -= v[j];
			}

			for(ll curr_k = 0; curr_k < k; curr_k++){
				if(best[curr_k] < val[curr_k][j]){
					sum += val[curr_k][j] - best[curr_k];
					best[curr_k] = val[curr_k][j];
				}
			}

			res = std::max(res, sum);
		}
	}

	std::cout << res << '\n';
}