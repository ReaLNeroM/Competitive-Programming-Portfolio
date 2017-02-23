#include <iostream>
#include <vector>
typedef long long ll;

static ll val[5000001];
class BIT{
public:
	void update(ll pos, ll change){
		while(pos <= 5000000){
			val[pos] += change;
			pos += pos & (-pos);
		}
	}
	ll check(ll pos){
		ll res = val[0];
		while(pos > 0){
			res += val[pos];
			pos -= pos & (-pos);
		}

		return res;
	}
};
int main() {
	std::ios_base::sync_with_stdio(false);
	BIT logn;

	static ll primes[5000001];
	for(ll i = 0; i <= 5000000; i++){
		primes[i] = 0;
	}
	for(ll i = 2; i <= 5000000; i++){
		if(primes[i] == 0){
			for(ll j = i; j <= 5000000; j += i){
				for(ll k = j; k > 1 and k % i == 0; k /= i){
					primes[j]++;
				}
			}
		}

		logn.update(i, primes[i]);
	}

	for(ll i = 1; i <= 5000000; i++){
		primes[i] = logn.check(i);
	}

	ll cases;
	std::cin >> cases;
	ll res[cases];

	for(ll i = 0, bigger, smaller; i < cases; i++){
		std::cin >> bigger >> smaller;

		res[i] = primes[bigger] - primes[smaller];
	}

	for(ll i = 0; i < cases; i++){
		std::cout << res[i] << std::endl;
	}
	return 0;
}
