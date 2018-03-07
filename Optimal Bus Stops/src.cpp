#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
const ll maxk = 105;
const double INF = 2e20;
ll n, k;
static double val[maxn];
static double dp[maxn][2];
static double pref[maxn];
static double sq[maxn];

double query(ll a, ll b){
	double ind = (pref[b + 1] - pref[a]) / (double) (b - a + 1LL); // Mean of Interval
	return (sq[b + 1] - sq[a]) - 2.0 * (pref[b + 1] - pref[a]) * ind + (double) (b - a + 1LL) * ind * ind;
}

void build(ll l, ll r, ll left_k, ll opt_l, ll opt_r){
	ll mid = (l + r) / 2;

	double& ans = dp[mid][1];
	ans = INF;

	ll best_ind = opt_r;

	if(left_k == 0){
		ans = INF;
	} else {
		for(ll i = std::max(opt_l, mid); i <= opt_r; i++){
			double attempt = query(mid, i) + dp[i + 1][0];
			
			if(ans > attempt){
				ans = attempt;
				best_ind = i;
			}
		}
	}

	if(l != mid){
		build(l, mid - 1, left_k, opt_l, best_ind);
	}
	if(mid != r){
		build(mid + 1, r, left_k, best_ind, opt_r);
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> k;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}
	std::sort(val, val + n);

	for(ll i = 1; i <= n; i++){
		pref[i] = pref[i - 1] + val[i - 1];
		sq[i] = sq[i - 1] + val[i - 1] * val[i - 1];
	}

	for(ll i = 0; i <= k; i++){
		build(0, n - 1, i, 0, n - 1);

		dp[n][1] = 0.0;
		for(ll j = 0; j <= n; j++){
			dp[j][0] = dp[j][1];
		}
	}

	std::cout.precision(9);
	std::cout << std::fixed << dp[0][0] << '\n';
}
