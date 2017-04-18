#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 1e2;
const double eps = 0.000000001;
ll drain[maxn], level[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n, charge;
	std::cin >> n >> charge;

	ll per_second_extra_charge = charge;

	for(ll i = 0; i < n; i++){
		std::cin >> drain[i] >> level[i];
		per_second_extra_charge -= drain[i];
	}

	if(per_second_extra_charge >= 0){
		std::cout << -1 << std::endl;
		return 0;
	}

	double l = 0, r = 1e18;

	for(ll i = 0; i < 150; i++){
		double mid = (l + r) / 2;

		double needed = 0.0;
		for(ll j = 0; j < n; j++){
			needed += std::max(0.0, ((double) drain[j]) * mid - level[j]);
		}

		if(needed > mid * charge){
			r = mid - eps;
		} else {
			l = mid + eps;
		}
	}

	std::cout.precision(9);
	std::cout << std::fixed << l;
}