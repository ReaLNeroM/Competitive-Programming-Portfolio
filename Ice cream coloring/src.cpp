#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
std::vector<int> col[maxn];
std::vector<int> adj[maxn];
int assignedpart[maxn];
int lastseen[maxn];
int res = 1;

void dfs(int pos, int par){
	int curr_pos = 1;
	for(int i = 0; i < col[pos].size(); i++){
		if(assignedpart[col[pos][i]] != -1){
			lastseen[assignedpart[col[pos][i]]] = pos;
		}
	}

	for(int i = 0; i < col[pos].size(); i++){
		if(assignedpart[col[pos][i]] == -1){
			while(lastseen[curr_pos] == pos){
				curr_pos++;
			}

			assignedpart[col[pos][i]] = curr_pos;
			lastseen[curr_pos] = pos;
			res = std::max(res, curr_pos);
		}
	}

	for(int i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i] != par){
			dfs(adj[pos][i], pos);
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	int v, c;
	std::cin >> v >> c;

	for(int i = 0; i < v; i++){
		int colors;
		std::cin >> colors;

		col[i].resize(colors);
		for(int j = 0; j < colors; j++){
			std::cin >> col[i][j];
			col[i][j]--;
		}
	}

	for(int i = 0; i < v - 1; i++){
		int f, s;
		std::cin >> f >> s;

		f--, s--;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	std::fill(lastseen, lastseen + maxn, -1);
	std::fill(assignedpart, assignedpart + maxn, -1);

	dfs(0, -1);

	std::cout << res << '\n';
	for(int i = 0; i < c; i++){
		if(assignedpart[i] == -1){
			assignedpart[i] = 1;
		}
		std::cout << assignedpart[i] << ' ';
	}
}