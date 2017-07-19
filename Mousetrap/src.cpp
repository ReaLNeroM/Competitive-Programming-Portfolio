#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int v, s, e;
std::vector<int> adj[maxn];
bool used[maxn];
int par_array[maxn];
int imp[maxn];
int level[maxn];
ll res = 0;

int dfs(int pos, int par, int last_imp_level, int last_imp = 0){
	int best = -1000;
	bool best_was_in_imp = false;
	int sec_best = -1000;

	for(int i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i] != par){
			int get;

			if(!imp[adj[pos][i]]){
				get = dfs(adj[pos][i], pos, last_imp_level, last_imp);
			} else {
				get = dfs(adj[pos][i], pos, level[adj[pos][i]], adj[pos][i]);
			}

			if(best < get){
				sec_best = best;
				best_was_in_imp = imp[adj[pos][i]];
				best = get;
			} else if(sec_best < get){
				sec_best = get;
			}
		}
	}

	if(pos == e){
		return 0;
	} else if(par != -1 and adj[pos].size() <= 2 and !best_was_in_imp){
		int curr = pos;
		int sum = 0;

		while(curr != last_imp){
			if(curr == pos){
				sum++;
			}

			sum += adj[curr].size() - 1;
			curr = par_array[curr];
		}

		curr = e;
		while(curr != last_imp){
			if(curr == e){
				sum++;
			}

			sum += adj[curr].size() - 2;
			curr = par_array[curr];
		}

		if(last_imp != e){
			if(last_imp_level == 0){
				sum += adj[last_imp].size() - 2;
			} else {
				sum += adj[last_imp].size() - 3;
			}
		}

		return sum;
	} else if(best_was_in_imp){
		return best;
	}

	return sec_best + 1;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> v >> e >> s;
	e--, s--;

	if(v > 10000){
		return 0;
	}
	if(e == s){
		std::cout << 0 << std::endl;
		return 0;
	}

	for(int i = 0; i < v - 1; i++){
		int f, s;
		std::cin >> f >> s;
		f--, s--;

		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	std::queue<int> q;
	q.push(s);
	used[s] = true;
	level[s] = 0;

	while(!q.empty()){
		int fr = q.front();
		q.pop();

		for(int i = 0; i < adj[fr].size(); i++){
			int next = adj[fr][i];

			if(!used[next]){
				used[next] = true;
				level[next] = level[fr] + 1;
				par_array[next] = fr;
				q.push(next);
			}
		}
	}

	int pos = e;
	while(pos != s){
		imp[pos] = true;
		pos = par_array[pos];
	}
	imp[s] = true;

	std::cout << dfs(s, -1, 0) << std::endl;
}
