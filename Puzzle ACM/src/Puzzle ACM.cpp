#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6;

const int ay[] = {1, 0, -1, 0};
const int ax[] = {0, 1, 0, -1};
const int op[] = {2, 3, 0, 1};

vector<int> adj[maxn];
int dfs_num[maxn];
int dfs_low[maxn];
int state[maxn];
int sweep[maxn];

int curr = 0;
int adder = 250000;
int neg = 500000;
bool good = true;

stack<int> s;

void dfs(int pos){
	state[pos] = 1;

	dfs_num[pos] = curr;
	dfs_low[pos] = curr;
 	curr++;

	s.push(pos);
	for(int i = 0; i < adj[pos].size(); i++){
		int nnext = adj[pos][i];

		if(state[nnext] == 0){
			dfs(nnext);
			dfs_low[pos] = min(dfs_low[pos], dfs_low[nnext]);
		} else if(state[nnext] == 1){
			dfs_low[pos] = min(dfs_low[pos], dfs_low[nnext]);
		}
	}

	if(dfs_low[pos] == dfs_num[pos]){
		while(!s.empty()){
			int fr = s.top();
			s.pop();

			if(fr < neg){
				if(sweep[neg + fr] == dfs_num[pos]){
					good = false;
				}
			} else {
				sweep[fr] = dfs_num[pos];
			}
			if(fr == pos){
				break;
			}
		}
	}

	state[pos] = 2;
}

void add(int pos, int dir, int pos2, int dir2){
	int id1 = pos + 250000 * dir;
	int id2 = pos2 + 250000 * dir2;

	adj[id1].push_back((id2 + neg) % maxn);
	adj[id2].push_back((id1 + neg) % maxn);
}

int main() {
	ios::sync_with_stdio(false);
	int cases;
	cin >> cases;

	for(int test = 0; test < cases; test++){
		int y, x;
		cin >> y >> x;
		char m[y][x];
		int id[y][x];

		int r = 0, w = 0;
		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				cin >> m[i][j];
				if(m[i][j] == 'W'){
					w++;
				} else if(m[i][j] == 'R'){
					id[i][j] = r;
					r++;
				}
			}
		}	

		if(r * 2 != w){
			cout << "NO\n";
			continue;
		}

		good = true;
		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				if(m[i][j] == 'W'){
					good = false;
					for(int k = 0; k < 4; k++){
						int ni = i + ay[k];
						int nj = j + ax[k];

						if(0 <= ni and ni < y and 0 <= nj and nj < x and m[ni][nj] == 'R'){
							good = true;
							break;
						}
					}
					if(!good){
						i = y, j = x;
						break;
					}
				}
			}
		}
		curr = 0;
		for(int i = 0; i < maxn; i++){
			adj[i].clear();
			dfs_num[i] = 0;
			dfs_low[i] = 0;
			state[i] = 0;
			sweep[i] = -1;
		}

		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				if(m[i][j] == 'W'){
					for(int k = 0; k < 4; k++){
						for(int l = k + 1; l < 4; l++){
							if(0 <= i + ay[k] and i + ay[k] < y and 0 <= j + ax[k] and j + ax[k] < x and m[i + ay[k]][j + ax[k]] == 'R'){
								if(0 <= i + ay[l] and i + ay[l] < y and 0 <= j + ax[l] and j + ax[l] < x and m[i + ay[l]][j + ax[l]] == 'R'){
									add(id[i + ay[k]][j + ax[k]], op[k], id[i + ay[l]][j + ax[l]], op[l]);
								}
							}
						}
					}
				}
			}
		}


		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				if(m[i][j] == 'R'){
					if(i == 0 or m[i - 1][j] != 'W'){
						adj[id[i][j] + neg].push_back(id[i][j]);
					}
					if(i == y - 1 or m[i + 1][j] != 'W'){
						adj[id[i][j]].push_back(id[i][j] + neg);
					}
					if(j == 0 or m[i][j - 1] != 'W'){
						adj[id[i][j] + adder + neg].push_back(id[i][j] + adder);
					}
					if(j == x - 1 or m[i][j + 1] != 'W'){
						adj[id[i][j] + adder].push_back(id[i][j] + adder + neg);
					}
				}
			}
		}

		for(int i = 0; i < maxn; i++){
			if(state[i] == 0){
				dfs(i);
			}
		}

		if(good){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
