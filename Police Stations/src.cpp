#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 3e5 + 1e2;
std::vector<int> adj[maxn];
std::vector<int> adj_ind[maxn];
bool used[maxn];
int defended[maxn];

int main(){
	std::ios::sync_with_stdio(false);
	int n, stations, dist;
	std::cin >> n >> stations >> dist;

	std::queue<int> q, qdist;

	for(int i = 0; i < stations; i++){
		int police_ind;
		std::cin >> police_ind;
		police_ind--;

		defended[police_ind] = true;
		q.push(police_ind);
		qdist.push(0);
	}

	for(int i = 0; i < n - 1; i++){
		int f, s;
		std::cin >> f >> s;
		f--, s--;

		adj[f].push_back(s);
		adj_ind[f].push_back(i);
		adj[s].push_back(f);
		adj_ind[s].push_back(i);
	}

	while(!q.empty()){
		int fr = q.front(), frdist = qdist.front();
		q.pop(), qdist.pop();

		if(frdist == dist){
			continue;
		}

		for(int i = 0; i < adj[fr].size(); i++){
			int nnext = adj[fr][i];
			if(!defended[nnext]){
				defended[nnext] = true;
				q.push(nnext);
				qdist.push(frdist + 1);
				used[adj_ind[fr][i]] = true;
			}
		}
	}

	int disabled = 0;
	for(int i = 0; i < n - 1; i++){
		if(!used[i]){
			disabled++;
		}
	}

	std::cout << disabled << std::endl;
	for(int i = 0; i < n - 1; i++){
		if(!used[i]){
			std::cout << i + 1 << ' ';
		}
	}
	std::cout << std::endl;
}