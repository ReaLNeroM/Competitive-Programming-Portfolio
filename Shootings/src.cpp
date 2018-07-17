#include <bits/stdc++.h>

typedef long long ll;

const ll MAXN = 5e5 + 1e2;
const ll OFFSET = 1e5 + 1e2;

ll sum[MAXN][3];
ll pref[MAXN][3];
ll partial_sum[MAXN][3];

int main(){
	std::ios::sync_with_stdio(false);

	#ifndef local
		freopen("shootings.in", "r", stdin);
		freopen("shootings.out", "w", stdout);
	#endif

	ll n;
	std::cin >> n;

	for(ll i = 0; i < n; i++){
		ll x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;

		pref[x1][0] += y2 - y1;
		pref[x2 + 1][0] -= y2 - y1;

		pref[x1 + y1 + 1][1]++;
		pref[std::min(x1 + y2, x2 + y1) + 1][1]--;
		pref[std::max(x1 + y2, x2 + y1) + 1][1]--;
		pref[x2 + y2 + 1][1]++;

		pref[OFFSET + x1 - y2 + 1][2]++;
		pref[OFFSET + std::min(x1 - y1, x2 - y2) + 1][2]--;
		pref[OFFSET + std::max(x1 - y1, x2 - y2) + 1][2]--;
		pref[OFFSET + x2 - y1 + 1][2]++;
	}

	ll partial_sum[] = {0, 0, 0};
	ll second_sum[] = {0, 0, 0};

	for(ll i = 0; i < MAXN; i++){
		partial_sum[0] += pref[i][0];
		partial_sum[1] += pref[i][1];
		partial_sum[2] += pref[i][2];

		second_sum[1] += partial_sum[1];
		second_sum[2] += partial_sum[2];

		sum[i][0] = partial_sum[0];
		sum[i][1] = second_sum[1];
		sum[i][2] = second_sum[2];
	}

	ll q;
	std::cin >> q;

	for(ll i = 0; i < q; i++){
		ll start, angle;
		std::cin >> start >> angle;
		angle--;

		if(angle == 2){
			start += OFFSET;
		}

		ll res = 0;
		if(start >= 0){
			res = sum[start][angle] * sum[start][angle];
		}

		if(angle != 0){
			res *= 2;
		}

		std::cout << res << '\n';
	}
}
