#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
std::vector<int> adj[maxn];
int level[maxn];
int parent[maxn];

void solve(int pos, int left, int steps, int border){
	if(left == 0){
		std::cout << pos + 1 << ' ';
		if(pos == border){
			std::cout << '\n';
			return;
		}

		solve(parent[pos], steps - 1, steps, border);
	} else {
		solve(parent[pos], left - 1, steps, border);
	}
}

void dfs(int pos, int par){
	parent[pos] = par;

	for(int i : adj[pos]){
		if(par != i){
			if(level[i] == -1){
			    level[i] = level[pos] + 1;
				dfs(i, pos);
			} else if(level[i] < level[pos]){
				int get = level[pos] - level[i] + 1;
                std::cerr << pos << ' ' << i << ' ' << get << '\n';
                
				if(get % 3 == 0){
					solve(pos, get / 3 - 1, get / 3, i);
					exit(0);
				}
			}
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);
    
    int v, e;
    std::cin >> v >> e;
    
    std::fill(level, level + v, -1);

    for(int i = 0; i < e; i++){
        int f, s;
        std::cin >> f >> s;
        f--, s--;

        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    
    level[0] = 0;
    dfs(0, -1);
    
    std::cout << -1 << '\n';
}