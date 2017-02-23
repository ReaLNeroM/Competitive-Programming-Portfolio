#include <iostream>
#include <algorithm>

typedef long long ll;

int main() {
	int n, m;
	std::cin >> n >> m;

	int link[n + 1];
	bool problem = false;
	for(int i = 0; i <= n; i++){
		link[i] = 0;
	}
	for(int i = 0, inp; i < n; i++){
		std::cin >> inp;

		if(link[inp] != 0){
			link[inp] = -1;
		} else {
			link[inp] = i + 1;
		}
	}

	int goal[m];
	bool impossible = false;
	for(int i = 0, inp; i < m; i++){
		std::cin >> inp;

		goal[i] = link[inp];
		if(goal[i] == 0){
			impossible = true;
		} else if(goal[i] == -1){
			problem = true;
		}
	}

	if(impossible){
		std::cout << "Impossible";
	} else if(problem){
		std::cout << "Ambiguity";
	} else {
		std::cout << "Possible" << std::endl;
		for(int i = 0; i < m; i++){
			std::cout << goal[i] << ' ';
		}
	}
	return 0;
}
