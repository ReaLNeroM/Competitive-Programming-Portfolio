#include <bits/stdc++.h>

typedef long long ll;

const int max_a = 3005;
const int max_b = 105;

int n_a, n_b;
int best[max_b][max_b];
int dp[max_a][max_b][2];
int a[max_a];
int b[max_b];

int dfs(int apos, int bpos, bool block){
	if(dp[apos][bpos][block] == -1){
		int& res = dp[apos][bpos][block];

		if(apos == n_a){
			res = 0;
		} else {
			res = dfs(apos + 1, bpos, 0);
			for(int k = 1; bpos + k < n_b; k++){
				res = std::max(res, dfs(apos + 1, bpos + k, 1) + best[bpos][bpos + k - 1]);
				if(bpos <= bpos + k - 2){
					res = std::max(res, dfs(apos + 1, bpos + k, 0) + best[bpos][bpos + k - 2]);
				}
			}

			if(!block){
				res = dfs(apos + 1, bpos, 1) + a[apos];
				for(int k = 1; bpos + k < n_b; k++){
					if(bpos + 1 <= bpos + k - 1){
						res = std::max(res, dfs(apos + 1, bpos + k, 1) + best[bpos + 1][bpos + k - 1] + a[apos]);
					}
					if(bpos + 1 <= bpos + k - 2){
						res = std::max(res, dfs(apos + 1, bpos + k, 0) + best[bpos + 1][bpos + k - 2] + a[apos]);
					}
				}
			}
		}
	}

	return dp[apos][bpos][block];
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n_a;

	a[0] = 0;
	for(int i = 1; i <= n_a; i++){
		std::cin >> a[i];
	}
	n_a++;

	std::cin >> n_b;

	for(int i = 0; i < n_b; i++){
		std::cin >> b[i];
	}

	for(int i = 0; i < n_b; i++){
		for(int j = i; j < n_b; j++){
			if(j == i){
				best[i][j] = b[i];
			} else if(j == i + 1){
				best[i][j] = std::max(b[i], b[j]);
			} else {
				best[i][j] = std::max(b[j] + best[i][j - 2], best[i][j - 1]);
			}
		}
	}

	std::cout << dfs(0, 0, 1) << '\n';
}