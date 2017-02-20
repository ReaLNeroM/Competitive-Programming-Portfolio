#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int val[maxn];
int dp[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> val[i];
		dp[i] = 1e9;
	}

	for(int i = 0; i < n; i++){
		if(i == 0){
			dp[i] = 20;
		} else {
			dp[i] = dp[i - 1] + 20;

			int l = 0, r = i - 1;

			int best = i;
			while(l <= r){
				int mid = (l + r) / 2;

				if(val[mid] + 90 > val[i]){
					r = mid - 1;
					best = mid;
				} else {
					l = mid + 1;
				}
			}

			if(best == 0){
				dp[i] = min(dp[i], 50);
			} else {
				dp[i] = min(dp[i], dp[best - 1] + 50);
			}

			l = 0, r = i - 1;

			best = i;
			while(l <= r){
				int mid = (l + r) / 2;

				if(val[mid] + 1440 > val[i]){
					r = mid - 1;
					best = mid;
				} else {
					l = mid + 1;
				}
			}

			if(best == 0){
				dp[i] = min(dp[i], 120);
			} else {
				dp[i] = min(dp[i], dp[best - 1] + 120);
			}
		}

		if(i == 0){
			cout << dp[i] << '\n';
		} else {
			cout << dp[i] - dp[i - 1] << '\n';
		}
	}
}

