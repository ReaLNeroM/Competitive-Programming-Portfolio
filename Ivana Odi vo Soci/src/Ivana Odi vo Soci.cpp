#include <iostream>

using namespace std;
typedef long long ll;

struct edge{
	int first, second, dist;
};

int bellman(int end, int v[], int vertices, edge e[], int edges){
	for(int i = 0; i < vertices - 1; i++){
		for(int j = 0; j < edges; j++){
			v[e[j].second] = std::min(v[e[j].second], v[e[j].first] + e[j].dist);
		}
	}

	for(int i = 0; i < edges; i++){
		if(v[e[i].first] + e[i].dist < v[e[i].second]){
			return -123456789;
		}
	}

	return v[end];
}

int main(){
	ios::sync_with_stdio(false);
	int m, v;
	cin >> m >> v;

	int stay[v];
	for(int i = 0; i < v; i++){
		cin >> stay[i];
		stay[i] *= -1;
	}
	int e;
	cin >> e;

	edge ed[e];

	int cost[v];
	for(int i = 0; i < v; i++){
		cost[i] = 10000000;
	}

	for(int i = 0; i < e; i++){
		std::cin >> ed[i].first >> ed[i].second;
		ed[i].dist = stay[ed[i].second];
	}

	int start = 0, end = v - 1;
	cost[start] = stay[start];

	int result = bellman(end, cost, v, ed, e);

	if(result == -123456789 or m - result < 0){
		std::cout << "NE";
	} else{
		std::cout << m - result;
	}
}
