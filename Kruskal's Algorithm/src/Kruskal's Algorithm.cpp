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
		if(parent != parent->parent){
			parent = parent->FindHead();
		}

		return parent;
	}

	void Merge(vertex* second_node){
		vertex* head = FindHead();
		second_node = second_node->FindHead();
		if(head->rank > second_node->rank){
			second_node->parent = head;
		} else if(second_node->rank > head->rank){
			head->parent = second_node;
		} else{
			head->parent = second_node;
			head->rank++;
		}
	}
};

struct edge{
	vertex* loc[2];
	int cost;

	bool operator<(const edge &x) const{
		return (cost < x.cost);
	}
};

int main(){
	int vertices, edges;
	std::cin >> vertices >> edges;

	vertex v[vertices];
	edge e[edges];
	std::vector<int> tree;
	for(int i = 0, loc1, loc2; i < edges; i++){
		std::cin >> loc1 >> loc2 >> e[i].cost;
		e[i].loc[0] = &v[loc1];
		e[i].loc[1] = &v[loc2];

	}

	std::sort(e, e + edges);

	for(int i = 0; i < edges; i++){
		if(e[i].loc[0]->FindHead() != e[i].loc[1]->FindHead()){
			tree.push_back(i);
			e[i].loc[0]->Merge(e[i].loc[1]);
		}
	}

	for(int i = 0; i < tree.size(); i++){
		std::cout << e[tree[i]].cost << " ";
	}
	return 0;
}

