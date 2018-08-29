#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
const ll INF = 1e9 + 1e2;
ll val[maxn];
ll cop[maxn];
ll tree[maxn];
ll n;

void update(ll pos){
	pos += n + 1;

	while(pos < maxn){
		tree[pos] += 1;
		pos += pos & -pos;
	}
}

ll query(ll pos){
	pos += n + 1;

	ll res = 0;
	while(pos > 0){
		res += tree[pos];
		pos -= pos & -pos;
	}

	return res;
}

ll countAbove(ll pos){
	memset(tree, 0, sizeof(tree));
	std::copy(val, val + n, cop);

	ll sum = 0;

	for(ll i = 0; i < n; i++){
		if(cop[i] >= pos){
			cop[i] = -1;
		} else {
			cop[i] = 1;
		}

		sum += cop[i];
	}

	ll res = 0;

	for(ll i = 0; i < n; i++){
		update(sum);

		sum -= cop[i];

		res += query(sum);
	}

	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}

	ll total = n * (n + 1) / 2;

	ll l = 1, r = INF;
	ll best = 1;

	while(l <= r){
		ll mid = (l + r) / 2;

		if(countAbove(mid) * 2 >= total){
			best = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	std::cout << best << '\n';
}
