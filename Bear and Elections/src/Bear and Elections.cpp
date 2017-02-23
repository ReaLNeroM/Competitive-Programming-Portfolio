#include <iostream>
#include <algorithm>

typedef long long ll;

int main() {
	int candidates;
	std::cin >> candidates;

	std::pair<int, int> votes[candidates];
	for(int i = 0; i < candidates; i++){
		std::cin >> votes[i].first;
		votes[i].second = i;
	}

	std::sort(votes, votes + candidates);

	int iterations = 0;
	while(votes[candidates - 1].second != 0){
		votes[candidates - 1].first--;

		for(int i = 0; i < candidates - 1; i++){
			if(votes[i].second == 0){
				votes[i].first++;
				break;
			}
		}

		std::sort(votes, votes + candidates);

		iterations++;
	}

	std::cout << iterations;
	return 0;
}
