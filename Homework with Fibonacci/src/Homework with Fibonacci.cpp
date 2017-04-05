#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e5 + 1e2;
const ll mod = 1e9 + 7;
static ll seg[8 * maxn];
static ll seg2[8 * maxn];
static ll laz[8 * maxn];
static ll val[maxn];
static int fib[(int) (2e7 + 1e2)];
ll n;

void build(ll ind, ll cl, ll cr){
	if(cl == cr){
		seg[ind] = fib[val[cl]];
		seg2[ind] = fib[val[cl] + 1];
		return;
	} else if(cl > cr){
		return;
	}

	ll mid = (cl + cr) / 2;

	build(2 * ind + 1, cl, mid);
	build(2 * ind + 2, mid + 1, cr);

	seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]) % mod;
	seg2[ind] = (seg2[2 * ind + 1] + seg2[2 * ind + 2]) % mod;
}

void propagate(ll ind){
	if(laz[ind] != 0){
		ll new_seg = (seg2[2 * ind + 1] * fib[laz[ind]] + seg[2 * ind + 1] * fib[laz[ind] - 1]) % mod;
		ll new_seg_2 = (seg2[2 * ind + 1] * fib[laz[ind] + 1] + seg[2 * ind + 1] * fib[laz[ind]]) % mod;
		seg [2 * ind + 1] = new_seg;
		seg2[2 * ind + 1] = new_seg_2;
		laz [2 * ind + 1] += laz[ind];

		new_seg = (seg2[2 * ind + 2] * fib[laz[ind]] + seg[2 * ind + 2] * fib[laz[ind] - 1]) % mod;
		new_seg_2 = (seg2[2 * ind + 2] * fib[laz[ind] + 1] + seg[2 * ind + 2] * fib[laz[ind]]) % mod;
		seg [2 * ind + 2] = new_seg;
		seg2[2 * ind + 2] = new_seg_2;
		laz [2 * ind + 2] += laz[ind];
	}

	laz[ind] = 0;
}

void update(ll ql, ll qr, ll val, ll ind = 0, ll cl = 0, ll cr = n - 1){
	propagate(ind);

	if(ql <= cl and cr <= qr){
		laz[ind] += val;
		ll new_seg = (seg2[ind] * fib[val] + seg[ind] * fib[val - 1]) % mod;
		ll new_seg_2 = (seg2[ind] * fib[val + 1] + seg[ind] * fib[val]) % mod;

		seg[ind] = new_seg;
		seg2[ind] = new_seg_2;
		return;
	} else if(cr < ql or qr < cl){
		return;
	}

	ll mid = (cl + cr) / 2;

	update(ql, qr, val, 2 * ind + 1, cl     , mid);
	update(ql, qr, val, 2 * ind + 2, mid + 1, cr );

	seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]) % mod;
	seg2[ind] = (seg2[2 * ind + 1] + seg2[2 * ind + 2]) % mod;
}

ll sum(ll ql, ll qr, ll ind = 0, ll cl = 0, ll cr = n - 1){
	propagate(ind);

	if(ql <= cl and cr <= qr){
		return seg[ind];
	} else if(cr < ql or qr < cl){
		return 0;
	}

	ll mid = (cl + cr) / 2;

	return (sum(ql, qr, 2 * ind + 1, cl     , mid) +
		    sum(ql, qr, 2 * ind + 2, mid + 1, cr )) % mod;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;

	fib[0] = 0;
	fib[1] = 1;
	for(ll i = 2; i < 2e7 + 1e2; i++){
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] %= mod;
	}

	for(ll x = 0; x < t; x++){
		fill(seg, seg + 8 * maxn, 0);
		fill(seg2, seg2 + 8 * maxn, 0);
		fill(laz, laz + 8 * maxn, 0);

		cin >> n;

		for(ll i = 0; i < n; i++){
			cin >> val[i];
			val[i]++;
		}

		build(0, 0, n - 1);

		ll q;
		cin >> q;

		for(ll i = 0; i < q; i++){
			ll t;
			cin >> t;

			if(t == 1){
				ll l, r;
				cin >> l >> r;
				l--, r--;

				cout << sum(l, r) << '\n';
			} else {
				ll l, r, change;
				cin >> l >> r >> change;
				l--, r--;

				if(change != 0){
					update(l, r, change);
				}
			}
		}
	}
}

