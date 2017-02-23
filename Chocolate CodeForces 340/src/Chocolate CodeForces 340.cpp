#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;

	ll val[n], ways[n + 1];
	for(ll i = 0; i < n; i++){
		cin >> val[i];
		ways[i] = 0;
	}
	ways[n] = 1;

	for(ll i = n - 1; i >= 0; i--){
		bool foundone = false;
		for(ll j = i; j < n; j++){
			if(val[j]){
				if(foundone){
					break;
				}
				foundone = true;
			}

			if(foundone){
				ways[i] += ways[j + 1];
			}
		}
	}

	cout << ways[0];
	return 0;
}
