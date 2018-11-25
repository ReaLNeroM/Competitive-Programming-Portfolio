#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e2 + 10;
int dp[maxn][maxn*maxn];
std::map<int, int> m;
int val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		m[val[i]]++;
	}

	dp[0][0] = 1;

	for(int k = 0; k < n; k++){
		for(int i = n - 1; i >= 0; i--){
			for(int j = 100 * n; j >= 0; j--){
				if(j + val[k] <= 100 * n){
					dp[i + 1][j + val[k]] += dp[i][j];
					if(dp[i + 1][j + val[k]] > 2){
						dp[i + 1][j + val[k]] = 2;
					}
				}
			}
		}
	}

	int res = 0;

	for(auto ite = m.begin(); ite != m.end(); ite++){
		for(int j = 1; j <= ite->second; j++){
			if(dp[j][j * ite->first] == 1){
				res = std::max(res, j);
			}
		}
	}
	if(m.size() == 2){
		res = n;
	}

	std::cout << res << '\n';
}
