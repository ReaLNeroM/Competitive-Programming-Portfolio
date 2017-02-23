#include <iostream>
#include <vector>

struct bt{
	int index;

	std::vector<bt*> in;
};

std::vector<int> best;

int bestdone(bt* location){
	if(best[location->index] == -1){
		int second = 1;

		for(int i = 0; i < location->in.size(); i++){
			if(location->in[i] != NULL){
				second += bestdone(location->in[i]);
			}
		}

		best[location->index] = second;

		for(int i = 0; i < location->in.size(); i++){
			if(location->in[i] != NULL){
				for(int j = 0; j < location->in[i]->in.size(); j++){
					if(location->in[i]->in[j] != NULL){
						second += bestdone(location->in[i]->in[j]);
					}
				}
			}
		}

		best[location->index] = std::min(best[location->index], second);
	}

	return best[location->index];
}
int main() {

	return 0;
}
