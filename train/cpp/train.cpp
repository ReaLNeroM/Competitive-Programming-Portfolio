#include "train.h"
#include <bits/stdc++.h>

const int maxn = 2e4 + 1e2;
int used[maxn];
std::vector<int> adj[maxn];
std::vector<int> rev[maxn];
bool cycle[maxn];

std::vector<int> who_wins(std::vector<int> a, std::vector<int> r, std::vector<int> u, std::vector<int> v) {
	std::vector<int> res(a.size(), !a[0]);

	int n = a.size();
	
	for(int i = 0; i < u.size(); i++){
		adj[u[i]].push_back(v[i]);
		rev[v[i]].push_back(u[i]);
	}

	std::queue<int> final_queue;

	for(int i = 0; i < n; i++){
		if(a[i] == r[i]){
			memset(used, false, sizeof(used));
			std::queue<int> q;
			q.push(i);
			used[i] = true;

			while(!q.empty()){
				int fr = q.front();
				q.pop();

				for(int next : adj[fr]){
					if(next == i){
						res[i] = cycle[i] = a[0];
						final_queue.push(i);

						while(!q.empty()){
							q.pop();
						}
						break;
					}

					if(!used[next] and (r[next] == 0 or a[i] == 1)){
						used[next] = true;
						q.push(next);
					}
				}
			}
		}
	}

	while(!final_queue.empty()){
		int fr = final_queue.front();
		final_queue.pop();

		for(int next : rev[fr]){
			if(res[next] == !a[0]){
				res[next] = a[0];
				final_queue.push(next);
			}
		}
	}
	
	return res;
}
