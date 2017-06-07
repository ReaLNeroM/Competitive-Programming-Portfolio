#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 100;
ll x, y, l, r;
ll xp[maxn];
ll yp[maxn];

ll peasant(ll a, ll b){
	ll res = 0;

	while(b > 0){
		if(b % 2 == 1){
			res += a;
			if(res > 1e18){
				return 0;
			}
		}
		b /= 2;

		a *= 2;
		if(a > 1e18){
			a = 1e18 + 1;
		}
	}

	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> x >> y >> l >> r;

	xp[0] = 1;
	yp[0] = 1;
	for(ll i = 1; i < 100; i++){
		xp[i] = peasant(xp[i - 1], x);
		yp[i] = peasant(yp[i - 1], y);
	}

	std::vector<ll> v;
	for(ll i = 0; i < 100; i++){
		for(ll j = 0; j < 100; j++){
			if(xp[i] and yp[j]){
				v.push_back(xp[i] + yp[j]);
			}
		}
	}

	std::sort(v.begin(), v.end());

	ll found = -1;
	ll res = 0;
	for(ll i = 0; i < v.size(); i++){
		if(l <= v[i] and v[i] <= r){
			if(found == -1){
				found = i;
				res = v[i] - l;
			}

			if(i + 1 == v.size() or !(l <= v[i + 1] and v[i + 1] <= r)){
				res = std::max(res, r - v[i]);
			} else {
				res = std::max(res, v[i + 1] - v[i] - 1);
			}
		}
	}

	if(found == -1){
		std::cout << r - l + 1 << std::endl;
		return 0;
	}
	std::cout << res << std::endl;
}