#include <iostream>

using namespace std;
typedef long long ll;

static ll dp[101][101];
ll n, m, k;

ll find(ll left, ll pos){
	if(dp[left][pos] == -1){
		if(pos == m and left == 0){
			dp[left][pos] = 1;
		} else if(pos == m){
			dp[left][pos] = 0;
		} else if(left == 0){
			dp[left][pos] = 0;
		} else {
			dp[left][pos] = 0;
			for(ll i = 1; i <= k and i <= left; i++){
				dp[left][pos] += find(left - i, pos + 1);
			}
		}
	}

	return dp[left][pos];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;

	for(ll i = 0; i <= n; i++){
		for(ll j = 0; j <= m; j++){
			dp[i][j] = -1;
		}
	}

	cout << find(n, 0);
	return 0;
}
