	#include <iostream>
	#include <vector>
	#include <queue>
	#include <utility>
	#include <functional>

	using namespace std;
	typedef long long ll;

	bool cmp(pair<int, int> &x, pair<int, int> &y) {
		return x.first < y.first;
	}
	int main() {
		ios::sync_with_stdio(false);

		int v, e;
		cin >> v >> e;

		vector<pair<int, int> > adj[v];
		for(int i = 0; i < e; i++){
			int f, s, c;
			cin >> f >> s >> c;

			adj[f - 1].push_back(make_pair(s - 1, c));
			adj[s - 1].push_back(make_pair(f - 1, c));
		}

		bool mark[v];
		int cost[v], p[v];
		for(int i = 0; i < v; i++){
			mark[i] = false;
			cost[i] = 1000000;
			p[i] = 0;
		}

		int s, f;
		cin >> s >> f;
		s--, f--;
		cost[s] = 0;
		p[s] = -1;

		priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		pq.push({1, s});

		while(!pq.empty()){
			int d = pq.top().first, ind = pq.top().second;
			pq.pop();
			if(mark[ind]){
				continue;
			}
			mark[ind] = true;

			for(int j = 0; j < adj[ind].size(); j++){
				if(cost[adj[ind][j].first] > adj[ind][j].second * d){
					cost[adj[ind][j].first] = adj[ind][j].second * d;
					p[adj[ind][j].first] = ind;
					pq.push({cost[adj[ind][j].first], adj[ind][j].first});
				}
			}
		}

		int afford;
		cin >> afford;

		if(cost[f] <= afford){
			cout << cost[f] << endl;
			int r[v];
			int pos = f, size = 0;
			while(pos >= 0){
				r[size] = pos;
				pos = p[pos];
				size++;
			}
			for(int i = size - 1; i >= 0; i--){
				cout << r[i] + 1 << ' ';
			}
		} else if(cost[f] < 1000000){
			cout << cost[f] << endl << "NE";
		} else {
			cout << "NE" << endl << "NE";
		}

		return 0;
	}
