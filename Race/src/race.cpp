#include <bits/stdc++.h>

using namespace std;
typedef long ll;
#include "race.h"

const int maxn = 2e5 + 5;
int v, dist;
int e[maxn][2];
int d[maxn];
vector<pair<int, int> > adj[maxn];
int swipe = 1;
int sum[maxn];
int used[maxn];
int disabled[maxn];

int dfs(int pos, int swipe){
	if(used[pos] == swipe){
		return 0;
	}
	used[pos] = swipe;

	sum[pos] = 1;

	for(int i = 0; i < adj[pos].size(); i++){
		int nnext = adj[pos][i].first;

		sum[pos] += dfs(nnext, swipe);
	}

	return sum[pos];
}

int best_path(int iv, int idist, int ie[][2], int id[]){
	v = iv;
	dist = idist;
	for(int i = 0; i < v - 1; i++){
		e[i][0] = ie[i][0];
		e[i][1] = ie[i][1];
		d[i] = id[i];
	}

	for(int i = 0; i < v - 1; i++){
		adj[e[i][0]].push_back({e[i][1], d[i]});
		adj[e[i][1]].push_back({e[i][0], d[i]});
	}

	for(int i = 0; i < v; i++){
		used[i] = 0;
	}
	int res = 2 * v;
	for(int swipe = 1; swipe < 32; swipe++){
		for(int i = 0; i < v; i++){
			adj[i].clear();
		}
		for(int i = 0; i < v - 1; i++){
			if(!disabled[e[i][0]] and !disabled[e[i][1]]){
				adj[e[i][0]].push_back({e[i][1], d[i]});
				adj[e[i][1]].push_back({e[i][0], d[i]});
			}
		}
		for(int i = 0; i < v; i++){
			if(used[i] != swipe){
				int size = dfs(i, swipe);
				bool good = true;
				int centroid = i;
				do {
					good = false;
					for(int j = 0; j < adj[centroid].size(); j++){
						if(sum[adj[centroid][j]] >= size / 2){
							centroid = adj[centroid][j];
							good = true;
							break;
						}
					}
				} while(good);

				disabled[centroid] = true;
			}
		}
	}

	if(res == 2 * v){
		return -1;
	}
	return res;
}
