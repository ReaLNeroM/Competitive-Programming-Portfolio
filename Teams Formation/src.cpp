#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n, need, blocks;
	std::cin >> n >> need >> blocks;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}

	ll left = n * blocks;
	ll extra = 0;
	std::vector<ll> types, times;
	for(ll i = 0; i < blocks * n and i < 2 * n; i++){
		if(!types.empty() and val[i % n] == types[types.size() - 1]){
			times[times.size() - 1]++;
			while(!times.empty() and times[times.size() - 1] >= need){
				times[times.size() - 1] -= need;
				left -= need;
				if(i >= n){
					extra += need;
				}

				if(times[times.size() - 1] == 0){
					types.pop_back();
					times.pop_back();
				}
			}
		} else {
			types.push_back(val[i % n]);
			times.push_back(1);
		}
	}

	if(types.size() == 1){
		times[0] += (blocks - 2) * (times[0] / 2);
		left -= (times[0] / need) * need;
	} else if(types.size() == 0){
		left -= (blocks - 2) / 2 * (n * blocks - left);
	} else if(blocks > 2){
		left -= (blocks - 2) * extra;
	}

	std::cout << left;
}