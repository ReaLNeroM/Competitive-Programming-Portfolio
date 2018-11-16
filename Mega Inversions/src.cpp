#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 1e2;
ll val[maxn];
ll fen[maxn];
ll fen2[maxn];

void update(ll pos, ll upd){
	pos++;
	while(pos < maxn){
		fen[pos] += upd;
		pos += pos & -pos;
	}
}

ll query(ll pos){
	pos++;

	ll res = 0;
	while(pos > 0){
		res += fen[pos];
		pos -= pos & -pos;
	}

	return res;
}

void update2(ll pos, ll upd){
	pos = maxn - pos - 1;

	while(pos < maxn){
		fen2[pos] += upd;
		pos += pos & -pos;
	}
}

ll query2(ll pos){
	pos = maxn - pos - 1;

	ll res = 0;
	while(pos > 0){
		res += fen2[pos];
		pos -= pos & -pos;
	}

	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
		update(val[i], 1);
	}

	update(val[0], -1);
	update2(val[0], 1);

	ll res = 0;

	for(ll i = 1; i < n; i++){
		res += query(val[i] - 1) * query2(val[i] + 1);

		update(val[i], -1);
		update2(val[i], 1);
	}

	std::cout << res << '\n';
}