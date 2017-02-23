#include <iostream>
#include <vector>
#include <queue>

//streptogsezol
//enteroforil

struct edge {
	int destination = 0, cost = 0;

	bool operator()(edge const &x, edge const &y) {
		return (y.cost < x.cost);
	}
};

int main() {
	int vertices, edges;

	std::cin >> vertices >> edges;

	bool used[vertices];
	for(int i = 0; i < vertices; i++){
		used[i] = false;
	}
	std::vector<edge> adjL[vertices];

	edge transfer, second;
	std::priority_queue<edge, std::vector<edge>, edge> q;
	q.push(transfer);

	for(int i = 0, first, second, cost; i < edges; i++){
		std::cin >> first >> second >> cost;
		transfer.destination = second, transfer.cost = cost;
		adjL[first].push_back(transfer);
		transfer.destination = first;
		adjL[second].push_back(transfer);
	}

	int treesum = 0;
	for(int i = 0; i < vertices; i++){
		while(!q.empty() and used[q.top().destination]){
			q.pop();
		}
		if(q.empty()){
			treesum = -1;
			break;
		}
		transfer = q.top();
		q.pop();
		used[transfer.destination] = true;
		treesum += transfer.cost;

		for(int j = 0; j < adjL[transfer.destination].size(); j++){
			if(!used[adjL[transfer.destination][j].destination]){
				second = adjL[transfer.destination][j];
				q.push(second);
			}
		}

	}

	std::cout << treesum;
	return 0;
}
