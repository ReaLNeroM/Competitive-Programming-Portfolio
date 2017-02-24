#include "grader.h"
//#include "garden.h"
//#include "gardenlib.h"
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 300005;
vector<int> adj[maxn];
int cycle[maxn];
int skip[maxn][31];
int dist[maxn];
int ans[maxn];

void tryout(int s, int v, int q, int que[]){
	for(int i = 0; i < maxn; i++){
		cycle[i] = false;
		adj[i].clear();
	}

	int pos = s;
	int cycle_size = 1;
	while(!cycle[pos]){
		cycle[pos] = cycle_size;
		cycle_size++;
		pos = skip[pos][0];
	}
	cycle_size--;
	if(pos != s){
		for(int i = 0; i < 2 * v; i++){
			adj[skip[i][0]].push_back(i);
		}
		for(int i = 0; i < 2 * v; i++){
			dist[i] = 1e9 + 5;
		}
		queue<int> qu;
		qu.push(s);
		dist[s] = 0;
		while(!qu.empty()){
			int fr = qu.front();
			qu.pop();

			for(int i = 0; i < adj[fr].size(); i++){
				int nnext = adj[fr][i];

				if(dist[nnext] > 1e9){
					dist[nnext] = dist[fr] + 1;
					qu.push(nnext);
				}
			}
		}

		for(int i = 0; i < q; i++){
			for(int j = 0; j < v; j++){
				if(dist[j] == que[i]){
					ans[i]++;
				}
			}
		}
	} else {
		vector<int> eend;
		for(int i = 0; i < v; i++){
			int best = 3 * v;

			int curr = 0;
			int pos = i;
			int last_pos = i;
			for(int j = 30; j >= 0; j--){
				curr += (1 << j);

				int next_pos = skip[pos][j];

				if(cycle[next_pos]){
					best = curr;
					curr -= (1 << j);
					last_pos = next_pos;
				} else {
					pos = next_pos;
				}
			}

			if(cycle[i]){
				last_pos = i;
				best = 0;
			}

			if(best != 3 * v){
				eend.push_back(best + (cycle_size - cycle[last_pos] + 1) % cycle_size);
			}
		}

		for(int i = 0; i < q; i++){
			for(int j = 0; j < eend.size(); j++){
				if(eend[j] <= que[i] and (que[i] - eend[j]) % cycle_size == 0){
					ans[i]++;
				}
			}
		}
	}
}

void count_routes(int v, int e, int s, int edg[][2], int q, int que[]) {
	for(int i = 0; i < e; i++){
		adj[edg[i][0]].push_back(edg[i][1]);
		adj[edg[i][1]].push_back(edg[i][0]);
	}

	for(int i = 0; i < v; i++){
		if(adj[adj[i][0]][0] == i){
			skip[i][0] = adj[i][0] + v;
		} else {
			skip[i][0] = adj[i][0];
		}

		if(adj[i].size() == 1){
			if(adj[adj[i][0]][0] == i){
				skip[v + i][0] = adj[i][0] + v;
			} else {
				skip[v + i][0] = adj[i][0];
			}
		} else {
			if(adj[adj[i][1]][0] == i){
				skip[v + i][0] = adj[i][1] + v;
			} else {
				skip[v + i][0] = adj[i][1];
			}
		}
	}

	for(int i = 1; i < 31; i++){
		for(int j = 0; j < 2 * v; j++){
			skip[j][i] = skip[skip[j][i - 1]][i - 1];
		}
	}

	tryout(s, v, q, que);
	tryout(s + v, v, q, que);

	for(int i = 0; i < q; i++){
		answer(ans[i]);
	}
}
