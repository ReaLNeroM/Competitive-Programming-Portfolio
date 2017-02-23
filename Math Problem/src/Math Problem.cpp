#include <iostream>
#include <vector>

int main() {
	std::vector<int> p[101];
	p[1].push_back(1);
	for(int i = 2; i <= 100; i++){
		int number = i;
		while(number % 2 == 0){
			p[i].push_back(2);
			number /= 2;
		}
		for(int j = 3; j <= std::min(99, number); j += 2){
			while(number % j == 0){
				p[i].push_back(j);
				number /= j;
			}
		}
	}

	int cases;
	std::cin >> cases;
	int res[cases];

	int used[100];
	for(int i = 0; i < cases; i++){
		for(int j = 2; j < 100; j++){
			used[j] = 0;
		}

		int numsgiven;
		std::cin >> numsgiven;
		res[i] = 1;

		for(int j = 0; j < numsgiven; j++){
			int inp;
			std::cin >> inp;

			for(int k = 0; k < p[inp].size(); k++){
				used[p[inp][k]]++;
			}

		}

		for(int k = 2; k <= 97; k++){
			if(used[k] % 2 == 1){
				res[i] *= k;
				res[i] %= 1000007;
			}
		}
	}

	for(int i = 0; i < cases; i++){
		std::cout << res[i] << std::endl;
	}
	return 0;
}
