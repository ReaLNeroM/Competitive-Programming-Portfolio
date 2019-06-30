#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1005;
const int INF = 1000000000;
int dist[maxn][maxn];
std::vector<std::vector<int>> edg;

int main(){
	std::ios::sync_with_stdio(false);

	int testCases;
	std::cin >> testCases;

	for(int testCase = 1; testCase <= testCases; testCase++){
		int n, m;
		std::cin >> n >> m;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				dist[i][j] = INF;
			}
			dist[i][i] = 0;
		}
		edg.clear();

		for(int i = 0; i < m; i++){
			int x, y, z;
			std::cin >> x >> y >> z;
			x--, y--;
			edg.push_back({x, y, z});
			dist[x][y] = std::min(dist[x][y], z);
			dist[y][x] = std::min(dist[y][x], z);
		}

		for(int k = 0; k < n; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		bool good = true;
		for(int i = 0; i < m; i++){
			if(dist[edg[i][0]][edg[i][1]] != edg[i][2]){
				good = false;
			}
			if(dist[edg[i][1]][edg[i][0]] != edg[i][2]){
				good = false;
			}
		}

		std::cout << "Case #" << testCase << ": ";
		if(good){
			std::cout << m << '\n';
			for(int i = 0; i < m; i++){
				std::cout << edg[i][0] + 1 << ' ' << edg[i][1] + 1 << ' ' << edg[i][2] << '\n';
			}
		} else {
			std::cout << "Impossible\n";
		}
	}
}