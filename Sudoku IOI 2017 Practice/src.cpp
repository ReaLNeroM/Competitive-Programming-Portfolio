#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1005;
int mat[maxn][maxn];
int v[maxn][maxn];
int h[maxn][maxn];
int curry[maxn * maxn];
int currx[maxn * maxn];
int r[maxn][maxn];
int holes = 0;
int n;
int most = 0;

void dfs(int made){
	std::cout << made << std::endl;
	if(made == holes){
		for(int i = 0; i < n * n; i++){
			for(int j = 0; j < n * n; j++){
				std::cout << mat[i][j] << ' ';
			}
			std::cout << std::endl;
		}
		return;
	}

	for(int i = 1; i <= n * n; i++){
		int y = curry[made];
		int x = currx[made];

		if(!v[y][i] and !h[x][i] and !r[(y / n) * n + x / n][i]){
			v[y][i] = true;
			h[x][i] = true;
			r[(y / n) * n + x / n][i] = true;
			mat[y][x] = i;
			dfs(made + 1);
			v[y][i] = false;
			h[x][i] = false;
			r[(y / n) * n + x / n][i] = false;
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(int i = 0; i < n * n; i++){
		for(int j = 0; j < n * n; j++){
			std::cin >> mat[i][j];

			if(mat[i][j] != 0){
				v[i][mat[i][j]] = true;
				h[j][mat[i][j]] = true;
				r[(i / n) * n + j / n][mat[i][j]] = true;
			} else {
				curry[holes] = i;
				currx[holes] = j;
				holes++;
			}
		}
	}

	dfs(0);
}
