#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef long long ll;

struct node {
	std::vector<ll> edges;
	ll containscat;
	bool used;
};

struct pos {
	ll index, cats;
};

int vertices, passable;
std::vector<node> n;


int main() {
	std::cin >> vertices >> passable;

	n.resize(vertices);
	for(int i = 0; i < vertices; i++){
		std::cin >> n[i].containscat;
		n[i].used = false;
	}

	for(int i = 0, child, parent; i < vertices - 1; i++){
		std::cin >> parent >> child;
		n[parent - 1].edges.push_back(child - 1);
		n[child - 1].edges.push_back(parent - 1);
	}

	std::queue<pos> q;
	pos start, copy;
	start.index = 0, start.cats = n[0].containscat;
	n[0].used = true;
	q.push(start);

	ll res = 0;
	bool pushed;
	while(!q.empty()){
		pushed = false;

		for(ll i = 0; i < n[q.front().index].edges.size(); i++){
			if(!n[n[q.front().index].edges[i]].used){
				if(n[n[q.front().index].edges[i]].containscat){
					copy.cats = q.front().cats + 1;
				} else {
					copy.cats = 0;
				}
				copy.index = n[q.front().index].edges[i];

				if(copy.cats <= passable){
					q.push(copy);
				}
				n[copy.index].used = true;
				pushed = true;
			}
		}

		q.pop();
		if(!pushed){
			res++;
		}
	}

	std::cout << res;
	return 0;
}
