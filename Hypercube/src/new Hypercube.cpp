#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 100003;

int main(){
	std::ios::sync_with_stdio(false);

	ll n, m, k;
	std::cin >> n >> m >> k;

	ll res = 1;
	for(int i = 0; i < (n - k); i++){
		res *= 2;
		res %= mod;
	}

	for(int i = (n - k); i < n; i++){
		res *= i + 1;
		res %= mod;
	}

	std::cout << (m - (m & -m)) << '\n';
	std::cout << (m + ((~m) & -(~m))) << '\n';
	std::cout << res << '\n';
}