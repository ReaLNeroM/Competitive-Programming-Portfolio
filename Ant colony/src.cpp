#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll val[maxn];
ll seg[4 * maxn];
std::pair<ll, ll> seg2[4 * maxn];

ll gcd(ll a, ll b){
	if(b == 0){
		return a;
	}

	return gcd(b, a % b);
}

void build(ll ind = 0, ll cl = 0, ll cr = maxn - 1){
	if(cl == cr){
		seg[ind] = val[cl];
		seg2[ind] = {val[cl], 1};
		return;
	}

	ll mid = (cl + cr) / 2;
	build(2 * ind + 1, cl, mid);
	build(2 * ind + 2, mid + 1, cr);

	auto fir = seg2[2 * ind + 1];
	auto sec = seg2[2 * ind + 2];

	if(fir.first == sec.first){
		seg2[ind] = {fir.first, fir.second + sec.second};
	} else {
		seg2[ind] = std::min(fir, sec);
	}

	seg[ind] = gcd(seg[2 * ind + 1], seg[2 * ind + 2]);
}

ll query(ll ql, ll qr, ll ind = 0, ll cl = 0, ll cr = maxn - 1){
	if(qr < cl or cr < ql){
		return 0;
	} else if(ql <= cl and cr <= qr){
		return seg[ind];
	}

	ll mid = (cl + cr) / 2;

	return gcd(query(ql, qr, 2 * ind + 1, cl     , mid),
		       query(ql, qr, 2 * ind + 2, mid + 1, cr ));
}

std::pair<ll, ll> query2(ll ql, ll qr, ll ind = 0, ll cl = 0, ll cr = maxn - 1){
	if(qr < cl or cr < ql){
		return {1e9, 0};
	} else if(ql <= cl and cr <= qr){
		return seg2[ind];
	}

	ll mid = (cl + cr) / 2;

	auto fir = query2(ql, qr, 2 * ind + 1, cl     , mid);
	auto sec = query2(ql, qr, 2 * ind + 2, mid + 1, cr );

	if(fir.first == sec.first){
		return {fir.first, fir.second + sec.second};
	}

	return std::min(fir, sec);
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	std::fill(val, val + maxn, 0);
	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}

	build();

	ll q;
	std::cin >> q;

	for(ll i = 0; i < q; i++){
		ll l, r;
		std::cin >> l >> r;
		l--, r--;

		ll gcdneeded = query(l, r);
		std::pair<ll, ll> minfound = query2(l, r);

		if(gcd(minfound.first, gcdneeded) == minfound.first){
			std::cout << (r - l + 1) - minfound.second << '\n';
		} else {
			std::cout << r - l + 1 << '\n';
		}
	}
}
