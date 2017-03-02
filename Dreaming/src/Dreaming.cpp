#include <bits/stdc++.h>
#include "grader.h"
using namespace std;
typedef long long ll;

const ll maxv = 100005;
vector<pair<ll, ll> > adj[maxv];
bool root[maxv];
int used[maxv];
ll dist[maxv];
ll stage;
ll maxd;
bool eend = false;

ll farthest(ll p){
	priority_queue<pair<ll, ll> > q;
	q.push(make_pair(0, p));

	ll fart = p, fartcost = 0;
	while(!q.empty()){
		ll cost = q.top().first, ind = q.top().second;
		q.pop();
		if(used[ind] >= stage){
			continue;
		}
		if(stage != 1){
			dist[ind] = max(dist[ind], cost);
		}
		if(cost > fartcost){
			fart = ind;
			fartcost = cost;
		}
		used[ind]++;
		for(ll i = 0; i < adj[ind].size(); i++){
			ll nextcost = cost + adj[ind][i].second, nextind = adj[ind][i].first;

			if(used[nextind] < stage){
				q.push(make_pair(nextcost, nextind));
			}
		}
	}

	if(stage == 3 and eend){
		maxd = fartcost;
	}

	return fart;
}

pair<ll, ll> rot(ll p){
	stage = 1;
	ll one = farthest(p);
	stage = 2;
	ll two = farthest(one);
	stage = 3;
	farthest(two);
	stage = 4;


	queue<ll> q;
	q.push(p);
	ll fart = p;
	while(!q.empty()){
		ll fr = q.front();
		q.pop();

		for(ll i = 0; i < adj[fr].size(); i++){
			ll next = adj[fr][i].first;

			if(used[next] < 5){
				used[next] = 5;
				q.push(next);
				if(dist[fart] > dist[next]){
					fart = next;
				}
			}
		}
	}

	return make_pair(fart, dist[fart]);
}

int travelTime(int v, int e, int c, int f[], int s[], int d[]){
	for(ll i = 0; i < v; i++){
		root[i] = false;
		used[i] = 0;
		dist[i] = 0;
	}

	for(ll i = 0; i < e; i++){
		adj[f[i]].push_back(make_pair(s[i], d[i]));
		adj[s[i]].push_back(make_pair(f[i], d[i]));
	}

	ll mostdist = -1;
	for(ll i = 0; i < v; i++){
		if(!used[i]){
			ll found = rot(i).first;

			root[found] = true;

			if(mostdist == -1 or dist[mostdist] < dist[found]){
				mostdist = found;
			}
		}
	}

	for(ll i = 0; i < v; i++){
		if(root[i] and i != mostdist){
			adj[mostdist].push_back(make_pair(i, c));
			adj[i].push_back(make_pair(mostdist, c));
		}

		used[i] = 0;
		dist[i] = 0;
		root[i] = false;
	}

	eend = true;
	rot(0).second;

	return maxd;
}
