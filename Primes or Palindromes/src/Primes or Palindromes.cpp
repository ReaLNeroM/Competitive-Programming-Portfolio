#include <iostream>

typedef long long ll;

int main() {
	ll palite, primeite, actual = 0;
	static int prime[12000001];
	for(ll i = 0; i <= 12000000; i++){
		prime[i] = 0;
	}
	for(ll palite = 1; palite <= 5; palite++){
		for(ll primeite = 1; primeite <= 5; primeite++){
			ll primes = 0, palindromes = 0, max;

			std::string str = "0";
			for(ll i = 1; i <= 2000000; i++){
				if(i != 1 and prime[i] != palite * primeite){
					prime[i] = palite * primeite;
					primes += primeite;

					for(ll j = i * i; j <= 2000000; j += i){
						prime[j] = palite * primeite;
					}
				}

				ll pos;
				for(pos = str.length() - 1; pos >= 0; pos--){
					if(str[pos] == '9'){
						str[pos] = '0';
					} else {
						str[pos]++;
						break;
					}
				}
				if(pos == -1){
					str.insert(str.begin(), '1');
				}

				palindromes += palite;
				for(ll j = 0, back = str.length() - 1; back > j; j++, back--){
					if(str[j] != str[back]){
						palindromes -= palite;
						break;
					}
				}

				if(primes <= palindromes){
					max = i;
				}
			}

			if(max != 2000000){
				actual = std::max(actual, max);
			}

		}
	}

	std::cout << actual;
	return 0;
}
