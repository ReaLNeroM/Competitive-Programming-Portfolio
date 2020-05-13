#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
const int maxk = 45;
std::vector<int> adj[maxk];

int main(){
	std::ios::sync_with_stdio(false);

	int y, x, k;
	std::cin >> y >> x >> k;

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			std::cin >> col[i][j];
		}
	}

	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			dist[i][j] = y + x + k;
		}
		dist[i][i] = 0;
	}

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			for(int k = 0; k < 4; k++){
				int ni = i + ay[k];
				int nj = j + ax[k];

				if(0 <= ni and ni < y and 0 <= nj and nj < x and col[i][j] != col[ni][nj]){
					adj[currcol].push_back(nextcol);
				}
			}
		}
	}

	for(int i = 0; i < k; i++){

	}

}