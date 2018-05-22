#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

class DrippingWater {
	static const int maxn = 55;
	static const int INF = 10001;
	const int source = 0;
	const int sink = 1;
	std::vector<int> ay;
	std::vector<int> ax;

	int n, y, x;

	std::vector<std::vector<int> > adj;
	int id[maxn][maxn][2];
	int total_ids = 0;

	std::vector<bool> visited;
	std::vector<int> par;

	int flow(){
		int res = 0;

		visited.resize(adj.size());
		par.resize(adj.size());

		bool gathered = true;
		do {
			gathered = false;

			std::fill(visited.begin(), visited.end(), false);
			std::fill(par.begin(), par.end(), -1);

			std::queue<int> q;

			q.push(source);
			visited[source] = true;
			par[source] = -2;

			while(!q.empty() and !visited[sink]){
				int fr = q.front();
				q.pop();

				for(int i = 0; i < total_ids; i++){
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
		if(id[a][b][c] == -1){
			id[a][b][0] = total_ids;
			id[a][b][1] = total_ids + 1;
			total_ids += 2;
		}

		return id[a][b][c];
	}
public:
	int fixCeiling(std::vector<std::string> ceilMap){
		ay = ax = std::vector<int>(4);
		ay[0] = ax[2] = 1;
		ay[1] = ax[3] = -1;
		y = ceilMap.size();
		x = ceilMap[0].size();
		n = y * x;

		memset(id, -1, sizeof(id));
		total_ids += 2; //for source and sink

		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				ind(i, j, 0);
				ind(i, j, 1);
			}
		}

		adj.resize(total_ids, std::vector<int>(total_ids, 0));

		for(int j = 0; j < x; j++){
			if(ceilMap[0][j] == 'x'){
				adj[source][ind(0, j, 0)] += INF;
			}
			if(ceilMap[y - 1][j] == 'x'){
				adj[ind(y - 1, j, 1)][sink] += INF;
			}
		}

		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				if(ceilMap[i][j] == 'x'){
					adj[ind(i, j, 0)][ind(i, j, 1)]++;
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