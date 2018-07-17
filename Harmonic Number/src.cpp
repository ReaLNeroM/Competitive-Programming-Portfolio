#include <bits/stdc++.h>

typedef long long ll;

const ll BASE = 1e13;
const ll maxn = 1e4 + 1e2;

struct BigInt {
	std::vector<ll> n;

	BigInt(ll initial_number = 0){
		n.push_back(initial_number);
	}
	BigInt(const BigInt &x){
		this->n = x.n;
	}

	bool operator<(BigInt const &x){
		if(this->n.size() != x.n.size()){
			return (this->n.size() < x.n.size());
		} else {
			for(ll i = (ll) this->n.size() - 1; i >= 0; i--){
				if(this->n[i] != x.n[i]){
					return (this->n[i] < x.n[i]);
				}
			}

			return false;
		}
	}	

	bool operator==(BigInt const &x){
		return this->n == x.n;
	}

	void operator+=(BigInt x){
		ll biggest_size = std::max(x.n.size(), this->n.size());
		ll carry = 0;

		for(ll i = 0; i < biggest_size or carry; i++){
			if(i < x.n.size()){
				carry += x.n[i];
			}
			if(i >= this->n.size()){
				this->n.push_back(0);
			}

			carry += this->n[i];

			this->n[i] = carry % BASE;
			carry /= BASE;
		}
	}

	void operator*=(ll x){
		ll carry = 0;

		for(ll i = 0; i < this->n.size() or carry; i++){
			if(i >= this->n.size()){
				this->n.push_back(0);
			}

			carry += this->n[i] * x;

			this->n[i] = carry % BASE;
			carry /= BASE;
		}
	}

	BigInt operator*(ll y){
		BigInt copy_num = *this;

		copy_num *= y;

		return copy_num;
	}

	void operator/=(ll x){
		ll carry = 0;

		ll curr_size = 0;
		bool started = false;

		for(ll i = (ll) this->n.size() - 1; i >= 0; i--){
			carry *= BASE;
			carry += this->n[i];

			if(carry >= x or started){
				started = true;
				
				this->n[i] = carry / x;
				carry = carry % x;
			} else if(!started){
				this->n.pop_back();
			}
		}
	}

};

std::ostream& operator<<(std::ostream& os, BigInt x){
	for(ll i = (ll) x.n.size() - 1; i >= 0; i--){
		if(i + 1 != x.n.size()){
			for(ll j = BASE / 10; j > x.n[i] and j > 1; j /= 10){
				os << 0;
			}
		}
		os << (ll) x.n[i];
	}

	return os;
}

ll prime[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	#ifndef local
		freopen("hn.in", "r", stdin);
		freopen("hn.out", "w", stdout);
	#endif

	ll n;
	std::cin >> n;

	memset(prime, true, sizeof(prime));

	BigInt denominator(1);

	for(ll i = 2; i <= n; i++){
		if(prime[i]){
			ll i_copy = i;
			while(n >= i_copy){
				denominator *= i;
				i_copy *= i;
			}

			for(ll j = i * i; j <= n; j += i){
				prime[j] = false;
			}
		}
	}

	BigInt numerator(denominator);

	for(ll i = 2; i <= n; i++){
		BigInt cop = denominator;
		cop /= i;
		numerator += cop;
	}

	for(ll i = 2; i <= n; i++){
		if(prime[i]){
			do {
				BigInt x = numerator; 
				x /= i;
				BigInt y = denominator; 
				y /= i;
				
				if(x * i == numerator and y * i == denominator){
					numerator = x;
					denominator = y;
				} else {
					break;
				}
			} while (true);
		}
	}

	std::cout << numerator << '\n' << denominator << '\n';
}
