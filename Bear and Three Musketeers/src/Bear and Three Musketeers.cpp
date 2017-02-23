#include <iostream>

typedef long long ll;

int main() {
	ll bears, edges;
	std::cin >> bears >> edges;

	ll friends[bears];
	bool adj[bears][bears];
	for(ll i = 0; i < bears; i++){
		friends[i] = 0;
		for(ll j = 0; j < bears; j++){
			adj[i][j] = false;
		}
	}

	std::pair<ll, ll> edge[edges];
	for(ll i = 0; i < edges; i++){
		std::cin >> edge[i].first >> edge[i].second;
		edge[i].first--, edge[i].second--;

		friends[edge[i].first]++, friends[edge[i].second]++;
		adj[edge[i].first][edge[i].second] = true;
		adj[edge[i].second][edge[i].first] = true;
	}


	ll min = bears * bears * bears;
	for(ll i = 0; i < edges; i++){
		for(ll j = 0; j < bears; j++){
			if(edge[i].first == j or edge[i].second == j){
				continue;
			}

			if(adj[edge[i].first][j] and adj[edge[i].second][j]){
				min = std::min(min, friends[edge[i].first] + friends[edge[i].second] + friends[j] - 6);
			}
		}
	}

	if(min == bears * bears * bears){
		std::cout << -1;
	} else {
		std::cout << min;
	}
	return 0;
}
