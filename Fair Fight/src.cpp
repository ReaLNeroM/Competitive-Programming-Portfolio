#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 10;
ll v[2][maxn];
ll seg[2][8 * maxn];

void build(ll type, ll ind = 0, ll l = 0, ll r = maxn - 1){
	if(l == r){
		seg[type][ind] = v[type][l];
		return;
	}

	ll mid = (l + r) / 2;

	build(type, 2 * ind + 1, l, mid);
	build(type, 2 * ind + 2, mid + 1, r);
	seg[type][ind] = std::max(seg[type][2 * ind + 1], seg[type][2 * ind + 2]);
}

ll query(ll type, ll ql, ll qr, ll ind = 0, ll cl = 0, ll cr = maxn - 1){
	if(cr < ql or qr < cl){
		return 0;
	}
	if(ql <= cl and cr <= qr){
		return seg[type][ind];
	}

	ll mid = (cl + cr) / 2;

	return std::max(query(type, ql, qr, 2 * ind + 1, cl     , mid),
					query(type, ql, qr, 2 * ind + 2, mid + 1, cr ));
}

int main(){
	std::ios::sync_with_stdio(false);

	ll testCases;
	std::cin >> testCases;

	for(ll testcase = 1; testcase <= testCases; testcase++){
		ll n, k;
		std::cin >> n >> k;

		for(ll i = 0; i < n; i++){
			std::cin >> v[0][i];
		}
		for(ll i = 0; i < n; i++){
			std::cin >> v[1][i];
		}
		build(0);
		build(1);
		ll res = 0;

		for(ll i = 0; i < n; i++){
			if(v[1][i] - k > v[0][i]){
				continue;
			}

			ll l = 0, r = i - 1;
			ll minX = i;

			while(l <= r){
				ll mid = (l + r) / 2;

				if(query(0, mid, i - 1) < v[0][i]){
					minX = mid;
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			}

			l = i, r = n - 1;
			ll maxX = i;
			while(l <= r){
				ll mid = (l + r) / 2;

				if(query(0, i, mid) == v[0][i]){
					maxX = mid;
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}

			ll threshY1 = i + 1;
			l = 0, r = i;
			while(l <= r){
				ll mid = (l + r) / 2;

				ll getResult = query(1, mid, i);
				if(getResult - k > v[0][i]){
					l = mid + 1;
				} else if(v[0][i] - k > getResult){
					r = mid - 1;
				} else {
					threshY1 = mid;
					l = mid + 1;
				}
			}

			ll threshY2 = i - 1;
			l = i, r = n - 1;
			while(l <= r){
				ll mid = (l + r) / 2;

				ll getResult = query(1, i, mid);
				if(getResult - k > v[0][i]){
					r = mid - 1;
				} else if(v[0][i] - k > getResult){
					l = mid + 1;
				} else {
					threshY2 = mid;
					r = mid - 1;
				}
			}

			ll minY = i;
			l = 0, r = i;
			while(l <= r){
				ll mid = (l + r) / 2;

				ll getResult = query(1, mid, i);
				if(getResult - k > v[0][i]){
					l = mid + 1;
				} else {
					minY = mid;
					r = mid - 1;
				}
			}

			ll maxY = i;
			l = i, r = n - 1;
			while(l <= r){
				ll mid = (l + r) / 2;

				ll getResult = query(1, i, mid);
				if(getResult - k > v[0][i]){
					r = mid - 1;
				} else {
					maxY = mid;
					l = mid + 1;
				}
			}

			if(threshY1 != i + 1 and std::max(minY, minX) <= threshY1){
				res += (ll) (threshY1 - std::max(minY, minX) + 1) * (std::min(maxX, maxY) - i + 1);
			}
			if(threshY2 != i - 1 and threshY2 <= std::min(maxY, maxX)){
				res += (ll) (std::min(maxY, maxX) - threshY2 + 1) * (i - std::max(minY, minX) + 1);
			}
			if(threshY1 != i + 1 and std::max(minY, minX) <= threshY1 and threshY2 != i - 1 and threshY2 <= std::min(maxY, maxX)){
				res -= (ll) (threshY1 - std::max(minY, minX) + 1) * (std::min(maxY, maxX) - threshY2 + 1);
			}
		}

		std::cout << "Case #" << testcase << ": " << res << '\n';
	}
}
