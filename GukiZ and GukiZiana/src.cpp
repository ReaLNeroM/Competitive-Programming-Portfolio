#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6;
const ll maxsq = 1000;
ll val[maxn];
std::unordered_map<ll, ll> m[maxsq];
ll inc[maxsq];
ll sq;

int main(){
	ll n, q;
	std::cin >> n >> q;

	sq = std::min(n, (ll) std::ceil(std::sqrt(n)));

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
		m[i / sq][val[i]]++;
	}

	for(ll i = 0; i < q; i++){
		ll type;
		std::cin >> type;

		if(type == 1){
			ll l, r, x;
			std::cin >> l >> r >> x;
			l--, r--;

			ll l_block = l / sq;
			ll r_block = r / sq;

			for(ll j = l_block + 1; j <= r_block - 1; j++){
				inc[j] += x;
			}

			for(ll j = l; j / sq == l_block and j <= r; j++){
				auto ite = m[l_block].find(val[j]);
				if(ite != m[l_block].end()){
					ite->second--;
					if(ite->second == 0){
						m[l_block].erase(ite);
					}
				}
				val[j] += x;
				m[l_block][val[j]]++;
			}

			if(l_block != r_block){
				for(ll j = r; j / sq == r_block; j--){
					auto ite = m[r_block].find(val[j]);
					if(ite != m[r_block].end()){
						ite->second--;
						if(ite->second == 0){
							m[r_block].erase(ite);
						}
					}
					val[j] += x;
					m[r_block][val[j]]++;
				}
			}
		} else {
			ll value;
			std::cin >> value;

			ll least = n + 1, most = -1;
			for(ll j = 0; j < sq; j++){
				auto ite = m[j].find(value - inc[j]);
				if(ite != m[j].end()){
					least = std::min(least, j);
					most = std::max(most, j);
				}
			}

			if(least == n + 1){
				std::cout << -1 << '\n';
			} else {
				ll least_seen = -1;
				ll most_seen = -1;

				for(ll j = least * sq; j < (least + 1) * sq; j++){
					if(val[j] + inc[least] == value){
						least_seen = j;
						break;
					}
				}

				for(ll j = most * sq; j < (most + 1) * sq; j++){
					if(val[j] + inc[most] == value){
						most_seen = j;
					}
				}

				std::cout << most_seen - least_seen << '\n';
			}
		}
	}
}