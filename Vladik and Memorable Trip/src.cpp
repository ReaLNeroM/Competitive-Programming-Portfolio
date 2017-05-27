#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 5005;
int val[maxn];
int last[maxn];
int first[maxn];
int dp[maxn];
int used[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::fill(first, first + maxn, maxn);

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		last[val[i]] = i;
		first[val[i]] = std::min(first[val[i]], i);
	}

	dp[n] = 0;
	for(int i = n - 1; i >= 0; i--){
		std::fill(used, used + maxn, false);

		dp[i] = dp[i + 1];
		if(first[val[i]] == i){
			int xxor = 0;
			int end = last[val[i]];

			for(int j = i; j <= end; j++){
				if(!used[val[j]]){
					if(i <= first[val[j]]){
						end = std::max(end, last[val[j]]);
					} else {
						xxor = -1e9;
						break;
					}
					used[val[j]] = true;
					xxor ^= val[j];
				}
			}

			dp[i] = std::max(dp[i], xxor + dp[end + 1]);
		}
	}

	std::cout << dp[0];
}