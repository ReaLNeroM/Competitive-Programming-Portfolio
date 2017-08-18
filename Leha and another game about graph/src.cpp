#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6;
int d[maxn];
std::vector<std::vector<int>> adj[maxn];
int need[maxn];
bool used[maxn];

int dfs(int pos){
	int refer = 0;
	used[pos] = true;

	for(std::vector<int> i : adj[pos]){
		int next = i[0];
		int edge = i[1];

		if(!used[next]){
			used[next] = true;
			int get = dfs(next);

			need[edge] += get;

			refer += get;
		}
	}

	if(d[pos] == 1){
		refer++;
	}

	return refer;
}

int main(){
	std::ios::sync_with_stdio(false);

	int v, e;
	std::cin >> v >> e;

	int negative = -1;
	int ones = 0;

	for(int i = 0; i < v; i++){
		std::cin >> d[i];
		if(d[i] == -1){
			negative = i;
		} else if(d[i] == 1){
			ones++;
		}
	}

	for(int i = 0; i < e; i++){
		int f, s;
		std::cin >> f >> s;
		f--, s--;

		adj[f].push_back({s, i + 1});
		adj[s].push_back({f, i + 1});
	}

	if(negative != -1){
		dfs(negative);
	} else {
		if(ones % 2 == 1){
			std::cout << -1 << std::endl;
			return 0;
		}

		dfs(0);
	}

	int res = 0;
	std::vector<int> resv;

	for(int i = 1; i <= e; i++){
		if(need[i] % 2 == 1){
			resv.push_back(i);
			res++;
		}
	}

	std::cout << res << '\n';

	for(int i : resv){
		std::cout << i << ' ';
	}
	std::cout << '\n';
}
