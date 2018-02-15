#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
const int maxboard = 1e6;
bool comp[maxn];

int main(){
	std::vector<int> primes;

	for(int i = 2; i < maxn; i++){
		if(!comp[i]){
			primes.push_back(i);

			for(int j = i * i; j < maxn; j += i){
				comp[j] = true;
			}
		}
	}

	double best = 0.0;
	int best_index = 0;
	for(int i = 2; i <= maxboard; i++){
		int curr = i;
		int rel_prime = i;
		for(int j = 0; j < primes.size(); j++){
			int steps = 0;

			while(curr % primes[j] == 0){
				curr /= primes[j];
				steps++;
			}

			if(steps != 0){
				rel_prime -= rel_prime / primes[j];
			}
		}

		if(curr != i and curr != 1){
			rel_prime -= rel_prime / curr;
		}

		if((double) i / rel_prime > best){
			best = (double) i / rel_prime;
			best_index = i;
		}
	}

	std::cout << best << ' ' << best_index << '\n';
}