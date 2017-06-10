#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
bool comp[maxn];
bool my_board[maxn];
std::vector<ll> prime;

int main(){
	std::ios::sync_with_stdio(false);

	for(ll i = 2; i < 1000000; i++){
		if(!comp[i]){
			prime.push_back(i);

			if(i < 10000){
				for(ll j = i * i; j < 1000000; j += i){
					comp[j] = true;
				}
			}
		}
	}

	ll t;
	std::cin >> t;

	for(ll x = 0; x < t; x++){
		ll l, r;
		std::cin >> l >> r;
		l = std::max(l, 2LL);

		for(ll i = 0; l + i <= r; i++){
			my_board[i] = 1;
		}

		for(ll i = 0; i < prime.size(); i++){
			ll least = (prime[i] - l % prime[i]) % prime[i];

			if(least + l == prime[i]){
				least += prime[i];
			}
			for(ll j = least; l + j <= r; j += prime[i]){
				my_board[j] = 0;
			}
		}

		ll res = 0;
		for(ll i = 0; l + i <= r; i++){
			if(my_board[i]){
				std::cout << l + i << '\n';
			}
		}
	}
}