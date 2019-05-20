#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 1e2;
std::vector<ll> v[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	ll res = 0;

	for(ll i = 0; i < n; i++){
		v[i].resize(2);
		std::cin >> v[i][0] >> v[i][1];

		if(v[i][0] > v[i][1]){
			res += (n - 1) * v[i][1];
			v[i][0] -= v[i][1];
			v[i][1] = 0;
		} else {
			res += (n - 1) * v[i][0];
			v[i][1] -= v[i][0];
			v[i][1] *= -1;
			v[i][0] = 0;
		}
	}

	std::sort(v, v + n);

	for(ll i = 0; i < n; i++){
		res += std::abs(v[i][1]) * i + std::abs(v[i][0]) * (n - i - 1);
	}

	std::cout << res << '\n';
}