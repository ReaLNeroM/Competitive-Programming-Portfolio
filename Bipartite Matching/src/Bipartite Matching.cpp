#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int v, e;
	cin >> v >> e;

	bool machine[v + 2];
	for(int i = 0; i <= v + 1; i++){
		machine[i] = false;
	}

	vector<pair<int, int> > adj[v + 2];

	for(int i = 0; i < e; i++){
		int f, s;
		cin >> f >> s;
		machine[s] = true;

		adj[f].push_back({s, 1});
	}

	for(int i = 1; i <= v; i++){
		if(machine[i]){
			adj[i].push_back({v + 1, 1});
		} else {
			adj[0].push_back({i, 1});
		}
	}

	int flow = 0;

	while(true){
		bool used[v + 2];
		int parent[v + 2];
		int parentedge[v + 2];
		for(int i = 0; i <= v + 1; i++){
			used[i] = false;
		}

		queue<int> q;
		q.push(0);
		used[0] = true;

		while(!q.empty()){
			int fr = q.front();
			q.pop();

			for(int i = 0; i < adj[fr].size(); i++){
				if(!used[adj[fr][i].first] and adj[fr][i].second > 0){
					parent[adj[fr][i].first] = fr;
					parentedge[adj[fr][i].first] = i;
					used[adj[fr][i].first] = true;
					q.push(adj[fr][i].first);
				}
			}
		}

		if(used[v + 1]){
			int bottleneck = 10000;
			int pos = v + 1;
			while(pos != 0){
				int prev = parent[pos];

				bottleneck = min(bottleneck, adj[prev][parentedge[pos]].second);
				pos = prev;
			}

			pos = v + 1;
			while(pos != 0){
				int prev = parent[pos];
				adj[prev][parentedge[pos]].second -= bottleneck;
				adj[pos].push_back({prev, bottleneck});

				pos = prev;
			}

			flow += bottleneck;
		} else {
			break;
		}
	}

	cout << flow;
	return 0;
}
