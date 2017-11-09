#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 50;
ll h[maxn];
ll gold[maxn];
std::vector<ll> v[maxn];
ll n, k;

ll ways(ll pos, ll last, ll accumulated){
	if(pos == n){
		return (accumulated >= k);
	}

	ll sum = 0;

	if(last == -1 or h[last] <= h[pos]){
		sum += ways(pos + 1, pos, accumulated + gold[pos]);
	}
	sum += ways(pos + 1, last, accumulated);

	return sum;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> k;

	for(ll i = 0; i < n; i++){
		std::cin >> h[i] >> gold[i];
	}

	if(n <= 20){
		std::cout << ways(0, -1, 0);
	} else {
		for(ll i = 1; i < (1 << 20); i++){
			ll biggest = n;
			ll sum = 0;

			for(ll j = 0, bit = 1; bit <= i; j++, bit *= 2){
				if(i & bit){
					if(biggest != -1 and h[biggest] > h[j]){
						sum = -1;
						break;
					}

					biggest = j;
					sum += gold[j];
				}
			}

			if(sum != -1){
				v[biggest].push_back(sum);
			}
		}
		for(ll i = 1; i < (1 << (n - 20)); i++){
			ll biggest = n;
			ll smallest = n;
			ll sum = 0;

			for(ll j = 20, bit = 1; bit <= i; j++, bit *= 2){
				if(i & bit){
					if(biggest != -1 and h[biggest] > h[j]){
						sum = -1;
						break;
					}

					if(smallest == n){
						smallest = j;
					}
					biggest = j;
					sum += gold[j];
				}
			}

			if(sum != -1){
				v[smallest].push_back(sum);
			}
		}

		for(ll i = 0; i < n; i++){
			std::sort(v[i].begin(), v[i].end());
		}

		ll res = 0;

		for(ll i = 0; i < 20; i++){
			for(ll j = 20; j < n; j++){
				if(h[i] <= h[j]){
					ll a = 0;
					ll b = v[j].size();

					while(a < v[i].size()){
						while(b > 0 and v[i][a] + v[j][b - 1] > =k){
							b--;
						}

						res += v[j].size() - b;
						a++;
					}
				}
			}
		}

		for(ll i = 0; i < n; i++){
			res += std::distance(std::lower_bound(v[i].begin(), v[i].end(), k), v[i].end());
		}

		std::cout << res << '\n';
	}
}