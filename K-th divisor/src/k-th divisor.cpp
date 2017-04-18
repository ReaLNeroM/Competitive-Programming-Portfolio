#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ll n, k;
	cin >> n >> k;

	ll divisors = 0;
	for(ll i = 1; i * i <= n; i++){
		if(n % i == 0){
			if(i * i == n){
				divisors += 1;
			} else {
				divisors += 2;
			}
		}
	}
	ll l = 1, r = divisors;

	if(divisors < k){
		cout << -1 << endl;
		return 0;
	}
	for(ll i = 1; i * i <= n; i++){
		if(n % i == 0){
			if(l == k){
				cout << i << endl;
				break;
			} else if(r == k){
				cout << n / i << endl;
				break;
			}
			l++, r--;
		}
	}
	return 0;
}
