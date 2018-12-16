#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
int step[maxn];
int val[maxn];
int dp[maxn][5];
int par[maxn][5];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	memset(dp, 0, sizeof(dp));
	dp[0][0] = true;
	dp[0][1] = true;
	dp[0][2] = true;
	dp[0][3] = true;
	dp[0][4] = true;

	for(int i = 1; i < n; i++){
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				if((val[i - 1] < val[i] and j < k) or (val[i - 1] == val[i] and j != k) or (val[i - 1] > val[i] and j > k)){
					if(dp[i - 1][j]){
						dp[i][k] |= dp[i - 1][j];
						par[i][k] = j;
					}
				}
			}
		}
	}

	int res = -1;
	int resj = -1;

	for(int i = 0; i < 5; i++){
		if(dp[n - 1][i]){
			res = n - 1;
			resj = i;
		}
	}


	if(res == -1){
		std::cout << -1 << '\n';
		return 0;
	}

	do {
		step[res] = resj;
		resj = par[res][resj];
		res--;
	} while(res > 0);
	step[0] = resj;

	
	for(int i = 0; i < n; i++){
		std::cout << step[i] + 1 << ' ';
	}
}