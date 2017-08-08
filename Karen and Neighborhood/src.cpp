#include <bits/stdc++.h>

typedef long long ll;

ll n, k;
ll accumulated = 0;
ll need = -1;

bool dfs(ll pos, ll ind){
	std::map<ll, ll> m;

	m[pos] = 1;

	while(!m.empty()){
		ll get = m.begin()->first;
		if(get < 1){
			break;
		}
		ll times = m.begin()->second;

		ll mid = (get - 1) / 2;

		if(get == need){
			if(k < accumulated + times){
				if(!dfs((pos - 1) / 2 - 1, ind)){
					dfs(pos - (pos - 1) / 2 - 1, (pos - 1) / 2 + 1);
				}
				return true;
			} else if(k == accumulated + times){
				std::cout << ind + (mid + 1) + 1 << std::endl;
				return true;
			} else {
				accumulated += times;
				return false;
			}
		}


		m[mid - 1] += times;
		m[get - mid - 1] += times;
	}

	return false;
}

int main(){
	std::cin >> n >> k;

	if(k == 1){
		std::cout << 1 << std::endl;
	} else if(k == 2){
		std::cout << n << std::endl;
	} else {
		n -= 2;
		k -= 2;

		std::map<ll, ll> m;

		m[n] = 1;

		while(!m.empty()){
			ll get = m.rbegin()->first;
			ll times = m.rbegin()->second;
			m.erase(--m.end());
			ll mid = (get - 1) / 2;
			std::cout << get << ' ' << times << ' ' << mid << ' ' << mid << ' ' << get - mid - 1 << std::endl;

			if(k <= times){
				need = get;
				break;
			}
			k -= times;
			m[mid] += times;
			m[get - mid - 1] += times;

		}

		std::cout << need << ' ' << k << std::endl;

		dfs(n, 0);
	}
}