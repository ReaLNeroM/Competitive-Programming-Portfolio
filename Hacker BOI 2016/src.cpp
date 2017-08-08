#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 300005;
const ll mod = 1e9 + 9;
ll seg[8 * maxn];
ll segl[26][8 * maxn];
ll laz[8 * maxn];
ll ppow[maxn];
std::unordered_map<ll, std::vector<ll>> m;
std::string s;

void build(ll l, ll r, ll ind){
	if(l == r){
		seg[ind] = s[l] - 'a' + 1;
		segl[s[l]]
		return;
	}

	int mid = (l + r) / 2;

	build(l, mid, 2 * ind + 1);
	build(mid + 1, r, 2 * ind + 2);

	seg[ind] = seg[2 * ind + 1] * ppow[r - (mid + 1) + 1] + seg[2 * ind + 2];
}

void propagate(ll side, ll ind, ll l, ll r){
	if(laz[side][ind]){
		std::vector<ll> v = m[seg[side][ind]];
		seg[side][2 * ind + 1] = v[0];
		seg[side][2 * ind + 2] = v[1];

		laz[side][ind] = false;
	}
}

ll ans_s;

ll query(ll side, ll ql, ll qr, ll cl = 0, ll cr = maxn - 1, ll ind = 0){
	if(ql <= cl and cr <= qr){
		ans_s = cr - cl + 1;
		return seg[side][ind];
	} else if(qr < cl or cr < ql){
		ans_s = 0;
		return 0;
	}

	propagate(side, ind, cl, cr);

	ll mid = (cl + cr) / 2;

	ll f_v = query(side, ql, qr, cl, mid, 2 * ind + 1);
	ll f_s = ans_s;
	ll s_v = query(side, ql, qr, mid + 1, cr, 2 * ind + 2);
	ll s_s = ans_s;

	ll res;
	res = f_v * ppow[s_s] + s_v;
	res %= mod;
	if(f_v and s_v){
		m[res] = {f_v, s_v, f_v, s_s};
	}

	ans_s = f_s + s_s;

	return res;
}

void update(ll side, ll ql, ll qr, ll qval, ll cl = 0, ll cr = maxn - 1, ll ind = 0){
	while(ql != qr and ql < cl){
		ql += m[qval][2];
		qval = m[qval][1];
	}
	while(ql != qr and cr < qr){
		qr -= m[qval][3];
		qval = m[qval][0];
	}

	if(ql == cl and cr == qr){
		seg[side][ind] = qval;
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
	seg[side][ind] %= mod;
	m[seg[side][ind]] = {seg[side][2 * ind + 1], seg[side][2 * ind + 2], mid - cl + 1, cr - (mid + 1) + 1};
}

int main(){
	std::ios::sync_with_stdio(false);

	ppow[0] = 1;
	for(ll i = 1; i < maxn; i++){
		ppow[i] = ppow[i - 1] * 31;
		ppow[i] %= mod;
	}

	ll n, q;
	std::cin >> n >> q;

	std::cin >> s;
	while(s[0].size() != maxn){
		s[0] += (char) ('a' - 1);
	}

	s[1] = s[0];
	std::reverse(s[1].begin(), s[1].end());

	build(0, 0, maxn - 1, 0);
	build(1, 0, maxn - 1, 0);

	std::stringstream ostr;

	for(ll i = 0; i < q; i++){
		char c;
		std::cin >> c;

		if(c == 'Q'){
			ll a, b;
			std::cin >> a >> b;

			a--, b--;

			if(query(0, a, b) == query(1, maxn - 1 - b, maxn - 1 - a)){
				ostr << "YES\n";
			} else {
				ostr << "NO\n";
			}
		} else {
			// ll t;
			// std::cin >> t;

			// if(t == 1){
			// 	ll a, b, c;
			// 	std::cin >> a >> b >> c;
			// 	a--, b--, c--;
			// 	return -1;
			// } else if(t == 2){
			// 	ll a, b;
			// 	std::cin >> a >> b;
			// 	a--, b--;

			// 	ll hash_a = query(0, a, b);
			// 	ll hash_b = query(1, maxn - 1 - b, maxn - 1 - a);

			// 	update(0, a, b, hash_b);
			// 	update(1, maxn - 1 - b, maxn - 1 - a, hash_a);
			// } else if(t == 3){
			// 	ll i;
			// 	char ch;
			// 	std::cin >> i >> ch;
			// 	i--;
			// 	return -1;
			// }
		}
	}

	std::cout << ostr.str();
}
