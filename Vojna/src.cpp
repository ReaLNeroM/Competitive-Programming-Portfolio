#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 55;
std::vector<int> adj[maxn];
int passed = 0;
int sum = 0;
std::vector<int> res;
int degree[maxn];
bool seen[maxn];
int need[maxn][maxn];

void dfs(int pos){
	while(!adj[pos].empty()){
		int next = adj[pos][adj[pos].size() - 1];
		adj[pos].pop_back();
		dfs(next);
	}

	res.push_back(pos);
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;


	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char c;
			std::cin >> c;

			for(char k = '1'; k <= c; k++){
				adj[i].push_back(j);
				sum++;
				need[i][j]++;
			}
		}
	}

	dfs(0);

	for(int i = 0; i < res.size(); i++){
		// std::cout << res[i] + 1 << ' ';
		if(i != 0){
			need[res[i - 1]][res[i]]--;
		}
		if(!seen[res[i]]){
			seen[res[i]] = true;
			passed++;
		}
	}

	if(res.size() - 1 != sum){
		std::cout << -1 << std::endl;
	} else {
		std::cout << res.size() - 1 << std::endl;
	}
}