#include "collapse.h"
#include <bits/stdc++.h>

const int maxn = 5005;
std::vector<int> adj[maxn];
std::vector<std::vector<int>> query[maxn];
bool used[maxn];

int find_res(int size, int cut){
	std::fill(used, used + size, false);

	int res = 0;

	std::queue<int> q;

	for(int i = 0; i < size; i++){
		if(!used[i]){
			res++;
			used[i] = true;
			q.push(i);

			while(!q.empty()){
				int fr = q.front();
				q.pop();

				for(int next : adj[fr]){
					if(fr <= cut and cut < next){
						continue;
					} else if(next <= cut and cut < fr){
						continue;
					} else {
						if(!used[next]){
							used[next] = true;
							q.push(next);
						}
					}
				}
			}
		}
	}

	return res;
}

std::vector<int> simulateCollapse(
	int N,
	std::vector<int> T,
	std::vector<int> X,
	std::vector<int> Y,
	std::vector<int> W,
	std::vector<int> P
) {

	for(int i = 0; i < W.size(); i++){
		query[W[i]].push_back({P[i], i});
	}

	std::vector<int> res(W.size());

	for(int i = 0; i < T.size(); i++){
		if(T[i] == 0){
			adj[X[i]].push_back(Y[i]);
			adj[Y[i]].push_back(X[i]);
		} else {
			adj[X[i]].erase(std::find(adj[X[i]].begin(), adj[X[i]].end(), Y[i]));
			adj[Y[i]].erase(std::find(adj[Y[i]].begin(), adj[Y[i]].end(), X[i]));
		}

		for(std::vector<int> j : query[i]){
			res[j[1]] = find_res(N, j[0]);
		}
	}

	return res;
}
