#include <iostream>
#include <vector>

struct worker {
	int value, best = -1;

	std::vector<int> next;
};

std::vector<worker> w;

int gen(int pos){
	if(w[pos].best == -1){
		w[pos].best = w[pos].value;
		for(int i = 0; i < w[pos].next.size(); i++){
			for(int j = 0; j < w[w[pos].next[i]].next.size(); j++){
				w[pos].best += gen(w[w[pos].next[i]].next[j]);
			}
		}

		int second = 0;
		for(int i = 0; i < w[pos].next.size(); i++){
			second += gen(w[pos].next[i]);
		}

		w[pos].best = std::max(w[pos].best, second);
	}

	return w[pos].best;
}

int main() {
	int nodes;
	std::cin >> nodes;

	w.resize(nodes);
	std::cin >> w[0].value;

	for(int i = 1, boss; i < nodes; i++){
		std::cin >> w[i].value >> boss;

		w[boss].next.push_back(i);
	}

	std::cout << gen(0);
	return 0;
}
