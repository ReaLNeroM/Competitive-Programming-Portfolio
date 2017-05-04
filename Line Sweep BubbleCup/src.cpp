#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2005;
int block[maxn][maxn];
int sum[maxn][maxn];
int done[maxn][maxn];
int main(){
	std::ios::sync_with_stdio(false);

	int y, x;
	std::cin >> y >> x;

	int p;
	std::cin >> p;

	for(int i = 0; i < p; i++){
		int py, px;
		std::cin >> py >> px;

		block[py][px] = true;
	}

	for(int i = 1; i <= y; i++){
		for(int j = 1; j <= x; j++){
			sum[i][j] = block[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
		}
	}

	int res = y;
	for(int j = 1; j <= x; j++){
		int run = 0;

		for(int i = 1; i <= y + 1; i++){
			if(j == y + 1 or block[i][j]){
				if(run != 0){
					res = std::min(res, run);
				}
				run = 0;
			} else {
				run++;
			}
		}
	}

	int sweeps = 0;
	for(int i = 1; i <= y; i++){
		int start = false;

		for(int j = 1; j <= x; j++){
			if(!done[i][j] and sum[i + res - 1][j] - sum[i - 1][j] - sum[i][j - 1] + sum[i - 1][j - 1] == 0){
				if(!start){
					std::cout << i << ' ' << j << std::endl;
					sweeps++;
					start = true;
				}
			} else if(start and sum[i + res - 1][j] - sum[i - 1][j] - sum[i][j - 1] + sum[i - 1][j - 1] != 0){
				start = false;
			}
			if(start){
				for(int k = i; k < i + res; k++){
					done[k][j] = true;
				}
			}
		}
	}

	for(int i = y; i >= 1; i--){
		int start = false;

		for(int j = 1; j <= x; j++){
			if(!done[i][j] and sum[i][j] - sum[i - res][j] - sum[i][j - 1] + sum[i - res][j - 1] == 0){
				if(!start){
					sweeps++;
					start = true;
				}
			} else if(start and sum[i][j] - sum[i - res][j] - sum[i][j - 1] + sum[i - res][j - 1] != 0){
				start = false;
			}
			if(start){
				for(int k = i; k > i - res; k--){
					done[k][j] = true;
				}
			}
		}
	}

	std::cout << res << '\n' << sweeps << std::endl;
}