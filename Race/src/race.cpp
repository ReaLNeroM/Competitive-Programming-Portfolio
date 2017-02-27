#include <bits/stdc++.h>

using namespace std;
typedef long ll;
//#include "race.h"
#include "grader.h"

const ll maxn = 2e5 + 5;
ll v, dist;
ll e[maxn][2];
ll d[maxn];
vector<pair<ll, ll> > adj[maxn];
ll swipe = 1;
ll sum[maxn];
ll used[maxn];
ll disabled[maxn];
ll res = 2 * maxn;
map<ll, ll> m;

ll dfs(ll pos, ll swipe){
	if(used[pos] == swipe){
		return 0;
	}
	used[pos] = swipe;

	sum[pos] = 1;

	for(ll i = 0; i < adj[pos].size(); i++){
		ll nnext = adj[pos][i].first;

		sum[pos] += dfs(nnext, swipe);
	}

	return sum[pos];
}
void dfs2(ll pos, ll par, bool add, ll curr_sum, ll curr_dist){
	if(!add and curr_sum <= dist){
		ll to_find = dist - curr_sum;
		if(m.find(to_find) != m.end()){
			res = min(res, curr_dist + m[to_find]);
		}
	} else {
		if(m.find(curr_sum) == m.end()){
			m[curr_sum] = curr_dist;
		} else {
			m[curr_sum] = min(m[curr_sum], curr_dist);
		}
	}
	for(ll i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i].first != par){
			dfs2(adj[pos][i].first, pos, add, curr_sum + adj[pos][i].second, curr_dist + 1);
		}
	}
}

int best_path(int iv, int idist, int ie[][2], int id[]){
	v = iv;
	dist = idist;
	for(ll i = 0; i < v - 1; i++){
		e[i][0] = ie[i][0];
		e[i][1] = ie[i][1];
		d[i] = id[i];
	}

	for(ll i = 0; i < v; i++){
		used[i] = 0;
	}

	res = 2 * v;
	for(ll swipe = 1; swipe < 40; swipe++){
		for(ll i = 0; i < v; i++){
			adj[i].clear();
		}
		for(ll i = 0; i < v - 1; i++){
			if(!disabled[e[i][0]] and !disabled[e[i][1]]){
				adj[e[i][0]].push_back({e[i][1], d[i]});
				adj[e[i][1]].push_back({e[i][0], d[i]});
			}
		}
		for(ll i = 0; i < v; i++){
			if(used[i] != swipe){
				ll size = dfs(i, swipe);
				bool good = true;
				ll prev = -1;
				ll centroid = i;
				do {
					good = false;
					for(ll j = 0; j < adj[centroid].size(); j++){
						if(adj[centroid][j].first != prev and sum[adj[centroid][j].first] > size / 2){
							prev = centroid;
							centroid = adj[centroid][j].first;
							good = true;
							break;
						}
					}
				} while(good);

				m.clear();
				m[0] = 0;

				for(ll j = 0; j < adj[centroid].size(); j++){
					dfs2(adj[centroid][j].first, centroid, false, adj[centroid][j].second, 1);
					dfs2(adj[centroid][j].first, centroid, true, adj[centroid][j].second, 1);
				}

				disabled[centroid] = true;
			}
		}
	}

	if(res == 2 * v){
		return -1;
	}
	return res;
}
