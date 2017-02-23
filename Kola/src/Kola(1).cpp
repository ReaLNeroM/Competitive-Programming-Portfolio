#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

int maxchargedist;

struct pusher {
	int pos, charge, chargedist;
	int cost;
	bool triggered = false;

	bool operator()(const pusher &x, const pusher &y) const {
		return (x.charge - 1) * maxchargedist + x.chargedist - x.cost < (y.charge - 1) * maxchargedist + y.chargedist - y.cost;
	}
};

int main() {
	int vertices, badcities, charges;
	std::cin >> vertices >> badcities >> charges >> maxchargedist;

	std::vector <std::pair <int, int> > adjList[vertices];

	int edges;
	std::cin >> edges;

	for (int i = 0, left, right, cost; i < edges; i++) {
		std::cin >> left >> right >> cost;

		std::pair <int, int> p;
		p.second = cost;

		p.first = right - 1;
		adjList[left - 1].push_back(p);
		p.first = left - 1;
		adjList[right - 1].push_back(p);
	}

	int dist[10][3 + 1][10 + 1];

	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j <= charges; j++) {
			for (int k = 0; k <= maxchargedist; k++) {
				dist[i][j][k] = vertices * 100;
			}
		}
	}

	pusher copy;
	copy.pos = 0;
	copy.charge = charges;
	copy.chargedist = 0;
	copy.cost = 0;
	dist[copy.pos][copy.charge][copy.chargedist] = 0;

	std::priority_queue <pusher, std::vector <pusher>, pusher> pq;
	pq.push(copy);

	while (!pq.empty()) {
		copy = pq.top();
		pq.pop();
		pusher copy2 = copy;
		bool driveable = true;

		if (copy2.charge > 0) {
			copy2.charge = copy.charge - 1;
			copy2.chargedist = maxchargedist;
			copy2.triggered = true;

			dist[copy2.pos][copy2.charge][copy2.chargedist] = copy2.cost;
			pq.push(copy2);
		}

		if(copy.pos < badcities and !copy.triggered){
			driveable = false;
		}


		copy.triggered = false;
		if (dist[copy.pos][copy.charge][copy.chargedist] >= copy.cost) {
			for (int l = 0; l < adjList[copy.pos].size(); l++) {
				copy2 = copy;
				copy2.pos = adjList[copy.pos][l].first;
				if (driveable and copy.chargedist >= adjList[copy.pos][l].second) {
					copy2.chargedist = copy.chargedist - adjList[copy.pos][l].second;

					if (dist[copy2.pos][copy2.charge][copy2.chargedist] > copy2.cost) {
						dist[copy2.pos][copy2.charge][copy2.chargedist] = copy2.cost;
						pq.push(copy2);
					}

				}

				copy2.cost += adjList[copy.pos][l].second;

				if (dist[copy2.pos][copy2.charge][copy2.chargedist] > copy2.cost) {
					copy2.chargedist = 0;
					dist[copy2.pos][copy2.charge][copy2.chargedist] = copy2.cost;
					pq.push(copy2);
				}
			}
		}
	}

	int min = edges * 100;
	for (int i = 0; i <= charges; i++) {
		for (int j = 0; j <= maxchargedist; j++) {
			min = std::min(min, dist[vertices - 1][i][j]);
		}
	}

	std::cout << min;
	return 0;
}
