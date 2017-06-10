#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 100;
ll val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;
	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}
	val[n] = 0;

	std::stack<std::vector<ll>> s;

	ll res = 0;
	for(ll i = 0; i <= n; i++){
		ll least = i;

		while(!s.empty() and s.top()[0] >= val[i]){
			least = std::min(least, s.top()[1]);
			if(s.top()[0] * (i - s.top()[1]) == 2900738985){
				std::cout << s.top()[0] << ' ' << s.top()[1] << ' ' << i << std::endl;
			}
			res = std::max(res, s.top()[0] * (i - s.top()[1]));
			s.pop();
		}

		s.push({val[i], least});
	}

	std::cout << res << std::endl;
}