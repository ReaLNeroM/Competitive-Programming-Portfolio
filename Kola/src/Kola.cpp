#include <iostream>
#include <vector>
#include <queue>
#include <utility>

typedef long long ll;

#define currstateval best[fr.pos][fr.chleft][fr.eleft]

struct state {
	int pos, chleft, eleft;
};

state make_state(int a, int b, int c){
	state copy;
	copy.pos = a;
	copy.chleft = b;
	copy.eleft = c;

	return copy;
}

int main() {
	int vertices, bnrcity, charge, energy, edges;
	std::cin >> vertices >> brcity >> charge >> energy >> edges;

	std::vector<std::pair<int, int> > adj[vertices];
	for(int i = 0; i < edges; i++){
		int first, second, dist;
		std::cin >> first >> second >> dist;

		adj[first - 1].push_back(std::make_pair(second - 1, dist));
		adj[second - 1].push_back(std::make_pair(first - 1, dist));
	}

	int best[vertices + 1][charge + 1][energy + 1];
	for(int i = 0; i <= vertices; i++){
		for(int j = 0; j <= charge; j++){
			for(int k = 0; k <= energy; k++){
				best[i][j][k] = edges * 100;
			}
		}
	}

	std::queue<state> q;
	q.push(make_state(0, charge, 0));
	best[0][charge][0] = 0;

	while(!q.empty()){
		state fr = q.front();
		q.pop();

		if(fr.chleft > 0 and best[fr.pos][fr.chleft - 1][energy] > currstateval){
			q.push(make_state(fr.pos, fr.chleft - 1, energy));
			best[fr.pos][fr.chleft - 1][energy] = currstateval;
		}

		for(int i = 0; i < adj[fr.pos].size(); i++){
			int e_leftover = fr.eleft - adj[fr.pos][i].second;
			int e_connect = e_leftover;
			if(adj[fr.pos][i].first < brcity){
				e_connect = 0;
			}

			if(e_leftover >= 0 and best[adj[fr.pos][i].first][fr.chleft][e_connect] > currstateval){
				q.push(make_state(adj[fr.pos][i].first, fr.chleft, e_connect));
				best[adj[fr.pos][i].first][fr.chleft][e_connect] = currstateval;
			}
			if(best[adj[fr.pos][i].first][fr.chleft][0] > currstateval + adj[fr.pos][i].second){
				q.push(make_state(adj[fr.pos][i].first, fr.chleft, 0));
				best[adj[fr.pos][i].first][fr.chleft][0] = currstateval + adj[fr.pos][i].second;
			}
		}

	}

	int min = edges * 100;
	for(int i = 0; i <= charge; i++){
		for(int j = 0; j <= energy; j++){
			min = std::min(min, best[vertices - 1][i][j]);
		}
	}

	std::cout << min;
	return 0;
}
