#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
std::string s;
ll res = 0;

int main(){
	std::ios::sync_with_stdio(false);

	ll n, x, y;
	std::cin >> n >> x >> y;

	std::cin >> s;

	ll components = 0;
	for(ll i = 0; i < n; i++){
		if(s[i] == '0'){
			components++;
			for(ll j = i + 1; j < n; j++){
				if(s[j] != '0' or j == n - 1){
					i = j;
					break;
				}
			}
		}
	}
	
	if(components == 0){
		res = 0;
	} else {
		res = std::min(y * components, x * (components - 1LL) + y);
	}

	std::cout << res << '\n';
}