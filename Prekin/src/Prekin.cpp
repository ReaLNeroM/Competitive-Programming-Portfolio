//============================================================================
// Name        : Kruskal's.cpp
// Author      : Vladimir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>

class vertex{
	int rank = 1;
	vertex *parent = this;

	public:
	vertex* FindHead(){
		if(this != parent){
			parent = parent->FindHead();
		}
		return parent;
	}

	void Merge(vertex* second_node){
		vertex* head = FindHead(), *second_head = second_node->FindHead();
		if(head->rank > second_head->rank){
			second_head->parent = head;
		} else if(second_head->rank > head->rank){
			head->parent = second_head;
		} else{
			head->parent = second_head;
			second_head->rank++;
		}
	}
	void Reset(){
		this->rank = 1;
		this->parent = this;
	}
};

struct edge{
	int loc[2];
	int cost;
	bool usedinbest = false;

	bool operator<(const edge &x) const{
		return (cost < x.cost);
	}
};

int main(){
	int vertices, edges;
	std::cin >> vertices >> edges;

	vertex v[vertices];
	edge e[edges];
	for(int i = 0; i < edges; i++){
		std::cin >> e[i].loc[0] >> e[i].loc[1] >> e[i].cost;

		e[i].loc[0]--, e[i].loc[1]--;
	}

	std::sort(e, e + edges);

	int sum = 0;
	for(int i = 0; i < edges; i++){
		if(v[e[i].loc[0]].FindHead() != v[e[i].loc[1]].FindHead()){
			v[e[i].loc[0]].Merge(&v[e[i].loc[1]]);
			sum += e[i].cost;
			e[i].usedinbest = true;
		}
	}

	std::cout << sum << " ";


	sum = 9999999;
	for(int i = 0; i < vertices - 1; i++){
		int currsum = 0, edgesused = 0, atcurredge = 0;
		bool done = false;
		for(int j = 0; j < vertices; j++){
			v[j].Reset();
		}
		for(int j = 0; j < edges; j++){
			if(e[j].usedinbest and !done){
				if(atcurredge == i){
					done = true;
					continue;
				}
				atcurredge++;
			}
			if(v[e[j].loc[0]].FindHead() != v[e[j].loc[1]].FindHead()){
				edgesused++;
				v[e[j].loc[0]].Merge(&v[e[j].loc[1]]);
				currsum += e[j].cost;
			}
		}
		if(edgesused == vertices - 1 and done){
			sum = std::min(sum, currsum);
		}
	}

	std::cout << sum;
	return 0;
}
