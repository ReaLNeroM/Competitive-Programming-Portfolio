m#include <iostream>

typedef long long ll;

int main() {

	bool bipartite = true;

	while(!q.empty()){
		for(int i = 0; i < adj[q.front()].size(); i++){
			if(color[q.front()] == color[adj[q.front()][i]]){
				bipartite = false;
			} else {
				color[adj[q.front()][i]] = !color[q.front()];
				q.push_ba
			}
		}

		q.pop();
	}
	return 0;
}
