#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int t;
	std::cin >> t;

	for(int test_case = 1; test_case <= t; test_case++){
		ll n, k;
		std::cin >> n >> k;
		k--;

		std::map<ll, ll> m;
		m[n] = 1;

		std::cout << "Case #" << test_case << ": ";

		while(!m.empty()){
			ll get = m.rbegin()->first;
			ll get_amount = m.rbegin()->second;

			m.erase(--m.end());

			ll a = get / 2;
			ll b = get - a - 1;

			if(k < get_amount){
				std::cout << a << ' ' << b << '\n';
				break;
			}

			k -= get_amount;

			m[a] += get_amount;
			m[b] += get_amount;
		}
	}
}