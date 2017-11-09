#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	std::multiset<ll> s;

	for(ll i = 0; i < n; i++){
		ll x;
		std::cin >> x;
		s.insert(x);
	}

	ll sum = 0;

	if(s.size() % 2 == 0){
		s.insert(0);
	}
	while(s.size() > 1){
		ll curr = 0;
		for(ll j = 0; j < 3 and !s.empty(); j++){
			curr += *s.begin();
			s.erase(s.begin());
		}

		sum += curr;
		s.insert(curr);
	}

	std::cout << sum << '\n';
}