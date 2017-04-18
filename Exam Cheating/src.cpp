#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 10;
short dp[maxn][maxn][51][2];
int val[2][maxn];
int pref[4][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n, looks, jump;
	std::cin >> n >> looks >> jump;

	for(int i = 0; i < 2; i++){
		int size;
		std::cin >> size;

		for(int j = 0; j < size; j++){
			int ind;
			std::cin >> ind;
			val[i][ind] = true;
		}
	}

	for(int x = 0; x < 4; x++){
		pref[x][0] = 0;
		for(int i = 1; i < maxn; i++){
			pref[x][i] = pref[x][i - 1];

			if((x == 1 or x == 3) and val[0][i]){
				pref[x][i]++;
			} else if((x == 2 or x == 3) and val[1][i]){
				pref[x][i]++;
			}
		}
	}

	for(int i = 0; i < maxn; i++){
		for(int j = 0; j <= looks; j++){
			for(int k = jump - 1; k >= 0; k--){
				for(int l = 0; l < 2; l++){
					dp[i][j][k][l] = 0;
				}
			}
		}
	}

	for(int i = 1; i < maxn; i++){
		for(int j = 0; j <= looks; j++){
			for(int k = jump; k >= 0; k--){
				for(int l = 0; l < 2; l++){
					if(k == 0){
						dp[i][j][k][l] = dp[i - 1][j][k][l];

						if(j > 0){
							dp[i][j][k][l] = std::max((int) dp[i][j][k][l], std::max((int) dp[i][j - 1][jump][0], (int) dp[i][j - 1][jump][1]));
						}
					} else {
						dp[i][j][k][l] = dp[i - 1][j][k - 1][l] + val[l][i];

						if(j > 0){
							int a = std::max(0, i - k);
							int b = i;
							dp[i][j][k][l] = std::max((int) dp[i][j][k][l], (int) dp[a][j - 1][jump - k][!l] + pref[3][b] - pref[3][a]);
						}
					}
				}
			}
		}
	}

	std::cout << dp[maxn - 1][looks][0][0] << std::endl;
}