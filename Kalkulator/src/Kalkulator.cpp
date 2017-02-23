#include <iostream>
#include <queue>

typedef long long ll;

int main() {
	std::string str;
	std::cin >> str;

	int goal;
	std::cin >> goal;

	int cost[5001];
	for(int i = 0; i <= 5000; i++){
		cost[i] = 100000;
	}

	std::queue<int> q;
	for(int i = 0; i < str.length(); i++){
		if(str[i] != '0'){
			q.push(str[i] - '0');
		}
		cost[str[i] - '0'] = 1;
	}

	while(!q.empty()){
		for(int i = 0; i < str.length(); i++){
			if(q.front() * 10 + str[i] - '0' <= 5000){
				q.push(q.front() * 10 + str[i] - '0');
				cost[q.front() * 10 + str[i] - '0'] = cost[q.front()] + 1;
			}
		}

		q.pop();
	}

	for(int i = 0; i <= 2500; i++){
		for(int j = 1; j <= i; j++){
			if(cost[i] < 50000 and cost[j] < 50000){
				if(i * j >= 5000){
					cost[5000] = std::min(cost[5000], cost[i] + 1 + cost[j]);
				} else {
					cost[i * j] = std::min(cost[i * j], cost[i] + 1 + cost[j]);
				}
			}
		}
	}

	for(int i = 0; i < 5000; i++){
		for(int j = 0; j <= i; j++){
			if(cost[i] < 50000 and cost[j] < 50000){
				if(i + j >= 5000){
					cost[5000] = std::min(cost[5000], cost[i] + 1 + cost[j]);
				} else {
					cost[i + j] = std::min(cost[i + j], cost[i] + 1 + cost[j]);
				}
			}
		}
	}

	std::cout << cost[goal];
	return 0;
}
