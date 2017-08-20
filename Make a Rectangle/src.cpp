#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5;
int val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}
	std::sort(val, val + n);

	ll a = 0;
	ll b = 0;

	for(ll i = n - 1; i >= 0; i--){
		if(val[i] == val[i - 1]){
			if(val[i] > a){
				b = a;
				a = val[i];
			} else if(val[i] > b){
				b = val[i];
			}

			i--;
		}
	}

	std::cout << a * b << '\n';
}