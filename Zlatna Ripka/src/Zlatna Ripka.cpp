#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int main() {
	int rounds;
	std::cin >> rounds;

	int res[rounds];

	std::vector<int> array[2];
	for(int i = 0; i < rounds; i++){
		res[i] = 0;

		for(int j = 0, num; j < 2; j++){
			std::cin >> num;

			std::vector<int>::iterator ite;

			ite = std::lower_bound(array[j].begin(), array[j].end(), num);
			if(ite == array[j].end()){
				array[j].push_back(num);
			} else {
				array[j].insert(ite, num);
			}
		}

		for(int j = 0; j <= i; j++){
			res[i] = std::max(res[i], array[0][j] + array[1][i - j]);
		}
	}

	for(int i = 0; i < rounds; i++){
		std::cout << res[i] << std::endl;
	}
	return 0;
}
