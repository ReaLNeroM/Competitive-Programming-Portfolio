#include <iostream>

typedef long long ll;

const int maxn = 255;
int val[maxn][maxn];
int vertical[maxn];
int horizontal[maxn];
int sum[maxn][maxn];
int dp[maxn][maxn];
int rose[maxn][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int y, x;
	std::cin >> y >> x;

	for(int i = 0; i <= y; i++){
		for(int j = 0; j <= x; j++){
			horizontal[i] = 1e9;
			vertical[j] = 1e9;
			val[i][j] = 1e9;
		}
	}

	int roses, needed;
	std::cin >> roses >> needed;

	for(int i = 0; i < roses; i++){
		int py, px;
		std::cin >> py >> px;

		rose[py][px]++;
	}

	for(int i = 0; i <= y; i++){
		for(int j = 0; j <= x; j++){
			sum[i][j] = rose[i][j];
			if(i > 0){
				sum[i][j] += sum[i - 1][j];
			}
			if(j > 0){
				sum[i][j] += sum[i][j - 1];
			}
			if(i > 0 and j > 0){
				sum[i][j] -= sum[i - 1][j - 1];
			}
		}
	}

	for(int i = 1; i <= y; i++){
		for(int j = 1; j <= x; j++){
			int accumulated = rose[i][j];

			int height = i;
			while(1 < height and accumulated < needed){
				height--;
				accumulated += rose[height][j];
			}

			for(int k = j; k > 0; k--){
				accumulated = sum[i][j] - sum[height - 1][j] - sum[i][k - 1] + sum[height - 1][k - 1];
				while(height < i and accumulated - (sum[height][j] - sum[height][k - 1] - sum[height - 1][j] + sum[height - 1][k - 1]) >= needed){
					accumulated -= (sum[height][j] - sum[height][k - 1] - sum[height - 1][j] + sum[height - 1][k - 1]);
					height++;
				}
				if(accumulated >= needed){
					val[i][j] = std::min(val[i][j], 2 * (j - k + 1) + 2 * (i - height + 1));
				}
			}
			horizontal[i] = std::min(horizontal[i], val[i][j]);
			vertical[j] = std::min(vertical[j], val[i][j]);
		}
	}

	for(int i = 1; i <= y; i++){
		horizontal[i] = std::min(horizontal[i], horizontal[i - 1]);
	}
	for(int j = 1; j <= x; j++){
		vertical[j] = std::min(vertical[j], vertical[j - 1]);
	}

	int res = 1e9;
	for(int i = 1; i <= y; i++){
		for(int j = 1; j <= x; j++){
			int accumulated = rose[i][j];

			int height = i;
			while(1 < height and accumulated < needed){
				height--;
				accumulated += rose[height][j];
			}

			for(int k = j; k > 0; k--){
				accumulated = sum[i][j] - sum[height - 1][j] - sum[i][k - 1] + sum[height - 1][k - 1];
				while(height < i and accumulated - (sum[height][j] - sum[height][k - 1] - sum[height - 1][j] + sum[height - 1][k - 1]) >= needed){
					accumulated -= (sum[height][j] - sum[height][k - 1] - sum[height - 1][j] + sum[height - 1][k - 1]);
					height++;
				}
				if(accumulated >= needed){
					res = std::min(res, 2 * (j - k + 1) + 2 * (i - height + 1) + std::min(horizontal[height - 1], vertical[k - 1]));
				}
			}
		}
	}
	if(res == 1e9){
		std::cout << "NO" << std::endl;
		return 0;
	}
	std::cout << res << std::endl;
}
