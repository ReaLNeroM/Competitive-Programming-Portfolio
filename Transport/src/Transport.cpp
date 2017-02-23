#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int ve, ed;
	cin >> ve >> ed;

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

	int cost[ve], cities[ve];
	bool mark[ve];
	for(int j = 0; j < ve; j++){
		cost[j] = 1000000;
		cities[j] = 0;
		mark[j] = false;
	}

	int s, e;
	cin >> s >> e;
	s--, e--;
	cost[s] = party[s];
	cities[s] = 1;
	priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({cost[s], s});

	while(!pq.empty()){
		int city = pq.top().second;
		pq.pop();

		if(mark[city]){
			continue;
		}
		mark[city] = true;

		for(int i = 0; i < adj[city].size(); i++){
			int fullcost = cost[city] + adj[city][i].second + party[adj[city][i].first];
			if(cost[adj[city][i].first] > fullcost){
				cost[adj[city][i].first] = fullcost;
				cities[adj[city][i].first] = cities[city] + 1;

				pq.push({fullcost, adj[city][i].first});
			}
		}
	}

	cout << cost[e] << endl << cities[e];
	return 0;
}
