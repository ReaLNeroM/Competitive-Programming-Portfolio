#include <iostream>
#include <utility>
#include <vector>
#include <queue>

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(false);
	ll start, end;
	std::cin >> start >> end;
	start--, end--;
	if(start > end){
		std::swap(start, end);
	}

	ll vertices, edges;
	std::cin >> vertices >> edges;

	std::vector<std::pair<ll, ll> > adj_list[vertices];

	for (ll i = 0, first, second, cost; i < edges; i++) {
		std::pair<ll, ll> copy;
		std::cin >> first >> second >> cost;

		copy.second = cost;

		copy.first = second - 1;
		adj_list[first - 1].push_back(copy);

		copy.first = first - 1;
		adj_list[second - 1].push_back(copy);
	}

	ll cost[vertices];
	for (ll i = 0; i < vertices; i++) {
		cost[i] = -1;
	}
	cost[start] = 0;

	std::queue<int> q;
	q.push(start);

	while(!q.empty()){
		int fr = q.front();
		q.pop();

		for(int i = 0; i < adj_list[fr].size(); i++){
			if(cost[adj_list[fr][i].first] == -1){
				if(adj_list[fr][i].first < fr){
					cost[adj_list[fr][i].first] = cost[fr] - adj_list[fr][i].second;
				} else {
					cost[adj_list[fr][i].first] = cost[fr] + adj_list[fr][i].second;
				}

				q.push(adj_list[fr][i].first);
			}
		}
	}

	std::cout << cost[end];
	return 0;
}
