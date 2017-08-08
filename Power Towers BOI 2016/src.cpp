#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
std::vector<ll> divisor;
ll val[maxn];
ll care[maxn];
ll got[maxn];
ll mod[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll t, m;
	std::cin >> t >> m;

	divisor.push_back(2);
	divisor.push_back(5);

	for(ll test = 0; test < t; test++){
		ll n;
		std::cin >> n;

		for(ll i = 0; i < n; i++){
			std::cin >> val[i];
			val[i] %= m;
		}
		for(ll i = 1; i < divisor.size(); i++){
			mod[0] = divisor[i];

			for(int i = 0; i < n - 1; i++){
				if(std::gcd(mod[0], val[i]) == 1){
					int x = 1;
					for(int k = 1; k <= mod[0]; k++){
						x *= val[i];
						x %= mod[0];
						if(x == val[i] and k != 1){
							mod[i + 1] = k - 1;
							break;
						}
					}
					// mod[i + 1] = rel_prime(mod[0]);
				} else {
					
				}
			}

			for(ll j = n - 1; j >= 0; j--){
				ll ch = val[j];
				care[j] = 1;
				for(ll k = 1; k <= care[j + 1]; k++){
					care[j] *= ch;
					care[j] %= (divisor[i] - 1);
				}
				std::cout << care[j] << '\n';
			}

		}
		std::cout << std::endl;
	}
}