#include "garden.h"
#include "gardenlib.h"
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6;
vector<int> adj[maxn];

int skip[maxn][20];

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

		if(adj[i].size() == ){
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

	for(int i = 1; i < 20; i++){
		for(int j = 0; j < 2 * v; j++){
			skip[j][i] = skip[skip[j][i - 1]][i - 1];
		}
	}

	for(int i = 0; i < q; i++){
		int left = que[i] - 1;

		int pos = s;
		for(int j = 19; j >= 0; j--){
			if(left >= (1 << j)){
				pos = skip[pos][j];
				left -= (1 << j);
			}
		}

		if(pos >= v){
			answer(pos - v);
		} else {
			answer(pos);
		}
	}
}

