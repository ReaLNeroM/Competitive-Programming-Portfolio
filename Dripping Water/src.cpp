#include <string>
#include <vector>
#include <queue>
#include <algorithm>

int const ay[] = {1, -1, 0, 0};
int const ax[] = {0, 0, 1, -1};
static const int maxn = 5005;
static int adj[maxn][maxn];

class DrippingWater {
	static const int INF = 10001;
	int source = 5001;
	int sink = 5002;
	bool visited[maxn];
	int par[maxn];
	int n, y, x;

	int flow(){
		int res = 0;

		bool gathered = true;
		do {
			gathered = false;

			std::fill(visited, visited + maxn, false);
			std::fill(par, par + maxn, -1);

			std::queue<int> q;

			q.push(source);
			visited[source] = true;
			par[source] = -2;

			while(!q.empty() and !visited[sink]){
				int fr = q.front();
				q.pop();

				for(int i = 0; i < maxn; i++){
					if(adj[fr][i] and !visited[i]){
						q.push(i);
						visited[i] = true;
						par[i] = fr;
					}
				}
			}

			if(!visited[sink]){
				break;
			}

			int pos = sink;

			int flow_found = INF;
			while(pos != source and par[pos] != -1){
				flow_found = std::min(flow_found, adj[par[pos]][pos]);
				pos = par[pos];
			}

			res += flow_found;
			gathered = true;

			pos = sink;

			while(pos != source){
				adj[par[pos]][pos] -= flow_found;
				adj[pos][par[pos]] += flow_found;
				pos = par[pos];
			}
		} while(gathered);

		return res;
	}

	int ind(int a, int b, int c){
		return 2 * (a * x + b) + c;
	}

public:
	int fixCeiling(std::vector<std::string> ceilMap){
		y = ceilMap.size();
		x = ceilMap[0].size();

		std::fill(&adj[0][0], &adj[0][0] + maxn * maxn, 0);
		n = y * x;

		for(int j = 0; j < x; j++){
			if(ceilMap[0][j] == 'x'){
				adj[source][ind(0, j, 0)]++;
			}
			if(ceilMap[y - 1][j] == 'x'){
				adj[ind(y - 1, j, 1)][sink]++;
			}
		}

		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				if(ceilMap[i][j] == 'x'){
					adj[ind(i, j, 0)][ind(i, j, 1)] += 1;
				}
			}
		}

		for(int i = 0; i < y - 1; i++){
			for(int j = 0; j < x; j++){
				for(int k = 0; k < 4; k++){
					int ni = i + ay[k];
					int nj = j + ax[k];

					if(0 <= ni and ni < y and 0 <= nj and nj < x and ceilMap[ni][nj] == 'x'){
						adj[ind(i, j, 1)][ind(ni, nj, 0)] += INF;
					}
				}
			}
		}

		return flow();
	}
};
