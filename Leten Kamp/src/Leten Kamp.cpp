#include <iostream>
#include <vector>
#include <queue>

struct edge{
	int next, dist;
} insert;

std::vector<std::vector<long long> > dp;
std::vector<std::vector<long long> > adjmatrix;
std::vector<long long> req;

long long visiting(int pos, int visited){
	if(visited == (1 << req.size()) - 1){
		return adjmatrix[pos][0];
	}
	if(dp[pos][visited] == -1){
		dp[pos][visited] = 10000000000;
		for(int i = 0; i < dp.size(); i++){
			if(i != pos and (visited & (1 << i)) == 0){
				dp[pos][visited] = std::min(dp[pos][visited], visiting(i, visited + (1 << i)) + adjmatrix[pos][i]);
			}
		}
	}

	return dp[pos][visited];
}
int main() {
	int vertices, needed, edges;
	std::cin >> vertices >> needed >> edges;

	int req[needed];
	//req always includes 0
	for(int i = 0; i < needed; i++){
		std::cin >> req[i];
	}

	std::vector<edge> adjlist[vertices];
	for(int i = 0, first, second, dist; i < edges; i++){
		std::cin >> first >> second >> dist;

		insert.dist = dist;

		insert.next = second;
		adjlist[first].push_back(insert);

		insert.next = first;
		adjlist[second].push_back(insert);
	}

	for(int i = 0; i < needed; i++){
		//Dijkstra to calculate cost from 0 to every other node...
	}

	// convert 0 2 3 4 1 into 0 1 2 3 4 5 for the DP to work

	std::cout << visiting(0, 0);
	return 0;
}
