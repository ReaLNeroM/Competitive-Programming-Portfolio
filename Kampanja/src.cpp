#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e4 + 1e2;
const int maxc = 1e2 + 1e2;

int dp[maxn][maxc];
std::vector<int> v[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n, c;
	std::cin >> n >> c;

	for(int i = 0; i < c; i++){
		v[i].resize(4);
		std::cin >> v[i][2] >> v[i][3];
		v[i][0] = -v[i][2];
		v[i][1] = -v[i][3];
	}

	std::sort(v, v + c);

	for(int j = c - 1; j >= 0; j--){
		for(int i = 0; i <= n; i++){
			dp[i][j] = dp[i][j + 1];

			if(i >= v[j][2]){
				dp[i][j] = std::max(dp[i][j], dp[i + v[j][3] - v[j][2]][j + 1] + 1);
			}
		}
	}

	std::cout << dp[n][0] << '\n';
}