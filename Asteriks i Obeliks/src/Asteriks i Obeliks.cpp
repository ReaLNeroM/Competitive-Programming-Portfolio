#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int ve, ed, rc; // roman cities
	cin >> ve >> ed >> rc;
	int s, e;
	cin >> s >> e;
	s--, e--;

	vector<pair<int, int> > adj[ve];
	for(int i = 0; i < ed; i++){
		int fc, sc, c;
		cin >> fc >> sc >> c;
		fc--, sc--;

		adj[fc].push_back({sc, c});
		adj[sc].push_back({fc, c});
	}

	int party[ve];
	for(int i = 0; i < ve; i++){
		cin >> party[i];
	}

	int cost[ve], part[ve];
	bool mark[ve];
	for(int j = 0; j < ve; j++){
		cost[j] = 1000000;
		part[j] = 0;
		mark[j] = false;
	}

	for(int i = 0; i < rc; i++){
		int inp;
		cin >> inp;
		mark[inp - 1] = true;
	}

	priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({0, s});
	part[s] = party[s];
	cost[s] = part[s];

	while(!pq.empty()){
		int city = pq.top().second;
		pq.pop();

		if(mark[city]){
			continue;
		}
		mark[city] = true;

		for(int i = 0; i < adj[city].size(); i++){
			int fullcost = cost[city] + adj[city][i].second;
			if(party[adj[city][i].first] > part[city]){
				fullcost += party[adj[city][i].first] - part[city];
			}
			if(cost[adj[city][i].first] > fullcost){
				cost[adj[city][i].first] = fullcost;
				part[adj[city][i].first] = max(party[adj[city][i].first], part[city]);

				pq.push({fullcost, adj[city][i].first});
			}
		}
	}

	cout << cost[e];
	return 0;
}
