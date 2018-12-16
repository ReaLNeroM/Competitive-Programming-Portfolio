<<<<<<< HEAD
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

	for(int i = 0; i < n; i++){
		for(int j = 0; j <= 100 * n; j++){
			for(int k = 0; k < 100; k++){
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
			bool multipleSum = false;
			for(int i = 0; i < n; i++){
				if(val[i] != ite->first){
					if(j * ite->first - val[i] >= 0 and dp[j - 1][j * ite->first - val[i]]){
						multipleSum = true;
					}

				}
			}
			if(!multipleSum){
				res = std::max(res, j);
			}
		}
	}

	std::cout << res << '\n';
}
