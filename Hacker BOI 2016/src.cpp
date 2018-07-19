#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 300005;
const ll mod[] = {(ll) 1e9 + 9, (ll) 999999937LL};
ll seg_orig[2 * maxn][2];
ll size_orig[2 * maxn];

ll seg[4 * maxn][2];
ll size[4 * maxn];
ll laz[4 * maxn];
ll ppow[maxn][2];
std::string s;
ll n, q;

std::pair<ll, ll> query_orig(ll l, ll r){
	r++;
	ll res_l[] = {0, 0};
	ll res_r[] = {0, 0};
	ll size_l = 0;
	ll size_r = 0;

	for(l += n, r += n; l < r; l /= 2, r /= 2){
		if(l & 1){
			res_l[0] = (res_l[0] * ppow[size_orig[l]][0] + seg_orig[l][0]) % mod[0];
			res_l[1] = (res_l[1] * ppow[size_orig[l]][1] + seg_orig[l][1]) % mod[1];

			size_l += size_orig[l];

			l++;
		}
		if(r & 1){
			r--;

			res_r[0] = (seg_orig[r][0] * ppow[size_r][0] + res_r[0]) % mod[0];
			res_r[1] = (seg_orig[r][1] * ppow[size_r][1] + res_r[1]) % mod[1];

			size_r += size_orig[r];
		}
	}

	return {(res_l[0] * ppow[size_r][0] + res_r[0]) % mod[0], 
			(res_l[1] * ppow[size_r][1] + res_r[1]) % mod[1]};
}

void build(ll ind = 0, ll l = 0, ll r = n - 1){
	if(l == r){
		seg[ind][0] = seg[ind][1] = (s[l] - 'a') + 1LL;
		size[ind] = 1;
		laz[ind] = -1;
		return;
	}

	ll mid = (l + r) / 2;
	build(2 * ind + 1, l, mid);
	build(2 * ind + 2, mid + 1, r);

	seg[ind][0] = (seg[2 * ind + 1][0] * ppow[size[2 * ind + 2]][0] + seg[2 * ind + 2][0]) % mod[0];
	seg[ind][1] = (seg[2 * ind + 1][1] * ppow[size[2 * ind + 2]][1] + seg[2 * ind + 2][1]) % mod[1];
	size[ind] = size[2 * ind + 1] + size[2 * ind + 2];
	laz[ind] = -1;
}

void propagate(ll ind, ll l, ll r){
	if(laz[ind] == -1){
		return;
	}

	ll mid = (l + r) / 2;

	ll l_size = mid - l;
	ll r_size = r - (mid + 1);

	auto a = query_orig(laz[ind], laz[ind] + l_size);

	seg[2 * ind + 1][0] = a.first;
	seg[2 * ind + 1][1] = a.second;

	auto b = query_orig(laz[ind] + l_size + 1, laz[ind] + l_size + 1 + r_size);

	seg[2 * ind + 2][0] = b.first;
	seg[2 * ind + 2][1] = b.second;

	laz[2 * ind + 1] = laz[ind];
	laz[2 * ind + 2] = laz[ind] + l_size + 1;
	laz[ind] = -1;
}

std::pair<std::pair<ll, ll>, ll> query(ll ql, ll qr, ll ind = 0, ll cl = 0, ll cr = n - 1){
	if(cr < ql or qr < cl){
		return {{0, 0}, 0};
	} else if(ql <= cl and cr <= qr){
		return {{seg[ind][0], seg[ind][1]}, size[ind]};
	}

	propagate(ind, cl, cr);
	ll mid = (cl + cr) / 2;

	auto a = query(ql, qr, 2 * ind + 1, cl, mid);
	auto b = query(ql, qr, 2 * ind + 2, mid + 1, cr);
	return {{(a.first.first * ppow[b.second][0] + b.first.first) % mod[0], 
			 (a.first.second * ppow[b.second][1] + b.first.second) % mod[1]}, a.second + b.second};
}

void update(ll ql, ll qr, ll upd_pos, ll ind = 0, ll cl = 0, ll cr = n - 1){
	if(cr < ql or qr < cl){
		return;
	} else if(ql <= cl and cr <= qr){
		auto x = query_orig(upd_pos, upd_pos + cr - cl);
		seg[ind][0] = x.first;
		seg[ind][1] = x.second;
		laz[ind] = upd_pos;
		return;
	}

	propagate(ind, cl, cr);

	ll mid = (cl + cr) / 2;

	ll left_updated = std::max(0LL, mid - std::max(cl, ql) + 1);
	update(ql, qr, upd_pos, 2 * ind + 1, cl, mid);
	update(ql, qr, upd_pos + left_updated, 2 * ind + 2, mid + 1, cr);

	seg[ind][0] = (seg[2 * ind + 1][0] * ppow[size[2 * ind + 2]][0] + seg[2 * ind + 2][0]) % mod[0];
	seg[ind][1] = (seg[2 * ind + 1][1] * ppow[size[2 * ind + 2]][1] + seg[2 * ind + 2][1]) % mod[1];
}

int main(){
	std::ios::sync_with_stdio(false);

	ppow[0][0] = ppow[0][1] = 1;
	for(ll i = 1; i < maxn; i++){
		ppow[i][0] = (ppow[i - 1][0] * 31LL) % mod[0];
		ppow[i][1] = (ppow[i - 1][1] * 37LL) % mod[1];
	}

	std::cin >> s;

	n = s.size();
	std::cin >> q;

	for(ll i = 2 * n - 1; i >= n; i--){
		seg_orig[i][0] = seg_orig[i][1] = (s[i - n] - 'a') + 1LL;
		size_orig[i] = 1;
	}

	for(ll i = n - 1; i > 0; i--){
		seg_orig[i][0] = (seg_orig[2 * i][0] * ppow[size_orig[2 * i + 1]][0] + seg_orig[2 * i + 1][0]) % mod[0];
		seg_orig[i][1] = (seg_orig[2 * i][1] * ppow[size_orig[2 * i + 1]][1] + seg_orig[2 * i + 1][1]) % mod[1];
		size_orig[i] = size_orig[2 * i] + size_orig[2 * i + 1];
	}

	build();

	for(ll i = 0; i < q; i++){
		ll query_type;
		std::cin >> query_type;

		if(query_type == 1){
			ll m, n, p;
			std::cin >> m >> n >> p;

			m--, n--, p--;
			if(m > n){
				std::swap(m, n);
			}

			if(query(m, n) == query(p, p + (n - m))){
				std::cout << "Y\n";
			} else {
				std::cout << "N\n";
			}
		} else if(query_type == 2){
			ll m, n, p;
			std::cin >> m >> n >> p;
			m--, n--, p--;
			if(m > n){
				std::swap(n, m);
			}

			update(m, n, p);
		} else {
			return -1;
		}
	}
}
