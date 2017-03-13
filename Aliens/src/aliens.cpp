#include <bits/stdc++.h>
#include "aliens.h"
typedef long long ll;

const ll maxm = 1e6 + 1e2;
const ll maxn = 1e5 + 1e2;
const ll maxk = 4e3 + 1e2;
static ll extend[maxm];
std::vector<std::pair<ll, ll>> q;
static ll dp[4005][4005];
static ll dp2[50005][105];

ll score(ll a, ll b){
	ll c = q[b].second - 1;
	if(b != 0){
		c = std::max(c, q[b - 1].first);
	}

	a = q[a].first;
	b = q[b].second;

	return (a - b + 1LL) * (a - b + 1LL) - (c - b + 1LL) * (c - b + 1LL);
}

ll take_photos(int n, int m, int k, std::vector<int> r, std::vector<int> c) {
	std::fill(extend, extend + maxm, maxm);

	for(ll i = 0; i < r.size(); i++){
		if(r[i] <= c[i]){
			extend[c[i]] = std::min(extend[c[i]], (ll) r[i]);
		} else {
			extend[r[i]] = std::min(extend[r[i]], (ll) c[i]);
		}
	}

	ll curr = maxm;
	for(ll i = maxm - 1; i >= 0; i--){
		if(extend[i] < curr){
			curr = extend[i];
			q.push_back({i, extend[i]});
		}
	}
	std::reverse(q.begin(), q.end());

	for(ll i = 0; i <= q.size(); i++){
		for(ll j = 0; j <= k; j++){
			dp[i][j] = 1e18;
			dp2[i][j] = 1e18;
		}
	}

	if(k > 100){
		dp[0][0] = 0;

		for(ll i = 1; i <= k; i++){
			dp[0][i] = 0;
			ll point = 1;
			for(ll j = 1; j <= q.size(); j++){
				for(ll jmp = 131072; jmp >= 1; jmp /= 2){
					while(point + jmp <= j and dp[point - 1][i - 1] + score(j - 1, point - 1) > dp[point + jmp - 1][i - 1] + score(j - 1, point + jmp - 1)){
						point += jmp;
					}
				}

				dp[j][i] = dp[point - 1][i - 1] + score(j - 1, point - 1);
			}
		}

		return dp[q.size()][k];
	} else {
		dp2[0][0] = 0;

		for(ll i = 1; i <= k; i++){
			dp2[0][i] = 0;
			ll point = 1;
			for(ll j = 1; j <= q.size(); j++){
				for(ll jmp = 131072; jmp >= 1; jmp /= 2){
					while(point + jmp <= j and dp2[point - 1][i - 1] + score(j - 1, point - 1) > dp2[point + jmp - 1][i - 1] + score(j - 1, point + jmp - 1)){
						point += jmp;
					}
					while(point - jmp >= 1 and dp2[point - 1][i - 1] + score(j - 1, point - 1) > dp2[point - jmp - 1][i - 1] + score(j - 1, point - jmp - 1)){
						point -= jmp;
					}
				}

				dp2[j][i] = dp2[point - 1][i - 1] + score(j - 1, point - 1);
			}
		}

		return dp2[q.size()][k];
	}
}
