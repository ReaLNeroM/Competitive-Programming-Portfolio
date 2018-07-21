#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e2 + 1e2;
int v, e;
int color[maxn];
int used[maxn];
std::vector<int> adj[maxn];
std::vector<int> sec[maxn];

void bipartite_solve(){
	std::queue<int> q;

	used[0] = true;
	q.push(0);

	while(!q.empty()){
		int fr = q.front();
		q.pop();

		for(int next : adj[fr]){
			if(!used[next]){
				used[next] = true;
				color[next] = !color[fr];

				q.push(next);
			}
		}
	}
}

bool verify(){
	for(int i = 0; i < v; i++){
		sec[i].clear();
	}

	for(int i = 0; i < v; i++){
		if(color[i]){
			for(int next : adj[i]){
				for(int next2 : adj[next]){
					sec[i].emplace_back(next2);
				}
			}
		} else {
			for(int next : adj[i]){
				sec[i].emplace_back(next);
			}
		}
	}

	for(int i = 0; i < v; i++){
		std::fill(used, used + v, false);
		std::queue<int> q;

		used[i] = true;
		q.push(i);
		int size = 0;

		while(!q.empty()){
			int fr = q.front();
			size++;
			q.pop();

			for(int next : sec[fr]){
				if(!used[next]){
					used[next] = true;
					q.push(next);
				}
			}
		}

		if(size != v){
			return true;
		}
	}

	return false;
}

void brute_solve(){
	for(int bitset = 0; bitset < (1 << v); bitset++){
		for(int i = 0, bit = 1; i < v; i++, bit *= 2){
			color[i] = ((bit & bitset) != 0);
		}

		if(verify()){
			return;
		}
	}
}


int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> v >> e;

	for(int i = 0; i < e; i++){
		int f, s;
		std::cin >> f >> s;
		f--, s--;

		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	bool found_solution = false;
	bipartite_solve();

	if(!verify())
		if(v <= 15)
			brute_solve();
	
	found_solution = verify();
	if(!found_solution){
		std::cout << "NO\n";
		return 0;
	}

	std::cout << "YES\n";
	for(int i = 0; i < v; i++){
		std::cout << color[i] + 1 << ' ';
	}
	std::cout << '\n';
}
