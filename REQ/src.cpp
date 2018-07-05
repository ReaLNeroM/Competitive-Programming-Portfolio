#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
const ll mod = 1e9 + 7;
ll val[maxn];
std::pair<ll, ll> seg[4 * maxn];
ll totient[maxn];

ll gcd(ll a, ll b){
	if(b == 0){
		return a;
	}

	return gcd(b, a % b);
}

ll inverse(ll a){
	ll pow = mod - 2;

	ll res = 1;

	while(pow){
		if(pow % 2){
			res *= a;
			res %= mod;
		}

		a *= a;
		a %= mod;
		pow /= 2;
	}

	return res;
}

std::pair<ll, ll> combine(auto fir, auto sec){
	std::pair<ll, ll> cop;
	cop.second = gcd(fir.second, sec.second);
	cop.first = fir.first * sec.first % mod;
	cop.first = cop.first * cop.second % mod;
	cop.first = cop.first * inverse(totient[cop.second]) % mod;

	return cop;
}

void build(ll ind = 0, ll cl = 0, ll cr = maxn - 1){
	if(cl == cr){
		seg[ind] = {totient[val[cl]], val[cl]};
		return;
	}

	ll mid = (cl + cr) / 2;
	build(2 * ind + 1, cl, mid);
	build(2 * ind + 2, mid + 1, cr);

	seg[ind] = combine(seg[2 * ind + 1], seg[2 * ind + 2]);
}

std::pair<ll, ll> query(ll ql, ll qr, ll ind = 0, ll cl = 0, ll cr = maxn - 1){
	if(qr < cl or cr < ql){
		return {1, 1};
	} else if(ql <= cl and cr <= qr){
		return seg[ind];
	}

	ll mid = (cl + cr) / 2;

	return combine(query(ql, qr, 2 * ind + 1, cl     , mid),
		           query(ql, qr, 2 * ind + 2, mid + 1, cr ));
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	std::fill(val, val + maxn, 0);
	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}

	totient[1] = 1;
	for(ll i = 2; i < maxn; i++){
		totient[i] = i - 1;
	}

	for(ll i = 1; i <= 1000000; i++){
		for(ll j = 2; j * j <= i; j++){
			if(i % j == 0){
				totient[i] = totient[i / j] * totient[j] % mod * gcd(i / j, j) % mod * inverse(totient[gcd(i / j, j)]) % mod;
				break;
			}
		}
	}

	build();

	ll q;
	std::cin >> q;

	for(ll i = 0; i < q; i++){
		ll l, r;
		std::cin >> l >> r;
		l--, r--;

		std::cout << query(l, r).first << '\n';
	}
}
