#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
const ll mod = 1e9 + 7;

int p[maxn];
int v[maxn];
std::vector<int> adj[maxn];
int where[maxn]; //effectively a pointer
std::map<int, int> m[maxn];
ll result_for_node[maxn];
ll res = 0;

void dfs(int pos){
	int biggest = pos;
	int biggest_next = pos;

	for(int i = 0; i < adj[pos].size(); i++){
		int next = adj[pos][i];
		dfs(next);
		if(biggest == pos or m[where[next]].size() > m[biggest].size()){
			biggest = where[next];
			biggest_next = next;
		}
	}

	//add to res
	//add to result_for_node
	if(pos != biggest){
		result_for_node[pos] = result_for_node[biggest_next];
	}

	where[pos] = biggest;

	for(int i = 0; i < adj[pos].size(); i++){
		int next = adj[pos][i];
		if(next != biggest_next){
			for(auto ite = m[where[next]].begin(); ite != m[where[next]].end(); ite++){
				int& cache = m[biggest][ite->first];

				result_for_node[pos] += ite->second - 2;
				
				if(cache == 0){
					cache = 1;
				}

				cache *= ite->second;
				cache %= mod;

				result_for_node[pos] += cache;

				if(result_for_node[pos] < 0){
					result_for_node[pos] += mod;
				}
			}
		}
	}

	int& cache = m[biggest][v[pos]];

	if(cache == 0){
		cache = 1;
		cache *= 2;
		cache %= mod;
		result_for_node[pos] += cache;
		result_for_node[pos] %= mod;
	} else {
		result_for_node[pos] += cache;
		result_for_node[pos] %= mod;
		cache *= 2;
		cache %= mod;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	
	int n;
	std::cin >> n;
	
	for(int i = 0; i < n; i++){
		std::cin >> p[i] >> v[i];

		if(p[i] != -1){
			p[i]--;
			adj[p[i]].push_back(i);
		}
	}

	dfs(0);

	for(int i = 0; i < n; i++){
		std::cout << result_for_node[i] << std::endl;
	}

	std::cout << result_for_node[0] << std::endl;
}