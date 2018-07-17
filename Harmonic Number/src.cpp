#include <bits/stdc++.h>

typedef long long ll;

const ll BASE = 1e13;
const ll maxn = 1e4 + 1e2;

struct Bigll {
	std::vector<ll> n;

	Bigll(ll initial_number = 0){
		n.push_back(initial_number);
	}
	Bigll(const Bigll &x){
		this->n = x.n;
	}

	bool operator<(Bigll const &x){
		if(x.n.size() != this->n.size()){
			return (x.n.size() > this->n.size());
		} else {
			for(ll i = (ll) x.n.size() - 1; i >= 0; i--){
				if(x.n[i] != this->n[i]){
					return (x.n[i] > this->n[i]);
				}
			}

			return false;
		}
	}	
	bool operator<=(Bigll const &x){
		if(x.n.size() != this->n.size()){
			return (x.n.size() > this->n.size());
		} else {
			for(ll i = (ll) x.n.size() - 1; i >= 0; i--){
				if(x.n[i] != this->n[i]){
					return (x.n[i] > this->n[i]);
				}
			}

			return true;
		}
	}
	bool operator==(Bigll const &x){
		return this->n == x.n;
	}

	void operator+=(Bigll x){
		ll biggest_size = std::max(x.n.size(), this->n.size());
		ll carry = 0;

		for(ll i = 0; i < biggest_size or carry; i++){
			if(i < x.n.size()){
				carry += x.n[i];
			}
			if(i < this->n.size()){
				carry += this->n[i];
			} else {
				this->n.push_back(0);
			}

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

	Bigll operator*(ll y){
		Bigll copy_num = *this;

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
				this->n[i] = carry / x;
				if(!started){
					this->n.resize(i + 1);
				}
				started = true;
				carry = carry % x;
			}
		}
	}
};

ll prime[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	#ifndef local
		freopen("hn.in", "r", stdin);
		freopen("hn.out", "w", stdout);
	#endif

	ll n;
	std::cin >> n;

	Bigll denominator(1);

	memset(prime, true, sizeof(prime));

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

	Bigll numerator(denominator);

	for(ll i = 2; i <= n; i++){
		Bigll cop = denominator;
		cop /= i;
		numerator += cop;
	}

	for(ll i = 2; i <= n; i++){
		if(prime[i]){
			Bigll x = numerator;
			x /= i;
			Bigll y = denominator;
			y /= i;
			if(x * i == numerator and y * i == denominator){
				numerator = x;
				denominator = y;
			}
		}
	}

	for(ll i = (ll) numerator.n.size() - 1; i >= 0; i--){
		if(i + 1 != numerator.n.size()){
			for(ll j = BASE / 10; j > numerator.n[i]; j /= 10){
				std::cout << 0;
			}
		}
		std::cout << (ll) numerator.n[i];
	}
	std::cout << '\n';
	for(ll i = (ll) denominator.n.size() - 1; i >= 0; i--){
		if(i + 1 != denominator.n.size()){
			for(ll j = BASE / 10; j > denominator.n[i]; j /= 10){
				std::cout << 0;
			}
		}
		std::cout << (ll) denominator.n[i];
	}
	std::cout << '\n';
}
