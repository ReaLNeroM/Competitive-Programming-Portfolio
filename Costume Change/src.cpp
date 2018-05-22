#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 25;
int color[maxn][maxn];
int usedv[maxn][maxn];
int usedh[maxn][maxn];
int n;

int exceed = 0;
int changes = 0;
int res = maxn;

void dfs(int py, int px){
	if(py == n){
		if(exceed == 0){
			res = std::min(res, changes);
		}

		return;
	}
	if(px == n){
		dfs(py + 1, 0);
		return;
	}

	dfs(py, px + 1);

	if(usedv[px][color[py][px]] > 1 or usedh[py][color[py][px]] > 1){
		changes++;
		usedv[px][color[py][px]]--;
		usedh[py][color[py][px]]--;
		if(usedv[px][color[py][px]] == 1){
			exceed--;
		}
		if(usedh[py][color[py][px]] == 1){
			exceed--;
		}

		dfs(py, px + 1);
		
		changes--;
		usedv[px][color[py][px]]++;
		usedh[py][color[py][px]]++;
		if(usedv[px][color[py][px]] == 2){
			exceed++;
		}
		if(usedh[py][color[py][px]] == 2){
			exceed++;
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	ll tests;
	std::cin >> tests;

	for(int test = 1; test <= tests; test++){
		std::cin >> n;

		res = n * n;
		memset(usedv, 0, sizeof(usedv));
		memset(usedh, 0, sizeof(usedh));
		exceed = 0;
		changes = 0;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				std::cin >> color[i][j];
				color[i][j] += n;
				usedv[j][color[i][j]]++;
				usedh[i][color[i][j]]++;
				if(usedv[j][color[i][j]] == 2){
					exceed++;
				}
				if(usedh[i][color[i][j]] == 2){
					exceed++;
				}
			}
		}

		dfs(0, 0);
		std::cout << "Case #" << test << ": " << res << '\n';
	}
}
