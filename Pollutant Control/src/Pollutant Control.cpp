/*
 ID: vlade.m1
 PROG: milk6
 LANG: C++
*/

//#define mycomputer true

#ifdef mycomputer
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("milk6.in");
	std::ofstream fout("milk6.out");
#endif

#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;

struct indexededges {
	int first, second, third;
	int index;
};

indexededges make_e(int first, int second, int third, int index){
	indexededges e;
	e.first = first;
	e.second = second;
	e.third = third;
	e.index = index;

	return e;
}


static int cost[32][32];
int v, e;

bool cmp(indexededges a, indexededges b){
	return a.third - cost[a.first][a.second] > b.third - cost[b.first][b.second];
}

int flow(){
	int res = 0;

	bool change = false;
	do{
		change = false;

		int parent[v];
		for(int i = 0; i < v; i++){
			parent[i] = -1;
		}

		queue<int> q;
		q.push(0);
		parent[0] = 0;

		while(!q.empty()){
			int fr = q.front();
			q.pop();

			for(int i = 0; i < v; i++){
				if(cost[fr][i] > 0 and parent[i] == -1){
					q.push(i);
					parent[i] = fr;
				}
			}
		}

		if(parent[v - 1] != -1){
			change = true;

			int pos = v - 1, bottleneck = 2000000;
			while(pos != parent[pos]){
				bottleneck = min(bottleneck, cost[parent[pos]][pos]);
				pos = parent[pos];
			}

			pos = v - 1;
			while(pos != parent[pos]){
				cost[parent[pos]][pos] -= bottleneck;
				cost[pos][parent[pos]] += bottleneck;
				pos = parent[pos];
			}

			res += bottleneck;
		}
	} while(change);

	return res;
}
int main() {
	fin >> v >> e;

	indexededges adj[e];

	bool used[e];
	for(int i = 0; i < e; i++){
		int f, s, c;
		fin >> f >> s >> c;
		adj[i].first = f - 1, adj[i].second = s - 1, adj[i].third = c, adj[i].index = i;
		cost[f - 1][s - 1] += c;
		used[i] = false;
	}


	int flowres = flow(), edges = 0;
	fout << flowres << ' ';

	sort(adj, adj + e, cmp);
	for(int i = 0; i < e; i++){
		cost[adj[i].first][adj[i].second] += adj[i].third;
		int flowcopy = flow();

		if(flowres - adj[i].third == flowcopy){
			used[adj[i].index] = true;
			edges++;
			flowres = flowcopy;
		}
	}


	fout << edges << endl;

	for(int i = 0; i < e; i++){
		if(used[i]){
			fout << i + 1 << endl;
		}
	}
	return 0;
}
