#include <bits/stdc++.h>

typedef long long ll;

const ll MAXN = 1e6 + 1e2;
ll v, e;
std::vector<ll> adj[MAXN];
int state[MAXN];
int color[MAXN];

int dfs(int pos, int par){
	state[pos] = 1;

	for(int next : adj[pos]){
		if(next != par){
			if(state[next] == 1){
				color[next] = 2;
			} else if(state[next] == 0){
				color[next] = !color[pos];
				dfs(next, pos);
			}
		}
	}

	state[pos] = 2;
}

int main(){
	std::ios::sync_with_stdio(false);

	int test_cases;
	std::cin >> test_cases;

	while(test_cases--){
		std::cin >> v >> e;

		for(int i = 0; i < v; i++){
			adj[i].clear();
			state[i] = 0;
			color[i] = 0;
		}

		for(int i = 0; i < e; i++){
			int f, s;
			std::cin >> f >> s;
			f--, s--;

			adj[f].push_back(s);
			adj[s].push_back(f);
		}

		for(int i = 0; i < v; i++){
			if(!state[i]){
				color[i] = 0;
				dfs(i, -1);
			}
		}

		std::cout << 1 << '\n';
		for(int i = 0; i < v; i++){
			std::cout << color[i] + 1 << ' ';
		}
		std::cout << '\n';
	}
}
