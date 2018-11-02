#include <bits/stdc++.h>

typedef long long ll;

const int ay[] = {1, -1, 0, 0};
const int ax[] = {0, 0, 1, -1};
const int maxn = 2e3 + 1e2;

std::string m[maxn];
int dist[maxn][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int y, x;
	std::cin >> y >> x;

	int sy, sx;
	std::cin >> sy >> sx;
	sy--, sx--;

	int l, r;
	std::cin >> l >> r;

	for(int i = 0; i < y; i++){
		std::cin >> m[i];
	}

	memset(dist, -1, sizeof(dist));

	std::queue<int> qy[2], qx[2];
	int old = 0, nnew = 1;

	qy[old].push(sy);
	qx[old].push(sx);
	dist[sy][sx] = 0;

	for(int currIte = 0; currIte <= y * x; currIte++){
		while(!qy[old].empty()){
			int fry = qy[old].front();
			int frx = qx[old].front();
			qy[old].pop();
			qx[old].pop();

			for(int k = 0; k < 4; k++){
				int ny = fry + ay[k];
				int nx = frx + ax[k];

				if(0 <= ny and ny < y and 0 <= nx and nx < x and m[ny][nx] == '.'){
					if(k < 3 and (dist[ny][nx] == -1 or dist[ny][nx] > dist[fry][frx])){
						dist[ny][nx] = dist[fry][frx];
						qy[old].push(ny);
						qx[old].push(nx);
					} else if(dist[ny][nx] == -1 or dist[ny][nx] > dist[fry][frx] + 1){
						dist[ny][nx] = dist[fry][frx] + 1;
						qy[nnew].push(ny);
						qx[nnew].push(nx);
					}
				}
			}
		}

		old ^= 1;
		nnew ^= 1;
	}

	int res = 0;
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if(m[i][j] == '.' and dist[i][j] != -1 and dist[i][j] <= l and dist[i][j] + j - sx <= r){
				res++;
			}
		}
	}

	std::cout << res << '\n';
}
