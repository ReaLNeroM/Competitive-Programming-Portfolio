#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll comp[maxn];

ll gcd(ll a, ll b){
	if(b == 0){
		return a;
	}

	return gcd(b, a % b);
}

ll l_a, l_b, d_a, d_b;
	
void extended(ll a, ll b){
	if(b == 0){
			return;
	}

	ll nl_a, nl_b, nd_a, nd_b;

	nl_a = d_a;
	nl_b = d_b;

	nd_a = l_a - a/b * d_a;
	nd_b = l_b - a/b * d_b;

	l_a = nl_a;
	l_b = nl_b;
	d_a = nd_a;
	d_b = nd_b;

	extended(b, a % b);
}

int main(){
	std::ios::sync_with_stdio(false);

	comp[1] = 1;
	comp[0] = 1;

	ll n;
	std::cin >> n;
	
	std::vector<ll> p;

	for(ll i = 2; i < maxn; i++){
		if(comp[i] == 0){
			comp[i] = i;
			if(n % i == 0){
				p.push_back(i);
			}
			if(i < 10000){
				for(ll j = i * i; j < maxn; j += i){
					comp[j] = i;
				}
			}
		}
	}

	for(ll i = 0; i < p.size(); i++){
		for(ll j = i; j < p.size(); j++){
			if((n - 1) % gcd(p[i], p[j]) == 0){
				std::cout << "YES\n";

				l_a = 1;
				l_b = 0;
				d_a = 0;
				d_b = 1;

				extended(p[i], p[j]);
				std::cout << p[i] << ' ' << p[j] <<' ' << l_a << ' ' << l_b << '\n';
				l_a *= (n - 1) / gcd(p[i], p[j]);
				l_b *= (n - 1) / gcd(p[i], p[j]);
				l_a = std::abs(l_a);
				l_b = std::abs(l_b);
				ll a = l_a;
				ll b = l_b;
				ll tA = a;
				ll tB = b;
				ll prll = 0;
				for(ll aa = p[i] - 1; aa >= 1; aa--){
					prll += a / aa;
					a %= aa;
				}
				for(ll aa = p[j] - 1; aa >= 1; aa--){
					prll += b / aa;
					b %= aa;
				}
				std::cout << prll << '\n';
				return 0;

				a = tA;
				b = tB;
				for(ll aa = p[i] - 1; aa >= 1; aa--){
					while(a >= aa){
						std::cout << aa << ' ' << n / p[i] << '\n';
						a -= aa;
					}
				}

				for(ll aa = p[j] - 1; aa >= 1; aa--){
					while(b >= aa){
						std::cout << aa << ' ' << n / p[j] << '\n';
						b -= aa;
					}
				}
				return 0;
			}
		}
	}

	std::cout << "NO\n";
}