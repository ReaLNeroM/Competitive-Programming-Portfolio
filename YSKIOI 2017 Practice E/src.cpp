#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 55;
char mat[maxn][maxn];
bool used[maxn][maxn];
int y, x;
int res = 0;
const int ay[] = {1, -1, 0, 0};
const int ax[] = {0, 0, 1, -1};

void dfs(int posy, int posx){
	if(posy == 0 or posy == y - 1 or posx == 0 or posx == x - 1){
		res++;
		return;
	}

	for(int i = 0; i < 4; i++){
		int ny = posy + ay[i];
		int nx = posx + ax[i];

		if(mat[ny][nx] != 'x' and !used[ny][nx]){
			used[ny][nx] = true;
			dfs(ny, nx);
			used[ny][nx] = false;
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	int t;
	std::cin >> t;

	for(int test = 0; test < t; test++){
		std::cin >> y >> x;

		int sy, sx;

		std::string s;
		std::getline(std::cin, s);

		for(int i = 0; i < y; i++){
			std::string s;
			std::getline(std::cin, s);
			for(int j = 0; j < x; j++){
				mat[i][j] = s[j];
				if(mat[i][j] == 'S'){
					sy = i, sx = j;
				}
			}
		}

		std::fill(&used[0][0], &used[0][0] + sizeof(used), false);
		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				std::cout << mat[i][j];
			}
			std::cout << std::endl;
		}
		res = 0;

		used[sy][sx] = true;
		dfs(sy, sx);

		std::cout << res << std::endl;
	}
}