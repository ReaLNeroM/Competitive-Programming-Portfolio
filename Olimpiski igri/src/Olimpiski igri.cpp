#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int val[maxn];
int dp[maxn][3];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> val[i];
	}

	for(int j = 0; j < 3; j++){
		dp[0][j] = 0;
	}

	for(int i = 1; i <= n; i++){
		dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);

		if(val[i] % 2 == 1){
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
		} else {
			dp[i][1] = 0;
		}

		if(val[i] / 2 == 1){
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
		} else {
			dp[i][2] = 0;
		}
	}

	cout << max(max(dp[n][0], dp[n][1]), dp[n][2]);
}

