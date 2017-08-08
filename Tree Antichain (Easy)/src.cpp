#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int col[maxn];
int level[maxn];
std::vector<int> adj[maxn];
std::vector<int> res[2];

int main(){
	std::ios::sync_with_stdio(false);
	
	int t;
	std::cin >> t;
	
	for(int test = 0; test < t; test++){
		int n;
		std::cin >> n;
		
		for(int i = 0; i < n; i++){
			adj[i].clear();
			col[i] = -1;
			level[i] = 0;
		}
		res[0].clear();
		res[1].clear();
		
		for(int i = 0; i < n - 1; i++){
			int f, s;
			std::cin >> f >> s;
			f--, s--;
			adj[f].push_back(s);
			adj[s].push_back(f);
		}
		
		std::queue<int> q;
		q.push(0);
		col[0] = 0;
		level[0] = 0;
		
		int most_level = 1;
		
		while(!q.empty()){
			int fr = q.front();
			q.pop();
			res[col[fr]].push_back(fr);
			most_level = std::max(most_level, level[fr] + 1);
			
			for(int i = 0; i < adj[fr].size(); i++){
				int next = adj[fr][i];
				
				if(col[next] == -1){
					col[next] = !col[fr];
					level[next] = level[fr] + 1;
					q.push(next);
				}
			}
		}
		
		if(most_level == 2){
			std::cout << -1;
		} else if(most_level == 3){
			int a = res[0][res[0].size() - 1];
			
			bool no_need = false;	
			for(int k = 0; k < res[1].size(); k++){
				bool good = true;
				for(int i = 0; i < adj[a].size(); i++){
					if(adj[a][i] == res[1][k]){
						good = false;
						break;
					}
				}
	
				if(good){
					for(int j = 0; j < res[0].size(); j++){
						std::cout << res[0][j] + 1 << ' ';
					}
					std::cout << res[1][k] + 1 << ' ';
					for(int j = 0; j < res[1].size(); j++){
						if(res[1][j] != res[1][k]){
							std::cout << res[1][j] + 1 << ' ';
						}
					}
					no_need = true;
					break;
				}
			}				
			
			if(!no_need){
				std::cout << -1;
			}
		} else if(most_level >= 4){
			for(int i = res[0].size() - 1; i >= 0; i--){
				std::cout << res[0][i] + 1 << ' ';
			}
			for(int i = res[1].size() - 1; i >= 0; i--){
				std::cout << res[1][i] + 1 << ' ';
			}
		}
		
		std::cout << '\n';
	}
}