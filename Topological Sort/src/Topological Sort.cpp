#include <iostream>
#include <vector>
#include <queue>

struct vertex{
	int dood = 0;
	std::vector<int> incoming, outgoing;

	bool used = false;
};

std::vector<vertex> v;
std::queue<int> q;

void topo(int loc){
	if(v[loc].used){
		return;
	}

	v[loc].used = true;
	for(int i = 0; i < v[loc].incoming.size(); i++){
		topo(v[loc].incoming[j]);
	}

	std::cout << loc << " ";
}
int main(){
	int n, edges;
	std::cin >> n >> edges;

	v.resize(n);

	for(int i = 0, first, second; i < edges; i++){
		std::cin >> first >> second;
		v[second].incoming.push_back(first);
		v[first].outgoing.push_back(second);
		v[second].dood++;
	}

	for(int i = 0; i < n; i++){
//		topo(i);
		if(v[i].dood == 0){
			q.push(i);
		}
	}

	while(!q.empty()){
		std::cout << q.front() << " ";
		for(int i = 0; i < v[q.front()].outgoing.size(); i++){
			v[v[q.front()].outgoing[i]].dood--;
			edges--;

			if(v[v[q.front()].outgoing[i]].dood == 0){
				q.push(v[q.front()].outgoing[i]);
			}
		}

		q.pop();
	}

	if(edges > 0){
		std::cout << " WRONG " << std::endl;
	}
}
