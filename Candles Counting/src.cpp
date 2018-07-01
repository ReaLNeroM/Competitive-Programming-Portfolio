#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 50000 + 1e2;
const ll mod = 1e9 + 7;
const ll maxbit = 128;
ll val[maxn], color[maxn];
ll fenwick[maxbit][maxn];
std::map<ll, ll> m;

ll query(ll bit, ll pos){
	pos++;
	ll res = 0;

	while(pos > 0){
		res += fenwick[bit][pos];
		res %= mod;

		pos -= pos & -pos;
	}

	return res;
}

void add(ll bit, ll pos, ll value){
	pos++;

	while(pos < maxn){
		fenwick[bit][pos] += value;
		fenwick[bit][pos] %= mod;
		pos += pos & -pos;
	}
}


int main(){
	std::ios::sync_with_stdio(false);

	ll n, k;
	std::cin >> n >> k;

	for(ll i = 1; i <= n; i++){
		std::cin >> val[i] >> color[i];
		color[i]--;
		m[val[i]] = 0;
	}

	ll curr = 1;
	for(auto ite = m.begin(); ite != m.end(); ite++){
		ite->second = curr;
		curr++;
	}

	add(0, 0, 1);
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < (1 << k); j++){
			add(j | (1 << color[i]), m[val[i]], query(j, m[val[i]] - 1));
		}
	}

	std::cout << query((1 << k) - 1, n) << '\n';
}
