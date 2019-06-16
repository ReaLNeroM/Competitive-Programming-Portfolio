#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 125;
int lca[maxn][3];
std::vector<int> adj[maxn];
int in[maxn];
int par[maxn];
int level[maxn];
int color[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int testCases;
	std::cin >> testCases;

	for(int testCase = 1; testCase <= testCases; testCase++){
		int v, e;
		std::cin >> v >> e;

		for(int i = 0; i < v; i++){
			adj[i].clear();
		}
		memset(in, 0, sizeof(in));
		memset(par, 0, sizeof(par));
		memset(level, 0, sizeof(level));
		memset(color, 0, sizeof(color));

		for(int i = 0; i < e; i++){
			std::cin >> lca[i][0] >> lca[i][1] >> lca[i][2];
			lca[i][0]--, lca[i][1]--, lca[i][2]--;
			if(lca[i][2] != lca[i][0]){
				bool there = false;
				for(int next : adj[lca[i][2]]){
					if(next == lca[i][0]){
						there = true;
					}
				}
				if(!there){
					adj[lca[i][2]].push_back(lca[i][0]);
					in[lca[i][0]]++;
				}
			}
			if(lca[i][2] != lca[i][1]){
				bool there = false;
				for(int next : adj[lca[i][2]]){
					if(next == lca[i][1]){
						there = true;
					}
				}
				if(!there){
					adj[lca[i][2]].push_back(lca[i][1]);
					in[lca[i][1]]++;
				}
			}
		}

		bool good = true;

		std::queue<int> q;

		int gotten = 0;
		int root = -1;
		for(int i = 0; i < v; i++){
			if(in[i] == 0){
				if(root == -1){
					//choose this as root
					root = i;
					par[root] = -1;
					level[root] = 0;
				} else {
					par[i] = root;
					level[i] = level[root] + 1;
				}
				q.push(i);
			}
		}

		while(!q.empty()){
			int fr = q.front();
			gotten++;
			q.pop();

			for(int next : adj[fr]){
				if(in[next] == 1){
					par[next] = fr;
					level[next] = level[fr] + 1;
					q.push(next);
				} else {
					in[next]--;
				}
			}
		}

		if(gotten != v){
			good = false;
		} else if(gotten == v){
			for(int i = 0; i < e; i++){
				int a = lca[i][0];
				int b = lca[i][1];

				while(level[a] > level[b]){
					a = par[a];
				}
				while(level[a] < level[b]){
					b = par[b];
				}
				while(level[a] > 0 and a != b){
					a = par[a];
					b = par[b];
				}

				if(a != b or a != lca[i][2]){
					good = false;
				}
			}
		}

		std::cout << "Case #" << testCase << ": ";
		if(good){
			for(int i = 0; i < v; i++){
				std::cout << par[i] + 1;
				if(i != v - 1){
					std::cout << ' ';
				}
			}
		} else {
			std::cout << "Impossible";
		}
		std::cout << '\n';
	}
}
