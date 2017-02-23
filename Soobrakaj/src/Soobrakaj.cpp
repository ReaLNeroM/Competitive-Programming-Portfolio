#include <iostream>

typedef long long ll;

struct edge{
	ll first, second, dist;
};

int main() {
	ll vertices, edges;
	std::cin >> vertices >> edges;

	ll v[vertices];
	ll density[vertices];
	edge e[edges];

	for(ll i = 0; i < vertices; i++){
		v[i] = 10000000000;
		std::cin >> density[i];
	}

	for(ll i = 0; i < edges; i++){
		std::cin >> e[i].first >> e[i].second;
		e[i].first--, e[i].second--;
		e[i].dist = density[e[i].first] - density[e[i].second];
		e[i].dist = e[i].dist * e[i].dist * e[i].dist;
	}

	ll start, end;
	std::cin >> start >> end;
	start--, end--;
	v[start] = 0;

	for(ll i = 0; i < vertices - 1; i++){
		for(ll j = 0; j < edges; j++){
			v[e[j].second] = std::min(v[e[j].second], v[e[j].first] + e[j].dist);
		}
	}
	int endcost = v[end];
	for(ll i = 0; i < vertices - 1; i++){
		for(ll j = 0; j < edges; j++){
			v[e[j].second] = std::min(v[e[j].second], v[e[j].first] + e[j].dist);
		}
	}

	if(v[end] != endcost or v[end] == 10000000000){
		std::cout << "Impossible";
	} else {
		std::cout << v[end];
	}
	return 0;
}
