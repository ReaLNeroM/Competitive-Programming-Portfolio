#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int p[maxn];
std::vector<int> adj[maxn];
int degree[maxn];
int order[maxn];
int curr = 0;

void dfs(int pos){
	if(adj[pos].size() == 0){

	}
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> p[i];
		p[i]--;

		if(p[i] != -1){
			adj[p[i]].push_back(i);
		}
	}

	dfs(0);
}