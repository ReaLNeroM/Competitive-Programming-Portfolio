#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = (1 << 20);
ll val[maxn];
ll seg[4 * maxn];
ll segside[4 * maxn];

void build(ll ind = 0, ll cl = 0, ll cr = maxn - 1){
	if(cl == cr){
		seg[ind] = val[cl];
		segside[ind] = 1;
		return;
	}

	ll mid = (cl + cr) / 2;
	build(2 * ind + 1, cl, mid);
	build(2 * ind + 2, mid + 1, cr);

	if(segside[2 * ind + 1] == 0){
		seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
		segside[ind] = 1;
	} else {
		seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
		segside[ind] = 0;
	}
}

void update(ll pos, ll change, ll ind = 0, ll cl = 0, ll cr = maxn - 1){
	if(cl == cr){
		seg[ind] = change;
		return;
	}

	ll mid = (cl + cr) / 2;

	if(pos <= mid){
		update(pos, change, 2 * ind + 1, cl, mid);
	} else {
		update(pos, change, 2 * ind + 2, mid + 1, cr);
	}
	
	if(segside[2 * ind + 1] == 0){
		seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
		segside[ind] = 1;
	} else {
		seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
		segside[ind] = 0;
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n, q;
	std::cin >> n >> q;

	n = (1 << n);

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}

	build();

	for(ll i = 0; i < q; i++){
		ll p, b;
		std::cin >> p >> b;
		p--;

		update(p, b);

		std::cout << seg[0] << '\n';
	}
}