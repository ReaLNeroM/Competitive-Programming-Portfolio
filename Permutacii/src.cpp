#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 7;
const ll maxn = 1e6 + 1e2;
ll val[maxn];
ll used[maxn];
ll amount[maxn];
ll factorial[maxn];
ll res = 1;

ll pow(ll start, ll a, ll b){
	for(ll i = 1; i <= b; i++){
		start = start * a % mod;
	}

	return start;
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
		val[i]--;
	}

	factorial[0] = 1;
	for(ll i = 1; i <= n; i++){
		factorial[i] = factorial[i - 1] * i;
		factorial[i] %= mod;
	}

	for(ll i = 0; i < n; i++){
		if(!used[i]){
			std::queue<ll> q;
			q.push(i);

			ll found = 1;
			used[i] = true;

			while(!q.empty()){
				ll fr = q.front();
				q.pop();

				if(!used[val[fr]]){
					found++;
					used[val[fr]] = true;

					q.push(val[fr]);
				}
			}
			
			amount[found]++;
		}
	}

	for(ll i = 1; i <= n; i++){
		res *= pow(factorial[amount[i]], i, amount[i]);
		res %= mod;
	}

	std::cout << res << '\n';
}