#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 1e2;
ll mod;
std::unordered_map<ll, std::pair<ll, ll>> s[maxn];
ll influence[maxn];
ll n, k, p, m;

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> k >> p >> m;
	mod = m;

	ll x = 1;
	for(ll i = 0; i < 100000; i++){
		influence[i] = x;

		x *= p;
		x %= m;
	}

	s[0][0] = {0, 0};

	for(int x = 0; x < maxn; x++){
		s[x + 1].max_load_factor(0.25);
		auto ite = s[x].begin();
		while(ite != s[x].end()){
			ll frpos = x;
			ll frmod = ite->first;

			for(ll i = 0; i < k; i++){
				auto get = s[frpos + 1].find((frmod + influence[frpos] * i) % m);

				if(get != s[frpos + 1].end()){
					ll sz = (frpos + 1 + n + 1);
					sz /= n;
					sz *= n;
					std::vector<ll> v(sz, 1);

					ll pos = frpos;
					ll mod = frmod;

					v[pos + 1] = i + 1;

					while(pos + mod > 0){
						v[pos] = s[pos][mod].first + 1;
						mod = s[pos][mod].second;
						pos--;
					}

					for(ll j = sz - 1; j >= 0; j--){
						std::cout << v[j] << ' ';
					}
					std::cout << '\n';

					std::vector<ll> b(sz, 1);

					pos = frpos + 1;
					mod = (frmod + influence[frpos] * i) % m;

					while(pos + mod > 0){
						b[pos] = s[pos][mod].first + 1;
						mod = s[pos][mod].second;
						pos--;
					}

					for(ll j = sz - 1; j >= 0; j--){
						std::cout << b[j] << ' ';
					}
					std::cout << '\n';

					return 0;
				}

				s[frpos + 1][(frmod + influence[frpos] * i) % m] = {i, frmod};
			}
			ite++;
		}
	}
}
