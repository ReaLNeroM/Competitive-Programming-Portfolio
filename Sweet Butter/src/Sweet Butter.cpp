/*
ID: vlade.m1
PROG: butter
LANG: C++
 */
#include <fstream>
#include <queue>

std::ifstream fin("butter.in");
std::ofstream fout("butter.out");

struct cmp{
	int loc, cost;
	bool operator()(cmp const &x, cmp const &y) {
		return (x.cost > y.cost);
	}
} copy, top;

struct edge{
	int next, cost;
};

int main() {
	int cows, pastures, paths;
	fin >> cows >> pastures >> paths;

	int c[cows], sumcost[pastures];
	std::vector<edge> adj[pastures];

	for(int i = 0; i < pastures; i++){
		sumcost[i] = 0;
	}

	for(int i = 0, cow; i < cows; i++){
		fin >> cow;
		c[i] = cow - 1;
	}

	for(int i = 0, first, second; i < paths; i++){
		edge copy;

		fin >> first >> second >> copy.cost;

		first--, second--;

		copy.next = first;
		adj[second].push_back(copy);

		copy.next = second;
		adj[first].push_back(copy);
	}

	int cost[pastures];
	for(int cowpast = 0; cowpast < cows; cowpast++){
		std::priority_queue<cmp, std::vector<cmp>, cmp> pq;

		for(int set = 0; set < pastures; set++){
			cost[set] = 100000000;
		}

		copy.loc = c[cowpast];
		copy.cost = 0;
		cost[copy.loc] = 0;

		pq.push(copy);

		while(!pq.empty()){
			do{
				top = pq.top();
				pq.pop();
			} while(top.cost > cost[top.loc] and !pq.empty());

			for(int i = 0; i < adj[top.loc].size(); i++){
				copy.loc = adj[top.loc][i].next;
				copy.cost = top.cost + adj[top.loc][i].cost;

				if(copy.cost < cost[copy.loc]){
					cost[copy.loc] = copy.cost;
					pq.push(copy);
				}
			}
		}

		for(int add = 0; add < pastures; add++){
			sumcost[add] += cost[add];
		}
	}

	int best = sumcost[0];
	for(int i = 0, curr; i < pastures; i++){
		best = std::min(best, sumcost[i]);
	}

	fout << best << std::endl;
	return 0;
}
