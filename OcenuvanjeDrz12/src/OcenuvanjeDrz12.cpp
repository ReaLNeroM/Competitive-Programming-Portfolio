#include <iostream>
#include <vector>

long long servers, checks, maxtime = 200, best;
std::vector<long long> server;

long long canbedone(long long time, long long parent){
	if(time >= best){
		return best;
	}

	long long solvable = 0;
	for(int i = 0; i < servers; i++){
		solvable += time / server[i];
	}

	if(solvable >= checks){
		best = time;
		return std::min(canbedone(time / 2, time), time);
	} else if(solvable < checks){
		return canbedone((time + parent) / 2 + (time + parent) % 2, parent);
	}
}

int main() {
	std::cin >> servers >> checks;

	server.resize(servers);
	for(int i = 0; i < servers; i++){
		std::cin >> server[i];

		maxtime = std::min(maxtime, server[i]);
	}

	maxtime *= checks;

	best = maxtime;

	std::cout << canbedone(maxtime / 2, maxtime);
	return 0;
}
