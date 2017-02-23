#include <iostream>
#include <queue>
#include <cmath>
#include <functional>

#define maxv 5000

struct coordinate {
	int x, y;
} transfer;

struct star{
	int ind;
	double cost;
	bool operator()(star const &x, star const &y){
		return (x.cost < y.cost);
	}
} qpush, qextr;

double euclidd(coordinate x, coordinate y){
	return std::sqrt(std::pow(std::abs(x.x - y.x), 2) + std::pow(std::abs(x.y - y.y), 2));
}

double dijkstra(coordinate cs[], int stars, int start, int end){
	double cost[stars];

	for(int i = 1; i < stars; i++){
		cost[i] = 1000000;
	}
	std::priority_queue<star, std::vector<star>, star> queue;
	qpush.ind = start, qpush.cost = 0;
	queue.push(qpush);
	cost[0] = 0;

	while(!queue.empty()){
		qextr = queue.top();
		queue.pop();
		if(qextr.cost <= cost[qextr.ind]){
			for (int i = 1; i < stars; i++) {
				if (qextr.ind == i) continue;

				double jump = euclidd(cs[qextr.ind], cs[i]);
				if(jump > (double) 10) continue;

				if (cost[i] > qextr.cost + jump) {
					cost[i] = qextr.cost + jump;
					qpush.ind = i, qpush.cost = cost[i];
					queue.push(qpush);
				}
			}
		}

	}

	return cost[end];
}

int main() {
	int stars;
	std::cin >> stars;
	coordinate cs[stars];

	for (int i = 0; i < stars; i++) {
		std::cin >> cs[i].x >> cs[i].y;
	}

	std::cout << dijkstra(cs, stars, 0, stars - 1);
	return 0;
}
