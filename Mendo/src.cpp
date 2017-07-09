#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 262144;
const ll mod = 1e9 + 7;
ll seg[2][8 * maxn];
ll laz[2][8 * maxn];
ll ppow[maxn];
std::map<ll, std::vector<ll>> m;
std::string s[2];

void build(ll side, ll l, ll r, ll ind){
	if(l == r){
		seg[side][ind] = s[side][l] - 'a' + 1;
		return;
	}

	ll mid = (l + r) / 2;

	build(side, l, mid, 2 * ind + 1);
	build(side, mid + 1, r, 2 * ind + 2);

	seg[side][ind] = seg[side][2 * ind + 1] * ppow[mid - l + 1] + seg[side][2 * ind + 2];
	m[seg[side][ind]] = {seg[side][2 * ind + 1], seg[side][2 * ind + 2]};
}

void propagate(ll side, ll ind, ll l, ll r){
	if(laz[side][ind]){
		std::vector<ll> v = m[seg[side][ind]];
		seg[side][2 * ind + 1] = v[0];
		seg[side][2 * ind + 2] = v[1];

		laz[side][ind] = false;
	}
}

std::vector<ll> query(ll side, ll ql, ll qr, ll cl = 0, ll cr = maxn - 1, ll ind = 0){
	if(ql <= cl and cr <= qr){
		return {seg[side][ind], cr - cl + 1};
	} else if(qr < cl or cr < ql){
		return {0, 0};
	}

	propagate(side, ind, cl, cr);

	ll mid = (cl + cr) / 2;

	auto a = query(side, ql, qr, cl, mid, 2 * ind + 1);
	auto b = query(side, ql, qr, mid + 1, cr, 2 * ind + 2);

	ll res = a[0] * ppow[b[1]] + b[0];
	res %= mod;
	m[res] = {a[0], b[0]};

	return {res, a[1] + b[1]};
}

void update(ll side, ll ql, ll qr, ll qval, ll cl = 0, ll cr = maxn - 1, ll ind = 0){
	while(ql < cl){
		qval = m[qval][1];
		ql = (ql + qr) / 2 + 1;
	}
	while(cr < qr){
		qval = m[qval][0];
		qr = (ql + qr) / 2;
	}

	if(ql == cl and cr == qr){
		//compose
		seg[side][ind] =
		laz[side][ind] = true;
		return;
	} else if(qr < cl or cr < ql){
		return;
	}

	propagate(side, ind, cl, cr);

	ll mid = (cl + cr) / 2;

	update(side, ql, qr, qval, cl, mid, 2 * ind + 1);
	update(side, ql, qr, qval, mid + 1, cr, 2 * ind + 2);

	seg[side][ind] = seg[side][2 * ind + 1] * ppow[mid - cl + 1] + seg[side][2 * ind + 2];
	m[seg[side][ind]] = {seg[side][2 * ind + 1], seg[side][2 * ind + 2]};
}

int main(){
    std::ios::sync_with_stdio(false);

    ppow[0] = 1;
    for(ll i = 1; i < maxn; i++){
    	ppow[i] = ppow[i - 1] * 27;
    	ppow[i] %= mod;
    }

    ll q;
    std::cin >> q >> q;

    std::cin >> s[0];
    while(s[0].size() != maxn){
    	s[0] += (char) ('a' - 1);
    }
    s[1] = s[0];
    std::reverse(s[1].begin(), s[1].end());

    build(0, 0, maxn - 1, 0);
    build(1, 0, maxn - 1, 0);
    for(ll i = 0; i < q; i++){
    	char c;
    	std::cin >> c;

    	if(c == 'Q'){
    		ll a, b;
    		std::cin >> a >> b;

  			a--, b--;

  			std::cout << query(0, a, b)[0] << std::endl;
  			if(query(0, a, b)[0] == query(1, maxn - 1 - b, maxn - 1 - a)[0]){
  				std::cout << "YES\n";
  			} else {
  				std::cout << "NO\n";
  			}
    	} else {
    		ll t;
    		std::cin >> t;

    		if(t == 1){

    		} else if(t == 2){
    			ll a, b;
    			std::cin >> a >> b;
    			a--, b--;

    			ll hash_a = query(0, a, b)[0];
    			ll hash_b = query(1, maxn - 1 - b, maxn - 1 - a)[0];

    			update(0, a, b, hash_b);
    			update(1, maxn - 1 - b, maxn - 1 - a, hash_a);
    		} else if(t == 3){

    		}
    	}
    }
}
