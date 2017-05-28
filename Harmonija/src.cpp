#include <bits/stdc++.h>

typedef long long ll;

const int mostprimefactors = 20; //overkill
std::vector<int> bigger[mostprimefactors];

int main(){
	std::ios::sync_with_stdio(false);

	ll b;
	std::cin >> b;

	// std::vector<int> primes;
	// ll residue = b;

	// for(int i = 2; i * i < residue; i++){
	// 	if(residue % i == 0){
	// 		primes.push_back(i);
	// 		while(residue % i == 0){
	// 			residue /= i;
	// 		}
	// 	}
	// }

	// if(residue != 1){
	// 	primes.push_back(residue);
	// 	residue = 1;
	// }

	// for(int i = 0; i < primes.size(); i++){
	// 	for(int j = primes[i]; j < b; j *= primes[i]){
	// 		if()
	// 	}
	// }

	ll res = 0;

	for(ll a = b / 2 + 1; a <= b; a++){
		if((b * a) % (2 * a - b) == 0){
			res += 2;

			std::cout << a << ' ' << (b * a) / (2 * a - b) << std::endl;
		}
	}

	res--; // a == c leads to overcounting

	std::cout << res;
}