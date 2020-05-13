#include <bits/stdc++.h>

typedef long long ll;

const int ay[] = {1, -1, 0, 0};
const int ax[] = {0, 0, 1, -1};

const int maxn = 1e3 + 1e2;
char val[maxn][maxn];
static bool visited[maxn][maxn];

int main(){
	std::ios::sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			std::cin >> val[i][j];
		}
	}

	bool empty = true;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(val[i][j] != '.'){
				empty = false;
			}
		}
	}

	if(empty){
		std::cout << 0 << std::endl;
		return 0;
	}

	bool good = true;

	for(int i = 0; i < n; i++){
		int stage = 0;
		int stage2 = 0;
		for(int j = 0; j < m; j++){
			if(val[i][j] == '#'){
				stage2 = -1;
			}
			if(stage == 0 and val[i][j] == '#'){
				stage = 1;
			} else if(stage == 1 and val[i][j] == '.'){
				stage = 2;
			} else if(stage == 2 and val[i][j] == '#'){
				stage = 3;
			}
		}

		if(stage == 3 or stage2 == 0){
			good = false;
			break;
		}
	}

	for(int j = 0; j < n; j++){
		int stage = 0;
		int stage2 = 0;
		for(int i = 0; i < m; i++){
			if(val[i][j] == '#'){
				stage2 = -1;
			}
			if(stage == 0 and val[i][j] == '#'){
				stage = 1;
			} else if(stage == 1 and val[i][j] == '.'){
				stage = 2;
			} else if(stage == 2 and val[i][j] == '#'){
				stage = 3;
			}
		}

		if(stage == 3 or stage2 == 0){
			good = false;
			break;
		}
	}

	if(!good){
		std::cout << -1 << std::endl;
		return 0;
	}

	int comps = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!visited[i][j] and val[i][j] == '#'){
				comps++;
				std::queue<int> qy, qx;
				qy.push(i);
				qx.push(j);

				while(!qy.empty()){
					int fry = qy.front(), frx = qx.front();
					qy.pop(), qx.pop();

					visited[fry][frx] = true;

					for(int k = 0; k < 4; k++){
						int ny = fry + ay[k];
						int nx = frx + ax[k];

						if(0 <= ny and ny < n and 0 <= nx and nx < m and !visited[ny][nx] and val[ny][nx] == '#'){
							visited[ny][nx] = true;
							qy.push(ny);
							qx.push(nx);
						}
					}
				}
			}
		}
	}

	std::cout << comps << std::endl;
}