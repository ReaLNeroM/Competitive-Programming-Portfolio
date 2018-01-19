#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e7;
bool composite[maxn];
int pow10[10];

bool prime(int a, int b){
	ll x = (ll) a * (ll) pow10[(int) std::ceil(std::log10(b + 1))] + b;
	ll y = (ll) b * (ll) pow10[(int) std::ceil(std::log10(a + 1))] + a;

	if(x >= maxn or y >= maxn){
		return false;
	} else {
		return (!composite[x] && !composite[y]);
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	for(int i = 0, pow = 1; i < 10; i++, pow *= 10){
		pow10[i] = pow;
	}

	composite[0] = composite[1] = true;

	std::vector<int> primes;
	for(int i = 2; i < maxn; i++){
		if(!composite[i]){
			if(i != 2 and i != 5 and i < 300000){
				primes.push_back(i);
			}

			if(i < 10000){
				for(int j = i * i; j < maxn; j += i){
					composite[j] = true;
				}
			}
		}
	}

	for(int i = 0; i < primes.size(); i++){
		for(int j = i + 1; j < primes.size(); j++){
			if(prime(primes[i], primes[j])){
				for(int k = j + 1; k < primes.size(); k++){
					if(prime(primes[k], primes[j]) and prime(primes[k], primes[i])){
						for(int l = k + 1; l < primes.size(); l++){
							if(prime(primes[l], primes[k]) and prime(primes[l], primes[j]) and prime(primes[l], primes[i])){
								for(int m = l + 1; m < primes.size(); m++){
									if(prime(primes[m], primes[l]) and prime(primes[m], primes[k]) and prime(primes[m], primes[j]) and prime(primes[m], primes[i])){
										std::cout << primes[i] << ' ' << primes[j] << ' ' << primes[k] << ' ' << primes[l] << ' ' << primes[m] << '\n';
										return 0;
									}
								}
							}
						}
						if(k % 10 == 0){
							std::cout << i << ' ' << j << ' ' << k << std::endl;
						}
					}
				}
			}
		}
	}
}