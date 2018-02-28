#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 20;
static char dp[maxn][(1 << 20)][2];
int val[maxn][maxn];
int bit[maxn][maxn];
ll currpow = 1;
ll need = 0;
int y, x;

char dfs(int py, int px, int bitset, bool paren = true){
	int ind = py * x + px;
	if(dp[ind][bitset][paren] == 2){
		dp[ind][bitset][paren] = 0;

		if(bitset == need){
			dp[ind][bitset][paren] = 1;
		} else {
			if(paren){
				for(int i = 0; i < x and dp[ind][bitset][paren] == 0; i++){
					if(!(bitset & bit[py][i]) and val[py][i]){
						dp[ind][bitset][paren] |= dfs(py, i, bitset | bit[py][i], !paren);
					}
				}
			} else if(!paren){
				for(int i = 0; i < y and dp[ind][bitset][paren] == 0; i++){
					if(!(bitset & bit[i][px]) and val[i][px]){
						dp[ind][bitset][paren] |= dfs(i, px, bitset | bit[i][px], !paren);
					}
				}
			}
		}
	}

	return dp[ind][bitset][paren];
}

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> y >> x;

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			std::cin >> val[i][j];
			bit[i][j] = currpow;
			currpow *= 2;
			if(val[i][j]){
				need += bit[i][j];
			}
		}
	}

	for(int i = 0; i < y * x; i++){
		for(int j = 0; j < currpow; j++){
			dp[i][j][0] = dp[i][j][1] = 2;
		}
	}
	
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if(val[i][j] and dfs(i, j, bit[i][j], true)){
				std::cout << "DA\n";
				return 0;
			}
		}
	}

	std::cout << "NE\n";
}