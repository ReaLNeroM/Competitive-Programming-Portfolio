#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2e3;
int ay[] = {1, -1, 0, 0};
int ax[] = {0, 0, 1, -1};
bool used[maxn][maxn];

int dfs(int y, int x, int steps_left){
	used[y][x] = true;
	if(steps_left == 0){
		used[y][x] = false;
		return 1;
	}

	int res = 0;

	for(int i = 0; i < 4; i++){
		int ny = y + ay[i];
		int nx = x + ax[i];

		if(!used[ny][nx]){
			res += dfs(ny, nx, steps_left - 1);
		}
	}

	used[y][x] = false;
	return res;
}

int main(){
	int n;
	std::cin >> n;

	std::cout << dfs(maxn / 2, maxn / 2, n);
}