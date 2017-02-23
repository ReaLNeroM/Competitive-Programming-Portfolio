#include <iostream>
#include <queue>

typedef long long ll;

int main() {
	ll stands = 2, waiting = 2;
//	std::cin >> stands >> waiting;

	std::queue <std::pair <std::string, ll> > st[stands];

	for (int i = 0; i < stands; i++) {
		for (int j = 0; j < waiting; j++) {
			std::pair <std::string, ll> copy;
			std::cin >> copy.first >> copy.second;
			st[i].push(copy);
		}
		int wait = 0;
		for(int j = 0; j < waiting; j++){
			st[i].front().second += wait;
			wait = st[i].front().second;
			st[i].push(st[i].front());
			st[i].pop();
		}
	}

	int min;
	int last = 0;
	for (int i = 0; i < stands * waiting; i++) {
		min = -1;
		for (int j = 0; j < stands; j++) {
			if (!st[j].empty() and (min == -1 or st[j].front().second < st[min].front().second)) {
				min = j;
			}
		}

		std::cout << st[min].front().first;

		if(last != st[min].front().second){
			std::cout << '\n';
		} else {
			std::cout << ' ';
		}
		last = st[min].front().second;
		st[min].pop();
	}
	std::cout << '\n';
	return 0;
}
