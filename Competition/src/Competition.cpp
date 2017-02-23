#include <iostream>
#include <queue>

typedef long long ll;

struct compare {
	int ms, index, lap;

	bool operator()(compare const &x, compare const &y) const {
		return x.ms > y.ms;
	}
};
int main() {
	std::ios::sync_with_stdio(false);
	int laps, competitors;
	std::cin >> competitors >> laps;

	std::priority_queue<compare, std::vector<compare>, compare> q;
	int speed[competitors], drink[competitors];

	for(int i = 0; i < competitors; i++){
		std::cin >> speed[i] >> drink[i];

		compare copy;
		copy.ms = speed[i];
		copy.index = i;
		copy.lap = 1;

		q.push(copy);
	}

	int last = 0, max = 0, curr = 0;
	for(int i = 0; i < laps * competitors; i++){
		if(q.top().ms == last){
			curr++;
			max = std::max(max, curr);
		} else {
			last = q.top().ms;
			curr = 1;
		}

		compare copy = q.top();
		q.pop();

		if(copy.lap == laps){
			continue;
		}

		copy.ms += speed[copy.index] + copy.lap % drink[copy.index];

		copy.lap++;

		q.push(copy);
	}

	std::cout << max;
	return 0;
}
