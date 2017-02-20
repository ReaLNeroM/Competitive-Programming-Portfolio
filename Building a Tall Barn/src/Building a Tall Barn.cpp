#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
ll n, k;
ll val[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("tallbarn.in", "r", stdin);
    freopen("tallbarn.out", "w", stdout);

	cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> val[i];
	}
	sort(val, val + n);

	long double l = 0.0L, r = val[n - 1];
	long double best = 1e20;

	for(int i = 0; i < 200; i++){
		ll left = k;
		long double mid = (l + r) / 2.0L;
		long double attempt = 0;

		for(int j = 0; j < n; j++){
			long double dis = (sqrt((4.0L * val[j]) / mid + 1.0L) - 1.0) / 2;
			attempt += (long double) val[j] / ceil(dis);
			left -= ceil(dis);
		}

		if(left >= 0){
			r = mid;
			attempt += left * mid;
			best = min(best, attempt);
		} else {
			l = mid;
		}
	}

	long long res = round(best);
	cout << res;
}

