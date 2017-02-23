#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

struct pusher {
	int previous, curr;
	int cost;

	bool operator<(const pusher &x) const{
		return cost < x.cost;
	}
};

int main() {
	int vertices, edges;
	std::cin >> vertices >> edges;

	std::vector<int> bad[vertices][vertices];

	std::vector<int> adj[vertices];
	for(int i = 0, a, b; i < edges; i++){
		std::cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int triple;
	std::cin >> triple;
	for(int i = 0, a, b, c; i < triple; i++){
		std::cin >> a >> b >> c;

		bad[a][b].push_back(c);
	}


	int dist[vertices];
	for(int i = 0; i < vertices; i++){
		dist[i] = 100000000;
	}
	dist[0] = 0;

	std::queue<pusher> q;
	pusher x;
	x.previous = 0;
	x.curr = 0;
	x.cost = 0;

	q.push(x);
	while(!q.empty()){
		pusher copy = q.front();
		q.pop();

		for(int i = 0; i < adj[copy.curr].size(); i++){
			bool allowed = true;

			for(int j = 0; j < bad[copy.previous][copy.curr].size(); j++){
				if(bad[copy.previous][copy.curr][j] == adj[copy.curr][i]){
					allowed = false;
					break;
				}
			}

			if(allowed and dist[adj[copy.curr][i]] > copy.cost + 1){
				pusher copy2 = copy;

				copy2.cost += 1;
				copy2.curr = adj[copy.curr][i];
				copy2.previous = copy.curr;
				dist[copy2.curr] = copy2.cost;

				q.push(copy2);
			}
		}
	}

	if(dist[vertices - 1] == 100000000){
		std::cout << "GRESHKA";
	} else {
		std::cout << dist[vertices - 1];
	}
	return 0;
}
