#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e2 + 1e2;

const int ay[] = {1, -1, 0, 0};
const int ax[] = {0, 0, 1, -1};

char mat[maxn][maxn];
int dist[maxn][maxn];
bool block[maxn][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int y, x;
	std::cin >> y >> x;

	int rob_i = 0, rob_j = 0;
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			std::cin >> mat[i][j];
			dist[i][j] = 1e9;
			block[i][j] = false;
			if(mat[i][j] == 'S'){
				rob_i = i, rob_j = j;
			}
		}
	}

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if(mat[i][j] == 'C'){
				for(int k = j; k < x; k++){
					if(mat[i][k] == '.' or mat[i][k] == 'C' or mat[i][k] == 'S'){
						block[i][k] = true;
					} else if(mat[i][k] == 'W'){
						break;
					}
				}
				for(int k = i; k < y; k++){
					if(mat[k][j] == '.' or mat[k][j] == 'C' or mat[k][j] == 'S'){
						block[k][j] = true;
					} else if(mat[k][j] == 'W'){
						break;
					}
				}
				for(int k = j; k >= 0; k--){
					if(mat[i][k] == '.' or mat[i][k] == 'C' or mat[i][k] == 'S'){
						block[i][k] = true;
					} else if(mat[i][k] == 'W'){
						break;
					}
				}
				for(int k = i; k >= 0; k--){
					if(mat[k][j] == '.' or mat[k][j] == 'C' or mat[k][j] == 'S'){
						block[k][j] = true;
					} else if(mat[k][j] == 'W'){
						break;
					}
				}
			}
		}
	}

	std::priority_queue<std::vector<int>> pq;

	pq.push({-0, rob_i, rob_j});

	while(!pq.empty()){
		int frdist = -pq.top()[0];
		int fri = pq.top()[1];
		int frj = pq.top()[2];

		pq.pop();

		if(!block[fri][frj]){
			block[fri][frj] = true;
		} else {
			continue;
		}

		if(mat[fri][frj] == '.' or mat[fri][frj] == 'S'){
			for(int k = 0; k < 4; k++){
				int ni = fri + ay[k];
				int nj = frj + ax[k];

				if(0 <= ni and ni < y and 0 <= nj and nj < x and (mat[ni][nj] == '.' or mat[ni][nj] == 'U' or mat[ni][nj] == 'D' or mat[ni][nj] == 'L' or mat[ni][nj] == 'R')){
					if(!block[ni][nj]){
						if(mat[ni][nj] == '.' and dist[ni][nj] > frdist + 1){
							dist[ni][nj] = frdist + 1;
							pq.push({-dist[ni][nj], ni, nj});
						} else if(mat[ni][nj] != '.' and dist[ni][nj] > frdist){
							dist[ni][nj] = frdist;
							pq.push({-dist[ni][nj], ni, nj});
						}
					}
				}
			}
		} else {
			int ni, nj;
			if(mat[fri][frj] == 'U'){
				ni = fri - 1;
				nj = frj;
			} else if(mat[fri][frj] == 'D'){
				ni = fri + 1;
				nj = frj;
			} else if(mat[fri][frj] == 'L'){
				ni = fri;
				nj = frj - 1;
			} else if(mat[fri][frj] == 'R'){
				ni = fri;
				nj = frj + 1;
			} else {
				continue;
			}

			if(0 <= ni and ni < y and 0 <= nj and nj < x and (mat[ni][nj] == '.' or mat[ni][nj] == 'U' or mat[ni][nj] == 'D' or mat[ni][nj] == 'L' or mat[ni][nj] == 'R')){
				if(!block[ni][nj]){
					if(mat[ni][nj] == '.' and dist[ni][nj] > frdist + 1){
						dist[ni][nj] = frdist + 1;
						pq.push({-dist[ni][nj], ni, nj});
					} else if(mat[ni][nj] != '.' and dist[ni][nj] > frdist){
						dist[ni][nj] = frdist;
						pq.push({-dist[ni][nj], ni, nj});
					}
				}
			}
		}
	}

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if(mat[i][j] == '.'){
				if(dist[i][j] == 1e9){
					std::cout << -1 << '\n';
				} else {
					std::cout << dist[i][j] << '\n';
				}
			}
		}
	}
}