#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll val[maxn];
ll fenwick[3][maxn];

void update(ll tree, ll pos, ll change){
	pos++;

	while(pos < maxn){
		fenwick[tree][pos] += change;
		pos += pos & -pos;
	}
}

ll query(ll tree, ll pos){
	pos++;

	ll res = 0;

	while(pos > 0){
		res += fenwick[tree][pos];
		pos -= pos & -pos;
	}

	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	std::map<ll, ll> m;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
		m[val[i]] = true;
	}

	ll curr = 0;
	ll res = 0;

	for(auto ite = m.begin(); ite != m.end(); ite++){
		ite->second = (ll) m.size() - curr;
		curr++;
	}

	for(ll i = 0; i < n; i++){
		res += query(1, m[val[i]]);
		update(1, m[val[i]], query(0, m[val[i]]));
		update(0, m[val[i]], 1);
	}

	std::cout << res << '\n';
}
n