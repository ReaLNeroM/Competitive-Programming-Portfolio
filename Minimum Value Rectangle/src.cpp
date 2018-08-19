#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll val[maxn];
std::map<ll, ll> m, ss;

bool cmpscore(std::vector<ll> a, std::vector<ll> b){
	if(a[0] == -1){
		return true;
	}

	ll p = 2 * (a[0] + a[1]);
	ll s = a[0] * a[1];

	ll p2 = 2 * (b[0] + b[1]);
	ll s2 = b[0] * b[1];
	if(p * p * s2 >= p2 * p2 * s){
		return true;
	}

	return false;
}

int main(){
	std::ios::sync_with_stdio(false);

	ll t;
	std::cin >> t;

	for(ll test = 0; test < t; test++){
		ll n;
		std::cin >> n;

		m.clear();
		ss.clear();

		for(ll i = 0; i < n; i++){
			std::cin >> val[i];
			ss[val[i]]++;
			if(ss[val[i]] >= 2){
				m[val[i]] = ss[val[i]];
			}
		}

		std::vector<ll> res = {-1, -1, -1, -1};

		for(auto ite = m.begin(); ite != m.end(); ite++){
			if(ite != m.begin()){
				auto sec = ite;
				sec--;

				if(sec->second >= 2 and ite->second >= 2 and cmpscore(res, std::vector<ll>{ite->first, sec->first})){
					res = {ite->first, sec->first};
				}
			}

			if(ite->second >= 4){
				if(cmpscore(res, std::vector<ll>{ite->first, ite->first})){
					res = {ite->first, ite->first};
				}
			}
		}

		std::cout << res[0] << ' ' << res[0] << ' ' << res[1] << ' ' << res[1] << '\n';
	}
}