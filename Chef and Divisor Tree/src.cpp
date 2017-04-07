#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 1e6 + 1e2;
bool prime[maxn];
vector<int> primes;
ll lleft[maxn];
vector<ll> factors[maxn];

int main(){
	fill(prime, prime + maxn, true);
	for(int i = 2; i < maxn; i++){
		if(prime[i]){
			primes.push_back(i);
		}
		if(prime[i] and i < 10000){
			for(int j = i * i; j < maxn; j += i){
				prime[j] = false;
			}
		}
	}

	ll a, b;
	cin >> a >> b;

	for(int i = 0; a + i <= b; i++){
		lleft[i] = a + i;
	}

	for(int i = 0; i < primes.size(); i++){
		ll smallest = a + (primes[i] - a % primes[i]) % primes[i];
		ll smallestind = smallest - a;
		while(smallest <= b){
			if(a <= smallest){
				ll times = 0;
				while(lleft[smallestind] % primes[i] == 0){
					times++;
					lleft[smallestind] /= primes[i];
				}
				factors[smallestind].push_back(times);
			}
			smallest += primes[i];
			smallestind += primes[i];
		}
	}

	ll sum = 0LL;
	for(int i = 0; a + i <= b; i++){
		vector<ll> v = factors[i];
		if(lleft[i] != 1){
			v.push_back(1);
		}

		if(!v.empty()){
			sort(v.begin(), v.end(), greater<ll>());
			while(v[0] > 0){
				ll facts = 1;
				for(int j = 0; j < v.size(); j++){
					facts *= v[j] + 1LL;
				}
				v[0]--;
				sum += facts;
				sort(v.begin(), v.end(), greater<ll>());
			}
		}
	}

	cout << sum << endl;
}
