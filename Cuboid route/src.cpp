#include <bits/stdc++.h>

typedef long long ll;

std::vector<ll> perfect_table;

bool isPerfectSquare(ll n){
	int l = 0, r = perfect_table.size() - 1;

	while(l <= r){
		int mid = (l + r) / 2;

		if(perfect_table[mid] == n){
			return true;
		} else if(perfect_table[mid] < n){
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	return false;
}

ll test(ll M){
	ll res = 0;

	for(ll i = 1; i <= M; i++){
		for(ll j = 2; j <= 2 * i; j++){
			ll dist_min = i * i + j * j;
			if(isPerfectSquare(dist_min)){
				if(j > i + 1){
					res += (2 * (i + 1) - j) / 2;
				} else {
					res += j / 2;
				}
			}
		}
		std::cout << i << ' ' << res << '\n';
	}

	return res;
}

int main(){
	for(ll i = 1; i <= 5000; i++){
		perfect_table.push_back(i * i);
	}

	ll n = 1818;
	std::cout << test(n) << '\n';
}