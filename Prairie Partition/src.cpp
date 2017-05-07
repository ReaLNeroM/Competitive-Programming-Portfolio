#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 5;
ll val[maxn];
std::map<ll, ll> app;

ll pow2[maxn];
ll head[maxn];
ll place[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
		app[val[i]]++;
	}

	ll foll = (1LL << 50LL);
	ll need = 0;

	for(ll i = n - 1; i >= 0; i--){
		while(foll > val[i]){
			foll /= 2;
		}

		if(foll == val[i]){
			app[val[i]] -= need;
			if(app[val[i]] < 0){
				std::cout << -1 << std::endl;
				return 0;
			}

			need += (app[val[i]] + 1) / 2;
		} else {
			need += app[val[i]];
		}

		while(i != 0 and val[i] == val[i - 1]){
			i--;
		}
	}

	std::cout << need << std::endl;

	auto ite = app.begin();

	ll curr = 1;
	ll slot = 0;
	while(ite != app.end()){
		while(curr < ite->first){
			slot++;
			curr *= 2;
		}

		if(curr == ite->first){
			pow2[slot] += ite->second;
		} else {
			head[slot - 1] += ite->second;
		}
		ite++;
	}
}