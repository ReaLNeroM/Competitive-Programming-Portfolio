#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e5 + 1e2;
ll divisors[maxn];

ll f(ll n){
	ll factors = 1;

	ll upto = 1;

	for(ll i = 2; i * i <= n; i++){
		upto = i;

		divisors[i] = 0;

		while(n % i == 0){
			n /= i;
			divisors[i]++;
		}

		factors *= divisors[i] + 1;
	}

	ll res = 1;

	if(n != 1){
		factors *= 2;
		res *= (factors / 2 * 1 + 1);
	}

	for(ll i = 2; i <= upto; i++){
		res *= ((factors * divisors[i]) / 2 + 1);
	}

	return res;
}

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	ll n;
	while(cin >> n, n != 0){
		cout << f(n) << endl;
	}
}
